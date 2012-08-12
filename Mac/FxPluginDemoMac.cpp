/***********************************************************
Author: Med0paW

Created:    2012-08-10
License:    GPLv3
***********************************************************/

#include "Mac/PluginWindowMac.h"
#include "Mac/PluginWindowMacCG.h"

#include "FxPluginDemoMac.h"

FxPluginDemoMac::FxPluginDemoMac()
{
}

FxPluginDemoMac::~FxPluginDemoMac()
{
}

bool FxPluginDemoMac::onWindowAttached(FB::AttachedEvent* evt, FB::PluginWindowMac* wnd)
{
	// load the picture from url
	CFURLRef url = CFURLCreateWithString(NULL, CFSTR("http://www.mozilla.org/media/img/firefox/template/header-logo.png"), NULL);
	CGDataProviderRef dataProvider = CGDataProviderCreateWithURL(url);
	m_image = CGImageCreateWithPNGDataProvider(dataProvider, NULL, false, kCGRenderingIntentDefault);

	return FxPluginDemo::onWindowAttached(evt, wnd);
}

bool FxPluginDemoMac::onWindowDetached(FB::DetachedEvent* evt, FB::PluginWindowMac* wnd)
{
	// release picture resource
	CGImageRelease(m_image);

    return FxPluginDemo::onWindowDetached(evt, wnd);
}

bool FxPluginDemoMac::onDrawCG(FB::CoreGraphicsDraw *evt, FB::PluginWindowMacCG*)
{
	// save the states
	CGContextRef cgContext(evt->context);
	CGContextSaveGState(cgContext);

	// calculate width and height
	FB::Rect bounds(evt->bounds);
	short width = bounds.right - bounds.left, height = bounds.bottom - bounds.top;

	// flip the coordinate space
	CGContextTranslateCTM(cgContext, 0.0, height);
	CGContextScaleCTM(cgContext, 1.0, -1.0);

	// clear the stage
	CGRect rect = { {0,0}, {width, height} };
	CGContextClearRect(cgContext, rect);

	// draw the picture
	CGContextDrawImage(cgContext, rect, m_image);

	// restore the states
	CGContextRestoreGState(cgContext);

	return true;
}

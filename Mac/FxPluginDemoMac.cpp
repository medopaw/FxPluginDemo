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
	m_image = CGImageCreateWithPNGDataProvider(dataProvider, NULL, false, kCGRenderingIntentDefault);	// here we use fasle instead of "NO"

	return FxPluginDemo::onWindowAttached(evt,wnd);
}

bool FxPluginDemoMac::onWindowDetached(FB::DetachedEvent* evt, FB::PluginWindowMac* wnd)
{
    return FxPluginDemo::onWindowDetached(evt,wnd);
}

bool FxPluginDemoMac::onDrawCG(FB::CoreGraphicsDraw *evt, FB::PluginWindowMacCG*)
{
    FB::Rect bounds(evt->bounds);
    FB::Rect clip(evt->clip);
    CGContextRef cgContext(evt->context);
	short width = bounds.right - bounds.left, height = bounds.bottom - bounds.top;

	// save the states
	CGContextSaveGState(cgContext);

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

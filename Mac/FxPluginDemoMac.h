/***********************************************************
Author: Med0paW

Created:    2012-08-10
License:    GPLv3
***********************************************************/

#ifndef H_FXPLUGINDEMOMAC
#define H_FXPLUGINDEMOMAC

#include "PluginEvents/MacEventCocoa.h"
#include "Mac/PluginWindowMac.h"
#include "Mac/PluginWindowMacCG.h"

#include "../FxPluginDemo.h"

class FxPluginDemoMac : public FxPluginDemo
{
public:
	FxPluginDemoMac();
	virtual ~FxPluginDemoMac();

	BEGIN_PLUGIN_EVENT_MAP()
		EVENTTYPE_CASE(FB::CoreGraphicsDraw, onDrawCG, FB::PluginWindowMacCG)
		EVENTTYPE_CASE(FB::AttachedEvent, onWindowAttached, FB::PluginWindowMac)
		EVENTTYPE_CASE(FB::DetachedEvent, onWindowDetached, FB::PluginWindowMac)
		PLUGIN_EVENT_MAP_CASCADE(FxPluginDemo)
	END_PLUGIN_EVENT_MAP()

	virtual bool onWindowAttached(FB::AttachedEvent *evt, FB::PluginWindowMac*);
	virtual bool onWindowDetached(FB::DetachedEvent *evt, FB::PluginWindowMac*);

protected:
	bool onDrawCG(FB::CoreGraphicsDraw *evt, FB::PluginWindowMacCG*);

private:
	CGImageRef m_image;
};

#endif

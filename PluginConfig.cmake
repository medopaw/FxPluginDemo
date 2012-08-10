#/**********************************************************\ 
#
# Auto-Generated Plugin Configuration file
# for FxPluginDemo
#
#\**********************************************************/

set(PLUGIN_NAME "FxPluginDemo")
set(PLUGIN_PREFIX "FPD")
set(COMPANY_NAME "PKU")

# ActiveX constants:
set(FBTYPELIB_NAME FxPluginDemoLib)
set(FBTYPELIB_DESC "FxPluginDemo 1.0 Type Library")
set(IFBControl_DESC "FxPluginDemo Control Interface")
set(FBControl_DESC "FxPluginDemo Control Class")
set(IFBComJavascriptObject_DESC "FxPluginDemo IComJavascriptObject Interface")
set(FBComJavascriptObject_DESC "FxPluginDemo ComJavascriptObject Class")
set(IFBComEventSource_DESC "FxPluginDemo IFBComEventSource Interface")
set(AXVERSION_NUM "1")

# NOTE: THESE GUIDS *MUST* BE UNIQUE TO YOUR PLUGIN/ACTIVEX CONTROL!  YES, ALL OF THEM!
set(FBTYPELIB_GUID 881673a9-5cbf-590e-becc-30efb579757b)
set(IFBControl_GUID e7973db9-557d-57ff-9692-7acdccc7dcd4)
set(FBControl_GUID 7d34a497-c263-570c-aff1-43365c97b22f)
set(IFBComJavascriptObject_GUID 45ef34ae-eb43-5012-a684-2619a5358bd0)
set(FBComJavascriptObject_GUID 816938aa-30b7-5d93-8da6-6017fea245dc)
set(IFBComEventSource_GUID 09243773-582a-5d29-9587-07e10f4af012)

# these are the pieces that are relevant to using it from Javascript
set(ACTIVEX_PROGID "PKU.FxPluginDemo")
set(MOZILLA_PLUGINID "pku.edu.cn/FxPluginDemo")

# strings
set(FBSTRING_CompanyName "PKU")
set(FBSTRING_PluginDescription "Firefox Plugin Demo using FireBreath")
set(FBSTRING_PLUGIN_VERSION "1.0.0.0")
set(FBSTRING_LegalCopyright "Copyright 2012 PKU")
set(FBSTRING_PluginFileName "np${PLUGIN_NAME}.dll")
set(FBSTRING_ProductName "Firefox Plugin Demo")
set(FBSTRING_FileExtents "")
set(FBSTRING_PluginName "FxPluginDemo")
set(FBSTRING_MIMEType "application/x-fxplugindemo")

# Uncomment this next line if you're not planning on your plugin doing
# any drawing:

#set (FB_GUI_DISABLED 1)

# Mac plugin settings. If your plugin does not draw, set these all to 0
set(FBMAC_USE_QUICKDRAW 0)
set(FBMAC_USE_CARBON 1)
set(FBMAC_USE_COCOA 1)
set(FBMAC_USE_COREGRAPHICS 1)
set(FBMAC_USE_COREANIMATION 0)
set(FBMAC_USE_INVALIDATINGCOREANIMATION 0)

# If you want to register per-machine on Windows, uncomment this line
#set (FB_ATLREG_MACHINEWIDE 1)

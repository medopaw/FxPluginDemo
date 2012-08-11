/**********************************************************\ 
 
 Auto-generated Factory.cpp
 
 This file contains the auto-generated factory methods 
 for the FxPluginDemo project
 
\**********************************************************/

#include "FactoryBase.h"
#if FB_WIN
#include "FxPluginDemo.h"
#else
#include "Mac/FxPluginDemoMac.h"
#endif
#include <boost/make_shared.hpp>

class PluginFactory : public FB::FactoryBase
{
public:
    ///////////////////////////////////////////////////////////////////////////////
    /// @fn FB::PluginCorePtr createPlugin(const std::string& mimetype)
    ///
    /// @brief  Creates a plugin object matching the provided mimetype
    ///         If mimetype is empty, returns the default plugin
    ///////////////////////////////////////////////////////////////////////////////
    FB::PluginCorePtr createPlugin(const std::string& mimetype)
    {
#if FB_WIN
        return boost::make_shared<FxPluginDemo>();
#else
        return boost::make_shared<FxPluginDemoMac>();
#endif
    }
    
    ///////////////////////////////////////////////////////////////////////////////
    /// @see FB::FactoryBase::globalPluginInitialize
    ///////////////////////////////////////////////////////////////////////////////
    void globalPluginInitialize()
    {
        FxPluginDemo::StaticInitialize();
    }
    
    ///////////////////////////////////////////////////////////////////////////////
    /// @see FB::FactoryBase::globalPluginDeinitialize
    ///////////////////////////////////////////////////////////////////////////////
    void globalPluginDeinitialize()
    {
        FxPluginDemo::StaticDeinitialize();
    }
};

///////////////////////////////////////////////////////////////////////////////
/// @fn getFactoryInstance()
///
/// @brief  Returns the factory instance for this plugin module
///////////////////////////////////////////////////////////////////////////////
FB::FactoryBasePtr getFactoryInstance()
{
    static boost::shared_ptr<PluginFactory> factory = boost::make_shared<PluginFactory>();
    return factory;
}


# Description
This repository contains the source code for FxPluginDemo, a Firefox plugin demo using [FireBreath](http://www.firebreath.org).
The plugin registers `application/x-fxplugindemo` as its MIME type.

# Demostration
1. Showing a picture in plugin window (under development)
-  Provide a scriptable port (done)

# Installation & Building on Mac

	git clone git://github.com/firebreath/FireBreath.git FireBreath
    mkdir projects
	cd projects
	git clone git://github.com/medopaw/FxPluginDemo.git FxPluginDemo
	cd ..
	./FireBreath/prepmac.sh projects/
	cd build
	xcodebuild
	ln -s projects/FxPluginDemo/Debug/FxPluginDemo.plugin ~/Library/Internet\ Plug-Ins/

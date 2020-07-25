# Cerulean - 50 Shades of Blue (WIP)

## Preview
Love the content? Consider Subscribing: https://tinyurl.com/ydx35uwd

[![Cerulean - 50 Shades of Blue](https://raw.githubusercontent.com/VaughnValle/demo/master/THUMA.png)](https://www.youtube.com/watch?v=Le_gTAlBNO8)

## Dependencies
### BSPWM
### SXHKD
### Polybar
### Picom
### Rofi

## Installation Steps (Ubuntu/Pop! OS 20.04)
__NOTE:__ This guide uses ``~/Downloads`` as the default path for cloning repos
1. Update your repositories:

		 sudo apt update
2. Upgrade your system:

		 sudo apt upgrade
3. Install __bspwm__:
	- Clone the repository:
			 git clone https://github.com/baskerville/bspwm.git
	- Compile and install __bspwm__:
			 
			 cd bspwm
			 make
			 sudo make install
	- Copy __bspwm configuration files__:
			 
			 mkdir ~/.config/bspwm
			 cp examples/bspwmrc ~/.config/bspwm
			 chmod +x ~/.config/bspwm/bspwmrc
			 cd ..
	- __Optional__: Configure __bspwmrc__ to your liking

			 vim ~/.config/bspwm/bspwmrc

4. Install __sxhkd__:
	- Clone the repository:

			 git clone https://github.com/baskerville/sxhkd.git
	- Compile and install __sxhkd__:
			 
			 cd sxhkd
			 make
			 sudo make install
	- Copy __sxhkd configuration files__:
			
			 mkdir ~/.config/sxhkd
			 cp examples/sxhkdrc ~/.config/sxhkd
			 cd ..
	- __Optional__: Configure the keybind in __sxhkdrc__ to your liking:

			 vim ~/.config/sxhkd/sxhkdrc
	   __NOTE__: Make sure the __terminal emulator__ used in the config file is installed as the terminal will be the only way we can interact with bspwm upon startup after a fresh installation
5. Install Polybar:
	- Install __required__ dependencies:

			 sudo apt install build-essential git cmake cmake-data pkg-config python3-sphinx libcairo2-dev libxcb1-dev libxcb-util0-dev libxcb-randr0-dev libxcb-composite0-dev python3-xcbgen xcb-proto libxcb-image0-dev libxcb-ewmh-dev libxcb-icccm4-dev libxcb-xkb-dev libxcb-xrm-dev libxcb-cursor-dev libasound2-dev libpulse-dev libjsoncpp-dev libmpdclient-dev libcurl4-openssl-dev libnl-genl-3-dev
	- Clone the repository:
	
			 git clone --recursive https://github.com/polybar/polybar
	- Compile and install:

			 cd polybar
			 mkdir build
			 cd build
			 cmake ..
			 make -j$(nproc)
			 sudo make install
6. Install Picom:
	- Install __required__ dependencies:

			 sudo apt install libxext-dev libxcb1-dev libxcb-damage0-dev libxcb-xfixes0-dev libxcb-shape0-dev libxcb-render-util0-dev libxcb-render0-dev libxcb-randr0-dev libxcb-composite0-dev libxcb-image0-dev libxcb-present-dev libxcb-xinerama0-dev libpixman-1-dev libdbus-1-dev libconfig-dev libgl1-mesa-dev  libpcre2-dev  libevdev-dev uthash-dev libev-dev libx11-xcb-dev
	- Clone the repository:

			 git clone https://github.com/ibhagwan/picom.git
	- Build (with Ninja):

			 cd picom
			 git submodule update --init --recursive
			 meson --buildtype=release . build
			 ninja -C build
	- Install:

			 ## Default installation path is /usr/local, use
			 meson configure -Dprefix=<path> build 
			 ## To change the install prefix
			 
			 ninja -C build install
			 cd ..

7. Install Rofi:
	- Install __required__ dependencies:

			 sudo apt install libpango-dev libpangocairo-dev libcairo-dev libcairo-xcb-dev libglib2.0-dev gmodule-2.0-dev gio-unix-2.0-devlibrsvg2.0 libstartup-notification-1.0-dev libxkbcommon-dev libxkbcommon-x11-dev libjpeg-dev libxcb-dev xcb-util-dev xcb-util-wm-dev xcb-util-xrm-dev
	- Clone the repository:

			 git clone https://github.com/davatorium/rofi.git
	- Build:

			 cd rofi
			 mkdir build && cd build
			 ../configure
			 make
	- Install:

			 sudo make install

## Thanks for dropping by!


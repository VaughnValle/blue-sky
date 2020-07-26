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
	- Install __required dependencies__(vim included):

			 sudo apt install vim xcb libxcb-util0-dev libxcb-ewmh-dev libxcb-randr0-dev libxcb-icccm4-dev libxcb-keysyms1-dev libxcb-xinerama0-dev libasound2-dev libxcb-xtest0-dev libxcb-shape0-dev
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
			 cp ../bspwm/examples/sxhkdrc ~/.config/sxhkd
			 cd ..
	- __Optional__: Configure the keybind in __sxhkdrc__ to your liking:

			 vim ~/.config/sxhkd/sxhkdrc
	   __NOTE__: Make sure the __terminal emulator__ used in the config file is installed as the terminal will be the only way we can interact with bspwm upon startup after a fresh installation
5. Install Polybar:
	- Install __required dependencies__:

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
	- Install __required dependencies__:

			 sudo apt install meson libxext-dev libxcb1-dev libxcb-damage0-dev libxcb-xfixes0-dev libxcb-shape0-dev libxcb-render-util0-dev libxcb-render0-dev libxcb-randr0-dev libxcb-composite0-dev libxcb-image0-dev libxcb-present-dev libxcb-xinerama0-dev libpixman-1-dev libdbus-1-dev libconfig-dev libgl1-mesa-dev  libpcre2-dev  libevdev-dev uthash-dev libev-dev libx11-xcb-dev
	- Clone the repository:

			 git clone https://github.com/ibhagwan/picom.git
	- Build (with Ninja):

			 cd picom
			 git submodule update --init --recursive
			 meson --buildtype=release . build
			 ninja -C build
	- Install:

			 sudo ninja -C build install
			 cd ..
	  __NOTE__: Default installation path is /usr/local, use this to change the install prefix:

			 meson configure -Dprefix=<path> build
7. Install Rofi:
	- Install __required dependencies__:

			 sudo apt install bison flex libstartup-notification0-dev check autotools-dev libpango1.0-dev librsvg2-bin librsvg2-dev libcairo2-dev libglib2.0-dev libxkbcommon-dev libxkbcommon-x11-dev libjpeg-dev
	- Get necessary releases:

			 cd ~/Downloads
			 wget https://github.com/davatorium/rofi/releases/download/1.5.4/rofi-1.5.4.tar.gz
			 wget https://github.com/libcheck/check/releases/download/0.15.1/check-0.15.1.tar.gz
	- Build __check__:

			 cd check-0.15.1
			 ./configure
			 make
			 make check
	- Install __check__:

			 sudo make install
			 cd ..
	- Build __rofi__:

			 cd rofi
			 mkdir build && cd build
			 ../configure
			 make
	- Install __rofi__:

			 sudo make install
	- Enable and use __rofi__:

			 vim ~/.config/sxhkd/sxhkdrc
9. Install spotify:

		 curl -sS https://download.spotify.com/debian/pubkey.gpg | sudo apt-key add - 
		 echo "deb http://repository.spotify.com stable non-free" | sudo tee /etc/apt/sources.list.d/spotify.list
		 sudo apt update && sudo apt install spotify-client
10. Install spicetify:
	- Installation:

			 curl -fsSL https://raw.githubusercontent.com/khanhas/spicetify-cli/master/install.sh | sh
		 	 sudo chmod a+wr /usr/share/spotify
		 	 sudo chmod a+wr /usr/share/spotify/Apps -R
	- Launch Spotify using spicetify: 

			 spicetify
		 	 spicetify backup apply enable-devtool
		 	 spicetify update
	- Theming:

		 	 cd ~/Downloads
		 	 git clone https://github.com/morpheusthewhite/spicetify-themes.git
		 	 cd spicetify-themes
		 	 cp -r * ~/spicetify-cli/Themes
		 	 cd ~/spicetify-cli/Themes/Dribbblish/
		 	 cp dribbblish.js ../../Extensions
		 	 spicetify config extensions dribbblish.js
		 	 spicetify config current_theme Dribbblish color_scheme base
		 	 spicetify config inject_css 1 replace_colors 1 overwrite_assets 1
		 	 spicetify apply
		 	 spicetify config current_theme Dribbblish
		 	 spicetify config color_scheme nord-dark
		 	 spicetify apply  
		 
11. Install SLiM and slimlock:
12. Install alacritty: 

		 sudo apt install alacritty
## Thanks for dropping by!


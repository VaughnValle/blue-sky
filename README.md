<h1 align="center">Cerulean</h1>
<p align="center">
  <img src="https://img.shields.io/badge/MAINTAINED-YES-green?style=for-the-badge">
  <img src="https://img.shields.io/badge/LICENSE-MIT-blue?style=for-the-badge">
  <img src="https://img.shields.io/github/issues/VaughnValle/blue-sky?style=for-the-badge"
</p>

[![Cerulean - 50 Shades of Blue](https://raw.githubusercontent.com/VaughnValle/mirth-os/master/images/cerulean.gif)](https://www.youtube.com/watch?v=Le_gTAlBNO8)

Cerulean is a minimalistic Linux setup for Pop! OS using various shades of blue. This setup uses BSPWM as the tiling window manager.

Love the content? Help me reach my goal of upgrading my laptop integrated GPU; any amount helps :)

[![paypal](https://www.paypalobjects.com/en_US/i/btn/btn_donateCC_LG.gif)](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=8QCEHJMN43VAE)

Or consider supporting me __on these platforms:__  

[![](https://c5.patreon.com/external/logo/become_a_patron_button.png)](https://www.patreon.com/sudo_rice)
[![](https://raw.githubusercontent.com/VaughnValle/demo/master/yt-badge.png)](https://www.youtube.com/sudo_rice)


## Dependencies
* bspwm
* sxhkd
* polybar
* picom
* rofi
* spotify-client
* spicetify
* alacritty
* zsh
* oh my zsh!
* powerlevel10k
* vim
* slim
* slimlock

## Installation Steps (Ubuntu/Pop! OS 20.04)
__NOTE:__ This guide uses ``~/Downloads`` as the default path for cloning repos
1. Update your repositories:

		 sudo apt update
2. Upgrade your system:

		 sudo apt upgrade
3. Install __bspwm__:

	Install required dependencies (vim included):

		 sudo apt install build-essential git vim xcb libxcb-util0-dev libxcb-ewmh-dev libxcb-randr0-dev libxcb-icccm4-dev libxcb-keysyms1-dev libxcb-xinerama0-dev libasound2-dev libxcb-xtest0-dev libxcb-shape0-dev
	Clone the repository:

		 cd ~/Downloads
		 git clone https://github.com/baskerville/bspwm.git
	Compile and install bspwm:
			 
		 cd bspwm
		 make
		 sudo make install
	Copy bspwm configuration files:
			 
		 mkdir ~/.config/bspwm
		 cp examples/bspwmrc ~/.config/bspwm
		 chmod +x ~/.config/bspwm/bspwmrc
		 cd ..
	__OPTIONAL:__ Configure bspwmrc to your liking

		 vim ~/.config/bspwm/bspwmrc

4. Install __sxhkd__:
	
	Clone the repository:

		 git clone https://github.com/baskerville/sxhkd.git
	Compile and install sxhkd:
			 
		 cd sxhkd
		 make
		 sudo make install
	Copy sxhkd configuration files:
			
		 mkdir ~/.config/sxhkd
		 cp ../bspwm/examples/sxhkdrc ~/.config/sxhkd
		 cd ..
	__OPTIONAL:__ Configure the keybind in sxhkdrc to your liking:

		 vim ~/.config/sxhkd/sxhkdrc
	
	---  
	 __NOTE:__ Make sure the terminal emulator used in the config file is installed as the terminal will be the only way we can interact with bspwm upon startup after a fresh installation

	---
5. Install Polybar:
	
	Install required dependencies:

		 sudo apt install cmake cmake-data pkg-config python3-sphinx libcairo2-dev libxcb1-dev libxcb-util0-dev libxcb-randr0-dev libxcb-composite0-dev python3-xcbgen xcb-proto libxcb-image0-dev libxcb-ewmh-dev libxcb-icccm4-dev libxcb-xkb-dev libxcb-xrm-dev libxcb-cursor-dev libasound2-dev libpulse-dev libjsoncpp-dev libmpdclient-dev libcurl4-openssl-dev libnl-genl-3-dev
	Clone the repository:
	
		 git clone --recursive https://github.com/polybar/polybar
	Compile and install __Polybar__:

		 cd polybar
		 mkdir build
		 cd build
		 cmake ..
		 make -j$(nproc)
		 sudo make install
6. Install Picom:
	
	Install required dependencies:

		 sudo apt install meson libxext-dev libxcb1-dev libxcb-damage0-dev libxcb-xfixes0-dev libxcb-shape0-dev libxcb-render-util0-dev libxcb-render0-dev libxcb-randr0-dev libxcb-composite0-dev libxcb-image0-dev libxcb-present-dev libxcb-xinerama0-dev libpixman-1-dev libdbus-1-dev libconfig-dev libgl1-mesa-dev  libpcre2-dev  libevdev-dev uthash-dev libev-dev libx11-xcb-dev libxcb-glx0-dev
	Clone the repository:

		 git clone https://github.com/ibhagwan/picom.git
	Build (with Ninja):

		 cd picom
		 git submodule update --init --recursive
		 meson --buildtype=release . build
		 ninja -C build
	Install __Picom__:

		 sudo ninja -C build install
		 cd ..
	---  
	__NOTE:__ Default installation path is ``/usr/local``, use this to change the install prefix:

		 meson configure -Dprefix=<path> build

	---
7. Install Rofi:
	
	Install required dependencies:

		 sudo apt install bison flex libstartup-notification0-dev check autotools-dev libpango1.0-dev librsvg2-bin librsvg2-dev libcairo2-dev libglib2.0-dev libxkbcommon-dev libxkbcommon-x11-dev libjpeg-dev
	Get necessary releases:

		 cd ~/Downloads
		 wget https://github.com/davatorium/rofi/releases/download/1.5.4/rofi-1.5.4.tar.gz
		 wget https://github.com/libcheck/check/releases/download/0.15.1/check-0.15.1.tar.gz
	Build check:

		 cd check-0.15.1
		 ./configure
		 make
		 make check
	Install check:

		 sudo make install
		 cd ..
	Build __rofi__:

		 cd rofi
		 mkdir build && cd build
		 ../configure
		 make
	Install __rofi__:

		 sudo make install
	Enable and use __rofi__:

		 vim ~/.config/sxhkd/sxhkdrc
	  
	Change __dmenu__ to:

		 rofi -modi run,drun,window -show drun -show-icons -sidebar-mode 
9. Install spotify:

		 curl -sS https://download.spotify.com/debian/pubkey_0D811D58.gpg | sudo apt-key add - 
		 echo "deb http://repository.spotify.com stable non-free" | sudo tee /etc/apt/sources.list.d/spotify.list
		 sudo apt update && sudo apt install spotify-client
10. Install spicetify:

	Install __spicetify__:

		 curl -fsSL https://raw.githubusercontent.com/khanhas/spicetify-cli/master/install.sh | sh
		 sudo chmod a+wr /usr/share/spotify
	 	 sudo chmod a+wr /usr/share/spotify/Apps -R
	Launch Spotify using spicetify: 

		 spicetify
		 spicetify backup apply enable-devtool
		 spicetify update
	Theming:

		 cd ~/Downloads
		 git clone https://github.com/morpheusthewhite/spicetify-themes.git
	 	 cd spicetify-themes
	 	 cp -r * ~/spicetify-cli/Themes
	 	 cd ~/spicetify-cli/Themes/Dribbblish/
	 	 cp dribbblish.js ../../Extensions
	 	 spicetify config extensions dribbblish.js
		 spicetify config current_theme Dribbblish color_scheme nord-dark
	 	 spicetify config inject_css 1 replace_colors 1 overwrite_assets 1
	 	 spicetify apply
11. Install alacritty: 
	
	Install __alacritty__:

		 sudo apt install alacritty
	Clone the repo: 

		 cd ~/Downloads
		 git clone https://github.com/VaughnValle/blue-sky.git
	Apply alacritty theme:

		 mkdir ~/.config/alacritty
		 cp blue-sky/alacritty/alacritty.yml ~/.config/alacritty/
	---
	__NOTE:__ If you get the ```error: GLSL 3.30 is not supported``` error, do this:

		 vim /usr/share/applications/com.alacritty.Alacritty.desktop
          
	and change ``Exec=alacritty`` to ``Exec=bash -c "LIBGL_ALWAYS_SOFTWARE=1 alacritty"``

	---
12. Apply the desktop wallpaper:

		 sudo apt install feh
		 echo 'feh --bg-fill $HOME/Downloads/blue-sky/wallpapers/blue3.png' >> ~/.config/bspwm/bspwmrc
13. Configure polybar:

		 mkdir ~/.config/polybar
		 cd ~/Downloads/blue-sky/polybar
		 cp * -r ~/.config/polybar
		 echo '~/.config/polybar/./launch.sh' >> ~/.config/bspwm/bspwmrc
		 cd fonts
		 sudo cp * /usr/share/fonts/truetype/
14. Install Oh My ZSH!:

		 sudo apt install zsh
		 sh -c "$(curl -fsSL https://raw.github.com/ohmyzsh/ohmyzsh/master/tools/install.sh)
15. Install Powerlevel10k:

		 git clone --depth=1 https://github.com/romkatv/powerlevel10k.git ${ZSH_CUSTOM:-$HOME/.oh-my-zsh/custom}/themes/powerlevel10k
16. Theme vim:

		 mkdir -p ~/.vim/colors
		 cd ~/Downloads
		 cp blue-sky/nord.vim ~/.vim/colors
		 git clone https://github.com/vim-airline/vim-airline.git
		 cd vim-airline
		 cp * -r ~/.vim
		 cd ~/Downloads
		 git clone https://github.com/vim-airline/vim-airline-themes.git
		 cd vim-airline-themes
		 cp * -r ~/.vim
		 echo 'colorscheme nord' >> ~/.vimrc
		 echo let g:airline_theme=\'base16\' >> ~/.vimrc
17. Theme rofi:

		 mkdir -p ~/.config/rofi/themes
		 cp ~/Downloads/blue-sky/nord.rasi ~/.config/rofi/themes
		 rofi-theme-selector #preview the "nord theme" with Enter and apply it with Alt+a
		 
		 # modify keybindings
		 vim ~/.config/sxhkd/sxhkdrc
		 # replace dmenu with rofi -show drun
18. Install slim and slimlock:

	Installation __slim__ and __slimlock__:
	
		 sudo apt install slim libpam0g-dev libxrandr-dev libfreetype6-dev libimlib2-dev libxft-dev
		 sudo dpkg-reconfigure gdm3 #select slim
		 
	---
	__NOTE:__ If you get ``fatal error: ft2build.h:`` do:

		 sudo vim /usr/include/X11/Xft/Xft.h
	
	Change line __39__: to ``#include <freetype2/ft2build.h>" <truncated>`` and do:

		 sudo cp /usr/include/freetype2/freetype /usr/include

	Then run:
		
		 sudo make
		 sudo make install
		 cd ..
	---	
	Theming:

		 cd ~/Downloads/blue-sky
		 sudo cp slim.conf /etc && sudo cp slimlock.conf /etc
		 sudo cp default /usr/share/slim/themes

## Thanks for dropping by!

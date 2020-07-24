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

			 cd ~/Downloads
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


## Thanks for dropping by!


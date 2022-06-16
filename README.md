## Introduction
Hi guys, I have always been wanted to try SLASM'EM after I ascended in vanilla nethack with the wonderful GLHack port, however SLASHEM seems discontinued and last update of it was 2007, and I experience difficulty running it properly. Here is a working version, as tested in December 2020, with some patches to make it work as in 2020.

This repository is based on the latest version of the discontinued SLASH'EM(0.08E0F1) as of Dec 24, 2020, and is properly configured for OpenGL and SDL gaming, with workarounds I can successfully compile the game on my computer (Arch Linux Rolling Release).

modifications / bugfixes are:
1. Fix the libPNG obsolete function call in `win/gl/gl_image.c`;
2. Fix the missing `$(WINSDLLIB)` in Makefile;
3. Generating the missing GLHack fonts and tilesets;
4. Patch MSGTYPE from Pasi Kallinen (https://bilious.alt.org/?397)
## Installation
On Linux machine, just `make all` and `sudo make install` shall work fine.

The default installation path is `/usr/local/slashemdir`, you may want to change it by modifing `HACKDIR` AND `SLASHEMDIR` in `./Makefile` and `./src/config.h` .

You will then need to manually copy the tilesets and fonts you need to `/usr/local/slashemdir`. They are png files in dat folder.

in case of bugs, go pray to RNGesus as nobody is maintaining this anymore.

screenshot (quite literally):
![IMG_20200205_165436](https://user-images.githubusercontent.com/24752033/170781273-13f57489-cdf1-4660-b90d-aac2869f81af.jpg)

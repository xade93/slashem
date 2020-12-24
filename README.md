# slashem
a working version of the discontinued NetHack variant SLASH'EM

## Introduction
Hi guys, I have always been wanted to try SLASM'EM after I ascended in vanilla nethack using wizard with the GLHack port, however SLASHEM seems discontinued and last update of it was 2007. Here is a working version, as tested in December 2020, with some patches to make it work as in 2020.

Major modifications are:
1. Fix the libPNG obsolete function call in win/gl/gl_image.c;
2. Fix the missing $(WINSDLLIB) in Makefile;
3. Fix the missing GLHack fonts and tilesets;
4. Some quality-of-life enhancements

## Installation
On Linux machine, just `make all` shall work fine.

The default installation path is `/usr/local/slashemdir`, you may want to change it by modifing `HACKDIR` AND `SLASHEMDIR` in ./Makefile and ./src/config.h .

You will then need to manually copy the tilesets and fonts you need to /usr/local/slashemdir. They are png files in dat folder.

in case of bugs, please email shizhengyu93@hotmail.com .


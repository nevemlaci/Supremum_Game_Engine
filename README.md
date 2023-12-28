# Supremum

SUPREMUM GAME ENGINE is my first take at creating something actually object oriented. It is some sort of an SDL wrapper for C++ with some basic extensions to make creating games easier.

This is a hobby project to familiarize myself with OOP and C++ in general. You'll see some stuff that would hurt the eyes of an experienced programmer.

## Build
* To build the project you should first clone it: `git clone https://github.com/nevemlaci/Supremum_Game_Engine`

* Then open game.sln in Visual Studio. Install SDL2 from their Github Repo either by building it or downloading it from releases: https://github.com/libsdl-org/SDL/releases/tag/release-2.28.5

* Put the `.lib` and `.dll`(Windows) files in a `./lib` directory(path is relative to `game.sln`). VS might ask you to drop the dlls into the parent folder too.

* Run it using Visual Studio. :) If you run into any problems check the project setup and try to set the linker up manually.

## Installing
  If you do not want to use git to clone the project, a(non compiled) version is available under Releases with the dependencies pre-packaged. Please note that Releases might not be updated as frequently as the source code.

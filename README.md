__OPEN.SH__
===========

![version1]( "version1")

__An add-on script for newsboat, with cross computer URL sharing.
That proxy's through Tor.__

INSTALLATION
------------

To install to user binary file, using nb file name.
        
        sudo make install

_Need root privilages for moving the executable to /usr/bin/ directory._

__For developers__

For help in use of development I use the
        
        make test

Command to test out the menu and other tui type things.

        make test2

I use this command to test the URL opening function from
out side the TUI. URL configurable in makefile, 
_if you can find a better URL, give me your reasoning's, and ill consider changing it_


Recommended use / Guide
----------------------

__Whist Using the new open.c this is phased out__
I recommend that you should 
add this little alias to your bashrc
        
        alias nb="/$HOME/.config/newsboat/open.sh"

Also probably put the script in newsboat "config" file _$HOME/.config/newsboat/_

Needed Dependencys
------------------

- [xdotool](https://github.com/jordansissel/xdotool) _for browsers_
- [nvim](https://neovim.io/) _for log function_

Optional Dependences
--------------------

_most of the above I want to be down here_

- [Proxychains](https://github.com/haad/proxychains) or
- [Proxychains-ng](https://github.com/rofl0r/proxychains-ng)
- [mpv](https://mpv.io/)
- [openbsd-netcat](https://salsa.debian.org/debian/netcat-openbsd)

Todo
====

- ~~add makefile~~
- ~~add readme how to use program~~
- add support
    * ~~other browser like firefox, librewolf, brave, lynx, links, etc... Including detecting witch is installed~~
    * ~~"log" text editors, vim, vi, ed, ETC~~
    * ~~media viewer mpv, vlc, (idk), etc...~~ : open.c
    * ~~Add availability for both gnu and openbsd netcat~~ : removing the middle man
    * Wayland
    * Multiple ip and ip selection
    * some encryption for transmission of urls
    * support for IPv6
    * Automatic loging in?
    * Support for media, Cage WM?
    * add copy to clip board as alternative to opening browser or video
- ~~add a main window, for better control~~
- ~~add a config.h~~
- find a way to use other terminals kitty, alacritty, ETC : scroll stops working
- ~~client in c~~
- server in c
- ~~transmit server.sh to a /tmp folder~~
- ~~proxychains better support and easy off switch~~
- Multipal newsboat urls
- proxychains better support and easy off switch in c
- option to start and login through ftp
- summary of updates, would then give you a summary then two options, update or do not update 


# Contribution Guidelines

* Search previous suggestions and issues before making a new one, as yours could be a duplicate.
* Make an individual pull request for each suggestion.
* New code, or code improvements to the existing code is welcome.
* Try to check your spelling and grammar, and don't hesitate to fix mine.

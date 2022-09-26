<pre>
 ██████╗ ██████╗ ███████╗███╗   ██╗   ███████╗██╗  ██╗ 
██╔═══██╗██╔══██╗██╔════╝████╗  ██║   ██╔════╝██║  ██║
██║   ██║██████╔╝█████╗  ██╔██╗ ██║   ███████╗███████║
██║   ██║██╔═══╝ ██╔══╝  ██║╚██╗██║   ╚════██║██╔══██║
╚██████╔╝██║     ███████╗██║ ╚████║██╗███████║██║  ██║
 ╚═════╝ ╚═╝     ╚══════╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝
</pre>

__OPEN.SH__
===========

__An add-on script for newsboat, with cross computer URL sharing.
That proxy's through Tor.__

Recommended use / Guide
----------------------

__Whist Using the new open.c this is phased out__

I recommend that you should 
add this little alias to your bashrc
        
        alias nb="/$HOME/.config/newsboat/open.sh"

Also probably put the script in newsboat "config" file _$HOME/.config/newsboat/_

Needed Dependencys
------------------

- [Kitty](https://sw.kovidgoyal.net/kitty/)
- [Proxychains](https://github.com/haad/proxychains) or
  [Proxychains-ng](https://github.com/rofl0r/proxychains-ng)
- [xdotool](https://github.com/jordansissel/xdotool)
- [openbsd-netcat](https://salsa.debian.org/debian/netcat-openbsd)
- [tor-browser](https://www.torproject.org/)
- [mpv](https://mpv.io/)
- [nvim](https://neovim.io/) _for log function_

Optional Dependences
--------------------

_most of the above I want to be down here_

Todo
====

- add makefile
- add readme how to use program
- add support
    * ~~other browser like firefox, librewolf, brave, lynx, links, etc... Including detecting witch is installed~~ in open.o
    * "log" text editors, vim, vi, ed, ETC
    * media viewer vlc, (idk), etc...
    * Add availability for both gnu and openbsd netcat
    * Wayland
    * Multiple ip and ip selection
    * some encryption for transmission of urls _ssh?_
    * support for IPv6
    * loging in gnome, bash, startx, ETC
    * add copy to clip board as alternative to opening browser or video
- ~~add a main window, for better control~~
- add a config.h
- revamp server for multiple windows
- find a way to use other terminals, st, alacritty, ETC
- ~~transmit server.sh to a /tmp folder~~
- Transmited urls stack in server.sh
- option to start and login through ftp
- auto update settings for server.sh, store them in main computers config
- summary of updates, would then give you a summary then two options, update or do not update 
- ~~proxychains better support and easy off switch~~


# Contribution Guidelines

* Search previous suggestions and issues before making a new one, as yours could be a duplicate.
* Make an individual pull request for each suggestion.
* New code, or code improvements to the existing code is welcome.
* Try to check your spelling and grammar, and don't hesitate to fix mine.

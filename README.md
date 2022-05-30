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

    __An addon script for newsboat, with cross computer url sharing.
    That proxys through Tor.__

_Please help, I no spell good_


Recomended use / Guide
----------------------

I recommend that you should 
add this little alias to your bashrc
        
        alias nb="/$HOME/.config/newsboat/open.sh"

Also probably put the script in newsboat config file _$HOME/.config/newsboat/_

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

Optional Dependencys
--------------------

_most of the above I want to be down here_

Todo
====

- add readme how to use program
- Options, commited out, in newsboat config
    * Option to change proxy port and ip
    * ~~Option to stop proxychains~~
    * Option to change default browser
    * Option to turn off new window
    * Option to change default media viewer
    * ~~Option to goto mac on video~~
    * ~~Option to goto mac on url~~
- Detect if missing any required or wanted packages
    - Warn user
    - Try not to use the one not installed
- add support
    * other browser like firefox, librewolf, brave, lynx, links, etc... Including detecting witch is installed
    * "log" text editors, vim, vi, ed, ETC
    * media viewer vlc, (idk), etc...
    * add availablity for both gnu and openbsd netcat
    * wayland
    * Multapal ip and ip selection
    * some encryption for transmission of urls _ssh?_
    * support for IPv6
    * loging in gnome, bash, startx, ETC
    * add copy to clip board as alternative to opening browser or video
- newsboat macro to goto main nb window
- ~~add a main window, for better control~~
- after close newsboat or log window select main controler
- bspwm spacific window managment things,
    * main is floating when exit newsboat, or log, the go back to non floating, and in small corner
    * other window manager spacific (this is a maybe)
- add make lists from mac
- revamp server.sh for multipal windows
- find a way to use other terminals, st, alacritty, ETC
- ~~transmit server.sh to a /tmp folder~~
- Transmited urls stack in server.sh
- option to start and login through ftp
- update option in open.sh window
- auto update, open.sh, from github, ask if whant to update, and presents the user with two options, summary, and no
- define in config whether to ask to update or not
- summary of updates, would then give you a summary then two options, update or do not update 
- auto update settings for server.sh, store them in main computers config
- ~~proxychains better support and easy off switch~~
- volume controller
- possibly complile this _needed feed back_
- make custom newsboat version to include this or a diff file?


# Contribution Guidelines

* Search previous suggestions and issues before making a new one, as yours could be a duplicate.
* Make an individual pull request for each suggestion.
* New code, or code improvements to the existing code is welcome.
* Try to check your spelling and grammar, and dont hesitate to fix mine.

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


Recomend
--------

I recommend that you should 
add this little alias to your bashrc
        
        alias nb="/$HOME/.config/newsboat/open.sh"

Also probably put the script in newsboat config file

Needed Dependencys
------------------

- [Kitty](https://sw.kovidgoyal.net/kitty/)
- [Proxychains](https://github.com/haad/proxychains) or
[Proxychains-ng](https://github.com/rofl0r/proxychains-ng)
- [xdotool](https://github.com/jordansissel/xdotool)
- [openbsd-netcat](https://salsa.debian.org/debian/netcat-openbsd)
- [tor-browser](https://www.torproject.org/)
- [mpv](https://mpv.io/)

Optional Dependencys
--------------------

_most of the above I want to be down here_

Todo
====

- Options, commited outt, in newsboat config
    * Option to change proxy port and ip
    * Option to stop proxychains
    * Option to change default browser
    * Option to turn off new window
    * Option to change default media viewer
- Detect if missing any required or wanted packages
    - Warn user
    - Try not to use the one not installed
- add support for other browser like firefox, librewolf, brave, lynx, links, etc... 
Including detecting witch is installed
- add support for other media viewer vlc, (idk), etc...
- proxychains better support and easy off switch
- add availablity for both gnu and openbsd netcat
- add compatability for wayland
- kitty computer controler -- volume
- possibly complile this _needed feed back_
- make custom newsboat version to include this'


# Contribution Guidelines

* Search previous suggestions and issues before making a new one, as yours could be a duplicate.
* Make an individual pull request for each suggestion.
* New code, or code improvements to the existing code is welcome.
* Try to check your spelling and grammar, and dont hesitate to fix mine.

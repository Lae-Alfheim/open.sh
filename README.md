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

__An addon script for newsboat, with cross computer url sharing.__

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
- [tor-browser]()
- [mpv]()

Optional Dependencys
--------------------

_most of the above I want to be down here_

Todo
====

- Option to stop proxychains
- Detect if missing any required or wanted packages
- add support for other browser like firefox, librewolf, brave, lynx, links, etc... 
Including detecting witch is installed
- add support for other media viewer vlc, (idk), etc...
- proxychains better support and easy off switch
- add config in config for newsboat, and commited out
- add availablity for both gnu and openbsd netcat
- add compatability for wayland

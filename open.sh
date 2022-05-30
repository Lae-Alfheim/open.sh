#! /bin/bash

url=$1 # Sets input to be value url

if pidof newsboat; then

        printf "\nNewsboat Is Found\n"
        if [[ $url == "status" ]]; then
                echo status
#        if [[ $(cat $HOME/.config/newsboat/config | grep "# " | grep -v "##" | grep "OPEN.SH" -A10 | grep  | sed 's/# //') == *TOR=FALSE* ]]; then
        elif [[ -z $url ]]; then
                printf "\nThere is nothing\n"
                exit
        else
                if [[  $(cat /tmp/newsboat-config) == *Mac=yes* && $(cat $HOME/.config/newsboat/config | grep "# " | grep -v "##" | grep "OPEN.SH" -A10) == *VIDEO=FALSE* ]]; then
                        if [[ $url == *odysee.com/* || $url == *youtube.com/* || $url == *surveillance-report.castos.com/episodes/* ]]; then
                                echo "Mac is the Yes"
                                ip=192.168.0.18
                                #ip=192.168.1.244
                                port=2999
                                echo $url | nc $ip $port -q 1
                                exit
                        else
                                echo "not video"
                        fi
                elif [[ $(cat /tmp/newsboat-config) == *Mac=yes* && $(cat $HOME/.config/newsboat/config | grep "# " | grep -v "##" | grep "OPEN.SH" -A10) == *URl=FALSE* ]]; then
                        echo "Mac is the Yes"
                        ip=192.168.0.18
                        #ip=192.168.1.244
                        port=2999
                        echo $url | nc $ip $port -q 1
                        exit
                elif [[ $url == *odysee.com/* || $url == *youtube.com/* || $url == *surveillance-report.castos.com/episodes/* ]]; then
                        mpv $url
                        exit
                else
                        xdotool search --name 'Tor Browser' windowactivate click 1
                        xdotool key --clearmodifiers ctrl+t  # open a new tab in Tor Browser
                        xdotool type $url  # type the URL in the search bar
                        xdotool key --clearmodifiers Return  # press enter
                        exit
                fi
        fi
else
        if [[ $url == "log" ]]; then
                # TODO detect for kitty
                # TODO select back nb window after launch using xdotool
                # TODO detect for xdotool
                printf "\n\nOpenining LOG\n"
                kitty --detach nvim $HOME/dox/NOTES/log.md
                config="Log=yes\n$(cat /tmp/newsboat-config | grep -v 'Log=no' | grep -v 'Log=yes' | grep -v '^$')"
                printf "\n"
                printf $config | tee /tmp/newsboat-config
                printf "\n"
        fi
        printf " ██████╗ ██████╗ ███████╗███╗   ██╗   ███████╗██╗  ██╗\n██╔═══██╗██╔══██╗██╔════╝████╗  ██║   ██╔════╝██║  ██║\n██║   ██║██████╔╝█████╗  ██╔██╗ ██║   ███████╗███████║\n██║   ██║██╔═══╝ ██╔══╝  ██║╚██╗██║   ╚════██║██╔══██║\n╚██████╔╝██║     ███████╗██║ ╚████║██╗███████║██║  ██║\n ╚═════╝ ╚═╝     ╚══════╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝\n"
        printf "starting ...\n"
        nb () {
                if [[ $(cat $HOME/.config/newsboat/config | grep "# " | grep -v "##" | grep "OPEN.SH" -A10 | grep TOR | sed 's/# //') == *TOR=FALSE* ]]; then
                        kitty --detach newsboat
                        printf "\n opening without tor"
                else
                        kitty --detach proxychains -q newsboat
                        printf "\n opening with tor"
                fi
                printf "\n Openining \n"
        }
        nb
        while read -n 1 feed
        do
                case $feed in  # TODO add more options
                "q" | "Q")      # Quit
                        printf "\nGoodbye\n"
                        break
                        ;;
                "o" | "O")
                        printf "Openining: "
                        while read -n 1 feed
                        do
                                case $feed in
                                "l" | "L")
                                        kitty --detach nvim $HOME/dox/NOTES/log.md
                                        break
                                        ;;
                                *)
                                        break
                                        ;;
                                esac
                        done
                        printf "\n"
                        ;;
                m" | "M")      # Go to Mac toggle
                        case $(cat /tmp/newsboat-config 2> /dev/null) in
                        *Mac=yes*)
                                config="Mac=no\n$(cat /tmp/newsboat-config | grep -v 'Mac=no' | grep -v 'Mac=yes' | grep -v '^$')"
                                printf "\n"
                                printf $config | tee /tmp/newsboat-config
                                printf "\n"
                                ;;
                        *)
                                config="Mac=yes\n$(cat /tmp/newsboat-config | grep -v 'Mac=no' | grep -v 'Mac=yes' | grep -v '^$')"
                                printf "\n"
                                printf $config | tee /tmp/newsboat-config
                                printf "\n"
                                ;;
                        esac
                        ;;
                "e" | "E")      # Edit Connection Details
                        printf "\n Work in Progress: Edit Connection Details\n"
                        # TODO fix/add more options and replace test
                        while read -n 1 feed
                        do
                                case $feed in
                                "t" | "T")
                                        printf "\ntest\n"
                                        ;;
                                "q" | "Q" | *)
                                        printf "\ndone!\n"
                                        break
                                        ;;
                                esac
                        done
                        printf "\n"
                        ;;
                "c" | "C")      # Print Config
                        printf "\n"
                        if ! cat /tmp/newsboat-config; then
                                printf "\nNo Configs Set\n"
                        fi
                        printf "\n"
                        ;;
                "n" | "N")      # Open Newsboat Differ Urls
                        # TODO add more url options
                        nb
                        ;;
                "h" | "H")      # Help Menu
                        # TODO add to help menu
                        printf "\n\nhelp menu\n\n"
                        ;;
                "l" | "L")      # Open log in kitty
                        case $(cat /tmp/newsboat-config 2> /dev/null) in
                        *Log=yes*)
                                config="Log=no\n$(cat /tmp/newsboat-config | grep -v 'Log=no' | grep -v 'Log=yes' | grep -v '^$')"
                                printf "\n"
                                printf $config | tee /tmp/newsboat-config
                                printf "\n"
                                ;;
                        *) 
                        # TODO detect for kitty
                        # TODO select back nb window after launch using xdotool
                        # TODO detect for xdotool
                                printf "\n\nOpenining LOG\n"
                                kitty --detach nvim $HOME/dox/NOTES/log.md
                                config="Log=yes\n$(cat /tmp/newsboat-config | grep -v 'Log=no' | grep -v 'Log=yes' | grep -v '^$')"
                                printf "\n"
                                printf $config | tee /tmp/newsboat-config
                                printf "\n"
                                ;;
                        esac
                        ;;
                *)              # Open Newsboat
                        nb
                        ;;
                esac
        done
fi

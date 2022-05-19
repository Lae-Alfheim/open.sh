#! /bin/bash


url=$1

if pidof newsboat; then
        printf "\nNewsboat Is Found\n"
        if [[ $(cat /tmp/newsboat-config) == *Mac=yes* ]]; then
                echo "Mac is the Yes"
                ip=192.168.0.18 #33
#                ip=192.168.1.244
                port=2999
                echo $url | nc $ip $port -q 1
                exit 
        elif [[ -z $url ]]; then
                printf "\nThere is nothing\n"
                exit
        else

                media=True
                if [[ $url == *odysee.com/* || $url == *youtube.com/* || $url == *surveillance-report.castos.com/episodes/* ]]; then
                        mpv $url
                        exit
                else
#                       xdotool search --name 'Tor Browser' windowactivate click 1
#                       sleep 1s
#                       bspc node -d 1
#                       bspc desktop -f 1
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
 #              while /bin/true; do
 #                      if [[ $(cat /tmp/newsboat-config) == *Log=no* ]]; then
 #                              break
 #                      fi
 #                      echo hi
 #                      notify-send "$(date "+%Y-%m-%d")" "$(echo ""; cat $HOME/dox/NOTES/log.md | grep $(date "+%Y-%m-%d") -A9999999999 | grep -v ~~ | grep __Extra -B99 | grep __Extra -v | grep -v '^[[:space:]]*$' | grep -v $(date "+%Y-%m-%d") )"
 #                      sleep 15m
 #              done &
                kitty --detach nvim $HOME/dox/NOTES/log.md
                config="Log=yes\n$(cat /tmp/newsboat-config | grep -v 'Log=no' | grep -v 'Log=yes' | grep -v '^$')"
                printf "\n"
                printf $config | tee /tmp/newsboat-config
                printf "\n"
        fi
        printf " ██████╗ ██████╗ ███████╗███╗   ██╗   ███████╗██╗  ██╗\n██╔═══██╗██╔══██╗██╔════╝████╗  ██║   ██╔════╝██║  ██║\n██║   ██║██████╔╝█████╗  ██╔██╗ ██║   ███████╗███████║\n██║   ██║██╔═══╝ ██╔══╝  ██║╚██╗██║   ╚════██║██╔══██║\n╚██████╔╝██║     ███████╗██║ ╚████║██╗███████║██║  ██║\n ╚═════╝ ╚═╝     ╚══════╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝\n"
        printf "starting ...\n"
        kitty --detach proxychains -q newsboat
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
                                *)
                                        break
                                        ;;
                                esac
                        done
                "m" | "M")      # Go to Mac toggle
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
                        newsboat
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
#                               printf "\n\nOpenining LOG\n"
#                               while /bin/true; do
#                                       if [[ $(cat /tmp/newsboat-config) == *Log=no* ]]; then
#                                               break
#                                       fi
#                                       echo hi
#                                       notify-send "$(date "+%Y-%m-%d")" "$(echo ""; cat $HOME/dox/NOTES/log.md | grep $(date "+%Y-%m-%d") -A9999999999 | grep -v ~~ | grep __Extra -B99 | grep __Extra -v | grep -v '^[[:space:]]*$' | grep -v $(date "+%Y-%m-%d") )"
#                                       sleep 15m
#                               done &
                                kitty --detach nvim $HOME/dox/NOTES/log.md
                                config="Log=yes\n$(cat /tmp/newsboat-config | grep -v 'Log=no' | grep -v 'Log=yes' | grep -v '^$')"
                                printf "\n"
                                printf $config | tee /tmp/newsboat-config
                                printf "\n"
                                ;;
                        esac
                        #printf "\n\nOpenining LOG\n"
                        #while /bin/true; do
                        #        sleep 15s
                        #        notify-send -w -a LOG Log "Hola mon"
                        #done &
                        #kitty --detach nvim $HOME/dox/NOTES/log.md
                        #kitty --detach parallel -u ::: '' 'sh; while true; do sleep 15s; notify-send -w -a LOG Log; done'
                        ;;
                *)              # Open Newsboat
                        kitty --detach proxychains -q newsboat
                        ;;
                esac
        done
fi

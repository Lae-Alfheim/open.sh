#! /usr/bin/env bash

ip address show | grep "scope global dynamic wlan0"

if [[ $(xdotool > /dev/null 2>&1) == 1 ]]; then
        tool=1
else
        tool=0
fi

while read -p "CONTINUE " -r input
do 
        if [[ $input == "q" ]]; then
                break; fi

        nc -l 2999 -q 1 > /tmp/newsboat-urls
        url=$(cat /tmp/newsboat-urls)

        if [[ $url == *odysee.com/* || $url == *youtube.com/* || $url == *surveillance-report.castos.com/episodes/* ]]; then
                if [[ $url == *surveillance-report.castos.com/episodes/* ]]; then
                        proxy=False
                elif [[ $(devour > /dev/null 2>&1) == 1 ]]; then
                        swallow=False; fi
 
                if [[ $swallow == "True" && $proxy == "True" ]]; then
                        devour mpv $url
                elif [[ $swallow == "True" && $proxy == "False" ]]; then
                        devour mpv $url
                elif [[ $swallow == "False" && $proxy == "True" ]]; then
                        proxychains -f 127.0.0.1:9050 mpv $url
                else
                        mpv $url
                fi

        else                
                xdotool search --name 'Tor Browser' windowactivate click 1
                sleep 1s
                bspc node -d 1
                sleep 1s
                bspc desktop -f 1
                xdotool search --name 'Tor Browser' windowactivate click 1
                bspc node -t floating
                xdotool key --clearmodifiers ctrl+t  # open a new tab in Tor Browser
                xdotool type $url  # type the URL in the search bar
                xdotool key --clearmodifiers Return  # press enter
        fi
done

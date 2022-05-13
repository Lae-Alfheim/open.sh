#! /bin/bash

# Show current devices ip address
ip address show | grep "scope global dynamic wlan0"

# Check for xdotool program
if [[ $(xdotool > /dev/null 2>&1) == 1 ]]; then; tool=1
else; tool=0; fi

while true; do
        if [[ $input == "q" ]]; then
                break; fi
        
        # listen on port 2999
        nc -l 2999 -C > /tmp/newsboat-urls
        echo seen
        url=$(cat /tmp/newsboat-urls)
        
        # Opening URL
        # Check if we should use mpv
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
                else; mpv $url; fi
        else    # if bspwm's bspc is not installed
                if ! command -v bspc &> /dev/null; then
                        xdotool search --name 'Tor Browser' windowactivate click 1
                        xdotool key --clearmodifiers ctrl+t  # open a new tab in Tor Browser
                        xdotool type $url  # type the URL in the search bar
                        xdotool key --clearmodifiers Return  # press enter
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
        fi
done

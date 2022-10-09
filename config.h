/* See LICENSE file for copyright and license details. */

/* {{{ */


const unsigned int SERVER = 1;
const unsigned int WIDTH=16; /* How Many Spaces Till Menu */
const unsigned int CLEAR=8; /* How Many Spaces After Menu */
const char *DEFAULTURL = "api.invidious.io"; /* Default */
const char *MUSIC = "mpv --no-video --volume=50 --shuffle $HOME/mdi/Music/* &> /dev/null &"; /* Music Command */
const char *MUSICSTOP = "pkill mpv"; /* Music Close */
const char *NEWSBOAT = "st newsboat &"; /* Newsboat Launcher */
const char *LOG = "nvim $HOME/dox/NOTES/log.md";


/*
 *  to add tor to newsboat, add proxychain infront
 * of NEWSBOAT variable
 */

/* }}} */

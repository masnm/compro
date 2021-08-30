#!/bin/bash

sudo cp mdebug /bin/mdebug
sudo cp mverdict /bin/mverdict
sudo cp minputsubmit /bin/minputsubmit
sudo cp dn.sh /bin/dn
sudo cp macceptedwrongans /bin/macceptedwrongans
sudo cp mcoderun /bin/mcoderun

echo -e '\e[0;33m#___ Dont forgate to make aliases___#\e[m'
echo 'alias t="mverdict"'
echo 'alias d="mdebug"'
echo 'alias is="minputsubmit"'
echo 'alias v="macceptedwrongans"'
echo 'alias r="mcoderun"'

#!/bin/bash

set -xe

CDIR=$(pwd)
for i in $(ls -R | grep :); do
    DIR=${i%:}                    # Strip ':'
    cd $DIR
    touch x.txt
#    $1                            # Your command
    cd $CDIR
done

#!/bin/bash

set -xe

echo $0
echo $1
if [[ "$1" == *.c ]]; then
	echo 'this is c program'
else
	echo 'this is not a c program'
fi
echo $2
echo $3

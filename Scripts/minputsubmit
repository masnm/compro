#!/bin/bash

if [ "$1" == "" ]
then
	echo -e '\e[0;31m#___File Name is Empty___#\e[m'
	exit 1
fi

if [ "$1" == "1" ] || [ "$1" == "2" ] || [ "$1" == "3" ] || [ "$1" == "4" ] || [ "$1" == "5" ]
then
	xclip -o > in$1
	exit 0
fi

if [ "$1" != "" ] && [ "$2" == "" ]
then
	xclip -selection clipboard < $1.cpp
	exit 0
fi

boolean=false

if [ "$1" != "" ] && [ "$2" != "" ]
then
	for (( i = 1 ; i < 6 ; ++i ));
	do
		if [ "$2" == "$i" ]
		then
			xclip -o > $1in$2
			boolean=true
		fi
	done
	for (( i = -1, j = 1 ; i > -6 ; --i, ++j ));
	do
		if [ "$2" == "$i" ]
		then
			xclip -o > $1out$j
			boolean=true
		fi
	done
fi

if [ "$boolean" == "false" ]
then
	exit 2
fi

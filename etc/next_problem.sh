#!/bin/bash

if [ "$1" == "" ]
then
	echo -e '\e[0;31m#___Problem Name is Empty___#\e[m'
else
	if [ -d "$1" ]
	then
		echo -e '\e[0;33m#___Directory Already Exists___#\e[m'
	else
		mkdir "$1"
		cp ./Template/template ./"$1"/src.cpp
		cp ./Template/Makefile ./"$1"/Makefile
	fi
fi

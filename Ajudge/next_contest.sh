#!/bin/bash

if [ "$1" == "" ]
then
	echo -e '\e[0;31m#___Contest Name is Empty___#\e[m'
elif [ "$2" == "" ]
then
	echo -e '\e[0;31m#___Problem Count is Empty___#\e[m'
else
	if [ -d "$1" ]
	then
		echo -e '\e[0;33m#___Directory Already Exists___#\e[m'
	else
		mkdir "$1"
		string=abcdefghijklmnopqrstuvwxyzabc
		for (( i = 0 ; i < $2 ; i++ ));
		do
			touch ./"$1"/"${string:$i:1}".cpp
			#cp ./Template/template ./"$1"/"${string:$i:1}".cpp
			#echo "${string:$i:1}"
		done
		#cp ./Template/Makefile ./"$1"/Makefile
	fi
fi

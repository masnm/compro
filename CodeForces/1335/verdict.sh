#!/bin/bash
DIFF=$(diff <(./a.out < $1) $2)
if [ "$DIFF" == "" ]
then
	echo -e '\e[0;32m#________Accepted________#\e[m'
else
	echo -e '\e[0;31m#________Wrong Answer________#\e[m'
	echo -e '\e[0;32mAnswer : \e[m'
	cat $2
	echo -e '\e[0;31mOutput : \e[m'
	./a.out < $1
	exit 1
fi

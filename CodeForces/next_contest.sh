#!/bin/bash
if [ -s $1 ]
then
	echo -e '\e[0;31mContest folder is already available.\e[m'
	echo ""
else
	python ./Template/codeforces_prepare_contest.py $1
	cp ./Template/Makefile ./$1/Makefile
	cp ./Template/verdict.sh ./$1/verdict.sh
fi

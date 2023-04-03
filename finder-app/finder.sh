#!/bin/sh

#Program that searche for a directory with it's name 
#been passed in filesdir and search for a string inside
#inside of it

[[ $# -lt 2 ]] && echo "The parameters were not specified correctly" && exit 1

filesdir=$1
searchstr=$2

if [ ! -d $filesdir ]
then 
    echo "The first argument is not a directory"
    return 1
fi 

NUMBER_OF_FILES=$(grep -rlc $searchstr $filesdir | wc -l)
NUMBER_OF_LINES=$(grep -roh $searchstr $filesdir | wc -l)
echo "The number of files are $NUMBER_OF_FILES and the number of matching lines are $NUMBER_OF_LINES"
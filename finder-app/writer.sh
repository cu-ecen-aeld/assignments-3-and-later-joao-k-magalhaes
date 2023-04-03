#!/bin/bash
#Program that receives a full path to a file on the filesytem,
#with the name writefile, and then write to that file a text 
#string, wich will be stored writestr.

[[ $# -lt 2 ]] && echo "The parameters were not specified correctly" && exit 1

writefile=$1
writestr=$2

FILE_PATH=$(dirname $writefile)

if [ ! -d $FILE_PATH ]
then
    mkdir -p $FILE_PATH
    echo $writestr > $writefile
else  
    echo $writestr > $writefile
fi

if [ ! -f $writefile ]
then 
    echo "The file $writefile could not be created"
    exit 1
fi 
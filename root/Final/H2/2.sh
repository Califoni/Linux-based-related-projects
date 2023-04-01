#! /bin/bash

if [ -d $1 ]
then
    ls $1
elif [ -f $1 ]
then
    cat $1
fi
#!/bin/bash

if [ ! "$#" -eq 3 ];
then
    echo "ARGUMENT"
    exit 1
fi

if [ ! -f $1 ];
then
    echo "File does not exist"
    exit 1
fi

file=$1
pattern=$2
replace=$3

sed -i '/^[[:space:]]*$/d' $file &> /dev/null
sed -i "s/$pattern/$replace/g" $file &> /dev/null
sed -i 'n;d' $file &> /dev/null
exit 0

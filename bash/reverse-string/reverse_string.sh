#!/bin/bash

PURE_BASH=1

TEXT=$1
LEN=${#TEXT}

if [[ $PURE_BASH == 0 ]]; then
    echo $TEXT | rev

else
    for (( i=$LEN-1; i>=0; i--)); do
        REVERSED+=${TEXT:$i:1}
    done
    echo $REVERSED
fi

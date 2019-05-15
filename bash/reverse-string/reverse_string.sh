#!/bin/bash

pure_bash=1

text="$1"
len=${#text}

if (( $pure_bash == 0 )); then
    echo "$text" | rev

else
    for (( i=$len-1; i>=0; i--)); do
        reversed+=${text:$i:1}
    done
    echo "$reversed"
fi

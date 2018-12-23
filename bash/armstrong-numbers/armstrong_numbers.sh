#!/bin/bash

function is_armstrong_number() {
    local num=$1
    local len=${#num}
    local total=0

    for (( i=0; i<len; i++ )); do
        local digit=${num:i:1}
        local power=$(( digit ** len ))
        total=$(( total + power ))
    done

    if [ $total -eq $num ]; then
        echo "true"
    else
        echo "false"
    fi
}

is_armstrong_number $1

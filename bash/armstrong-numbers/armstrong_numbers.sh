#!/bin/bash

function is_armstrong_number() {
    local num=$1
    local len=${#num}
    local count=0
    local total=0

    while [ $count -lt $len ]
    do
        local char=${num:count:1}
        local power=$(( char ** len ))
        total=$(( total + power ))
        count=$(( count + 1 ))
    done

    if [ $total -eq $num ]
    then
        echo "true"
    else
        echo "false"
    fi
}

is_armstrong_number $1

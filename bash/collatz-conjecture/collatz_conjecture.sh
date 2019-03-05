#!/bin/bash

function main() {
    local num=$1
    local count=0

    if [ $num -le 0 ]; then
        echo "Error: Only positive numbers are allowed"
        return 1
    fi

    while [ $num -gt 1 ]; do
        count=$(( $count + 1 ))
        if (( $num % 2 == 0)); then
            num=$(( $num / 2 ))
        else
            num=$(( 3 * $num + 1 ))
        fi
    done

    echo $count
}

main $1

#!/bin/bash

if [[ $# -ne 1 || ! $1 =~ ^[0-9]+$ ]]; then
    echo 'Usage: leap.sh <year>'
    exit 1
fi

if (( $1 % 4 == 0 )); then
    if (( $1 % 100 != 0 || $1 % 400 == 0)); then
        echo 'true'
        exit 0
    fi
fi

echo 'false'

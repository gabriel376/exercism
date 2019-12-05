#!/usr/bin/env bash

function main {
    string=${1^^*}
    for char in {A..Z}; do
        [[ $string =~ $char ]] || end "false"
    done
    end "true"
}

function end {
    echo "${1}"
    exit 0
}

main "$@"

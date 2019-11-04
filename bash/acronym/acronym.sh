#!/usr/bin/env bash

string="$1"
add=true
acronym=""

for (( i = 0; i < ${#string}; i++ )); do
    char=${string:i:1}

    if [[ ${char} =~ [a-zA-Z] && ${add} == true ]]; then
        acronym+=${char^}
        add=false

    elif [[ ${char} =~ ( |-) ]]; then
        add=true
    fi
done

echo ${acronym}

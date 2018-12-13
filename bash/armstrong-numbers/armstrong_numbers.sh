#!/bin/bash

function is_armstrong_number() {
    NUM=$1
    LEN=${#NUM}
    COUNT=0
    TOTAL=0

    while [ $COUNT -lt $LEN ]
    do
        CHAR=${NUM:COUNT:1}
        POWER=$(( CHAR**LEN  ))
        TOTAL=$(( TOTAL + POWER  ))
        COUNT=$(( COUNT + 1  ))
    done

    if [ $TOTAL -eq $NUM ]
    then
        echo "true"
    else
        echo "false"
    fi
}

is_armstrong_number $1

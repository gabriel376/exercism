#!/bin/bash

# set locale for date
LANG=en_US.UTF8

start=$1
giga=$(( 10 ** 9 ))

echo $(date -u -d "$start + $giga seconds")

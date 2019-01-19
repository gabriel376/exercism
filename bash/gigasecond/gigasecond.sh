#!/bin/bash

LANG=en_US
GIGA=$(( 10 ** 9 ))
echo `date -u -d "$1 + $GIGA seconds"`

#!/bin/bash

kind=$1
a=$2
b=$3
c=$4

valid_kind() {
    [[ "$1" -eq "equilateral" ]] ||
    [[ "$1" -eq "isosceles" ]] ||
    [[ "$1" -eq "scalene" ]]
}

valid_number() {
    re='^[0-9]+([.][0-9]+)?$'
    [[ "$1" =~ $re ]]
}

valid_args() {
    [[ "$#" -eq "4" ]] &&
    valid_kind "$kind" &&
    valid_number "$a" &&
    valid_number "$b" &&
    valid_number "$c"
}

valid_cond() {
    [[ $(echo "$1" | bc) -eq "1" ]]
}

valid_triangle() {
    valid_cond "$a * $b * $c != 0" &&
    valid_cond "$a <= $b + $c" &&
    valid_cond "$b <= $a + $c" &&
    valid_cond "$c <= $a + $b"
}

if ! valid_args "$@"; then
    echo "Usage: bash triangle.sh kind a b c"
    echo "    kind:      equilateral|isosceles|scalene"
    echo "    a|b|c:     integer or floating-point number"
    exit 1
elif ! valid_triangle; then
    echo "false"
    exit 0
fi

count=$(echo -e "$a\n$b\n$c" | sort | uniq | wc -l)

equilateral() {
    [[ $count -eq "1" ]]
}

isosceles() {
    [[ $count -le "2" ]]
}

scalene() {
    [[ $count -eq "3" ]]
}

if $kind $a $b $c; then
    echo "true"
else
    echo "false"
fi

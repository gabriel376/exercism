#!/bin/bash

function square_of_sum {
    local sum=0
    for (( i=1; i<=$1; i++ )); do
        sum=$(( sum + i ))
    done
    echo $(( sum * sum ))
}

function sum_of_squares {
    local sum=0
    for (( i=1; i<=$1; i++ )); do
        sum=$(( sum + (i * i) ))
    done
    echo $sum
}

function difference {
    echo $(( `square_of_sum $1` - `sum_of_squares $1` ))
}

$1 $2

#!/bin/bash

drops=([3]=Pling [5]=Plang [7]=Plong)

for drop in ${!drops[@]}; do
    (( $1 % $drop == 0 )) && sound+=${drops[$drop]}
done

echo ${sound:-$1}

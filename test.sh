#!/bin/bash

OLDIFS=$IFS
IFS=$'\n'
PORTS=$(shuf -i 1200-1300 -n5)
PORTS=($PORTS)
IFS=$OLDIFS

for I in ${!PORTS[@]}; 
do
    PORT=${PORTS[I]}
    IFS=,
    OTHERPORTS=$(echo "${PORTS[*]}")
    IFS=$OLDIFS

    if [[ I -eq 1 ]];
    then
        ./raft-server -port $PORT -cluster $OTHERPORTS &
    else
        ./raft-server -port $PORT -cluster $OTHERPORTS &
    fi
done

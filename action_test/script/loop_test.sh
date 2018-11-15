#!/bin/bash
trap "exit" INT
COUNTER=0

while :
do
  let COUNTER+=1
  echo "===== LOOP COUNTER [$COUNTER] ====="
  roslaunch action_test client.launch
done


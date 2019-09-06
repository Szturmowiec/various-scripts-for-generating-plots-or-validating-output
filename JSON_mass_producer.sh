#!/bin/bash

if [ "$#" -lt 3 ]; then
    echo "Wrong number of parameters - in order to run the script, you need to pass the following arguments in this order:"
    printf "Path to the root files directory\nPath to the output directory (it will be created if it doesn't exists)\nPath to the JSON generator\n"
    exit 2
fi

mkdir -p $2
json_producer=$(realpath $3)
output=$(realpath $2)
input=$(realpath $1)$"/*"

for f in $input
do
  out="${f%_*}"
  root -b -q $json_producer$'++("'$f'",'2',"'$out$'.json",'0')'
  if [ $? -ne 0 ]; then
      echo "Error while processing file'$f'"
      exit 2
  fi
  cp "'$out$'.json" $output
done

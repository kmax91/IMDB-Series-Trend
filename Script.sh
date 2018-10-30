#!/bin/bash

title_code=$1
./Import $1
arg=$(cat Name.txt)
echo $arg
echo "$arg;$title_code" 2>&1 | tee -a Names_Database.txt
gnuplot -c 'gnuscript.p' "$arg"

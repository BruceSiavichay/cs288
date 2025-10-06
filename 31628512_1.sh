#!/bin/bash

if [ ${#@} -eq 0 ]; then
	echo No numbers entered to sort
	exit
fi

numbers=("$@")
original=("$@")

# insertion sort algorithm
for i in `seq 1 "${#numbers[@]}"`; do
	key=${numbers[$i]}
	j=$(($i-1))

	while [[ $j -ge 0 && ${numbers[$j]} -gt $key ]]
	do
		numbers[$((j+1))]=${numbers[$j]}
		j=$(($j-1))
	done

	numbers[$((j+1))]=$key
done

echo Original array: "${original[@]}"
echo Sorted array: "${numbers[@]}"

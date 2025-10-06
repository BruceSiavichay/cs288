#!/bin/bash

echo "Enter directory:"
read userPath

if [ ! -d $userPath ]; then
	echo "Error: Directory path does not exist"
	exit
elif [ -d $userPath ]; then
	`cd $userPath`
	echo "Analyzing directory: $userPath"

	#tail -n +2 takes the second column forward note for future me
	#so on some columns (files less than 1000 bytes, there would be two spaces next to each other which would mess up everything. tr-s ' ' basically condenses this and makes sure it's one note for future me
	nameArray=(`ls -l | tail -n +2 | tr -s ' ' |  cut -d ' ' -f 9`)
	sizeArray=(`ls -l | tail -n +2 | tr -s ' ' | cut -d ' ' -f 5`)

	totalSize=0
	numItems=0

	echo "All items with sizes:"
	for size in "${sizeArray[@]}"; do
		echo "- ${nameArray[$numItems]}: ${sizeArray[$numItems]} bytes"
		((totalSize+=size))
		((numItems++))
	done

	average=$((totalSize/numItems))
	echo "Average size: $average bytes"

	greaterItems=0
	index=0
	echo "Items larger than average ($average bytes):"
	for size in "${sizeArray[@]}"; do
		if [ $size -gt $average ]; then
			((greaterItems++))
			echo "$greaterItems. ${nameArray[$index]}: ${sizeArray[$index]} bytes"	
		fi
		((index++))
	done

	echo "Total items above average: $greaterItems out of $numItems"
fi

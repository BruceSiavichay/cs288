#!/bin/bash


function traverse {
	echo $1 # function parameter

	if [ ! -d "$1" ]; then
		return
	fi

	#checks if directory is empty; its empty we dont need to go further
	if [ `ls "$1" | wc -l` -eq 0]; then
		return
	fi

	entries=("$1"/*)
	for entry in "${entries[@]}"
	do
		if [ -f"$entry" ] && [ -s "$entry"]; then
			echo "$entry"
		fi
		traverse "$entry"
	done
}

traverse $1 # Shell parameter

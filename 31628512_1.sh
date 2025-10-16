#!/bin/bash

function traverse {
	if [ ! -d "$1" ]; then
		return
	fi

	if [ `ls "$1" | wc -l` -eq 0 ]; then
		return
	fi

	entries=("$1"/*)

	for entry in "${entries[@]}"
	do
		if [[ -f "$entry" && "$entry" == *txt ]]; then
			while IFS= read -r line;
			do
				match=($(echo $line | grep -oE '[A-Za-z][A-Za-z0-9._-]*@[A-Za-z0-9.-]+\.[A-Za-z]+'))
				lines+=($match)
			done < "$entry"
		fi

		traverse "$entry"
	done
}

if [[ ${#@} -eq 0 || ${#@} -gt 1 ]]; then
	echo Invalid number of arguments
	exit
fi

if [ ! -d "$1" ]; then
	echo Error: Provided path is not a directory
	exit
fi

lines=()

traverse $1

echo "Extraction Complete: Emails sorted and stored in unique_emails.txt"
touch unique_emails.txt

printf "%s\n" "${lines[@]}" | sort -u > unique_emails.txt

#!/bin/bash

if [[ ${#@} -eq 0 || ${#@} -gt 1 ]]; then
	echo Invalid number of arguments
	exit
fi

if [ ! -f "$1" ]; then
	echo Entered file does not exist
	exit
fi

file=$1
originalDates=()
sortKeys=()

while IFS= read -r line;
do
	match=$(echo $line | grep -oE '[0-9]{2}[-/.][0-9]{2}[-/.][0-9]{4}')

	if [ ! -z "$match" ]; then
		#checks whether the format has / - or .
       		if [[ "$match" == *"-"* ]]; then
               		year=$(echo "$match" | cut -d '-' -f 3)
                	month=$(echo "$match" | cut -d '-' -f 1)
                	day=$(echo "$match" | cut -d '-' -f 2)
        	elif [[ "$match" == *"/"* ]]; then
                	year=$(echo "$match" | cut -d '/' -f 3)
                	month=$(echo "$match" | cut -d '/' -f 1)
                	day=$(echo "$match" | cut -d '/' -f 2)
        	elif [[ "$match" == *"."* ]]; then
                	year=$(echo "$match" | sed 's/\./ /g' | cut -d ' ' -f 3)
                	month=$(echo "$match" | sed 's/\./ /g' | cut -d ' ' -f 1)
                	day=$(echo "$match" | sed 's/\./ /g' | cut -d ' ' -f 2)
        	fi

        	sortKey="${year}${month}${day}"

        	#echo "${sortKey}|${match}"
        	sortKeys+=("${sortKey}|${match}")

	fi
done < "$file"

printf "%s\n" "${sortKeys[@]}" | sort -d | cut -d '|' -f 2

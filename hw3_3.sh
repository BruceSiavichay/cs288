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
sortKeys=()

while IFS= read -r line;
do
	match=$(echo $line | cut -d ',' -f 3 | sed 's/^[ ]*//;s/[ ]*$//')
	if [ ! -z "$match" ]; then
		twoWordMatch=$(echo $match | grep -oE '[A-Za-z]*[ ][A-Za-z]*')
		if [ ! -z "$twoWordMatch" ]; then
			date=$(echo "$line" | cut -d ',' -f 2 | sed 's/^[ ]*//;s/[ ]*$//')
			name=$(echo "$line" | cut -d ',' -f 1 )
			year=$(echo "$date" | cut -d '-' -f 1)
			month=$(echo "$date" | cut -d '-' -f 2)
			day=$(echo "$date" | cut -d '-' -f 3)

			age=$((2025-year))
			#because the month and day can start with a 0, we need to explicitly clarify that it's a base 10 by putting 10# in front. Also when you are doing this the brackets need to be circular for some reason.
			if (( 10#$month > 10 )); then
				((age--))
			elif (( 10#$month == 10 && 10#$day >= 10#05 )); then
				((age--))
			fi
			sortKeys+=("${age}|${name}") 
		fi
	fi
done < "$file"

#this prints out the array, sorts them in reverse order, and then reads the age and name in a while loop like above and puts it in correct format.
printf "%s\n" "${sortKeys[@]}" | sort -r |
while IFS='|' read -r age name;
do
	printf "%s, Age: %s\n" "$name" "$age"
done

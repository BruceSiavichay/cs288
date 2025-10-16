#!/bin/bash

function traverse {
	if [ ! -d "$1" ]; then
		#echo Directory does not exist
		return
	fi

	#checks if directory is empty; its empty we dont need to go further
	if [ `ls "$1" | wc -l` -eq 0 ]; then
		return
	fi

	entries=("$1"/*)

	#basenames=()
	#paths=()

	for entry in "${entries[@]}"
	do
		if [ -f "$entry" ]; then #&& [ -s "$entry" ]; then
			for i in `seq 0 "${#basenames[@]}"`
			do
				if [ "${basenames[$i]}" = "$(basename $entry)" ]; then
					((duplicatefiles+=2))
					echo "Found duplicate filename $base"
					echo "Original file: ${paths[$i]}"
					echo "Duplicate file: $entry"
					prompting=0

					while [ $prompting -ne 1 ]
					do
						echo "Do you want to remove $entry? (yes/no):"
                                        	read userInput
                                        	#the tr command can also be used to lowercase like this
                                        	userInputLower=$(echo "$userInput" | tr '[:upper:]' '[:lower:]')
                                        	if [[ "$userInputLower" == "yes" || "$userInputLower" == "y" ]]; then
							prompting=1
                                                	rm $entry
							((duplicatefiles-=2))
							((filesdeleted++))
                                        	elif [[ "$userInputLower" == "no" || "$userInputLower" == "n" ]]; then
							prompting=1
                                                	continue
                                        	fi
					done
				fi
			done
			((totalfiles++))
		fi
		basenames+=("$(basename $entry)")
		paths+=("$entry")
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

totalfiles=0
duplicatefiles=0
filesdeleted=0

basenames=()
paths=()

traverse $1


echo "Total files processed: $totalfiles"
echo "Duplicate files found: $duplicatefiles"
echo "Files deleted: $filesdeleted"


#!/bin/bash

echo "Enter a directory path:"
read userPath

if [ ! -d $userPath ]; then
	echo "Error: Directory path does not exist"
	exit
elif [ -d $userPath ]; then
	`cd $userPath`
	echo "Successfully navigated to $userPath"
	echo
	files=()
	for entry in *; do
		if [ -f "$entry" ]; then
			files+=( "$entry" )
		fi
	done

	echo "Files in this directory:"
	for i in `seq 1 "${#files[@]}"`; do
		echo "$i)  ${files[$((i-1))]}"
	done
	size=${#files[@]}
	echo "$(($size+1)) ) Exit"

	echo "Select a file (enter number): "
	read userFileChoice
	echo
	while [ $userFileChoice -ne $(($size+1)) ]
	do
		if [[ $userFileChoice -lt 1 || $userFileChoice -gt $size ]]; then
			echo "Error: Chosen number not in file range."
			echo "Select a file (enter number): "
			read userFileChoice
		else
			echo "=== Last 10 lines of ${files[$((userFileChoice-1))]} ==="
                	tail -n 10 "${files[$((userFileChoice-1))]}"
                	echo
                	echo "Would you like to see more? (yes/no):"
                	read userExploreChoice

                	position=`wc -l ${files[$((userFileChoice-1))]} | cut -d ' ' -f 1`
                	((position-=10))

                	while [ $userExploreChoice != "no" ]
                	do
                        	echo "=== Previous 10 lines ==="
                        	head -n $position "${files[$((userFileChoice-1))]}" | tail -n 10
                        	((position-=10))
				if [ $position -le 0 ]; then
                               		echo "You've reached the beginning of the file"
                                	break
                        	fi
                        	echo
                        	echo "Would you like to see more? (yes/no):"
                        	read userExploreChoice
                	done


                	echo "Files in this directory:"
                	for i in `seq 1 "${#files[@]}"`; do
                        	echo "$i) ${files[$((i-1))]}"
                	done
                	echo "$(($size+1)) ) Exit"

			echo "Select a file (enter number): "
                	read userFileChoice
		fi
	done
	echo "Thank you for using the File Viewer. Goodbye!"
fi


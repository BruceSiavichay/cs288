#!/bin/bash

queue[0]="$1" #shell parameter
while [ "${#queue[@]}" -ne 0 ];
do
	echo "${queue[0]}"
	if [ -d "${queue[0]}" ] && [ `ls "${queue[0]}" | wc -l` -ne 0 ]; then

		entries=("${queue[0]}"/*)
		# merge both queue and entries array together
		queue=("${queue[@]}" "${entries[@]}")
	fi
	# remove the first elements (FIFO)
	queue=("${queue[@]:1}")
done

#!/bin/bash

if [ ${#@} -eq 0 ]; then
	echo Error: No file names provided
	exit
elif [ ${#@} -lt 3 ]; then
	echo Error: Fewer than 3 file names provided
	exit
fi

filenames=("$@")

directoryname="backup_$(date +%Y%m%d)"

#-p only makes the directory if it doesn't exist, so we won't get future errors
mkdir -p "$directoryname"

for filename in "${filenames[@]}"; do
	if [ ! -f "$filename" ]; then
		echo Warning: File $filename does not exist	
	else
		cp "$filename" "$directoryname/"

		#+%Y%m%d puts it in YYYYMMDD format
		newname="$directoryname/${filename}_$(date +%Y%m%d)"
		mv "$directoryname/$filename" "$newname"
	fi
done

cd "$directoryname"
touch log.txt

#> is used to overwrite, >> to append.
echo "Original filenames: ${filenames[@]}" > log.txt
echo "New filenames: " >> log.txt
for file in "${filenames[@]}"; do
	echo "${file}_$(date +%Y%m%d)" >> log.txt
done

cd ..

echo Backup process is complete
echo Location of the backup directory `pwd`

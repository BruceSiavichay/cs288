#!/bin/bash
#1. 
echo "Enter text"
read userText
echo ${#userText}
echo ${userText:0:5}

#2. 

dateVar = $(date)
echo dateVar

#3.

echo "Enter a filename"
read userInput

if [ -z "$userInput" ]; then
	echo "Error: No filename provided"
elif [ -f "$userInput" ]; then
	tail -n 10 "$filename"
else
	echo "file not found"
fi



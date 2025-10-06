#!/bin/bash

var="hello"
#x=10

#x = 20

#echo $var
#echo $x

#Environment Variables: these are the variables created by system and contains system specific information. To see, use env.


echo $USER
echo $LOGNAME
echo $?
echo $HOME
echo $RANDOM #gives random number between 0 to 32767
echo $SECONDS # number of seconds since the start of session

name="john"
# export will make a variable an environment variable, only as long as your script is running
export name="john"

#prompt string
#PS1=''
#shortcuts: \u - username \w - wording directory, \t- time, \d - date, $ - prompt character

#Expansions: are few ways to operate on strings/text
#1. Arithmatic Expansion: to perform arithmetic operations
#syntax: $((expression))
x=10
y=20
echo $((x+y))

#2. Variable Expansion: operations on variables like getting length, slicing, etc.
#syntax: ${var}
# length: ${#var}
# extract a substring ${var:position}
# extract certain substring: ${var:position:length}

# 3. Command Substition/expansion: stores the output of a command into a var
# syntax: `command` or $(command)
# result = `cut -f 1 -d : /etc/passwd`
# log = `child.sh` #takes the output of script and stores it in var

#4. Brace Expansion: expands over a sequence of values
#syntax: {start..end}
#echo {1..10} #gives a range of values from 1 to 10
# variable expansion is ineligible within brace expansion
# x=1
# y=10
# echo {$x..$y} #wouldn't work, expansions must be separate

#5. Filename expansion: bash scans each word for certain characters like *, ?, [], and if these characters appear, they will be regarded as pattern.
#It replaces all the file/directory matching the pattern.
# * matches for any character of any length, including null character
# ? matches any single character
# [] matches for any single chracter enclosed within [ ]
#
# echo home* #searches for any file with home, and then any character
# echo home?
# echo home[12345]

#6. Tilde expansion: replace path to the home directory for unquoted tilde
# syntax: ~

#read num #read reads uner input and stores it into variable
#echo $num

#Single vs Double Quotes.
#Single quotes: does not allow for variable resolution
#Double quotes: allows for variable resolution

z=10
echo "The variable stores $z"
echo 'The variable stores $z' #the actual z value isnt here, just the literal



#conditional statements
# syntax (spaces matter):
#if [ expression ]; then
#	statements
#elif [ expression ]; then
#	statements
#else
#	statements
#fi

read num
if [ $num -eq 10 ]; then
	echo "yes"
else
	echo "no"
fi

echo "enter a filename: "
read filename

if [ -f $filename ] && [ -r $filename ]; then
	echo "file exists and has read permission"
	cp $filename ~/Desktop
else
	echo "file does not exist and nor ead"
fi


#Arrays:
#3 WAYS TO CREATE ARRAY
#first way: 

pet=("a dog" "a cat" lizard) #if there's no space, no need for quotes

#second way
pet[10]="a bird"

#third way
arr=(a{1..10})

#Extraction: 
##use variable expansion along with index position
# ${array_name[index]}
#
# extract range of elements
# ${array_name[@]:position:length}
#
# extract all elements
# ${arrayname[*]} or ${arrayname[@]}
#
# extract length
# echo ${#pet[@]}
#
# extraact index positions
# ${!array_name[@]}
#
# add new element
# array+=element
#
# delete an element, sets to NULL
# unset array_name[index]
#
# Loops:
# for var in param1 param2 param3
# do
# 	statements
# done
#
# for i in [1..10..2]
# do
# 	echo $i
# done #1 to 10, increment of 2
#
# x=1
# y=10
#
# for i in `seq $x $y`
# do
# 	echo $i
# done
#
# while [ condition ]
# do
# 	statments
# done

# Shell Parameters/ Arguments
# parameters passed as the script is invoked
# treated as arrays of elements
# syntax: $N, where N is the positional number of the argument
#

#echo $0 #Scripts's name
#echo $1 #first shell argument, etc.
#echo $* # extract all shell parameters excluding the script name
#echo $@ #same thing

# functions (very powerful)
# treated as mini scripts

#function func_name {
#	statements
#	return 1
#}
#
#func_name
#
#function func_name {
#	echo $1 #function parameter
#	echo $2
#}
#
#echo $1 #shell parameter

#func_name "my_file.txt" param2
#func_name $1 $2 #passing shell parameters as function parameters
#
#In bash, by default all variables are in global scope
#
#function func_name {
#	var="hello"
#	local var2="goodbye" #now its local
#}
#
#func_name
#echo $var #works!
#
#ouput=$(func_name)

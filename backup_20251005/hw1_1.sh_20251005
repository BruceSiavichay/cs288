echo "Welcome to Bash Number Guessing Game!"
echo "Think of a number between 1 and 50."
echo "You have 7 attempts to guess it!"
echo "Enter your guess: "

read userNumber
randomNumber=$((RANDOM%50 + 1))
attempts=0
gamesPlayed=0
gamesWon=0
gaming=0

while [ $gaming -ne 1 ]
do
	if [[ $userNumber -gt 50 || $userNumber -lt 1 ]]; then
		((attempts++))
		echo "Invalid input! Please enter a number between 1 and 50."
		echo "Attempts remaining: $((7-$attempts))"
		echo "Enter your guess: "
	elif [ $userNumber -lt $randomNumber ]; then
		((attempts++))
		echo "Too low! Try a higher number."
		echo "Attempts remaining: $((7-$attempts))"
		echo "Enter your guess: "
	elif [ $userNumber -gt $randomNumber ]; then
		((attempts++))
		echo "Too high! Try a lower number."
		echo "Attempts remaining: $((7-$attempts))"
		echo "Enter your guess: "
	fi

	if [[ $userNumber -eq $randomNumber || $attempts -eq 7 ]]; then
		if [ $userNumber -eq $randomNumber ]; then
			((attempts++))
			((gamesWon++))
			echo "Congratulations! You guessed the number $randomNumber in $attempts attempts!"
		elif [ $attempts -eq 7 ]; then
			echo "Game Over! The number was $randomNumber, Better luck next time!"
		fi
		((gamesPlayed++))
		echo "Would you like to play again? (yes/no):"
		read userChoice

		if [ "$userChoice" = "no" ]; then
			echo "Thanks for playing!"
			((gaming=1))
		elif [ "$userChoice" = "yes" ]; then
			((attempts=0))
			((randomNumber=$((RANDOM%50+1))))
			echo "Enter your guess: "
			read userNumber
		fi
	else
		read userNumber
	fi
done

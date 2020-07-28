#!/bin/bash

LEMIN="./lem_in"
DIR="maps/"
ERROR_DIR='error/'
ERROR_MAPS=`ls $DIR$ERROR_DIR`
SIMPLE_DIR='simple/'
SIMPLE_MAPS=`ls $DIR$SIMPLE_DIR`
LAST_DIR='last/'
CHOICE=0
MAP=0
let "REPETITION = 1"

echo -e "Choice :\n0 - Error\n1 - Simple"
echo -e "2 - flow-one\n3 - flow-ten\n4 - flow-thousand"
echo -e "5 - big\n6 - big-superposition"
read -e -p "What do you want to test ? " CHOICE

case $CHOICE in
		"0")
				for ERRMAP in $ERROR_MAPS
				do
					echo -e "\n\033[33mMAP NAME : $ERRMAP\033[37m\n"
					time $LEMIN $DIR$ERROR_DIR$ERRMAP
					#$LEMIN $DIR$ERROR_DIR$MAP | leaks lem_in;
				done
				;;
		"1")
				for SIMMAP in $SIMPLE_MAPS
				do
					echo -e "\n\033[33mMAP NAME : $SIMMAP\033[37m\n"
					time $LEMIN $DIR$SIMPLE_DIR$SIMMAP
					#$LEMIN $DIR$SIMPLE_DIR$MAP | leaks lem_in;
				done
				;;
		"2")
				MAP="--flow-one"
				;;
		"3")
				MAP="--flow-ten"
				;;
		"4")
				MAP="--flow-thousand"
				;;
		"5")
				MAP="--big"
				;;
		"6")
				MAP="--big-superposition"
				;;
		*)
				echo "Wrong command"
				;;
esac

if [ $MAP != "0" ]; then
	read -e -p "How many times ? " REPETITION
	echo -e "\n\033[33mMAP NAME : $MAP\033[37m\n"
	if [ $REPETITION -eq 1 ]; then
		./generator $MAP > $DIR$LAST_DIR$REPETITION
		time $LEMIN $DIR$LAST_DIR$REPETITION
		$LEMIN $DIR$LAST_DIR$REPETITION | grep ^L | wc -l
		#./generator $MAP | $LEMIN | leaks lem-in;
	elif [ $REPETITION -gt 1 ]; then
		rm -rf maps/last
		mkdir maps/last
		while [ $REPETITION -ne 0 ]
		do
			echo -e "\n\033[35mMAP number $REPETITION\033[37m\n"
			./generator $MAP > $DIR$LAST_DIR$REPETITION
			head $DIR$LAST_DIR$REPETITION | grep "lines required" | cut -d ' ' -f 6-8 | tr '\n' ' '
			echo -e "   lem_in: \c"
			time $LEMIN $DIR$LAST_DIR$REPETITION | grep ^L | wc -l
			let "REPETITION = REPETITION - 1"
			sleep 1
		done
	else
		echo -e "\nPlease put a number greater than 0.\n"
	fi
fi

if [ $CHOICE -eq 0 ]; then
	echo -e "\n\n\033[32m/dev/urandom/\033[37m"
	#$LEMIN /dev/urandom;
	$LEMIN /dev/urandom | leaks lem_in;

	echo -e "\n\n\033[32m/dev/null/\033[37m"
	#$LEMIN /dev/null;
	$LEMIN /dev/null | leaks lem_in;

	#echo -e "\n\n\033[32m/dev/zero/\033[37m"
	#$LEMIN /dev/zero;
	#$LEMIN /dev/zero | leaks lem_in;

	echo -e "\n\n\033[32mNothing\033[37m"
	#echo "" | $LEMIN;
	echo "" | $LEMIN | leaks lem_in;
fi
#!/bin/bash
# Sidhardh Burre, ssb3vk@virgina.edu, 3/27/2021, averagetime.sh

#echo 'Please input a number (0-9) for runtime or "quit" to exit this script'

#read -p 'Runtime/quit: ' input

read input

if [[ "quit" == $input ]] ; then
    exit 0
    
else
    sum=0
    timeTaken=0
    maxLoop=6 #has to be one greater than 5 so that the print statement works right
    for (( i = 1 ; i < maxLoop ; i ++ )); do #is it fine to declare i here instead of "before" ?
	echo 'Running iteration' $i'...'
	timeTaken=`./a.out $input | tail -1` #piping in the time value
	echo 'time taken:' $timeTaken 'ms'
	(( sum = sum + timeTaken )) #math to create sum of total time
    done

    echo '5 iterations took' $sum 'ms'
    
    (( average = sum / 5 ))

    echo 'Average time was' $average 'ms'

    #bash dumb with echo spacing was' a$ will output "was a"
    # was'$a will output "wasa" actually dumb

    exit 0

fi

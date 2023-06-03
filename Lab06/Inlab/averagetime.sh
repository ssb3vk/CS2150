#!/bin/bash
# Sidhardh Burre, ssb3vk@virgina.edu, 3/27/2021, averagetime.sh

read dictFile
read gridFile

RUNNING_TIME1=`./a.out $dictFile $gridFile | tail -1`
RUNNING_TIME2=`./a.out $dictFile $gridFile | tail -1`
RUNNING_TIME3=`./a.out $dictFile $gridFile | tail -1`
RUNNING_TIME4=`./a.out $dictFile $gridFile | tail -1`
RUNNING_TIME5=`./a.out $dictFile $gridFile | tail -1`


i=0
i=$(echo "1000*($RUNNING_TIME1+$RUNNING_TIME2+$RUNNING_TIME3+$RUNNING_TIME4+$RUNNING_TIME5) / 5" | bc)
#Allowed to take this line from the wiki page essentially? 

echo $i

exit 0

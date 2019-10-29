#!/bin/bash
#Filename: averagetime.sh
#Julia Shea - jts6mq - inlab6 - 10/22/19

#accept user input
echo "Please enter the name of the dictionary file:"
read dictionary
echo "Please enter the name of the grid file:"
read grid

#calculate runtime in milliseconds
time1=`./a.out $dictionary $grid | tail -1`
time2=`./a.out $dictionary $grid | tail -1`
time3=`./a.out $dictionary $grid | tail -1`
time4=`./a.out $dictionary $grid | tail -1`
time5=`./a.out $dictionary $grid | tail -1`

#print these times
echo "Running times in milliseconds:"
echo $time1
echo $time2
echo $time3
echo $time4
echo $time5

#calculate total runtime
total=`expr $time1 + $time2`
total=`expr $total + $time3`
total=`expr $total + $time4`
total=`expr $total + $time5`

#calculate and print the average of all 5 iterations
echo "Average time in milliseconds:"
echo `expr $total / 5`

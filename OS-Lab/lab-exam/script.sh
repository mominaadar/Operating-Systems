#!/bin/bash

str=$1
num1=$2
num2=$3

if [ $str = 'add' ]
then
	add=$( expr $num1 + $num2 )	
	echo $num1 "+" $num2 "=" $add
	
elif [ $str = "sub" ]
then
	sub=$( expr $num1 - $num2 )
	echo $num1 "-" $num2 "=" $sub

elif [ $str = "mul" ]
then
	mul=$( expr $num1 \* $num2 )
	echo $num1 "*" $num2 "=" $mul

elif [ $str = "div" ]
then 
	div=$( expr $num1 / $num2 )
	echo $num1 "/" $num2 "=" $div

elif [ $str = "rem" ]
then
	rem=$( expr $num1 % $num2 )
	echo $num1 "%" $num2 "=" $rem
	
fi

# to me expr syntax seems more easy because I don't have to insert double brackets as one can forget to add them.

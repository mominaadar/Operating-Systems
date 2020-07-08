#!/bin/bash

count="1 2 3 4 5 6 7 8 9 10"

for i in $count
do

	gcc -o server server.c 
	./server $i

	gcc -o client client.c
	./client

done

cat < message_history


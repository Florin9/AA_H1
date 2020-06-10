#!/bin/bash

#VARIABLES
good_tests=0
no_tests=0
#FUNCTIONS
function clean
{
	rm "./tester"
	rm -rf "./outchecker"
}

function compileTreap
{
	make treap
	mkdir "./outchecker"

}

function compileHeap
{
	make heap
	mkdir "./outchecker"
}

function checkTestTreap
{
	no_tests=$((no_tests + 1))
	echo -ne "Testing\t$1\t.....................................>\t\n"
	cat "./in/$1.in" | ./tester > "./outchecker/$1.out" 
	
	diff "./out/$1.out" "./outchecker/$1.out" > /dev/null && echo -ne "\t $1 passed!\n" && good_tests=$((good_tests + 1)) || echo -ne "\t**$1 Failed - files are different**\n"

}	


#EXECUTION
compileTreap
echo -ne "\t...........Testing Treap...........\n"

checkTestTreap "test0"
checkTestTreap "test1"
checkTestTreap "test2"
checkTestTreap "test3"
checkTestTreap "test4"
checkTestTreap "test5"
checkTestTreap "test6"
checkTestTreap "test7"
checkTestTreap "test8"
checkTestTreap "test9"

clean

compileHeap

echo -ne "\n\t...........Testing Heap...........\n"
checkTestTreap "test0"
checkTestTreap "test1"
checkTestTreap "test2"
checkTestTreap "test3"
checkTestTreap "test4"
checkTestTreap "test5"
checkTestTreap "test6"
checkTestTreap "test7"
checkTestTreap "test8"
checkTestTreap "test9"

echo -ne "Good tests: $good_tests/$no_tests\n"

clean





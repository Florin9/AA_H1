build: 
		g++ -Wall -o2 -c algo.cpp
heap: algoheap.c algo_test.c
		gcc -Wall -o2 algoheap.c algo_test.c -o tester

treap: algotreap.c algo_test.c
		gcc -Wall -o2 algotreap.c algo_test.c -o tester

clean:
	rm -rf *.o ./tester

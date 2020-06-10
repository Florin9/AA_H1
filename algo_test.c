#include <stdio.h>
#include <stdlib.h>
#include "algo.h"

int main() {

	void* a = initialize(50);
    /*a = insert(a,5);
    printf("%d\n",getMax(a));
printf("%d\n",getMax(a));
printf("%d\n",getMax(a));
printf("%d\n",getMax(a));
a = deleteMax(a);
printf("%d\n",getMax(a));
a = insert(a,10);
printf("%d\n",getMax(a));
a = insert(a, 9);
printf("%d\n",getMax(a));
a = deleteMax(a);
printf("%d\n",getMax(a));
a = insert(a,20);
printf("%d\n",getMax(a));
a = insert(a, 25);
printf("%d\n",getMax(a));*/

	char c = 1;
	int elem;
	while(c != '0') {
		scanf("%c", &c);
		if(c == 'I'){
			scanf("%d", &elem);
			a = insert(a, elem);
		}
		if(c == 'G') {
			printf("%d\n",getMax(a));
		}
		if(c == 'D') {
			a = deleteMax(a);
		}
	}
	return 0;
}

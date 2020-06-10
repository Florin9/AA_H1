#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* generaterandom(int nr,int maxnumber) {
    int* x = malloc(nr*sizeof(int));
    int in, im;
    int N = maxnumber;

    im = 0;
/*Knuth Algorithm*/
    for (in = 0; in < N && im < nr; ++in) {
      int rn = N - in;
      int rm = nr - im;
      if (rand() % rn < rm)
        /* use it */
        x[im++] = in - N/2;/* range from -N/2 to N/2*/
    }

    return x;
}

void shuffle(int *array, size_t n)
{
    if (n > 1)
    {
        size_t i;
        for (i = 0; i < n - 1; i++)
        {
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          int t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
}
int comparedescending(const void *p, const void *q) {
    int l = *(const int *)p;
    int r = *(const int *)q;
    return r-l;
}
void sortdescending(int* array, size_t n) {
    qsort(array,n,sizeof(int),comparedescending);
}
void testsortare(int* input,int nr) {
    int i;
    for(i = 0; i < nr; i++) {
        printf("I %d\n", input[i]);
    }
    for(i = 0; i < nr; i++) {
        printf("G\n");
        printf("D\n");
    }

}

void testrandom(int* input, int nr) {
    int nrinputs = 0;
    int nrdelete = 0;
    int nrget = 0;
    while(nrinputs < nr) {
        int k = rand()%4;
        switch (k){
            case 3:
            case 0:
                printf("I %d\n",input[nrinputs]);
                nrinputs++;
                break;
            case 1:
                printf("G\n");
                nrget++;
                break;
            case 2:
                printf("D\n");
                nrdelete++;
                break;
            default:
                break;
        }
    }
    printf("G\n");
}

int main(int argc, char* argv[])
{
    srand(time(NULL));
    if(argc != 5) {
        printf("Usage: ./generator numar_max_insert, ordine_insert(ascending/descending/random), tip_problema(sortare,random) maxnumber > testID.in\n");
        return -1;
    }
    int nr = atoi(argv[1]);
    int maxnumber = atoi(argv[4]);
    int* valori_insert = generaterandom(nr,2*maxnumber);
    int i;

    int ok = 0;
    if(strcmp(argv[2], "descending") == 0) {
        sortdescending(valori_insert,nr);
        ok = 1;
    }
    if(strcmp(argv[2], "random") == 0) {
        shuffle(valori_insert,nr);
        ok = 1;
    }
    if(strcmp(argv[2], "ascending") == 0) {
        ok = 1;
    }
    if(!ok) {
        printf("Usage: ./generator numar_max_insert ordine_insert(ascending/descending/random) tip_problema(sortare,random) maxnumber > testID.in\n");
        return -1;
    }
    ok = 0;
    if(strcmp(argv[3], "sortare") == 0) {
        testsortare(valori_insert,nr);
        ok = 1;
    }
    if(strcmp(argv[3], "random") == 0) {
        testrandom(valori_insert, nr);
        ok = 1;
    }
    if(!ok) {
        printf("Usage: ./generator numar_max_insert ordine_insert(ascending/descending/random) tip_problema(sortare,random) maxnumber > testID.in\n");
        return -1;
    }
    return 0;
}

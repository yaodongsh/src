#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a=*b;
    *b=temp;
}

//common insert_sort, replace all gap with 1
//with gap means sort the element with gap like sort a[i], a[i+gap], a[i+2*gap]
void insert_sort (int a[], int n, int gap)
{
    for (int i=gap; i<n; i++) {
        for (int j=i-gap; j>=0 && a[j]>a[j+gap]; j-=gap) {
            swap(&a[j], &a[j+gap]);
        }
    }
}

//shell sort begin with sort element with gap, and make gap be smaller (array in order in gaps) once gap =1, it is an insert sort
//insert_sort is efficient when most of element is in order
void shell_sort (int a[], int n)
{
    for(int gap=n/2; gap>0; gap/=2) {
        insert_sort(a, n, gap);
    }
}

void check(int a[], int n)
{
    for(int i=1; i<n; i++) {
        for(int j=i-1; j>=0; j--) {
             if(a[j]>a[i])
                 assert(0);
        }
    }
}

#define NUM 100

int main(void)
{
    int a[NUM];
    srand(time(NULL));
    for (int i=0; i<NUM; i++) {
        a[i] = rand() % 100;
        printf("%d ", a[i]);
    }
    printf("\n");
//    insert_sort(a, NUM, 1);
    shell_sort(a, NUM);
    for (int i=0; i<NUM; i++)
        printf("%d ", a[i]);
    printf("\n");
    check(a,NUM);
    printf("\n");
    return 0;
}


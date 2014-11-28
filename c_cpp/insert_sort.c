#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insert_sort (int a[], int n)
{
    int j;
    for (int i=1; i<n; i++) {
        for (j=0; j<i; j++) {
            if(a[i] < a[j]) 
                break;
        }
        // save a[i]
        int temp = a[i];
        //move all left data back one step
        //start from i and a[i] now is a hole
        for(int k=i; k>j; k--) {
            a[k] = a[k-1];
        }
        // put a[i] to correct position
        a[j] = temp;
    }
}

#define NUM 20 

int main(void)
{
    int a[NUM];
    srand(time(NULL));
    for (int i=0; i<NUM; i++) {
        a[i] = rand() % 100;
        printf("%d ", a[i]);
    }
    printf("\n");
//    int a[10] = {7,6,3,0,11,11,5,9,8,1};
    insert_sort(a,NUM);
    for (int i=0; i<NUM; i++)
        printf("%d ", a[i]);

    printf("\n");
    return 0;
}

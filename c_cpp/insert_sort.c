#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

//think a[0 .. i-1] in order and put a[i] to the correct position
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

void insert_sort2 (int a[], int n)
{
    for (int i=1; i<n; i++) {
        if(a[i] < a[i-1]) { // means there need a re-order
            int temp = a[i];
            int j;
         //find place j which a[j] <= temp, if a[j] > temp, move the element backward
            for (j=i-1; j>=0 && a[j]>temp; j--) {
                a[j+1]=a[j];
            }
        //find place j which a[j] <= temp
        //put a[i] to place j+1
            a[j+1]=temp;
        }
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a=*b;
    *b=temp;
}

void insert_sort3 (int a[], int n)
{
    for (int i=1; i<n; i++) {
//.        if(a[i] < a[i-1]) { // means there need a re-order, acutally no use since in below we check a[j] and a[j-1]
         //find place j which a[j] <= temp, if a[j] > temp, just swap a[i] forward 
        for (int j=i-1; j>=0 && a[j]>a[j+1]; j--) {
            swap(&a[j], &a[j+1]);
        }
//        }
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
//    insert_sort(a,NUM);
//    insert_sort2(a, NUM);
    insert_sort3(a, NUM);  
    for (int i=0; i<NUM; i++)
        printf("%d ", a[i]);
    printf("\n");
    check(a,NUM);
    printf("\n");
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

//given a b are both sorted array, merge them into c to be fully sorted
//it is a step of MergeSort

//algorithm: maintain 2 ptr for a and b, once a <= b, move a to c, then ptr of a increase, other move b to c and ptr of b increase, once one array is finished, just copy all left data of another array to c

#include <stdio.h>

void merge(int *a, int *b, int *c, int m, int n) {
   int i=0;
   int j=0;
   int k=0;
//copy smaller
   while (i<m && j<n) {
        if(a[i] < b[j]) {
            c[k] = a[i];
            i++;
        } else {
            c[k] = b[j];
            j++;
        }
        k++;
   }
//copy left
    while (j<n) {
        c[k] = b[j];
        j++;
        k++;
    }
    while (i<m) {
        c[k] = a[i];
        i++;
        k++;
    }
}

// merge for a[lo .. mid] and a[mid+1 .. hi] to temp
void merge_array(int a[], int lo, int hi, int temp[]) 
{
    int mid = (lo+hi)/2;
    int *a_lo = &a[lo];
    int *a_hi = &a[mid+1];
    merge(a_lo, a_hi, temp, mid-lo+1, hi-mid);
    //copy temp[lo .. hi] to a[lo .. hi]
    for (int i=lo; i<=hi; i++) {
        a[i] = temp[i-lo]; //temp always start from 0
//        printf("%d ", a[i]);
    }
}


void merge_sort(int a[], int lo, int hi, int temp[])
{
    if(lo < hi) { //exit condition lo=hi
        int mid = (lo+hi)/2;
        // recursive
        merge_sort(a, lo, mid, temp);
        merge_sort(a, mid+1, hi, temp);
        // 2 array is in sort, merge into one array
        merge_array(a, lo, hi, temp);
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
    int a[NUM], temp[NUM];
    srand(time(NULL));
    for (int i=0; i<NUM; i++) {
        a[i] = rand() % 100;
        printf("%d ", a[i]);
    }
    printf("\n");
    merge_sort(a, 0, NUM-1, temp);
    for (int i=0; i<NUM; i++)
        printf("%d ", a[i]);
    printf("\n");
    check(temp,NUM);
    printf("\n");
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

void quick_sort (int *s, int l, int r)
{
    int x = s[l]; // easily pick leftest value
    int i = l;
    int j = r;
    if(l < r) {
//from right to left, find data smaller than x
        while(i<j) {
			while (i<j && s[j]>=x)        
				j--;
			if(i<j) {
				s[i]=s[j]; //put bigger value to small half
				i++;
			}
//from left to right, find data bigger than x 
			while (i<j && s[i]<=x)
				i++;
			if(i<j) {
				s[j]=s[i];
				j--;
			}
        }
        s[i]=x; //put x to final position
//recursive
        quick_sort(s, l, i-1);
        quick_sort(s, i+1, r);
    }
}

void swap (int s[], int i, int j)
{
    int temp = s[i];
    s[i]=s[j];
    s[j]=temp;
}

void quick_sort1 (int s[], int l, int r)
{
    if(l < r) {
        //pick mid as base
        int mid= (l+r)/2;
        int base=s[mid];
        swap(s, l, mid); 
        int pos = l;
//make sure all elem which is < base in the left, always swap elem and s[pos], pos means how much elem are left to be < base
        for (int i=l; i<=r; i++) {
            if(s[i]<base) {
                swap(s, pos, i);
                pos++;
            }
        }
//put base into correct position
        s[pos]=base;
//recursive 
        quick_sort(s, l, pos-1);
        quick_sort(s, pos+1, r);
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
    quick_sort1(a, 0, NUM-1);
    for (int i=0; i<NUM; i++)
        printf("%d ", a[i]);
    printf("\n");
    check(a,NUM);
    printf("\n");
    return 0;
}

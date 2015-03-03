#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

void swap (int s[], int i, int j)
{
    int temp = s[i];
    s[i]=s[j];
    s[j]=temp;
}
/*
int partition (int s[], int l, int r)
{
    //choose s[l] as pivot
    int i=l;
    int j=l+1;
    while (j <= r) {
        if((s[j]>=s[l]) || (i==j)) 
            j++;
        else {
            swap(s, j, i+1);
            i++; 
        }
    }
    swap(s,l,i);
    return i;
}
*/
int partition (int s[], int l, int r)
{
   //choose s[l] as pivot
   int i=l;
   for (int j=l+1; j<=r; j++) {
       if(s[j] < s[l]) {
           swap(s, j, i+1);
           i++;
       }
   }
   swap(s,l,i);
   return i;
}

void check_partition(int s[], int pos, int size)
{
    if(pos >= size) assert(0);
    for (int i=0; i<pos; i++) {
        if(s[i] >= s[pos]) assert(0); 
    } 
    for (int i=pos+1; i<size; i++) {
        if(s[i] < s[pos]) assert(0); 
    } 

}

void quick_sort(int s[], int l, int r)
{
    if(l < r) {
        int pos = partition(s, l, r);
//        printf("%d %d %d\n", l, r, pos);
        if(pos < l || pos > r) assert(0);
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


#define NUM 10000 

int main(void)
{
    int a[NUM];
    srand(time(NULL));
    for (int i=0; i<NUM; i++) {
        a[i] = rand() % NUM;
//        printf("%d, ", a[i]);
    }
    printf("\n");
//   int pos = partition(a, 0, NUM-1);
//    printf("%d\n", pos);
    quick_sort(a,0, NUM-1);
    //check_partition(a, pos, NUM);
    check(a, NUM);
//    for (int i=0; i<NUM; i++)
//        printf("%d, ", a[i]);
    printf("\n");

}

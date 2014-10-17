
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

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int array[14] = {28, 67, 2, 3, 11, 49, 25, 77, 0, 21, 14, 67, 35, 5};
    quick_sort(array, 0, 13);
    int i;
    for (i=0; i<14; i++)
        printf("%d ", array[i]);
    printf("\n");
}

#!/usr/bin/python
# -*- coding: UTF-8 -*-
import random

def merge(arr, i, j):
    left=i
    right=j
    mid=(i+j)//2
    lo_half=arr[left:mid+1]  #means [left:mid]
    hi_half =arr[mid+1:right+1] #means [mid+1: right]
    assert(sort_check(lo_half))
    assert(sort_check(hi_half))
    ptr_lo=ptr_hi=0
    ptr_arr=left
    while((ptr_lo != len(lo_half)) and (ptr_hi != len(hi_half))):
        if(lo_half[ptr_lo] < hi_half[ptr_hi]): #start from 0
            arr[ptr_arr]=lo_half[ptr_lo]
            ptr_lo+=1
        else:
            arr[ptr_arr]=hi_half[ptr_hi]
            ptr_hi+=1
        ptr_arr+=1

    if(ptr_lo == len(lo_half)): # low half reach end
         while(ptr_hi != len(hi_half)):
            arr[ptr_arr]=(hi_half[ptr_hi])
            ptr_hi+=1
            ptr_arr+=1
    if(ptr_hi == len(hi_half)): # high half reach end
        while(ptr_lo != len(lo_half)):
            arr[ptr_arr]=lo_half[ptr_lo]
            ptr_lo+=1
            ptr_arr+=1

    #print(arr[i:j+1])

def sort_check(a):
    return (sorted(a)==a)

def merge_sort(arr,i,j):
    if(i<j):
        mid=(i+j)//2
        merge_sort(arr, i, mid)
        merge_sort(arr, mid+1, j)
        merge(arr, i, j)
    return

def test_merge():
    l0 = []
    l1 = []
    l2 = []
    for x in range(64):
        l0.append(random.randint(1, 1000))
        l1.append(random.randint(1, 1000))
    l0_0=sorted(l0)
    l1_0=sorted(l1)
    l2=l0_0+l1_0
    merge(l2, 0, len(l2)-1)
    print(sort_check(l2))

def test_merge_sort():
    l2=[]
    for x in range(64):
       l2.append(random.randint(1,1000))
    merge_sort(l2, 0, len(l2)-1)
    print(sort_check(l2))

def main():
    #test_merge()
    test_merge_sort()


if __name__ == '__main__':
    main()
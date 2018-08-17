import random

SIZE = 100

def max_heapify (li, index, size):
    left= 2*index+1
    right=2*index+2

    # pick out bigger of index and left
    if(left <= size and li[index] <= li[left]):
        largest=left
    else:
        largest=index

    # pick out bigger of largest and right
    if(right <= size and li[largest] <= li[right]):
        largest=right

    if (largest != index):
        li[largest], li[index] = li[index], li[largest]
        max_heapify(li, largest, size)

def build_heap(li):
    size = len(li)
    for i in range(0, size//2):
        k=size//2-1-i
        max_heapify(li, k, size-1)

def heap_sort(li):
    size=len(li)
    build_heap(li)
    for i in range(0, size-1):
        k=size-1-i
        li[0], li[k]=li[k],li[0] # swap (0, size-1)
        k-=1 # size = size-1
        max_heapify(li, 0, k)

############ test ########################
def check_heap(li):
    for i in range(len(li)//2-1):
        left=2*i+1
        right=2*i+2
        if(li[i] < li[left] or li[i] < li[right]):
            print("FAILED @ index:")
            print(i)
            assert(False)

def test_build_heap():
    li = [random.randint(1, 500) for i in range(SIZE)]
    print(li)
    build_heap(li)
    print(li)
    check_heap(li)

def test_heapsort():
    li = [random.randint(1, 500) for i in range(SIZE)]
    print(li)
    heap_sort(li)
    assert(sorted(li))
    print(li)

if __name__ == '__main__':
    test_heapsort()
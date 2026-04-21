#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int a[50], n;

void heapify(int a[], int n, int i)
{
    int largest, left, right, temp;
    largest = i;
    left  = 2*i + 1;
    right = 2*i + 2;
    if(left  < n && a[left]  > a[largest]) largest = left;
    if(right < n && a[right] > a[largest]) largest = right;
    if(largest != i) {
        temp = a[i]; a[i] = a[largest]; a[largest] = temp;
        heapify(a, n, largest);
    }
}

void buildHeap(int a[], int n)
{
    int i;
    for(i = n/2 - 1; i >= 0; i--)
        heapify(a, n, i);
}

void heapSort(int a[], int n)
{
    int i, temp;
    buildHeap(a, n);
    for(i = n-1; i > 0; i--) {
        temp = a[0]; a[0] = a[i]; a[i] = temp;
        heapify(a, i, 0);
    }
}

int main()
{
    int i;
    printf("Enter number of elements: "); scanf("%d", &n);
    srand(time(0));
    printf("\nRandomly generated elements:\n");
    for(i = 0; i < n; i++) { a[i] = rand() % 100; printf("%d ", a[i]); }
    printf("\n");
    heapSort(a, n);
    printf("\nSorted elements (Heap Sort):\n");
    for(i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}

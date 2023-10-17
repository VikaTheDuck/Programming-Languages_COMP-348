#include <stdio.h>
#include <stdlib.h>
#include "selectionsort.h"
#include "selectionsort.h" // included twice

int *findmin(int *, int);

int arr[] = {1, 4, 5, 6, -1 };

int main() {
int(*ptr)(int [], int) = &findmin;
int i;
selectionsort(arr, 5, ptr);
for(i = 0; i < 5; i++) printf("%d ", arr[i]);
return 0;
}

int *findmin(int *arr, int size) {
    int *min = arr;
    for (int i = 0; i < size; ++i) {
        if (*arr < *min)
            min = arr;
        arr++;
    }
    return min;
}

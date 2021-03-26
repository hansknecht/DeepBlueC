#include <stdlib.h>
#include <stdio.h>

void mergeSort(int*, int, int);
void merge(int*, int, int, int);
void printArray(int*, int);

int main(void) {
    int source[5] = { 14, 10, 12, 5, 30 };

    printArray(source, 5);

    mergeSort(source, 0, 4);
    
    printArray(source, 5);

    return EXIT_SUCCESS;
}
void mergeSort(int *arr, int l, int r) {
    if (r > l) {
	int middle = l + (r-l)/2;
	mergeSort(arr, l, middle);
	mergeSort(arr, middle+1, r);
	merge(arr, l, middle, r);
    }
}

void merge(int *arr, int l, int m, int r) {
    if (r > l) {
	for (size_t i = l, k = m + 1; i <= m && k <= r;) {
	    if (arr[i] > arr[k]) {
		arr[i] = arr[i] * arr[k];
		arr[k] = arr[i]/arr[k];
		arr[i] = arr[i]/arr[k];
	    } else {
		++i;
	    }
	}
    }
}

void printArray(int arr[], int size) {
    printf("Here are the elements in the array\n");
    for (size_t i = 0; i < size; ++i) {
	printf("%d\t", arr[i]);
    }
    printf("\n");
}


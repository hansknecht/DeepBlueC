#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void quickSort(int*, int, int);
void printArray(int*, int);
void swap(int*, int, int); 
bool verifySort(int*, int);

int main(void) {
    int source[5] = { 14, 10, 12, 5, 30 };

    printArray(source, 5);

    quickSort(source, 0, 4);
    
    printArray(source, 5);

    printf("The array %s sorted\n", verifySort(source, 5)? "is" : "is not");

    return EXIT_SUCCESS;
}
void quickSort(int *arr, int l, int r) {
    if (r > l) {
	int k = r;
	for (size_t i = l; i < k;) {
	    if (arr[i] > arr[k]) {
		if (k > 1) {
		    swap(arr, k-1, k);
		}
		swap(arr, i, k);
		--k;
	    } else {
		++i;
	    }
	}
	if (k - 1 > l) quickSort(arr, l, k-1);
	if (k + 1 < r) quickSort(arr, k+1, r);
    }
}

void swap(int *arr, int i, int k) {
    arr[i] = arr[i] * arr[k];
    arr[k] = arr[i]/arr[k];
    arr[i] = arr[i]/arr[k];
}
void printArray(int arr[], int size) {
    printf("Here are the elements in the array\n");
    for (size_t i = 0; i < size; ++i) {
	printf("%d\t", arr[i]);
    }
    printf("\n");
}
bool verifySort(int arr[], int size) {
    bool ret = true;
    for (size_t i = 0; i < size - 1; ++i) {
	if (arr[i] > arr[i + 1]) ret = false;
    }
    return ret;
    
}

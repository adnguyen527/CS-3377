#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

static int medianFunction(int* array, int size) {
	// insertion sort
	for (int i =0; i < size; i++) {
		int currentItem = *(array + i);
		int k;
		for (k = i-1; k >= 0 && *(array + k) > currentItem; k--) {
			*(array + k+1) = *(array + k);
		}
		*(array + k+1) = currentItem;
	}
	// check if size is even
	if (size%2 == 0) {
		int value1 = *(array + (size/2 - 1));
		int value2 = *(array + (size/2));
		return (value1 + value2)/2;
	}else{
		return *(array + (size/2));
	}
}


int main() {
	int size;
	int* array;
	int median;
	
	printf("Enter the size of the data set: ");
	scanf("%d", &size);
	array = (int*)malloc(size*sizeof(int));
	
	for (int i = 0; i < size; i++) 
		scanf("%d", &array[i]);
	
	median = medianFunction(array, size);
	printf("The median is %d\n", median);
	
	free (array);
	return 0;
}
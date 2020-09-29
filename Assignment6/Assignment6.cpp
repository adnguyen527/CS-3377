#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

// find mode of data set
static int modeFunction(int* array, int size) {
	int mode = -1, position = 0;
	int frequency[100];
	for (int i = 0; i < size; i++) // initialize frequencies to zero
		*(frequency + i) = 0;
	for (int k = 0; k < size; k++) {
		for (int i = 1; i < size; i++) { // to avoid counting itself
			if (*(array + k) == *(array + i) && &*(array + k) != &*(array + i))
				*(frequency + k) +=1; // increment if found  the same number
		}
	}
	
	int highest = *(frequency + 0);
	for (int i = 1; i < size; i++) // gets position of highest number
		if (*(frequency + i) > highest) {
			highest = *(frequency + i); 
			position = i;
		}
	for(int i = 0; i < size; i++)
        if(*(frequency + i) != *(frequency + (i + 1)) && (i + 1) < size) {
            mode = *(array + position);
            return mode;    //returns number that occurs most 
        }
	
	return mode;
	
}
// find median of data set
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
// find average of data set
static int averageFunction(int* array, int size) {
	int sum = 0; // calculate sum
	for (int i = 0; i < size; i++) { 
		sum += *(array + i);
	}
	return sum/size;
}


int main() {
	int size;
	int* array;
	int mode;
	int median;
	int average;
	
	printf("We are here to gather information about the number of movies\ncollege students see every month.\nHow many students were surveyed: ");
	scanf("%d", &size);
	array = (int*)malloc(size*sizeof(int));
	
	// build array
	for (int i = 0; i < size; i++) 
		scanf("%d", &array[i]);
	
	// calculation functions and print
	mode = modeFunction(array, size);
	printf("The mode is %d\n", mode);
	median = medianFunction(array, size);
	printf("The median is %d\n", median);
	average = averageFunction(array, size);
	printf("The average is %d\n", average);
	
	free (array);
	return 0;
}
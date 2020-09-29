#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

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


int main() {
	int size;
	int* array;
	int mode;
	
	printf("Enter the size of the data set: ");
	scanf("%d", &size);
	array = (int*)malloc(size*sizeof(int));
	
	for (int i = 0; i < size; i++) 
		scanf("%d", &array[i]);
	
	mode = modeFunction(array, size);
	printf("The mode is %d\n", mode);
	
	free (array);
	return 0;
}
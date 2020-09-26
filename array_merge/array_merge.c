#include "array_merge.h"
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include "mergesort.h"

int removeDuplicates(int* array, int size) { //Needs work
  if (size <= 1)
    return size;

  int i, j;
  j = 0;
  int* tmp;
  tmp = (int*) calloc(size, sizeof(int));

  for (i=0; i<size-1; i++) {
    if (array[i] != array[i+1]) {
      tmp[j] = array[i];
      j++;
    }
  }
  tmp[j] = array[size-1];
  j++;

  for (i=0; i<j; i++)
    array[i] = tmp[i];

  return j;
}

void printArray(int A[], int size) {
  int i;
  for (i=0; i<size; i++)
    printf("%d ", A[i]);
  printf("\n");
}

int* array_merge(int num_arrays, int* sizes, int** values) {
  int i;
  //int j;
  int arraySize = 0;
  int *longArray;

  //Create a variable that is the size of all the arrays combined
  for (i=0; i<num_arrays; i++) {
    arraySize = arraySize+sizes[i];
  }

  //Check if the array is empty
  if (arraySize <= 0) {
    int *empty;
    empty =(int*) calloc(1, sizeof(int));
    empty[0] = 0;
    return empty;
  }

  //Create an array that will contain the entries of all arrays combined
  longArray =(int*) calloc(arraySize, sizeof(int));

  memcpy(longArray, values[0], sizes[0]*sizeof(int));
  int appendLocation = sizes[0];
  for (i=1; i<num_arrays; i++) {
    memcpy(longArray+appendLocation+1, values[i], sizes[i]*sizeof(int));
    appendLocation = appendLocation + sizes[i-1];
  }

  //Sort longArray
  mergesort(arraySize, longArray);

  //Eliminate Duplicates
  printf("\nBefore\n");
  printArray(longArray, arraySize);

  int newArraySize;
  newArraySize = removeDuplicates(longArray, arraySize);
  printf("After\n");
  printArray(longArray, arraySize);
  printf("newArraySize=%d\n", newArraySize);

  //Count the number of entries

  //Create a new array starting with the size of the array

  return sizes;
}

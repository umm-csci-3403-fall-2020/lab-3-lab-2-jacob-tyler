#include "array_merge.h"
#include <stdio.h>
#include <stdlib.h>
#include "mergesort.h"

/*
void printArray(int A[], int size) {
  int i;
  for (i=0; i<size; i++)
    printf("%d ", A[i]);
  printf("\n");
}*/

int* array_merge(int num_arrays, int* sizes, int** values) {
  int i;
  //int j;
  int arraySize = 0;
  //int *tmpArray;
  //int *longArray;
  //int *result;

  //Sort the arrays
  for (i=0; i<num_arrays; i++) {
    mergesort(sizes[i], values[i]);
  }

  //Create a variable that is the size of all the arrays combined
  for (i=0; i<num_arrays; i++)
    arraySize = arraySize+sizes[i];

  //Check if the array is empty
  if (arraySize <= 0) {
    int *empty;
    empty =(int*) calloc(1, sizeof(int));
    empty[0] = 0;
    return empty;
  }
  /*
  //Create an array that will contain the entries of all arrays combined
  longArray = calloc(arraySize, sizeof(int));

  i=0;
  j=0;
  while (i<num_arrays) {
    tmpArray = calloc(sizes[i], sizeof(int));
    for (j=0; j<sizes[i]; j++) {
      longArray[j]
    }
  }*/
  return sizes;
}

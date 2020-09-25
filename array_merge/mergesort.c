#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "mergesort.h"

void mergeranges(int* values, int startindex, int midpoint, int endindex){
  int rangesize = endindex - startindex;
  int copyindex = 0;
  int firstindex = startindex;
  int secondindex = midpoint;
  int* destination;
  destination =(int*) calloc(rangesize, sizeof(int*));
  while(firstindex < midpoint && secondindex< endindex){
    if(values[firstindex] < values[secondindex]){
	destination[copyindex] = values[firstindex];
	++firstindex;
      } else{
	destination[copyindex] = values[secondindex];
	++secondindex;
      }
    ++copyindex;
  }

  while(firstindex < midpoint){
    destination[copyindex] = values[firstindex];
    ++copyindex;
    ++firstindex;
  }

  while(secondindex < endindex){
    destination[copyindex] = values[secondindex];
    ++copyindex;
    ++secondindex;
  }

  int i;
  for(i = 0; i < rangesize; ++i){
    values[i+startindex] = destination[i];
  }

  free(destination);
}

bool needssorting(int rangesize) {
  return rangesize >= 2;
}

void mergesortrange(int* values, int startindex, int endindex){
  int rangesize;
  int midpoint;
  rangesize = endindex - startindex;
  if(needssorting(rangesize)){
      midpoint = (startindex + endindex) /2;
      mergesortrange(values, startindex, midpoint);
      mergesortrange(values, midpoint, endindex);
      mergeranges(values, startindex, midpoint, endindex);
    }
}

void mergesort(int length, int* values) {
  return mergesortrange(values, 0, length);
}



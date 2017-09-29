//#include "SortingClass.hpp"
#include <stdlib.h>
#include <iostream>

using namespace std;

class CardManager {
    public:
        int *arrayToShort;
        int arrayLength;
        bool isMergeSort;
        
        CardManager(int[], int, bool);
        ~CardManager();
        void fullShort();
        void filterShort();
};

// Initialization for the class
CardManager::CardManager(int array[], int arrayL, bool mergeSort){
    arrayLength = arrayL;
    arrayToShort = new int[arrayLength];
    for(int i=0;i<arrayLength;i++){
        arrayToShort[i] = array[i];
    }
    isMergeSort = mergeSort;
}

// Deinitialization for the class
CardManager::~CardManager() {
    delete[] arrayToShort;
}

void intertionSort(int array[], int arrayLength){
    int keyPosition, counter;
    // iterating through all array
    for(int i=0;i<arrayLength;i++){
        counter = i - 1;
        keyPosition = i;
        // Going backwards from counter(i)
        while (counter >= 0) {
            // Swaping two with condition
            if(array[counter] > array[keyPosition]) {
                int temp = array[counter];
                array[counter] = array[keyPosition];
                array[keyPosition] = temp;
                keyPosition--;
            }
            counter--;
        }
    }
}

void mergeSort(int array[], int arrayLenght) {
    // Merge array
}

void CardManager::fullShort() {
    if (isMergeSort) {
        // run merge sort
    }else{
        // run intertionsort for arrayto short
        intertionSort(arrayToShort, arrayLength);
    }
}
void CardManager::filterShort() {
    if (isMergeSort) {
        // run merge sort
    }else{
        // run intertionsort for arrayto short
    }
}



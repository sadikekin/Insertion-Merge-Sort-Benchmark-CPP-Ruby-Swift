#include "SortingAlgorithm.hpp"
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void insertionSort(inputTextStruct * structInput, int structInputLength, bool isFullShort){
    if(isFullShort){
        int keyPosition, counter;
        // iterating through all structInput
        for(int i=1;i<structInputLength;i++){
            counter = i - 1;
            keyPosition = i;
            // Going backwards from counter(i)
            while (counter >= 0) {
                // doing this for finding different char!
                int c = 0;
                string compareOne = structInput[counter].className;
                string compareTwo = structInput[keyPosition].className;
                
                // Swaping two with condition
                if(compareOne > compareTwo) {
                    // storing the struct element
                    inputTextStruct tempStuct = structInput[counter];
                    
                    // changing first struct with another one
                    structInput[counter] = structInput[keyPosition];
                    
                    // changing second set with temps
                    structInput[keyPosition] = tempStuct;
                    keyPosition--;
                    // if classes of the elements are same we gonna check cost
                }else if(structInput[counter].className == structInput[keyPosition].className){
                    // This is for cost
                    int compareOne = atoi(structInput[counter].cost.c_str());
                    int compareTwo = atoi(structInput[keyPosition].cost.c_str());
                
                    

                    // Swaping two with condition
                    if(compareOne > compareTwo) {
                        // storing the struct elements
                        inputTextStruct tempStuct = structInput[counter];
                        
                        // changing first struct with another one
                        structInput[counter] = structInput[keyPosition];
                        
                        // changing second set with temps
                        structInput[keyPosition] = tempStuct;
                        keyPosition--;
                        
                    }else if(compareOne == compareTwo){
                        // this is for name
                        int c = 0;
                        string compareOne = structInput[counter].name;
                        string compareTwo = structInput[keyPosition].name;
                        
                        // Swaping two with condition
                        if(compareOne > compareTwo) {
                            inputTextStruct tempStuct = structInput[counter];
                            
                            // changing first struct with another one
                            structInput[counter] = structInput[keyPosition];
                            
                            // changing second set with temps
                            structInput[keyPosition] = tempStuct;
                            keyPosition--;
                        }else{
                            break;
                        }
                    }else{
                        break;
                    }
                }else{
                    break;
                }
                counter--;
            }
        }
    }else{
        int keyPosition, counter;
        // iterating through all array
        for(int i=0;i<structInputLength;i++){
            counter = i - 1;
            keyPosition = i;
            // Going backwards from counter(i)
            while (counter >= 0) {
                // Swaping two with condition
                if(structInput[counter].type > structInput[keyPosition].type) {
                    // storing the struct elements
                    inputTextStruct tempStuct = structInput[counter];
                    
                    // changing first struct with another one
                    structInput[counter] = structInput[keyPosition];
                    
                    // changing second set with temps
                    structInput[keyPosition] = tempStuct;
                    keyPosition--;
                }else{
                    break;
                }
                counter--;
            }
        }
    }
}

void combineElementsWithFilter(inputTextStruct * structInput, int lowestValue, int highestValue, int middleValue){
    int i, j, k;
    inputTextStruct *temp = new inputTextStruct[highestValue-lowestValue+1];
    i = lowestValue;
    k = 0;
    j = middleValue + 1;
    
    // Making a binary tree
    while (i <= middleValue && j <= highestValue) {
        if (structInput[i].type > structInput[j].type) {
            temp[k] = structInput[j];
            k++;
            j++;
        }else {
            temp[k] = structInput[i];
            k++;
            i++;
        }
    }
    
    // Putting extra values if there are some
    while (i <= middleValue) {
        temp[k] = structInput[i];
        k++;
        i++;
    }
    while (j <= highestValue) {
        temp[k] = structInput[j];
        k++;
        j++;
    }
    
    // Merging the struct array.
    for (i = lowestValue; i <= highestValue; i++) {
        structInput[i] = temp[i-lowestValue];
    }
    delete [] temp;
}

void combineElementsWithFull(inputTextStruct * structInput, int lowestValue, int highestValue, int middleValue){
    int a, b, k;
    inputTextStruct *temp = new inputTextStruct[highestValue-lowestValue+1];
    a = lowestValue;
    k = 0;
    b = middleValue + 1;
    
    // Making a binary tree
    while (a <= middleValue && b <= highestValue) {
        
        int c = 0;
        string compareOne = structInput[a].className;
        string compareTwo = structInput[b].className;
        
        
        if (compareOne > compareTwo) {
            temp[k] = structInput[b];
            k++;
            b++;
        }else if(compareOne == compareTwo) {

            int compareOne = atoi(structInput[a].cost.c_str());
            int compareTwo = atoi(structInput[b].cost.c_str());

            if (compareOne > compareTwo){
                temp[k] = structInput[b];
                k++;
                b++;
            }else if( compareOne == compareTwo){
                if (structInput[a].name > structInput[b].name){
                    temp[k] = structInput[b];
                    k++;
                    b++;
                }else{
                    temp[k] = structInput[a];
                    k++;
                    a++;
                }
            }else{
                temp[k] = structInput[a];
                k++;
                a++;
            }
        }else{
            temp[k] = structInput[a];
            k++;
            a++;
        }
    }
    
    // Putting extra values if there are some
    while (a <= middleValue) {
        temp[k] = structInput[a];
        k++;
        a++;
    }
    while (b <= highestValue) {
        temp[k] = structInput[b];
        k++;
        b++;
    }
    
    // Merging the struct array.
    for (int i = lowestValue; i <= highestValue; i++) {
        structInput[i] = temp[i-lowestValue];
    }
    delete [] temp;
}


void mergeSortFilter(inputTextStruct * structInput,int lowestValue, int highestValue)
{
    if (lowestValue < highestValue )
    {
        int middleValue=(lowestValue+highestValue)/2;
        // Making binary tree for values
        mergeSortFilter(structInput, lowestValue, middleValue);
        mergeSortFilter(structInput, middleValue+1, highestValue);
        
        // Combining them with a order
        combineElementsWithFilter(structInput, lowestValue, highestValue, middleValue);
    }
}
void mergeSortFull(inputTextStruct * structInput,int lowestValue, int highestValue)
{
    if (lowestValue < highestValue )
    {
        int middleValue=(lowestValue+highestValue)/2;
        // Making binary tree for values
        mergeSortFull(structInput, lowestValue, middleValue);
        mergeSortFull(structInput, middleValue+1, highestValue);
        
        // Combining them with a order
        combineElementsWithFull(structInput, lowestValue, highestValue, middleValue);

    }
}

// Initialization for the class
CardManager::CardManager(bool mergeSort){
    isMergeSort = mergeSort;
}

// Deinitialization for the class
CardManager::~CardManager() {
}

void CardManager::fullShort(inputTextStruct *structToShort, int structLength) {
    if (isMergeSort) {
        // run merge sort
        mergeSortFull(structToShort,0,structLength);
    }else{
        // run insertionsort for arrayto short
        insertionSort(structToShort, structLength, true);
    }
}
void CardManager::filterShort(inputTextStruct *structToShort, int structLength) {
    if (isMergeSort) {
        // run merge sort
        mergeSortFilter(structToShort,0,structLength);
    }else{
        // run insertionsort for arrayto short
        insertionSort(structToShort, structLength, false);
    }
}



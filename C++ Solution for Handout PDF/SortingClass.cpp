//#include "SortingClass.hpp"
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

//Data structure for storing the data from the text
struct inputTextStruct
{
    string name;
    string className;
    string rarity;
    string set;
    string type;
    string cost;
};
// function for swaping elements
void swapElements(inputTextStruct * structInput, int counter, int keyPosition){
    string tempName = structInput[counter].name,tempClassName = structInput[counter].className,tempRarity = structInput[counter].rarity,tempSet = structInput[counter].set,tempType = structInput[counter].type, tempCost = structInput[counter].cost;

    // changing first struct with another one
    structInput[counter].name = structInput[keyPosition].name;
    structInput[counter].className = structInput[keyPosition].className;
    structInput[counter].cost = structInput[keyPosition].cost;
    structInput[counter].rarity = structInput[keyPosition].rarity;
    structInput[counter].set = structInput[keyPosition].set;
    structInput[counter].type = structInput[keyPosition].type;

    // changing second set with temps
    structInput[keyPosition].name = tempName;
    structInput[keyPosition].className = tempClassName;
    structInput[keyPosition].rarity = tempRarity;
    structInput[keyPosition].set = tempSet;
    structInput[keyPosition].type = tempType;
    structInput[keyPosition].cost = tempCost;
}

void intertionSort(inputTextStruct * structInput, int structInputLength, bool isFullShort){
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
                char compareOne = structInput[counter].className[c];
                char compareTwo = structInput[keyPosition].className[c];

                while(compareOne == compareTwo){
                    c++;
                    if ((c == structInput[counter].className.length()) && (c == structInput[keyPosition].className.length())){
                        break;
                    }
                    compareOne = structInput[counter].className[c];
                    compareTwo = structInput[keyPosition].className[c];
                }

                // Swaping two with condition
                if(compareOne > compareTwo) {
                    // storing the struct element
                    swapElements(structInput,counter,keyPosition);
                    keyPosition--;
                    // if classes of the elements are same we gonna check cost
                }else if(structInput[counter].className == structInput[keyPosition].className){
                    // This is for cost
                    int compareOne = stoi(structInput[counter].cost);
                    int compareTwo = stoi(structInput[keyPosition].cost);

                    // Swaping two with condition
                    if(compareOne > compareTwo) {
                        // storing the struct elements
                        swapElements(structInput,counter,keyPosition);
                        keyPosition--;

                    }else if(compareOne == compareTwo){
                        // this is for name
                        int c = 0;
                        char compareOne = structInput[counter].name[c];
                        char compareTwo = structInput[keyPosition].name[c];

                        while(compareOne == compareTwo){
                            c++;
                            if ((c == structInput[counter].name.length()) && (c == structInput[keyPosition].name.length())){
                                break;
                            }
                            compareOne = structInput[counter].name[c];
                            compareTwo = structInput[keyPosition].name[c];
                        }

                        // Swaping two with condition
                        if(compareOne > compareTwo) {
                            swapElements(structInput,counter,keyPosition);
                            keyPosition--;
                        }
                    }
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
                    string tempName = structInput[counter].name,tempClassName = structInput[counter].className,tempRarity = structInput[counter].rarity,tempSet = structInput[counter].set,tempType = structInput[counter].type, tempCost = structInput[counter].cost;

                    // changing first struct with another one
                    structInput[counter].name = structInput[keyPosition].name;
                    structInput[counter].className = structInput[keyPosition].className;
                    structInput[counter].cost = structInput[keyPosition].cost;
                    structInput[counter].rarity = structInput[keyPosition].rarity;
                    structInput[counter].set = structInput[keyPosition].set;
                    structInput[counter].type = structInput[keyPosition].type;

                    // changing second set with temps
                    structInput[keyPosition].name = tempName;
                    structInput[keyPosition].className = tempClassName;
                    structInput[keyPosition].rarity = tempRarity;
                    structInput[keyPosition].set = tempSet;
                    structInput[keyPosition].type = tempType;
                    structInput[keyPosition].cost = tempCost;

                    keyPosition--;
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
            temp[k].type = structInput[j].type;
            temp[k].className = structInput[j].className;
            temp[k].cost = structInput[j].cost;
            temp[k].name = structInput[j].name;
            temp[k].rarity = structInput[j].rarity;
            temp[k].set = structInput[j].set;
            k++;
            j++;
        }else {
            temp[k].type = structInput[i].type;
            temp[k].className = structInput[i].className;
            temp[k].cost = structInput[i].cost;
            temp[k].name = structInput[i].name;
            temp[k].rarity = structInput[i].rarity;
            temp[k].set = structInput[i].set;
            k++;
            i++;
        }
    }

    // Putting extra values if there are some
    while (i <= middleValue) {
        temp[k].type = structInput[i].type;
        temp[k].className = structInput[i].className;
        temp[k].cost = structInput[i].cost;
        temp[k].name = structInput[i].name;
        temp[k].rarity = structInput[i].rarity;
        temp[k].set = structInput[i].set;
        k++;
        i++;
    }
    while (j <= highestValue) {
        temp[k].type = structInput[j].type;
        temp[k].className = structInput[j].className;
        temp[k].cost = structInput[j].cost;
        temp[k].name = structInput[j].name;
        temp[k].rarity = structInput[j].rarity;
        temp[k].set = structInput[j].set;
        k++;
        j++;
    }

    // Merging the struct array.
    for (i = lowestValue; i <= highestValue; i++) {
        structInput[i].type = temp[i-lowestValue].type;
        structInput[i].className = temp[i-lowestValue].className;
        structInput[i].cost = temp[i-lowestValue].cost;
        structInput[i].name = temp[i-lowestValue].name;
        structInput[i].rarity = temp[i-lowestValue].rarity;
        structInput[i].set = temp[i-lowestValue].set;
    }
    delete [] temp;
}

void combineElementsWithFull(inputTextStruct * structInput, int lowestValue, int highestValue, int middleValue){
    int i, j, k;
    inputTextStruct *temp = new inputTextStruct[highestValue-lowestValue+1];
    i = lowestValue;
    k = 0;
    j = middleValue + 1;

    // Making a binary tree
    while (i <= middleValue && j <= highestValue) {

        int c = 0;
        char compareOne = structInput[i].className[c];
        char compareTwo = structInput[j].className[c];

        while(compareOne == compareTwo){
            c++;
            compareOne = structInput[i].className[c];
            compareTwo = structInput[j].className[c];
            if ((c == structInput[i].className.length()) && (c == structInput[j].className.length())){
                break;
            }
        }

        if (compareOne > compareTwo) {

            temp[k].type = structInput[j].type;
            temp[k].className = structInput[j].className;
            temp[k].cost = structInput[j].cost;
            temp[k].name = structInput[j].name;
            temp[k].rarity = structInput[j].rarity;
            temp[k].set = structInput[j].set;
            k++;
            j++;
        }else if(compareOne == compareTwo) {

            int compareOne = stoi(structInput[i].cost);
            int compareTwo = stoi(structInput[j].cost);
            if (compareOne > compareTwo){
                temp[k].type = structInput[j].type;
                temp[k].className = structInput[j].className;
                temp[k].cost = structInput[j].cost;
                temp[k].name = structInput[j].name;
                temp[k].rarity = structInput[j].rarity;
                temp[k].set = structInput[j].set;
                k++;
                j++;
            }else if( compareOne == compareTwo){
              
                if (structInput[i].name > structInput[j].name){
                    temp[k].type = structInput[j].type;
                    temp[k].className = structInput[j].className;
                    temp[k].cost = structInput[j].cost;
                    temp[k].name = structInput[j].name;
                    temp[k].rarity = structInput[j].rarity;
                    temp[k].set = structInput[j].set;
                    k++;
                    j++;
                }else{
                    temp[k].type = structInput[i].type;
                    temp[k].className = structInput[i].className;
                    temp[k].cost = structInput[i].cost;
                    temp[k].name = structInput[i].name;
                    temp[k].rarity = structInput[i].rarity;
                    temp[k].set = structInput[i].set;
                    k++;
                    i++;
                }
            }else{
                temp[k].type = structInput[i].type;
                temp[k].className = structInput[i].className;
                temp[k].cost = structInput[i].cost;
                temp[k].name = structInput[i].name;
                temp[k].rarity = structInput[i].rarity;
                temp[k].set = structInput[i].set;
                k++;
                i++;
            }
        }else{
            temp[k].type = structInput[i].type;
            temp[k].className = structInput[i].className;
            temp[k].cost = structInput[i].cost;
            temp[k].name = structInput[i].name;
            temp[k].rarity = structInput[i].rarity;
            temp[k].set = structInput[i].set;
            k++;
            i++;
        }
    }

    // Putting extra values if there are some
    while (i <= middleValue) {
        temp[k].type = structInput[i].type;
        temp[k].className = structInput[i].className;
        temp[k].cost = structInput[i].cost;
        temp[k].name = structInput[i].name;
        temp[k].rarity = structInput[i].rarity;
        temp[k].set = structInput[i].set;
        k++;
        i++;
    }
    while (j <= highestValue) {
        temp[k].type = structInput[j].type;
        temp[k].className = structInput[j].className;
        temp[k].cost = structInput[j].cost;
        temp[k].name = structInput[j].name;
        temp[k].rarity = structInput[j].rarity;
        temp[k].set = structInput[j].set;
        k++;
        j++;
    }

    // Merging the struct array.
    for (i = lowestValue; i <= highestValue; i++) {
        structInput[i].type = temp[i-lowestValue].type;
        structInput[i].className = temp[i-lowestValue].className;
        structInput[i].cost = temp[i-lowestValue].cost;
        structInput[i].name = temp[i-lowestValue].name;
        structInput[i].rarity = temp[i-lowestValue].rarity;
        structInput[i].set = temp[i-lowestValue].set;
    }
    delete [] temp;
}


void mergeSort(inputTextStruct * structInput,int lowestValue, int highestValue, bool isFullShort)
{
    if (lowestValue < highestValue )
    {
        int middleValue=(lowestValue+highestValue)/2;
        // Making binary tree for values
        mergeSort(structInput, lowestValue, middleValue,isFullShort);
        mergeSort(structInput, middleValue+1, highestValue,isFullShort);

        // Combining them with a order
        if (isFullShort){
            combineElementsWithFull(structInput, lowestValue, highestValue, middleValue);
        }else{
            combineElementsWithFilter(structInput, lowestValue, highestValue, middleValue);
        }
    }
}


class CardManager {
public:
    bool isMergeSort;

    CardManager( bool);
    ~CardManager();
    void fullShort(inputTextStruct *, int);
    void filterShort(inputTextStruct*, int);
};

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
        mergeSort(structToShort,0,structLength,true);
    }else{
        // run intertionsort for arrayto short
        intertionSort(structToShort, structLength, true);
    }
}
void CardManager::filterShort(inputTextStruct *structToShort, int structLength) {
    if (isMergeSort) {
        // run merge sort
        mergeSort(structToShort,0,structLength,false);
    }else{
        // run intertionsort for arrayto short
        intertionSort(structToShort, structLength, false);
    }
}

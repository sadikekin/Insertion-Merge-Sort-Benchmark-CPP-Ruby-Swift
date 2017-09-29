#include <iostream>
#include "SortingClass.cpp"
#include <stdlib.h>
#include <fstream>
#include <string>
#include <string.h>
// TODO: Read the text file
// TODO: inplement merge sort
int main(int argc, const char * argv[]) {
    
   
    ifstream file;
    string line;
    string inputArrayTenK[100000];
    
    file.open("hs-set-10k.txt");
    
    while (getline(file, line)){
        int k;
        string temp;
        string name,className,rarity,set,type,cost;
        cout << line << endl;
        k = 0;
        temp = "";
        while (line[k] != '\t'){
            temp += line[k];
            k++;
        }
        name = temp;
        cout << name << endl;
        k++;

        temp = "";
        while (line[k] != '\t'){
            temp += line[k];
            k++;
        }
        className = temp;
        cout << className << endl;
        k++;

        temp = "";
        while (line[k] != '\t'){
            temp += line[k];
            k++;
        }
        rarity = temp;
        cout << rarity << endl;
        k++;

        temp = "";
        while (line[k] != '\t'){
            temp += line[k];
            k++;
        }
        set = temp;
        cout << set << endl;
        k++;

        temp = "";
        while (line[k] != '\t'){
            temp += line[k];
            k++;
        }
        type = temp;
        cout << type << endl;
        k++;
        
        temp = "";
        while (line[k] != '\n'){
            temp += line[k];
            k++;
        }
        cost = temp;
        cout << cost << endl;
    }
    
//     int l[5];
//    for(int i=0;i<5;i++){
//        l[i] = 9-i;
//    }
//
//    CardManager tryOne(l,5,false);
//
//    tryOne.fullShort();
//
//    for(int i=0;i<5;i++){
//        cout << tryOne.arrayToShort[i] << endl;
//    }
    
    
}

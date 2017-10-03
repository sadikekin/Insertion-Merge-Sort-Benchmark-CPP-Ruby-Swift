#include "SortingClass.cpp"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    if(argc != 5) {
        cout << "Wrong number of arguments!" << endl;
        return 0;
    }

    ifstream file;
    string line;
    int counterForArray = 0, size = 0;

    // Taking arguments from the command line
    bool isFilter;
    bool isMergeSort;
    if (strcmp(argv[1], "-full") == 0) {
        isFilter = false;
    }else {
        isFilter = true;
    }
    if (strcmp(argv[2],"-i") == 0){
        isMergeSort =  false;
    }else {
        isMergeSort = true;
    }
    string inputFileName = argv[3];
    string outputFileName = argv[4];

    file.open(inputFileName);
    // opening the text file for size
    while(getline(file,line)){
        size++;
    }

    file.close();
    file.open(inputFileName);
    inputTextStruct *textStruct = new inputTextStruct[size];
    // This whole while splits the string from line. Puts those splited substrings to array(inputArray)
    while (getline(file, line)){
        int k;
        string temp;
        string name,className,rarity,set,type,cost;
        // Spliting array with \t symbol and adding these splited values to array like this ->  array << ["x","y","z"]
        k = 0;
        temp = "";
        while (line[k] != '\t'){
            temp += line[k];
            k++;
        }
        name = temp;
        k++;

        temp = "";
        while (line[k] != '\t'){
            temp += line[k];
            k++;
        }
        className = temp;
        k++;

        temp = "";
        while (line[k] != '\t'){
            temp += line[k];
            k++;
        }
        rarity = temp;
        k++;

        temp = "";
        while (line[k] != '\t'){
            temp += line[k];
            k++;
        }
        set = temp;
        k++;

        temp = "";
        while (line[k] != '\t'){
            temp += line[k];
            k++;
        }
        type = temp;
        k++;

        cost += line[k];

        // adding splited values to the array
        textStruct[counterForArray].name = name;
        textStruct[counterForArray].className = className;
        textStruct[counterForArray].cost = cost;
        textStruct[counterForArray].rarity = rarity;
        textStruct[counterForArray].set = set;
        textStruct[counterForArray].type = type;

        counterForArray++;
    }
    file.close();

    // Creating the object from sorting class
    CardManager letsSort(isMergeSort); // mergeSort value goes to the class

    if(isFilter) {
        letsSort.filterShort(textStruct,size);
    }else {
        letsSort.fullShort(textStruct,size);
    }



    ofstream myfile(outputFileName);

    if (myfile.is_open())
    {
      for(int i=0;i<size;i++){
          myfile << textStruct[i].name << "\t" << textStruct[i].className << "\t" << textStruct[i].cost << "\t" << textStruct[i].type << "\t" << textStruct[i].set << "\t" << textStruct[i].cost << endl;
      }
      myfile.close();
    }
    // for(int i=0;i<size;i++){
    //     cout << textStruct[i].className << " - " << textStruct[i].cost<< " - "<< textStruct[i].name << endl;
    // }

    // for(int i=0;i<size;i++){
    //     cout << textStruct[i].type << endl;
    // }

    delete [] textStruct;
    return 0;
}

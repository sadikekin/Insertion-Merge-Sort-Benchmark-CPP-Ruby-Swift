#ifndef SortingAlgorithm_hpp
#define SortingAlgorithm_hpp

#include <stdio.h>
#include <string>

struct inputTextStruct
{
    std::string name;
    std::string className;
    std::string rarity;
    std::string set;
    std::string type;
    std::string cost;
};



class CardManager {
public:
    bool isMergeSort;
    
    CardManager( bool);
    ~CardManager();
    void fullShort(inputTextStruct *, int);
    void filterShort(inputTextStruct*, int);
};



























#endif /* SortingAlgorithm_hpp */

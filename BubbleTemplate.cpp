#include <iostream>
#include <cstring>

using std::endl;
using std::cin;
using std::cout;
using std::cerr;
using std::nothrow;


template <class Type>
void ArrayPrint(Type *begin,void *end) {
    if(!begin) {
        cerr << "ERROR! Bad allocation!" << endl;
        return; 
    }
    for(int i=0;begin != end;++i,++begin) {
        cout << *begin << ", "; 
    }
    cout << endl;
}


template <class Type>
void SelfArrayFill(Type *begin,void *end) {  
    if(!begin) {
        cerr << "ERROR! Bad allocation!" << endl;
        exit(1); 
    }
    cout << "Input your array: ";
    while(begin != end) {
        cin >> *(begin++);
    }
    
}

template <class T>
void BubbleSort(T *begin,void *end) {
    if(!begin) {
        cerr << "ERROR! Bad allocation!" << endl;
        return; 
    }
    
    uint32_t size {};
    for(T *temp=begin; temp != end;++temp) {
        ++size;     
    }
    
    for(uint32_t i=0; i < size; ++i) {
        uint32_t sortLine = size - i;

        for(uint32_t j=0; j < sortLine - 1; ++j) {
            if(begin[j] > begin[j+1]) {
                T temp = begin[j];
                begin[j] = begin[j+1];
                begin[j+1] = temp;
            }
        }
    }
}

template <>
void ArrayPrint<char>(char *Array,void *unused) {
    if(!Array) {
        cerr << "ERROR! Bad allocation!" << endl;
        return; 
    }
    cout << Array << endl;
}


template <>
void SelfArrayFill(char *Array,void *unused) {
    if(!Array) {
        cerr << "ERROR! Bad allocation!" << endl;
        exit(1); 
    }
    cout << "Input your array (Only numbers and letters without spaces between): ";
    cin >> Array;
    cout << endl;
}


bool IsInputCorrectCheckFunc(char *Array,void *unused) {
    if(!Array) {
        cerr << "ERROR! Bad allocation!" << endl;
        return false; 
    }
    for(uint32_t i=0 ;Array[i]!='\0';++i) {
        bool firstCondition = (Array[i] >= '0' && Array[i] <= '9'),
             secondCondition= (Array[i] >= 'A' && Array[i] <= 'Z'),
             thirdCondition = (Array[i] >= 'a' && Array[i] <= 'z');     
        if(!(firstCondition || secondCondition || thirdCondition)) {
            return false;
        }
    }
    return true;
}

template<>
void BubbleSort(char *Array,void *unused) {
    if(!Array) {
        cerr << "ERROR! Bad allocation!" << endl;
        return; 
    }
    enum {UpperCaseLetter, LowerCaseLetter, Number};
    uint32_t size = strlen(Array);

    for(uint32_t i=0; i < size; ++i) {
        uint32_t sortLine = size - i;

        for(uint32_t j=0; j < sortLine - 1; ++j) {
            uint16_t priorityFirst,prioritySecond;

            if(Array[j] >= 'A' && Array[j] <= 'Z') {
                priorityFirst = UpperCaseLetter;
            }else if(Array[j] >= 'a' && Array[j] <= 'z') {
                priorityFirst = LowerCaseLetter;
            }else {
                priorityFirst = Number;
            }
            if(Array[j+1] >= 'A' && Array[j+1] <= 'Z') {
                prioritySecond = UpperCaseLetter;
            }else if(Array[j+1] >= 'a' && Array[j+1] <= 'z') {
                prioritySecond = LowerCaseLetter;
            }else {
                prioritySecond = Number;
            }

            if(priorityFirst > prioritySecond) {
                char temp = Array[j];
                Array[j] = Array[j+1];
                Array[j+1] = temp;
            }else if(Array[j] > Array[j+1]) {
                char temp = Array[j];
                Array[j] = Array[j+1];
                Array[j+1] = temp;
            }
        }
    }
}


int main() {
    
    uint32_t size;
    cout << "Input size of your array: ";
    cin >> size;
    cout << endl;

    short typeOfArray;
    unsigned int *ptrArrayInt = nullptr;
    char *ptrArrayChar = nullptr;
    double *ptrArrayDouble = nullptr;
    void *endOfArray = nullptr;
ArrayTypeGotoMark:
    cout << "Select type of data: |1-Unsigned int |2-Double |3-Char|" << endl;
    cin >> typeOfArray;
    cout << endl;

    enum {
        SELF_INT = 1,
        SELF_DOUBLE,
        SELF_CHAR
    };
        switch(typeOfArray)
        {
            case SELF_INT:
                ptrArrayInt = new(nothrow) unsigned int[size];
                if(!ptrArrayInt) {
                    cerr << "ERROR! Bad allocation!" << endl;
                    exit(1);
                }
                endOfArray = ptrArrayInt + size;
                SelfArrayFill(ptrArrayInt,endOfArray);
                cout << "Unsorted array: ";
                ArrayPrint(ptrArrayInt,endOfArray);
                BubbleSort(ptrArrayInt,endOfArray);
                cout << "Sorted array: ";
                ArrayPrint(ptrArrayInt,endOfArray);
                delete[] ptrArrayInt;
                break;
            
            case SELF_DOUBLE:
                ptrArrayDouble = new(nothrow) double[size+1];
                if(!ptrArrayDouble) {
                    cerr << "ERROR! Bad allocation!" << endl;
                    exit(1);
                }
                endOfArray = ptrArrayDouble + size;
                SelfArrayFill(ptrArrayDouble,endOfArray);
                
                cout << "Unsorted array: ";
                ArrayPrint(ptrArrayDouble,endOfArray);
                BubbleSort(ptrArrayDouble,endOfArray);
                cout << "Sorted array: ";
                ArrayPrint(ptrArrayDouble,endOfArray);
                delete[] ptrArrayDouble;
                break;

            case SELF_CHAR:
                 ptrArrayChar = new(nothrow) char[size] {'\0'};
                if(!ptrArrayChar) {
                    cerr << "ERROR! Bad allocation!" << endl;
                    exit(1);
                }
                endOfArray = ptrArrayChar + size;
              CharInputStrGotoMark:
                SelfArrayFill<char>(ptrArrayChar,endOfArray);
                if(!IsInputCorrectCheckFunc(ptrArrayChar,endOfArray)) {
                    cout << "Input error! Please retry..." << endl;
                    goto CharInputStrGotoMark;
                }
                cout << "Unsorted array: ";
                ArrayPrint(ptrArrayChar,endOfArray);
                BubbleSort(ptrArrayChar,endOfArray);
                cout << "Sorted array: ";
                ArrayPrint(ptrArrayChar,endOfArray);
                delete[] ptrArrayChar;
                break;

            default:
            cout << "Incorrect option! Please retry..." << endl;
            goto ArrayTypeGotoMark;
                break;
        }    

    return 0;
}
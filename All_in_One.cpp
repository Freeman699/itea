#include <iostream>
#include <cstring>

using std::endl;
using std::cout;
using std::cin;

constexpr unsigned int SIZE_OF_STR = 255;

void DigitFunc(char *ptr_strArray);
bool IsDigitFunc(char symbol);
void CaseFunc(char *ptr_strArray, bool mode);
short IsLowerUpperCaseSymbol(char symbol);
void ReverseStringFunc(char *ptr_strArray);

enum {
    LowerCaseChar = 1,
    UpperCaseChar,
    AsciiUpLowShift = 32
};


int main() {

    char strArray[SIZE_OF_STR];

StrEnterMark:
    cout << "Please enter your string: ";
    cin >> strArray;
    cout << endl;
    
    if(strlen(strArray) >= SIZE_OF_STR - 1) {
        cout << endl << "Your string might be too long\n Please retry..." << endl;
        goto StrEnterMark;
    }


    char *ptr_strArray = strArray;
    uint32_t answer;
    enum {
        IS_DIGIT = 1,
        CONVERT_UPPER,
        CONVERT_LOWER,
        REVERSE_STR,
        SWITCH_EXIT
    };

    do {
        cout << endl
            << "Choose your option:"                       << endl 
            << " 1 - Determine numbers"                    << endl 
            << " 2 - Convert to upper case all letters"    << endl
            << " 3 - Convert to lower case all letters"    << endl
            << " 4 - Reverse string"                       << endl
            << " 5 - exit"                                 << endl;
        cin >> answer;
        cout << endl;


        switch (answer)
        {
            case IS_DIGIT:
                DigitFunc(ptr_strArray);
                break;

            case CONVERT_UPPER:
                CaseFunc(ptr_strArray,true);
                break;

            case CONVERT_LOWER:
                CaseFunc(ptr_strArray,false);
                break;
            
            case REVERSE_STR:
                ReverseStringFunc(ptr_strArray);
                break;

            case SWITCH_EXIT:
                break;

            default:
                cout << "Incorrect option, please retry..." << endl;
                break;
        }
    
   
    } while(answer);

    return 0;
}



void DigitFunc(char *ptr_strArray) {

    cout << "Is digit: ";
    bool noneDigit = true;

    for(unsigned int i=0;ptr_strArray[i];++i) {

        if(IsDigitFunc(ptr_strArray[i])) {
            cout << " " << ptr_strArray[i];
            noneDigit = false;
        }
    }

    if(noneDigit) {
        cout << " NONE" << endl;
    }

    cout << endl;
}



bool IsDigitFunc(char symbol) {

    int num = symbol - '0';
    
    if(num >= 0 && num <= 9) {
        return true;
    }

    return false;
}



void CaseFunc(char *ptr_strArray, bool mode) {

    if(mode) {
        for(unsigned int i=0;ptr_strArray[i];++i) {

            if(IsLowerUpperCaseSymbol(ptr_strArray[i]) == LowerCaseChar) {
                ptr_strArray[i] -= ' ';
            }
        }
    }

    else {   
        for(unsigned int i=0;ptr_strArray[i];++i) {

            if(IsLowerUpperCaseSymbol(ptr_strArray[i]) == UpperCaseChar) {
                ptr_strArray[i] += ' ';
            }
        }
    }

    cout << endl << "Your string: " << ptr_strArray << endl;
}



short IsLowerUpperCaseSymbol(char symbol) {

    int character = symbol - 'A';	

    if(character >= 0 && character <= 25) {
        return UpperCaseChar;
    }

    character -= ' ';
    if(character >= 0 && character <= 25) {
        return LowerCaseChar;
    }

    return 0;
}



void ReverseStringFunc(char *ptr_strArray) {

    for(int i=0,j=strlen(ptr_strArray)-1; (i != j) || (i < j); ++i, --j) {
        
        char temp = ptr_strArray[i];
        ptr_strArray[i] = ptr_strArray[j];
        ptr_strArray[j] = temp;
        cout << endl << "Your string: " << ptr_strArray << endl;
    }

    cout << endl << "Your string: " << ptr_strArray << endl;
}
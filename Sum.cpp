#include <iostream>
#include <cstring>

using std::endl;
using std::cout;
using std::cin;

constexpr uint32_t MAX_SIZE = 100000;

bool DigitCheckFunc(char String[]);
void SumFunc(char FNum[],char SNum[]);
void InputFunc(char InputSring[]);


int main() {

    char FirstInputString[MAX_SIZE] {};
    char SecondInputString[MAX_SIZE] {};
  
    InputFunc(FirstInputString);
    InputFunc(SecondInputString);

    if(strlen(FirstInputString) >= strlen(SecondInputString)) {
        SumFunc(FirstInputString,SecondInputString);
    }else {
        SumFunc(SecondInputString,FirstInputString);
    }

    return 0;
}



void InputFunc(char InputSring[]) {
StrEnterMark:
    static int iter=1;
    cout << "Please enter " << iter <<" number: ";
    cin >> InputSring;
    cout << endl;
        
    if(strlen(InputSring) >= MAX_SIZE - 2) {
        cout << endl << "Your number might be too long\n Please retry..." << endl;
        goto StrEnterMark;
    }else if(DigitCheckFunc(InputSring)) {
        cout << endl << "Input error! Please retry..." << endl;
        goto StrEnterMark;
    }
    ++iter;
}



bool DigitCheckFunc(char String[]) {

    for(uint32_t i=0; String[i] != '\0' ;++i) {

        if(!isdigit(String[i])) {
            return true;
        }
    }
    return false;
}



void SumFunc(char FNum[],char SNum[]) {

    bool digit = false;
    uint32_t i = strlen(FNum) - 1;
    uint32_t k = strlen(SNum) - 1;

    for( ;k >= 0;--i, --k) {
        
        uint32_t tempSum = 0,
                 firstNum = FNum[i] - '0',
                 secondNum = SNum[k] - '0';

        if(digit) {
            ++firstNum;
            digit = false;
        }
        tempSum = firstNum + secondNum;
        if(tempSum >= 10) {

            digit = true;
            tempSum %= 10;
        }     
        FNum[i] = tempSum + '0';
    }

    if(digit) {
        for(uint32_t i = strlen(FNum); i >= 0; --i) {
            FNum[i+1] = FNum [i];
        }
        FNum[0] = 1 + '0';
    }
        cout << "Sum = " << FNum << endl;

}
#include <iostream>
#include <cstring>

using std::endl;
using std::cout;
using std::cin;

constexpr uint32_t MAX_SIZE = 100000;

bool DigitCheckFunc(char String[]);
void SumFunc(char FNum[],char SNum[]);




int main() {

    char FirstInputString[MAX_SIZE] {};
    char SecondInputString[MAX_SIZE] {};
    


StrFirstEnterMark:
    cout << "Please enter first number: ";
    cin >> FirstInputString;
    cout << endl;
    
    if(strlen(FirstInputString) >= MAX_SIZE - 2) {
        cout << endl << "Your number might be too long\n Please retry..." << endl;
        goto StrFirstEnterMark;
    }
    else if(DigitCheckFunc(FirstInputString)) {
        cout << endl << "Input error! Please retry..." << endl;
        goto StrFirstEnterMark;
    }



StrSecondEnterMark:
    cout << "Please enter second number: ";
    cin >> SecondInputString;
    cout << endl;
    
    if(strlen(SecondInputString) >= MAX_SIZE - 2) {
        cout << endl << "Your number might be too long\n Please retry..." << endl;
        goto StrSecondEnterMark;
    }
    else if(DigitCheckFunc(SecondInputString)) {
        cout << endl << "Input error! Please retry..." << endl;
        goto StrSecondEnterMark;
    }



    if(strlen(FirstInputString) >= strlen(SecondInputString)) {
        SumFunc(FirstInputString,SecondInputString);
    }
    else {
        SumFunc(SecondInputString,FirstInputString);
    }

    return 0;
}



bool DigitCheckFunc(char String[]) {

    for(uint32_t i=0; String[i] != '\0' ;++i) {
        bool flag = isdigit(String[i]);

        if(!flag) {
            return true;
        }
    }
    return false;
}



void SumFunc(char FNum[],char SNum[]) {

    bool digit = false;
    int i = strlen(FNum) - 1;
    int k = strlen(SNum) - 1;

    for( ;k >= 0;--i, --k) {
        
        // cout << "i = " << i << endl;

        uint32_t tempSum = 0,
                 firstNum = FNum[i] - '0',
                 secondNum = SNum[k] - '0';

        // cout << "firstNum = " << firstNum << endl;
        // cout << "secondNum = " << secondNum << endl;

        if(digit) {
            ++firstNum;
            digit = false;
        }

        tempSum = firstNum + secondNum;
        if(tempSum >= 10) {
            // cout << "Is digit +" << endl;
            digit = true;
            tempSum %= 10;
        }
        
        // cout << "tempSum = " << tempSum << endl;
        FNum[i] = tempSum + '0';
        // cout << "FNum = " << FNum << endl;
    }



        // cout << "FNum2 = " << FNum << endl;


    if(digit) {
        for(int i = strlen(FNum); i > 0; --i) {
            FNum[i+1] = FNum [i];
        }

        // cout << "FNum3 = " << FNum << endl;
        FNum[0] = 1 + '0';
    }

        cout << "Sum = " << FNum << endl;

}
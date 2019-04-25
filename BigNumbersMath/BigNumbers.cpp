#include <iostream>
#include <cstring>

#include "BigMath.hpp"

using std::endl;
using std::cout;
using std::cin;

constexpr uint32_t MAX_SIZE = 100000;


bool DigitCheckFunc(char String[]) {

    for(uint32_t i=0; String[i] != '\0' ;++i) {
        if(!isdigit(String[i])) {
            return true;
        }
    }
    return false;
}

bool BiggestNumFunc(char FNum[],char SNum[]) {
    enum {FirstIsBigger,SecondIsBigger,EQUAL = 0};
    
    for(uint32_t i=0;i < strlen(FNum); ++i) {
        if(FNum[i] > SNum[i]) {
            return FirstIsBigger;
        }else if(FNum[i] < SNum[i]) {
            return SecondIsBigger;
        }
    }
    return EQUAL;
}


void InputStrFunc(char InputString[]) {
    StrEnterMark:
        static int iter=1;
        cout << "Please enter " << iter <<" number: ";
        cin >> InputString;
        cout << endl;
        
        if(strlen(InputString) >= MAX_SIZE - 2) {
            cout << endl << "Your number might be too long\n Please retry..." << endl;
            goto StrEnterMark;
        }
        else if(DigitCheckFunc(InputString)) {
            cout << endl << "Input error! Please retry..." << endl;
            goto StrEnterMark;
        }
        ++iter;
}


int main() {

    cout << "Program for conducting mathematical operations on large numbers." << endl;

    char FirstInputString[MAX_SIZE] {};
    char SecondInputString[MAX_SIZE] {};
 
    InputStrFunc(FirstInputString);
    InputStrFunc(SecondInputString);

    uint32_t firstNumLength = strlen(FirstInputString),
             secondNumLength= strlen(SecondInputString);    
    bool is_second_bigger_then_first_num;
    char *Result = nullptr;

    if(firstNumLength > secondNumLength) {
        is_second_bigger_then_first_num = false;
    }else if(firstNumLength < secondNumLength) {
        is_second_bigger_then_first_num = true;
    }else {
        is_second_bigger_then_first_num = BiggestNumFunc(FirstInputString,SecondInputString);
    }

    const char *option_str = R"(Please select a number operation:
    1 - The sum of two numbers
    2 - Difference of two numbers
    3 - Multiplication of numbers(Not yet available)
    4 - Division numbers(Not yet available)
    5 - Exit)";
    uint16_t answer;
    bool resultLessThanZero = false;
    enum {SUM = 1,DIFFERENCE,MULTIPLY,DIVISION,EXIT};
    cout << option_str << endl; 

    auto  NotAvailable = []() {
        cout << "This feature is not implemented yet." << endl;
    };

InputOptionAnswerGotoMark:
    cin >> answer;
    cout << endl;
    switch (answer)
    {
        case SUM:
            if(!is_second_bigger_then_first_num) {
               Result = SumFunc(FirstInputString,SecondInputString);
            }else {
               Result = SumFunc(SecondInputString,FirstInputString);
            }
            cout << "Sum = " << Result << endl;
            break;
        
        case DIFFERENCE:
            if(!is_second_bigger_then_first_num) {
                Result = DiffFunc(FirstInputString,SecondInputString);
            }else {
                resultLessThanZero = true;
                Result = DiffFunc(SecondInputString,FirstInputString);
            }
            if(resultLessThanZero) {
                size_t shiftSize = sizeof(char) * strlen(Result);
                memmove(&Result[1],&Result[0],shiftSize);
                Result[0] = '-';
            }
                cout << "Difference = " << Result << endl;
            break;
        case MULTIPLY:
            NotAvailable();
            goto InputOptionAnswerGotoMark;
            break;
        case DIVISION:
            NotAvailable();
            goto InputOptionAnswerGotoMark;
            break;
        case EXIT:
            break;

        default:
            cout << "Wrong option! Please retry..." << endl;
            goto InputOptionAnswerGotoMark;
            break;
    }

    return 0;
}







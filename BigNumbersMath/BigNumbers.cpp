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

    const char *option_str = R"(Please select a number operation:
    1 - The sum of two numbers
    2 - Difference of two numbers
    3 - Multiplication of numbers
    4 - Division numbers(Not available)
    5 - Exit)";
    uint16_t answer;
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
            cout << "Sum = " << SumFunc(FirstInputString,SecondInputString) << endl;
            break;

        case DIFFERENCE:
            cout << "Difference = " << DiffFunc(FirstInputString,SecondInputString) << endl;
            break;

        case MULTIPLY:
            cout << "Multiplication = " << MultiplyFunc(FirstInputString,SecondInputString) << endl;
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







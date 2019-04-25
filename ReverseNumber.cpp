#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

int numOfDigits(int num);

int main(void) {

    int num;
    cout << "Please input number you want to reverse:";
    cin >> num;

    bool negative;
    if(num < 0) {
        negative = true;
        num = -num;
    }

    int reverseNum = 0;
    unsigned short t = numOfDigits(num);
    

    while(num) {

        int32_t numTen = num%10;
        int32_t numOfDigitsPow = pow(10,t);
        
        cout << "number%10: " << (num%10) << endl; 
        cout << "10^t: " << pow(10,t) << endl;

        // reverseNum += numTen * numOfDigitsPow;
        reverseNum += (num%10)*(pow(10,t));
        
        t--;
        num /= 10;
        cout << "number: " << reverseNum << endl;
    }

    if(negative) {
        reverseNum = -reverseNum;
    }

    cout << "Reversed number: " << reverseNum << endl;

    return 0;
}

int numOfDigits(int num) {

    int t;
    for(t=0;num;t++) {
        num /=10;
    }

    return t-1;
}
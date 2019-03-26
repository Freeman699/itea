#include <iostream>
#include <cmath>
#include <thread>

using std::cin;
using std::cout;
using std::endl;

constexpr int MAX_SIZE_OF_ARRAY = 50;

bool IsOdd(int num);

int main(void) {
    
    // int numArray [MAX_SIZE_OF_ARRAY];
    int amNum;

AmountOfNumbersMark:
    cout << "How many numbers do you want to enter: ";
    cin >> amNum;
    if(amNum > MAX_SIZE_OF_ARRAY) {
        cout << "Too many numbers, please retry";
        goto AmountOfNumbersMark;
    }

    cout << "You can only use numbers from -60 to 90 inclusive"<< endl << "Otherwise they will not be saved." 
         << endl << "Input your numbers: " << endl;

    int num,sum=0;

    for(int i=0;i<amNum;i++) {
        cin >> num;

        if((num > -60) && (num < 90) && IsOdd(num)) {
            sum += num;
        }
    }

    cout << endl << "Sum of all odd = " << sum;

    return 0;
}

bool IsOdd(int num) {
    
    if(num & 1) {
        return true;
    }

    return false;
}
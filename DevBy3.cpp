#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>

using std::endl;
using std::cin;
using std::cout;

int main(void) {

    char numString[100];
    cout << "Please input your numbers: ";
    cin.getline(numString,100);
    if(strlen(numString) >= 99) {
        cout << endl << "Error! String overflow";
        exit(0);
    }
    
    int sum=0;

    for(int i=strlen(numString)-1; i >= 0 ;i--) {
        if(numString[i] != ' ') {
            sum += numString[i] - '0';
        }

    }
    
    if((sum%3) == 0) {
        cout << "Your number can be divided by 3";
    }
    else {
        cout << "Your numver can not be divided by 3";
    }


    return 0;
}
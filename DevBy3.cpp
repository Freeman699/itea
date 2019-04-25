#include <iostream>
#include <cstring>

using std::endl;
using std::cin;
using std::cout;

int main() {

    char numString[100];
    cout << "Please input your numbers: ";
    cin.getline(numString,100);
    if(strlen(numString) >= 99) {
        cout << endl << "Error! String overflow";
        exit(0);
    }
    
    int sum=0;

    for(uint32_t i=0;numString[i] != '\0';++i) {
        if(numString[i] != ' ') {
            sum += numString[i] - '0';
        }

    }
    
    if((sum%3) == 0) {
        cout << "Your number can be divided by 3";
    }else {
        cout << "Your numver can not be divided by 3";
    }

    return 0;
}
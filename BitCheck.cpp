#include <iostream>

using std::endl;
using std::cin;
using std::cout;

int main() {
 
    cout << "Input your number: ";
    int32_t num;
    cin >> num;

    cout << endl << "Input bit number: ";
    uint32_t bitNum;
    cin >> bitNum;
    cout << endl;

    num >>= bitNum-1;

    if(num & 1) {
        cout << "Bit set";
    }
    else {
        cout << "Bit not set";
    }

    return 0;
}
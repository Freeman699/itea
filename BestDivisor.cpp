#include <iostream>

using std::endl;
using std::cin;
using std::cout;

int main() {

    cout << "Input your number: ";
    int num;
    cin >> num;

    if(num == 0) {
        cout << "Best divisor for num " << num << " = any number";
        return 0;
    }

    int bestDivisor = 1;
    int32_t middle = num/2;

    for(uint32_t t=1; t <= middle; ++t) {
        if(num%t == 0) {            
            bestDivisor = t;
        }    
    }

   cout << "Best divisor for num " << num << " = " << bestDivisor;


    return 0;
}   
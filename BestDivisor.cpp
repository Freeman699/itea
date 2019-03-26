#include <iostream>

using std::endl;
using std::cin;
using std::cout;

int main(void) {

    cout << "Input your number: ";
    int num;
    cin >> num;

    if(num == 0) {
        cout << "Best divisor for num " << num << " = any number";
        return 0;
    }

    int bestDivisor = 1;

    for(int t=0, k = 0; t < num/2; t++) {

        cout << endl << "t=" << t;

        if(num%t == 0) {            
                                    /*
                                     * Проблемма с оператором %
                                     * Не заходит в цикл ни разу если присуцтвует %t
                                    */
            bestDivisor = t;
        }    
    }

   cout << "Best divisor for num " << num << " = " << bestDivisor;


    return 0;
}   
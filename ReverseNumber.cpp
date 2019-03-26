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
    do {

        /*
            * Проблема при первой итерации в цикле
            * Любое число которое заканчивается не на ноль при первой итерации теряет единицу
            * 
            * Пример
            * 123
            * При первой итерации берём число 3 и умножаем на 10^2
            * Должно получится число 300
            * На деле 299
            * 
            * После первой итерации все работает как надо
        */

        reverseNum += (num%10)*(pow(10,t));
        cout << "number%10: " << (num%10) << endl; 
        cout << "10^t: " << pow(10,t) << endl;
        t--;
        num /= 10;
        cout << "number: " << reverseNum << endl;
    } while(num);

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
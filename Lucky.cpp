#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

int SumRecurs(int cnt, int sum, int tNum);

int main(void) { // Понимаю что это старый си вариант, но чем он плох?

    int tNum;
    const int defSize = 6;
    cout << "Please input your ticket number (only 6 characters): ";
    cin >> tNum;
    cout << endl;
    cout << "Num = " << tNum << endl;
    
    if(SumRecurs(defSize/2,0,tNum) == SumRecurs(defSize/2,0,(tNum/(pow(10,defSize/2))))) {
        cout << "You have a lucky ticket! Congratulations!" << endl;
    }
    else {
        cout << "Unfortunately your ticket is not lucky." << endl;
    }

    return 0;
}

int SumRecurs(int cnt, int sum, int tNum) {
    if(cnt == 1) return tNum%10;

    sum = sum + tNum%10 + SumRecurs(--cnt,sum,(tNum/10));

    return sum;
}
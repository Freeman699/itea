#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

int SumRecurs(int cnt, int sum, int tNum) {
    if(cnt == 1) return tNum%10;
    return ( sum + tNum%10 + SumRecurs(--cnt,sum,(tNum/10)) );
}


int main() {

    int tNum;
    const int DEF_SIZE = 6;
    cout << "Please input your ticket number (only 6 characters): ";
    cin >> tNum;
    cout << endl;
    cout << "Num = " << tNum << endl;
    
    uint32_t sizeDev2 = DEF_SIZE/2;

    if( SumRecurs(sizeDev2,0,tNum) == (SumRecurs(sizeDev2, 0, (tNum/(pow(10,sizeDev2))))) ) {
        cout << "You have a lucky ticket! Congratulations!" << endl;
    }else {
        cout << "Unfortunately your ticket is not lucky." << endl;
    }

    return 0;
}
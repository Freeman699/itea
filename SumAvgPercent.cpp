#include <cstdio>
#include <iostream>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    int32_t num;

InputNumMark:
    cout << "Input your number: ";
    cin >> num;
    cout << endl << "Your number: " << num << endl;

    double Solution = 0;
    uint32_t numCnt = 0;

    cout << "Sum = ";

    while(num) {
        ++numCnt;
        int32_t temp = num%10;
        Solution += temp;
        cout << temp;
        if(num /= 10) {
            cout << " + ";
        }
    }

    cout << " = " << Solution << endl;
    cout << "AVG = " << Solution << " / " << numCnt << " = " << Solution/numCnt;

    return 0;
}
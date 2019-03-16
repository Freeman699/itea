#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    printf("Integer literal E4 (HEX): %d\n",0xE4);
    printf("Integer literal 1337 (DEC): %d\n",1337);
    printf("Integer literal 0502 (OCT): %d\n",0502);
    printf("Integer literal 10001111 (BIN): "); cout << 0b10001111 << endl << endl;
    
    printf("Float literal 2.718: %.3f\n",2.718);
    printf("Float literal 3,14E-4: %f\n\n", 3.14E-4);


    printf("Char literal: %c\n", '~');
    printf("String literal: %s\n\n", "char");

    cout << "Boolean false v1: "<< false << endl
         << "Boolean true v1: " << true << endl
         << boolalpha
         << "Boolean false v2: "<< false << endl
         << "Boolean true v2: " << true << endl;
    

    return 0;
}
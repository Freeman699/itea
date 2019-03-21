#include <cstdio>
#include <cmath>
#include <iostream>

int main(void)
{
    std::cout << "Input your number: ";
    int decNum,counter = 0;
    std::cin >> decNum;
    std::cout << std::endl << "Your number: " << decNum;

    while(decNum != 0)
    {
        counter += decNum & 1;
        decNum >>= 1;
    }
    printf("\nCount of Bits: %i\n",counter);
    

    return 0;
}
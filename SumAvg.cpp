#include <cstdio>
#include <iostream>
#include <cstring>

constexpr int32_t SIZE_OF_STRING = 500;


int main()
{
    char tempString[SIZE_OF_STRING];

InputStringMark:
    std::cout << "Input your number: ";
    std::cin >> tempString;
    std::cout << std::endl;

    if(strlen(tempString) == SIZE_OF_STRING-1)
    {
        printf("\nYour number is too long, please retry\n");
        goto InputStringMark;
    }

    printf("\nYour number: %s\n",tempString);

    for(int t=0;t<strlen(tempString);t++)
    {
        if(isdigit(tempString[t]) == false)
        {
            printf("\nError!\n%s\n",tempString);
            for(int k=0;k<t;k++)printf(" ");
            printf("^\nNot a digit!\nPlease retry...\n");
            goto InputStringMark;
        }   
    }

    double Solution = 0;

    for(int t=0;t<strlen(tempString);t++)
    {
        Solution += tempString[t] - '0';
        printf("%d",tempString[t] - '0');
        if(t != (strlen(tempString)-1)) printf(" + ");
    }
    printf(" = %.0f\n",Solution);
    printf("AVG = %.0f / %d = %f\n",Solution,strlen(tempString),Solution/strlen(tempString));

    return 0;
}

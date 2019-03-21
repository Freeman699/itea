#include <cstdio>
#include <iostream>

int main(void)
{   
    int numOfSymbols;
    char chosenSymbol;

   printf("\n*****Build your own xmas tree!*****\n\n");
   printf("Type symbol:");
   std::cin >> chosenSymbol;
   printf("\nInput size of tree:");
   std::cin >> numOfSymbols;
   

    for(int blocsNum = 3; blocsNum <= numOfSymbols; blocsNum = blocsNum+1) // Ёлочка
    {
       for(int linesNum = blocsNum/2; linesNum<=blocsNum; linesNum++) //Вид ёлки можно изменить поменяв значение (от 1.5 до заданного числа) знаменателя при инициализации linesNum 
       {
           printf("\n");
           for(int spacesNum = numOfSymbols; spacesNum >= linesNum; spacesNum--) printf(" ");
           for(int symbolsNum = 1; symbolsNum <= ((linesNum*2)-1); symbolsNum++) printf("%c",chosenSymbol);
       }
    }
    printf("\n");

    for(int trunkHeight = numOfSymbols/2; trunkHeight < numOfSymbols; trunkHeight++) // Высота ствола ёлочки (от 1 до заданного числа)
    {
        for(int spacesNum = 1; spacesNum < numOfSymbols; spacesNum++) printf(" ");
        printf("|||\n");
    }

    for(int spacesNum = 1; spacesNum < numOfSymbols-1; spacesNum++) printf(" ");
    printf("/|||\\");



    return 0;
}
#include <iostream>
#include <cstring>
#include <fstream>


enum AsciiEnum {
    NumOfEngAlphChar = 26,
    NumOfArabicNums = 10,
    Ascii_Zero = 48,
    Ascii_Nine = Ascii_Zero + 9,
    Ascii_A_UP = 65,
    Ascii_Z_UP = Ascii_A_UP + 25,
    Ascii_a_low = 97,
    Ascii_z_low = Ascii_a_low + 25
};
enum NumOrCharEnum {
    NUMBER_ENCR,
    CHARACTER_ENCR
};


 auto LambdaReverseShift = [](bool charFlag,uint16_t shift,char *outSymb) {

        *outSymb -= shift;

        if(charFlag) {
            if(*outSymb < 0){
               *outSymb += NumOfEngAlphChar;
            }
        }
        else {
            if(*outSymb < 0){
               *outSymb += NumOfArabicNums;
            }
        }
    };


void CaesarDecryptor(char outStr[],uint32_t cryptoKey) {

    uint16_t charShift = cryptoKey % NumOfEngAlphChar,
             numShift  = cryptoKey % NumOfArabicNums;


    for(uint16_t i=0;outStr[i] != '\0';++i) {
        
        char *ptrTempChar = &outStr[i];
        
        bool isUpCharacter = (*ptrTempChar >= Ascii_A_UP) && (*ptrTempChar <= Ascii_Z_UP);
        bool isLowCharacter = (*ptrTempChar >= Ascii_a_low) && (*ptrTempChar <= Ascii_z_low);
        bool isNumber = (*ptrTempChar >= Ascii_Zero) && (*ptrTempChar <= Ascii_Nine);

        if(isNumber) {
            outStr[i] -= Ascii_Zero;
            LambdaReverseShift(NUMBER_ENCR,numShift,ptrTempChar);
            outStr[i] += Ascii_Zero;
        }
        else if(isUpCharacter) {
            outStr[i] -= Ascii_A_UP;
            LambdaReverseShift(CHARACTER_ENCR,charShift,ptrTempChar);
            outStr[i] += Ascii_A_UP;
        }
        else if(isLowCharacter) {
            outStr[i] -= Ascii_a_low;
            LambdaReverseShift(CHARACTER_ENCR,charShift,ptrTempChar);
            outStr[i] += Ascii_a_low;
        }
    }
}
                


void SymmetricDecryption(char outStr[],uint32_t cryptoKey) {

    uint32_t strSize = strlen(outStr);
    if(strSize <= 2){
        return;
    }

    char *tempBoofer = new char[strSize+1];  //(+1 для нул терминатора)
    if(!tempBoofer) {
        std::cout << " Warning! Bad allocation!" << std::endl;
        exit(1);
    }

    uint32_t linesNum = ((cryptoKey%5) + 2), columnsNum = (strSize/linesNum);
    for(uint32_t i=0; i < columnsNum; ++i) { 

        for (uint32_t j = 0,count = 0; count < linesNum; ++j,++count) {
            static uint32_t k = 0;
            tempBoofer[k++] = outStr[j * columnsNum + i];
        }
    }

    for(uint32_t j=columnsNum*linesNum; outStr[j] != '\0'; ++j) {
        tempBoofer[j] = outStr[j];
    }

    strcpy(outStr,tempBoofer);

    delete[] tempBoofer;
}
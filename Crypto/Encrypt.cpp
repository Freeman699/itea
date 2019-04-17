#include <iostream>
#include <ctime>
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


 auto LambdaShift = [](bool charFlag,uint16_t shift,char *inputSymb) {

        *inputSymb += shift;

        if(charFlag) {
            *inputSymb %= NumOfEngAlphChar;
        }
        else {
            *inputSymb %= NumOfArabicNums;
        }
    };


uint32_t CaesarCipher(char inputStr[]) {

    srand(time(NULL));
    uint32_t cryptoKey = rand() ;
    uint16_t charShift = cryptoKey % NumOfEngAlphChar,
             numShift  = cryptoKey % NumOfArabicNums;


    for(uint16_t i=0;inputStr[i] != '\0';++i) {
        
        char *ptrTempChar = &inputStr[i];
        
        bool isUpCharacter = (*ptrTempChar >= Ascii_A_UP) && (*ptrTempChar <= Ascii_Z_UP);
        bool isLowCharacter = (*ptrTempChar >= Ascii_a_low) && (*ptrTempChar <= Ascii_z_low);
        bool isNumber = (*ptrTempChar >= Ascii_Zero) && (*ptrTempChar <= Ascii_Nine);

        if(isNumber) {
            inputStr[i] -= Ascii_Zero;
            LambdaShift(NUMBER_ENCR,numShift,ptrTempChar);
            inputStr[i] += Ascii_Zero;
        }
        else if(isUpCharacter) {
            inputStr[i] -= Ascii_A_UP;
            LambdaShift(CHARACTER_ENCR,charShift,ptrTempChar);
            inputStr[i] += Ascii_A_UP;
        }
        else if(isLowCharacter) {
            inputStr[i] -= Ascii_a_low;
            LambdaShift(CHARACTER_ENCR,charShift,ptrTempChar);
            inputStr[i] += Ascii_a_low;
        }
    }

    return cryptoKey;
}

                

void SymmetricEncryption(char inputStr[],uint32_t cryptoKey) {

    std::ofstream outfile ("Encrypted_message.txt");
    std::cout << "  Encrypted message: ";

    uint32_t strSize = strlen(inputStr);
    if(strSize <= 2){
        std::cout << inputStr << std::endl;
        outfile << inputStr;
        outfile.close();
        return;
    }

    uint32_t columnsNum = ((cryptoKey%5) + 2), linesNum = (strSize/columnsNum);
    for(uint32_t i=0; i < columnsNum; ++i) { // columnsNum = (cryptoKey % 5) + 2 - случайное кол-во столбцов от 2 до 7

        for (uint32_t j = 0,count = 0; count < linesNum; ++j,++count) {
            outfile << inputStr[j * columnsNum + i];
            std::cout << inputStr[j * columnsNum + i];
        }
    }

    for(uint32_t j=columnsNum*linesNum; inputStr[j] != '\0'; ++j) { // Служит для того чтобы дописать в файл отброшеную строку
        outfile << inputStr[j];
        std::cout << inputStr[j];
    }

    std::cout << std::endl;

    outfile.close();
}
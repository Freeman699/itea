#include <iostream>
#include <string>
#include <fstream>

#include "Encrypt.hpp"
#include "Decrypt.hpp"


using std::endl;
using std::cout;
using std::cin;

constexpr uint16_t message_size = UINT16_MAX;



auto LambdaAnswer = []() {

    int16_t answer;
LambdaAnswerGotoMark:
    cin >> answer;
    cout << endl;
    enum {
        YES = 1,
        NO
    };

    switch (answer)
    {
    case YES:
        return true;
        break;
    
    case NO:
        return false;
        break;
    default:
        cout << "  Wrong option, please retry..." << endl;
        goto LambdaAnswerGotoMark;
        break;
    }
};



auto LambdaIsFileOpCheck = []() {

        std::fstream filecheck;
        filecheck.open("Encrypted_message.txt");

        if(filecheck.is_open()) {
            filecheck.close();
            return true;
        }else {
            return false;
        }
};



bool IsFileExistEncCheckFuc() {

     if(LambdaIsFileOpCheck()) {
        cout << "  WARNING!\n  File with name \"Encrypted_message.txt\" was detected." << endl 
             <<"  The file will be replaced by a new one.\n  Want to continue?\n  1 - Yes\n  2 - No" << endl;
        return LambdaAnswer();
    }else {
        return true;
    }
}



void EncryptFunc() {

    if( !(IsFileExistEncCheckFuc()) ) {
        return;
    }

    char inputStr[message_size] {};

EncryptFuncEnterMessageGotoMark:
    cout << "  Enter your message: ";
    cin.ignore();                       // Хотелось бы немного подробнее об этой сЫтуацЫЫ с cin.ignore() перед cin.getline(inputStr,message_size) так сказатб
    cin.getline(inputStr,message_size); 
    cout << endl;

    cout << "  Is this your message: " << inputStr << "\n  1 - Yes\n  2 - No" <<  endl;
    if( !(LambdaAnswer()) ) {
        goto EncryptFuncEnterMessageGotoMark;
    }
 
    uint32_t cryptoKey = CaesarCipher(inputStr);
    SymmetricEncryption(inputStr,cryptoKey);

    cout << "  Key: " << cryptoKey << endl;
    cout << "  Attention! The key will be needed to decrypt, remember it!" << endl;

}


bool IsFileExistDecCheckFunc() {

     if( !(LambdaIsFileOpCheck()) ) {
        cout << "  WARNING!\n  File with name \"Encrypted_message.txt\" was NOT detected." << endl;
        return false;
    }else {
        return true;
    }
}


void DecryptFunc() {
        
    if( !(IsFileExistDecCheckFunc()) ) {
        return;
    }

    std::ifstream inFile("Encrypted_message.txt");

    char outStr[message_size] {};
    uint32_t cryptoKey;

    cout << " Input decryption key:";
    cin >> cryptoKey;
    cout << endl;

    for(uint32_t i=0;!inFile.eof();++i) {
        inFile.get(outStr[i]);
    } 
    inFile.close();

    cout << "   Encrypded message: " << outStr << endl;

    SymmetricDecryption(outStr,cryptoKey);
    CaesarDecryptor(outStr,cryptoKey);
    
    cout << " Decrypded message: " << outStr << endl;

}

int main() {

    const char *option_str = R"(
    ╔══╦═══╦╗╔╦═══╦════╦══╗
    ║╔═╣╔═╗║║║║╔═╗╠═╗╔═╣╔╗║
    ║║─║╚═╝║╚╝║╚═╝║─║║─║║║║
    ║║─║╔╗╔╩═╗║╔══╝─║║─║║║║
    ║╚═╣║║║─╔╝║║────║║─║╚╝║
    ╚══╩╝╚╝─╚═╩╝────╚╝─╚══╝

  Program to encrypt and decrypt messages.
  The program has 2 options: encryption and decryption of messages.

  *Encryption*
    Selecting the encryption option will prompt you to enter a message.
    The encrypted message will be displayed in a text file in the program directory.
    After encryption, the program will display a number necessary for decryption.

    *Be careful! The text file created by the program is named "Encrypted_message.txt"*
    *Any previously created file with the same name will be replaced!                 *


  *Decryption*
    You must have an encrypted file with the name "Encrypted_message.txt" in the program directory.
    The program will request a key.
    After decrypting, a message will be displayed on the screen.
  )";
    cout << option_str << endl;


    int16_t answer;
    enum {
        ENCRYPT = 1,
        DECRYPT,
        EXIT
    };
    
    option_str = R"(
  Choose an option: 1 - Encrypt
                    2 - Decrypt
                    3 - Exit)";

SwitchMainGotoMark:
    do {
        cout << option_str << endl;
        cin >> answer;
        cout << endl;
        
        switch (answer)
        {
        case ENCRYPT:
            EncryptFunc();
            break;

        case DECRYPT:
            DecryptFunc();
            break;
        
        case EXIT:
            return 0;
            break;
        
        default:
            cout << "Wrong option, please retry..." << endl;
            goto SwitchMainGotoMark;
            break;
        }
    }while(true);

    return 0;
}
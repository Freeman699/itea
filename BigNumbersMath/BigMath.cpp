#include <cstring>
#include <iostream>
#include <cmath>

using namespace std;


bool IsSecondNumBiggerFunc(char FNum[],char SNum[]) {
    enum {FirstIsBigger,SecondIsBigger,EQUAL = 0};
    
    uint32_t firstNumSize = strlen(FNum),
             secondNumSize= strlen(SNum);

    if(firstNumSize > secondNumSize) {
        return FirstIsBigger;
    }else if(secondNumSize > firstNumSize) {
        return SecondIsBigger;
    }else {
        for(unsigned int i=0;i < strlen(FNum); ++i) {
            if(FNum[i] > SNum[i]) {
                return FirstIsBigger;
            }else if(FNum[i] < SNum[i]) {
                return SecondIsBigger;
            }
        }
    }
    return EQUAL;
}



char *SumFunc(char FNum[],char SNum[]) {

    if(IsSecondNumBiggerFunc(FNum,SNum)) {
        char *temp = FNum;
        FNum = SNum;
        SNum = temp;
    }

    bool digit = false;
    int i = strlen(FNum) - 1;

    for(int k = strlen(SNum) - 1 ;k >= 0;--i, --k) {   

        unsigned int tempSum = 0,
                 firstNum = FNum[i] - '0',
                 secondNum = SNum[k] - '0';

        if(digit) {
            ++firstNum;
            digit = false;
        }

        tempSum = firstNum + secondNum;

        if(tempSum >= 10) {
            digit = true;
            tempSum %= 10;
        }
        
        FNum[i] = tempSum + '0';
    }

    if(digit) {
        if(i>0) {
            for( ; i >=0; --i) {   

                unsigned int  Num = FNum[i] - '0';

                if(digit) {
                    ++Num;
                    digit = false;
                }
                if(Num >= 10) {
                    digit = true;
                    Num %= 10;
                }
    
                FNum[i] = Num + '0';
            }
        }

        for(int t = strlen(FNum); t >= 0; --t) {
            FNum[t+1] = FNum [t];
        }
        FNum[0] = 1 + '0';
    }

    return FNum;
}



char*  DiffFunc(char FNum[],char SNum[]) {
    
    bool result_less_then_zero = false;

    if(IsSecondNumBiggerFunc(FNum,SNum)) {
        char *temp = FNum;
        FNum = SNum;
        SNum = temp;
        result_less_then_zero = true;
    }


    bool digit = false;

     for(int k = strlen(SNum)-1, i = strlen(FNum)-1;i >= 0;--i, --k) {   

        int tempDiff = 0,
                firstNum = FNum[i] - '0',
                secondNum;
        if(k >=0) {
            secondNum = SNum[k] - '0';
        }else {
            secondNum = 0;
        }

        if(digit) {
            --firstNum;
            digit = false;
        }

        tempDiff = firstNum - secondNum;

        if(tempDiff < 0) {
            digit = true;
            tempDiff += 10;
        }

        FNum[i] = tempDiff + '0';
    }


    unsigned int numOfZero=0;
    for(unsigned int i=0;FNum[i] == '0';++i) {
        ++numOfZero;
    }
    if(numOfZero>0) {
        unsigned int shift = (strlen(FNum) - numOfZero + 1);
        memmove(FNum,FNum+numOfZero,shift*sizeof(char));
        FNum[shift] = '\0';
    }
    if(result_less_then_zero) {
                size_t shiftSize = sizeof(char) * strlen(FNum);
                memmove(&FNum[1],&FNum[0],shiftSize);
                FNum[0] = '-';
            }

    return FNum;
}



char *MultiplyFunc(char FNum[],char SNum[]) {

    
    if(!IsSecondNumBiggerFunc(FNum,SNum)) {
        char *temp = FNum;
        FNum = SNum;
        SNum = temp;
    }
    uint32_t sizeOfFirst = strlen(FNum),
             sizeOfSecond= strlen(SNum),
             sizeOfBoofer= sizeOfFirst+sizeOfSecond;
    char *boofer = new(std::nothrow) char[sizeOfBoofer + 1] {};
          boofer[sizeOfBoofer] = '\0';
    if(!boofer) {
        std::cout << "WARNING! Bad allocation." << std::endl;
        return nullptr;
    }

    for(int32_t i=sizeOfSecond-1,Scnt=0; i >= 0; --i,++Scnt) {
        int32_t sTemp = SNum[i] - '0',
                overBoofer = 0;

        for(int32_t j=sizeOfFirst-1,k = sizeOfBoofer-Scnt+1,Fcnt=0; j >= 0; --j, --k, ++Fcnt) {
          int32_t fTemp = FNum[j] - '0';
          boofer[k] += sTemp*fTemp*pow(10,Scnt+Fcnt) + overBoofer;
          cout << sTemp*fTemp*pow(10,Scnt+Fcnt) + overBoofer << endl;
          
          while(boofer[k] > 10) {
              overBoofer += boofer[k]/10;
              boofer[k] %=10;
          }  
        }
    }
    cout << "Boofer:" << boofer << endl;
    for(uint32_t i=0;i < sizeOfBoofer; ++i) {
        cout << boofer[i];
    }

    delete[] boofer;
    return FNum;
}
#include <iostream>
#include <cstring>

char *SumFunc(char FNum[],char SNum[]) {

    bool digit = false;
    int i = strlen(FNum) - 1;

    for(int k = strlen(SNum) - 1 ;k >= 0;--i, --k) {   

        uint32_t tempSum = 0,
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

                uint32_t  Num = FNum[i] - '0';

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
    
    bool digit = false;
    int i = strlen(FNum) - 1;

     for(int k = strlen(SNum) - 1 ;i >= 0;--i, --k) {   

        int32_t tempDiff = 0,
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

    uint32_t numOfZero=0;
    for(i=0;FNum[i] <= '0';++i) {
        ++numOfZero;
    }

    if(numOfZero>0) {
        uint32_t shift = (strlen(FNum) - numOfZero);
        memmove(&FNum[0],&FNum[numOfZero],shift*sizeof(char));
        FNum[shift] = '\0';
    }

    return FNum;
}

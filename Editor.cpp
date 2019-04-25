#include <iostream>

using std::endl;
using std::cout;
using std::cin;

void PrintStrFunc(char *ptrStr, int point);
uint32_t MStrlen(char *ptrStr);
bool CheckFunc(char *ptrStr, int strSize);
int MoveFunc(char *ptrStr, int point, int strSize);
void AddFunc(char *ptrStr, char *ptrBooferStr, int point, int strSize);
void InsertFunc(char *ptrStr, char *ptrBooferStr, int point, int strSize);
void DeleteFunc(char *ptrStr, int point, int strSize);
void CopyFunc(char *ptrStr, char *ptrBooferStr, int point, int strSize);
void CutFunc(char *ptrStr, char *ptrBooferStr, int point, int strSize);
void HelpFunc();

constexpr unsigned int MAX_STR_SIZE = 100;

int main() {
    
    cout << endl << " /Simple text editor\\" << endl;

    short answer;
    int point = 0;
    uint32_t strSize = 0;
    char *ptrStr = new char[MAX_STR_SIZE] {'\0'};
    char *ptrBooferStr = new char[MAX_STR_SIZE] {'\0'};
    ptrStr[0] = '\0';
    enum {
        ADD = 1,
        DEL,
        CPY,
        CUT,
        INS,
        MOV,
        HELP,
        EXIT
    };

    do {
        strSize = MStrlen(ptrStr);
       

        cout << endl 
             << " *********************" << endl
             << " * 1 - Add 6 - Mov   *" << endl
             << " * 2 - Del 7 - Help  *" << endl
             << " * 3 - Cpy 8 - Exit  *" << endl
             << " * 4 - Cut           *" << endl
             << " * 5 - Ins           *" << endl
             << " *********************" << endl;
        
        PrintStrFunc(ptrStr,point);
        

        cout << ' ';
        cin >> answer;
        cout << endl << endl;

        switch (answer)
        {
           
            
            case ADD:
                AddFunc(ptrStr,ptrBooferStr,point,strSize);
                break;

            case DEL:
                DeleteFunc(ptrStr,point,strSize);
                break;

            case CPY:
                CopyFunc(ptrStr,ptrBooferStr,point,strSize);
                break;
            
            case CUT:
                CutFunc(ptrStr,ptrBooferStr,point,strSize);
                break;

            case INS:
                InsertFunc(ptrStr,ptrBooferStr,point,strSize);
                break;

            case MOV:
                point = MoveFunc(ptrStr,point,strSize);
                break;

            case HELP:
                HelpFunc();
                break;

            case EXIT:
                delete []ptrStr;
                return 0;
                break;

            default:
                cout << "Wrong option! Please retry..." << endl;
                break;
        }
        
        

    } while(answer);


    return 0;
}


void PrintStrFunc(char *ptrStr,int point) {

    if(!ptrStr){
        return;
    }

    cout << endl << "String: " << ptrStr  << endl;
    uint16_t literalStringlong = sizeof("String:") / sizeof(char);

    for(int i = 0; i < point + literalStringlong; ++i) {
    }
    cout << "^" << endl;
}



uint32_t MStrlen(char *ptrStr) {
     if(!ptrStr){
        return;
    }

    uint32_t size = 0;

    while(ptrStr[size++] != '\0') {
    }

    return size;
}



int MoveFunc(char *ptrStr,int point,int strSize) {
     if(!ptrStr){
        return 0;
    }
          
    char side;
    int  numOfSteps;
MoveFuncInputMark:
    cout << "Input direction and number of steps: ";
    cin >> side;
    cin >> numOfSteps;
    cout << endl;
    if((side == 'l') || (side == 'r')) {
        if(side == 'l') {
            point -= numOfSteps;
            if(point < 0) {
                point = 0;
            }
        }
        else {
            point += numOfSteps;
            if(point > strSize) {
                point = strSize;
            }
        } 
    }
    else {
        cout << "Wrong option! Please retry..." << endl;
        goto MoveFuncInputMark;
    }



    return point;
}



void AddFunc(char *ptrStr,char *ptrBooferStr,int point,int strSize){
     if(!ptrStr || !ptrBooferStr){
        return;
    }

    cout << "Enter text: ";
    cin >> ptrBooferStr;
    cout << endl;
    if(MStrlen(ptrBooferStr) >= MAX_STR_SIZE) {
        cout << "Boofer overflow!" << endl;
    }else{
        InsertFunc(ptrStr,ptrBooferStr,point,strSize);
    } 
}



void InsertFunc(char *ptrStr,char *ptrBooferStr,int point,int strSize) {
    if(!ptrStr || !ptrBooferStr){
        return;
    }

    int freeSpace = MAX_STR_SIZE - strSize;
    int sizeOfBoofer = MStrlen(ptrBooferStr);
    if(sizeOfBoofer >= freeSpace) {
        cout << "String overflow!" << endl;
        return;
    }

    int numOfChar = strSize - point;
    int inputPoint = numOfChar + point + sizeOfBoofer;

    ptrStr[inputPoint--] = '\0';
    
    int tempPoint = point + numOfChar - 1;

    for( ; tempPoint >= point; --tempPoint, --inputPoint) {

        ptrStr[inputPoint] = ptrStr[tempPoint];
    }

    for(uint32_t t=0; t < sizeOfBoofer; ++t, ++point) {
        ptrStr[point] = ptrBooferStr[t];
    }
}

void DeleteFunc(char *ptrStr,int point, int strSize) {
    if(!ptrStr) {
        return;
    }

    int numOfChar;
    int tempPoint = point;
    char side;

DeleteFuncInputMark:
    cout << "Input direction and number of characters: ";
    cin >> side;
    cin >> numOfChar;
    cout << endl;
    if(side == 'l') {
        point -= numOfChar;
        if(point < 0) {
            point = 0;
        }
    }else if(side == 'r') {
        point += numOfChar;
        if(point > strSize) {
            point = strSize;
        }
    }else {
        cout << "Wrong option! Please retry..." << endl;
        goto DeleteFuncInputMark;
    }

    if(point >= tempPoint) {
        int boofer = tempPoint;
        tempPoint = point;
        point = boofer;
    }

    int numOfCharTemp = 0;
    for(int i=tempPoint; ptrStr[i] != '\0'; ++i) {
        ++numOfCharTemp;
    }   

    for(int i=0;i < numOfCharTemp; ++i, ++point) {
        ptrStr[point] = ptrStr[tempPoint + i];
    }
    ptrStr[point] = '\0';
}



void CopyFunc(char *ptrStr, char *ptrBooferStr, int point, int strSize) {
    if(!ptrStr || !ptrBooferStr){
        return;
    }

    char side;
    int  numOfChar;
    int tempPoint = point;
CopyFuncInputMark:
    cout << "Input direction and number of characters: ";
    cin >> side;
    cin >> numOfChar;
    cout << endl;
    if(side == 'l') {
        point -= numOfChar;
        if(point < 0) {
            point = 0;
        }
    }else if(side == 'r') {
        point += numOfChar;
        if(point > strSize) {
            point = strSize;
        }
    }else {
        cout << "Wrong option! Please retry..." << endl;
        goto CopyFuncInputMark;
    }

    if(point >= tempPoint) {
        int boofer = tempPoint;
        tempPoint = point;
        point = boofer;
    }


    int i = 0;
    for( ; point != tempPoint; ++i, ++point) {

        ptrBooferStr[i] = ptrStr[point];
    }
    ptrBooferStr[i] = '\0';
}



void CutFunc(char *ptrStr, char *ptrBooferStr, int point, int strSize) {
    if(!ptrStr || !ptrBooferStr){
        return;
    }

    char side;
    int  numOfChar;
    int tempPoint = point;
CutFuncInputMark:
    cout << "Input direction and number of characters: ";
    cin >> side;
    cin >> numOfChar;
    cout << endl;
    if(side == 'l') {
        point -= numOfChar;
        if(point < 0) {
            point = 0;
        }
    }else if(side == 'r') {
        point += numOfChar;
        if(point > strSize) {
            point = strSize;
        }
    }else {
        cout << "Wrong option! Please retry..." << endl;
        goto CutFuncInputMark;
    }

    if(point >= tempPoint) {
        int boofer = tempPoint;
        tempPoint = point;
        point = boofer;
    }


    int i = 0;
    int sPoint = point;
    for( ; point != tempPoint; ++i, ++point) {

        ptrBooferStr[i] = ptrStr[point];
    }
    ptrBooferStr[i] = '\0';

    point = sPoint;


    int numOfCharTemp = 0;
    for(int i=tempPoint; ptrStr[i] != '\0'; ++i) {
        ++numOfCharTemp;
    }   

    for(int i=0;i < numOfCharTemp; ++i, ++point) {
        ptrStr[point] = ptrStr[tempPoint + i];
    }
    ptrStr[point] = '\0';
}



void HelpFunc() {

    cout << "////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl
         << "* Add - The function adds the text you entered at the cursor position." << endl
         << "* Del - Removes text from the cursor position in the direction you choose. (Argument r - Right, l - Left is entered first, then the number of characters)" << endl
         << "* Cpy - Copies characters starting from a pointer in a selected direction. (Argument r - Right, l - Left is entered first, then the number of characters)" << endl
         << "* Cut - Cut characters starting from the pointer in the selected direction.(Argument r - Right, l - Left is entered first, then the number of characters)" << endl
         << "* Ins - Inserts previously copied or cut text at the cursor position."  << endl
         << "* Mov - Moves the cursor in the selected direction.                        (Argument r - Right, l - Left is entered first, then the number of characters)" << endl
         << "////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
}
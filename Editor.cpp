#include <iostream>

using std::endl;
using std::cout;
using std::cin;

void PrintStrFunc(char *ptrStr, int point);
int MStrlen(char *ptrStr);
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
    int point = 0, strSize = 0;
    char *ptrStr = new char[MAX_STR_SIZE];
    char *ptrBooferStr = new char[MAX_STR_SIZE];
    ptrStr[0] = '\0';
    enum {
        EXIT = 0,
        ADD,
        DEL,
        CPY,
        CUT,
        INS,
        MOV,
        HELP
    };

    do {
        strSize = MStrlen(ptrStr);
       

        cout << endl 
             << " *********************" << endl
             << " * 1 - Add 6 - Mov   *" << endl
             << " * 2 - Del 7 - Help  *" << endl
             << " * 3 - Cpy 0 - Exit  *" << endl
             << " * 4 - Cut           *" << endl
             << " * 5 - Ins           *" << endl
             << " *********************" << endl;
        
        PrintStrFunc(ptrStr,point);
        

        cout << ' ';
        cin >> answer;
        cout << endl << endl;

        switch (answer)
        {
            case EXIT:
                delete []ptrStr;
                return 0;
                break;
            
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
            
            default:
                cout << "Wrong option! Please retry..." << endl;
                break;
        }
        
        

    } while(answer);


    return 0;
}


void PrintStrFunc(char *ptrStr,int point) {

    cout << endl << "String:\"" << ptrStr << "\"" << endl;

    for(int i = 0; i < point + 8; ++i) { // +8 Посколько в 48 строке в cout String:\" занимает именно 8 символов
        cout << " ";
    }
    cout << "^" << endl;
}



int MStrlen(char *ptrStr) {

    int size = 0;

    while(ptrStr[size] != '\0') {
        size++;
    }

    return size;
}



int MoveFunc(char *ptrStr,int point,int strSize) {
          
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

    cout << "Enter text: ";
    cin >> ptrBooferStr;
    cout << endl;
    if(MStrlen(ptrBooferStr) >= MAX_STR_SIZE) {
        cout << "Boofer overflow!" << endl;
        return;
    }

    InsertFunc(ptrStr,ptrBooferStr,point,strSize);
}



void InsertFunc(char *ptrStr,char *ptrBooferStr,int point,int strSize) {

    int freeSpace = MAX_STR_SIZE - MStrlen(ptrStr) - 1;
    int sizeOfBoofer = MStrlen(ptrBooferStr);
    if(sizeOfBoofer >= freeSpace) {
        cout << "String overflow!" << endl;
        return;
    }

    int numOfChar = strSize - point;
    int inputPoint = numOfChar + point + sizeOfBoofer;

    ptrStr[inputPoint] = '\0';
    --inputPoint;
    
    int tempPoint = point + numOfChar - 1;

    for( ; tempPoint >= point; --tempPoint, --inputPoint) {

        ptrStr[inputPoint] = ptrStr[tempPoint];
    }

    for(int t=0; t < sizeOfBoofer; ++t, ++point) {
        ptrStr[point] = ptrBooferStr[t];
    }
}

void DeleteFunc(char *ptrStr,int point, int strSize) {

    int numOfChar;
    int tempPoint = point;
    char side;

DeleteFuncInputMark:
    cout << "Input direction and number of characters: ";
    cin >> side;
    cin >> numOfChar;
    cout << endl;
    if((side == 'l') || (side == 'r')) {
        if(side == 'l') {
            point -= numOfChar;
            if(point < 0) {
                point = 0;
            }
        }
        else {
            point += numOfChar;
            if(point > strSize) {
                point = strSize;
            }
        } 
    }
    else {
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

    char side;
    int  numOfChar;
    int tempPoint = point;
CopyFuncInputMark:
    cout << "Input direction and number of characters: ";
    cin >> side;
    cin >> numOfChar;
    cout << endl;
    if((side == 'l') || (side == 'r')) {
        if(side == 'l') {
            point -= numOfChar;
            if(point < 0) {
                point = 0;
            }
        }
        else {
            point += numOfChar;
            if(point > strSize) {
                point = strSize;
            }
        } 
    }
    else {
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

    char side;
    int  numOfChar;
    int tempPoint = point;
CutFuncInputMark:
    cout << "Input direction and number of characters: ";
    cin >> side;
    cin >> numOfChar;
    cout << endl;
    if((side == 'l') || (side == 'r')) {
        if(side == 'l') {
            point -= numOfChar;
            if(point < 0) {
                point = 0;
            }
        }
        else {
            point += numOfChar;
            if(point > strSize) {
                point = strSize;
            }
        } 
    }
    else {
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
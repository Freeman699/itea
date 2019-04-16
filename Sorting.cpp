#include <iostream>
#include <cstring>
#include <ctime>
#include <functional>

using std::endl;
using std::cout;
using std::cin;


void BubbleSort(int *ptrArray, uint32_t size,bool compare);
void QuickSort(int *ptrArray,uint32_t left,uint32_t right);
void PrintArray(int *ptrArray, uint32_t size);
void BestArrayFill(int *ptrArray, uint32_t size);
void AvgArrayFill(int *ptrArray, uint32_t size);
void WorstArrayFill(int *ptrArray, uint32_t size);
void SelfArrayFill(int *ptrArray, uint32_t size);
void ArrayCopy(int *ptrArray,int *new_ptrArray, uint32_t size);

auto LambdaSwap = [](int &first, int &second) {
    int temp = first;
    first = second;
    second = temp;  
};

int main() {

    uint32_t size;
    cout << "Input size of your array: ";
    cin >> size;
    cout << endl;

    auto badAllocCheck = [](int *ptr) {
        if(ptr) {
            return;
        }
        else {
            cout << "Warning! Bad Allocation!" << endl;
            exit(1);
        }
    };

    int *ptrArray = new int[size]; // Динамика поскольку заранее неизвестен размер массива.
    badAllocCheck(ptrArray);
    enum {
        SWITCH_EXIT = 0,
        BEST_FILL,
        AVG_FILL,
        WORST_FILL,
        SELF_FILL
    };
    short answer; 
    do {
        cout << "Which way would you like to fill your array?" << endl
             << "1 - Best fill"                                << endl
             << "2 - AVG fill"                                 << endl
             << "3 - Worst fill"                               << endl
             << "4 - By your self"                             << endl
             << "0 - Exit"                                     << endl;  
        cin >> answer;
        cout << endl;

        switch(answer)
        {
            case SWITCH_EXIT:
                return 0;
                break;
            
            case BEST_FILL:
                BestArrayFill(ptrArray,size);
                answer = 0;
                break;

            case AVG_FILL:
                AvgArrayFill(ptrArray,size);
                answer = 0;
                break;

            case WORST_FILL:
                WorstArrayFill(ptrArray,size);
                answer = 0;
                break;
            
            case SELF_FILL:
                SelfArrayFill(ptrArray,size);
                answer = 0;
                break;
        
            default:
            cout << "Incorrect option! Please retry..." << endl;
                break;
        }    
    }while(answer);

    cout << "Unsorted array: " << endl;
    PrintArray(ptrArray,size);
    cout << endl;

    int *ptrCopyArray = new int[size];
    badAllocCheck(ptrCopyArray);
    ArrayCopy(ptrArray,ptrCopyArray,size);

    enum {
            INCREAS = 1,
            DECREAS
        };
    bool compare;
    cout << "What is BubbleSort order to sort the array?\n1 - Increasing\n2 - Decreasing" << endl;
compareGotoMark:
    cin >> answer;
    cout << endl;

    switch (answer)
    {
    case INCREAS:
        compare = true;
        break;
    case DECREAS:
        compare = false;
        break;
    default:
        cout << "Incorrect option! Please retry..." << endl;
        goto compareGotoMark;
        break;
    }

    auto startTime = clock();
    // cout << "Time before:" << startTime << endl;
    BubbleSort(ptrArray,size,compare);
    auto endTime = clock();
    // cout << "Time after:" << startTime << endl;
    cout << endl << "///////////////////////////////////////////////////////"
         << endl << "////////////////////////Sorted array(BubbleSort)///////"
         << endl << "///////////////////////////////////////////////////////"
         << endl;
    PrintArray(ptrArray,size);
    cout << "Bubble Sort time: " << (endTime - startTime) << endl << endl;
    
    startTime = clock();
    QuickSort(ptrCopyArray,0,size-1);
    endTime = clock();
    cout << endl << "///////////////////////////////////////////////////////"
         << endl << "////////////////////////Sorted array(QuickSort)///////"
         << endl << "///////////////////////////////////////////////////////"
         << endl;
    // PrintArray(ptrCopyArray,size);
    cout << "Quick Sort time: " << (endTime - startTime) << endl << endl;

    delete []ptrArray;
    delete []ptrCopyArray;

    return 0;
}


void PrintArray(int *ptrArray, uint32_t size) {

    for(uint32_t i=0;i<size;++i){
        cout << ptrArray[i] << ' ';
    }
    cout << endl;
}


void ArrayCopy(int *ptrArray,int *new_ptrArray, uint32_t size) {

    for(uint32_t i=0;i<size;++i) {
        new_ptrArray[i] = ptrArray[i];
    }
}


void BestArrayFill(int *ptrArray, uint32_t size) {

    for(uint32_t i=0;i<size;++i){
        ptrArray[i] = i;
    }
}

void WorstArrayFill(int *ptrArray, uint32_t size) {

    for(uint32_t i=size,j=0;i>0;--i,j++) { // Тут есть момент с --i но можно оставить и беззнаковй тип
        ptrArray[j] = i;
    }
}

void AvgArrayFill(int *ptrArray, uint32_t size) {

    srand(time(NULL));
    for(uint32_t i=0;i<size;++i) {
        ptrArray[i] = rand()%100;
    }
}

void SelfArrayFill(int *ptrArray, uint32_t size) {

    for(uint32_t i=0;i<size;++i) {
        cin >> ptrArray[i];
    }
}



void BubbleSort(int *ptrArray, uint32_t size,bool compare) {

    auto comp = [](int &first,int &second,bool compare){
        if(compare) {
            return first > second;
        }else {
            return first < second;
        }
    };

    for(uint32_t i=0; i < size; ++i) {
        uint32_t sortLine = size - i;

        for(uint32_t j=0; j < sortLine - 1; ++j) {

            if(comp(ptrArray[j],ptrArray[j+1],compare)) {
                LambdaSwap(ptrArray[j],ptrArray[j+1]);
            }
        }
    } 
}


void QuickSort(int *ptrArray,uint32_t left,uint32_t right) {

    int i = left,
        j = right;

	while(i <= j) {

        int midle = ptrArray[(i+j)/2];

        while (ptrArray[i] < midle) {
            ++i;
        }
        while (ptrArray[j] > midle) {
            --j;
        }

		if (i <= j) {
            LambdaSwap(ptrArray[i],ptrArray[j]);
			++i;
			--j;
		}
	}

	if(j > left) {
        QuickSort(ptrArray, left, j);
    }
	if(i < right) {
        QuickSort(ptrArray, i, right);
    }
}

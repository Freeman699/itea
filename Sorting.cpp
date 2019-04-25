#include <iostream>
#include <cstring>
#include <ctime>
#include <functional>

using std::endl;
using std::cout;
using std::cin;


void BubbleSort(int *ptrArray, uint32_t size, std::function<bool(int, int)> func);
void QuickSort(int *ptrArray,uint32_t left,uint32_t right);
void PrintArray(int *ptrArray, uint32_t size);
void BestArrayFill(int *ptrArray, uint32_t size);
void AvgArrayFill(int *ptrArray, uint32_t size);
void WorstArrayFill(int *ptrArray, uint32_t size);
void SelfArrayFill(int *ptrArray, uint32_t size);
void ArrayCopy(int *ptrArray,int *new_ptrArray, uint32_t size);
void Swap(int &first, int &second);

auto badAllocCheck = [](int *ptr) {
        if(ptr) {
            return true;
        }
        else {
            cout << "Warning! Bad Allocation!" << endl;
            return false;
        }
};

int main() {

    uint32_t size;
    cout << "Input size of your array: ";
    cin >> size;
    cout << endl;

    

    int *ptrArray = new(std::nothrow) int[size]; // Динамика поскольку заранее неизвестен размер массива.
    if(!badAllocCheck(ptrArray)) {
        exit(1);
    }

    enum {
        
        BEST_FILL = 1,
        AVG_FILL,
        WORST_FILL,
        SELF_FILL,
        SWITCH_EXIT
    };
    short answer;
ArrayFillGotoMark:
    cout << "Which way would you like to fill your array?" << endl
         << "1 - Best fill"                                << endl
         << "2 - AVG fill"                                 << endl
         << "3 - Worst fill"                               << endl
         << "4 - By your self"                             << endl
         << "5 - Exit"                                     << endl;  
    cin >> answer;
    cout << endl;

    switch(answer)
    {  
        case BEST_FILL:
            BestArrayFill(ptrArray,size);
            break;

        case AVG_FILL:
            AvgArrayFill(ptrArray,size);
            break;

        case WORST_FILL:
            WorstArrayFill(ptrArray,size);
            break;
        
        case SELF_FILL:
            SelfArrayFill(ptrArray,size);
            break;
        
        case SWITCH_EXIT:
            delete[] ptrArray;
            return 0;
            break;
    
        default:
        cout << "Incorrect option! Please retry..." << endl;
            goto ArrayFillGotoMark;
            break;
    }    

    int *ptrCopyArray = new(std::nothrow) int[size];
    if(!badAllocCheck(ptrCopyArray)) {
        delete[] ptrArray;
        exit(1);
    }

    ArrayCopy(ptrArray,ptrCopyArray,size);

    time_t startTime,
           endTime;
    enum {
            INCREAS = 1,
            DECREAS
        };

    cout << "What is BubbleSort order to sort the array?\n1 - Increasing\n2 - Decreasing" << endl;
compareGotoMark:
    cin >> answer;
    cout << endl;

    switch (answer)
    {
    case INCREAS:
        startTime = clock();
        BubbleSort(ptrArray, size, [](int first,int second){ return first > second; });
        endTime = clock();
        break;

    case DECREAS:
        startTime = clock();
        BubbleSort(ptrArray, size, [](int first,int second){ return first < second; });
        endTime = clock();
        break;

    default:
        cout << "Incorrect option! Please retry..." << endl;
        goto compareGotoMark;
        break;
    }

    cout << "Bubble Sort time: " << (endTime - startTime) << endl << endl;
    

    startTime = clock();
    QuickSort(ptrCopyArray,0,size-1);
    endTime = clock();
    cout << "Quick Sort time: " << (endTime - startTime) << endl << endl;

    delete []ptrArray;
    delete []ptrCopyArray;

    return 0;
}



void Swap(int &first, int &second) {
    int temp = first;
    first = second;
    second = temp;  
}


void PrintArray(int *ptrArray, uint32_t size) {
    if(!badAllocCheck(ptrArray)) return;
    for(uint32_t i=0;i<size;++i){
        cout << ptrArray[i] << ' ';
    }
    cout << endl;
}


void ArrayCopy(int *ptrArray,int *new_ptrArray, uint32_t size) {
    if(!badAllocCheck(ptrArray)) return;
    for(uint32_t i=0;i<size;++i) {
        new_ptrArray[i] = ptrArray[i];
    }
}


void BestArrayFill(int *ptrArray, uint32_t size) {
    if(!badAllocCheck(ptrArray)) return;
    for(uint32_t i=0;i<size;++i){
        int64_t k=0;
        ptrArray[i] = k++;
    }
}

void WorstArrayFill(int *ptrArray, uint32_t size) {
    if(!badAllocCheck(ptrArray)) return;
    for(uint32_t i=size,j=0;i>0;--i,j++) {
        int64_t k = size;
        ptrArray[j] = k--;
    }
}

void AvgArrayFill(int *ptrArray, uint32_t size) {
    if(!badAllocCheck(ptrArray)) return;
    srand(time(NULL));
    for(uint32_t i=0;i<size;++i) {
        ptrArray[i] = rand()%100;
    }
}

void SelfArrayFill(int *ptrArray, uint32_t size) {
    if(!badAllocCheck(ptrArray)) return;
    for(uint32_t i=0;i<size;++i) {
        cin >> ptrArray[i];
    }
}


void BubbleSort(int *ptrArray, uint32_t size, std::function<bool(int, int)> func) {
    if(!badAllocCheck(ptrArray)) return;
    for(uint32_t i=0; i < size; ++i) {
        uint32_t sortLine = size - i;

        for(uint32_t j=0; j < sortLine - 1; ++j) {

            if( func(ptrArray[j],ptrArray[j+1]) ) {
                Swap(ptrArray[j],ptrArray[j+1]);
            }
        }
    } 
}


void QuickSort(int *ptrArray,uint32_t left,uint32_t right) {
    if(!badAllocCheck(ptrArray)) return;
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
            Swap(ptrArray[i],ptrArray[j]);
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

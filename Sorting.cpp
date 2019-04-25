#include <iostream>
#include <cstring>
#include <ctime>
#include <chrono>

using std::endl;
using std::cout;
using std::cin;


void BubbleSort(int *ptrArray, uint32_t size);
void QuickSort(int *ptrArray,int left,int right);
void PrintArray(int *ptrArray, uint32_t size);
void BestArrayFill(int *ptrArray, uint32_t size);
void AvgArrayFill(int *ptrArray, uint32_t size);
void WorstArrayFill(int *ptrArray, uint32_t size);
void SelfArrayFill(int *ptrArray, uint32_t size);
void ArrayCopy(int *ptrArray,int *new_ptrArray, uint32_t size);

int main() {

    uint32_t size;
    cout << "Input size of your array: ";
    cin >> size;
    cout << endl;

    int *ptrArray = new int[size];
    
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
    ArrayCopy(ptrArray,ptrCopyArray,size);


    auto startTime = clock();
    BubbleSort(ptrArray,size);
    auto endTime = clock();

    PrintArray(ptrArray,size);
    cout << "Bubble Sort time: " << (endTime-startTime) << endl << endl;
    
    startTime = clock();
    QuickSort(ptrCopyArray,0,size-1);
    endTime = clock();
    cout << "Quick Sort time: " << (startTime - endTime) << endl << endl;

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

    for(int64_t i=size,j=0;i>0;--i,j++) {
        ptrArray[j] = i;
    }
}

void AvgArrayFill(int *ptrArray, uint32_t size) {

    srand(time(NULL));
    for(uint32_t i=0;i<size; i++) {
        ptrArray[i] = rand()%100;
    }
}

void SelfArrayFill(int *ptrArray, uint32_t size) {

    for(uint32_t i=0;i<size;++i) {
        cin >> ptrArray[i];
    }
}



void BubbleSort(int *ptrArray, uint32_t size) {

    for(uint32_t i=0; i < size; ++i) {

        uint32_t sortLine = size - i;

        for(uint32_t j=0; j < sortLine - 1; ++j) {

            if(ptrArray[j] > ptrArray[j+1]) {
                int temp = ptrArray[j];
                ptrArray[j] = ptrArray[j+1];
                ptrArray[j+1] = temp;
            }
        }

    }
}


void QuickSort(int *ptrArray,int left,int right) {

    uint32_t i = left,
             j = right;

	while(i <= j) {

        int32_t midle = ptrArray[(i+j)/2];
        
		while (ptrArray[i] < midle) {
            ++i;
        }
		while (ptrArray[j] > midle) {
            --j;
        }

		if (i <= j) {
            int temp = ptrArray[i];
			ptrArray[i] = ptrArray[j];
			ptrArray[j] = temp;
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

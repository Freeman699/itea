#include <iostream>
#include <cstring>
#include <ctime>
#include <chrono>

using std::endl;
using std::cout;
using std::cin;


void BubbleSort(int *ptrArray, int size);
void QuickSort(int *ptrArray,int left,int right);
void PrintArray(int *ptrArray, int size);
void BestArrayFill(int *ptrArray, int size);
void AvgArrayFill(int *ptrArray, int size);
void WorstArrayFill(int *ptrArray, int size);
void SelfArrayFill(int *ptrArray, int size);
void ArrayCopy(int *ptrArray,int *new_ptrArray, int size);

int main() {

    int size;
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
    // cout << "Time before:" << startTime << endl;
    BubbleSort(ptrArray,size);
    auto endTime = clock();
    // cout << "Time after:" << startTime << endl;
    cout << endl << "///////////////////////////////////////////////////////"
         << endl << "////////////////////////Sorted array(BubbleSort)///////"
         << endl << "///////////////////////////////////////////////////////"
         << endl;
    PrintArray(ptrArray,size);
    cout << "Bubble Sort time: " << (startTime - endTime) << endl << endl;
    
    startTime = clock();
    QuickSort(ptrCopyArray,0,size-1);
    endTime = clock();
    cout << endl << "///////////////////////////////////////////////////////"
         << endl << "////////////////////////Sorted array(QuickSort)///////"
         << endl << "///////////////////////////////////////////////////////"
         << endl;
    PrintArray(ptrCopyArray,size);
    cout << "Quick Sort time: " << (startTime - endTime) << endl << endl;

    delete []ptrArray;
    delete []ptrCopyArray;

    return 0;
}


void PrintArray(int *ptrArray, int size) {
    for(int i=0;i<size;++i){
        cout << ptrArray[i] << ' ';
    }
    cout << endl;
}


void ArrayCopy(int *ptrArray,int *new_ptrArray, int size) {

    for(int i=0;i<size;++i) {
        new_ptrArray[i] = ptrArray[i];
    }
}


void BestArrayFill(int *ptrArray, int size) {

    for(int i=0;i<size;++i){
        ptrArray[i] = i;
    }
}

void WorstArrayFill(int *ptrArray, int size) {

    for(int i=size,j=0;i>0;--i,j++) {
        ptrArray[j] = i;
    }
}

void AvgArrayFill(int *ptrArray, int size) {

    srand(time(NULL));
    for(int i=0;i<size; i++) {
        ptrArray[i] = rand()%100;
    }
}

void SelfArrayFill(int *ptrArray, int size) {

    for(int i=0;i<size;++i) {
        cin >> ptrArray[i];
    }
}



void BubbleSort(int *ptrArray, int size) {

    int temp;
    int sortLine;
    for(int i=0; i < size; ++i) {

        sortLine = size - i;

        for(int j=0; j < sortLine - 1; ++j) {

            if(ptrArray[j] > ptrArray[j+1]) {
                temp = ptrArray[j];
                ptrArray[j] = ptrArray[j+1];
                ptrArray[j+1] = temp;
            }
        }

    }
}


void QuickSort(int *ptrArray,int left,int right) {

    int i = left,
        j = right, 
        midle = ptrArray[(i+j)/2], 
        temp;

	while(i <= j) {

		while (ptrArray[i] < midle) {
            ++i;
        }
		while (ptrArray[j] > midle) {
            --j;
        }

		if (i <= j) {
			temp = ptrArray[i];
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

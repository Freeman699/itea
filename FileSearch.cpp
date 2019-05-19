#include <iostream>
#include <fstream>
#include <cstring>

using std::cout;
using std::endl;


constexpr char Name_Of_File[] = "Search.txt";
constexpr uint32_t MAX_BOOFER_SIZE = 10000;

void SearchLinks(const char str[]) {
    const char searchForHttp[] = "http";
    const char searchForHttps[] = "https";
    
    if(memcmp(str,searchForHttps,strlen(searchForHttps)) == 0) {
        cout << str << endl;
    } else if(memcmp(str,searchForHttp,strlen(searchForHttp)) == 0) {
        cout << str << endl;
    }
}


int main() {

    std::fstream openedFile;
    openedFile.open(Name_Of_File);
    if(!openedFile.is_open()) {
        cout << "Unable to open file." << endl << "Check for a file with the name " << Name_Of_File << " in the program folder." << endl;
        return 0;
    }
    char *boofer = new(std::nothrow) char[MAX_BOOFER_SIZE];
    if(!boofer) {
        cout << "Error! Bad allocation!" << endl;
        openedFile.close();
        return 0;
    }

    while(openedFile.getline(boofer,MAX_BOOFER_SIZE,'\n')) {
        SearchLinks(boofer);
    }

    openedFile.close();
    delete[] boofer;

    return 0;
}
#include <iostream>

#include "Struct.hpp"

using std::cout;
using std::cin;
using std::endl;



void WorkWithHashTableFunc(const char* RawStr) {
    cout << "Functionality is in development. Select another option..." << endl;
}

ListNode *AddInList(ListNode *head) {

    int32_t key;
    ListNode *temp;

    auto EnterKey = [&key]() {
        cout << "Enter your number: ";
        cin >> key;
        cout << endl;
    };

    if(!head) {
        cout << "Your list is empty. Creating a list." << endl;
        EnterKey();
        head = ListAddNode(key,nullptr);
        return head;
    }


    EnterKey();
    uint32_t nodeNum;
    cout << "After which node to add a new item?" << endl;
    ListPrint(head);
    cout << "Enter node num: ";
    cin >> nodeNum;
    cout << endl;
    if(nodeNum == 0) {
        head = ListAddInHead(key,head);
    }
    temp = ListFindNode(nodeNum,head);
    if(!temp) {
        cout << "There is no node with this number!" << endl;
        return head;
    }

    ListAddNode(key,temp);

        return head;
}


ListNode *DeleteFromList(ListNode *head) {

    return head;
}


void WorkWithListFunc(const char* RawStr) {
    
    ListNode *head = nullptr;

    char answer;
    bool SwitchExit = false;
    enum { 
        AddInListEnum = 1 + '0',
        PrintListEnum,
        DeleteFromListEnum,
        AvailableOptionsEnum,
        Exit
    };
    RawStr = R"(
Selected mode: List
Available options:  1 - Add element in list
                    2 - Display the entire list
                    3 - Delete element from list
                    4 - Available options list
                    5 - Exit)";

AvailableOptionsListFuncGotoMark:
    cout << RawStr << endl;

    while (!SwitchExit) {
        cout << "Option:";
        cin >> answer;
        cout << endl;
        switch (answer) {

            case AddInListEnum:
                head = AddInList(head);
                break;

            case PrintListEnum:
                ListPrint(head);
                break;

            case DeleteFromListEnum:
                head = DeleteFromList(head);
                break;

            case AvailableOptionsEnum:
                        goto AvailableOptionsListFuncGotoMark;
                        break;

            case Exit:
                SwitchExit = true;
                break;

            default:
                cout << " Incorrect option! Please retry..." << endl;
                break;
        }
    }

    ListDelete(head);
    head = nullptr;
}



int main() {

    const char* RawStr = R"(
    ╔══╦════╦═══╦╗╔╦══╦════╦══╗╔═══╦══╗╔══╦═══╗
    ║╔═╩═╗╔═╣╔═╗║║║║╔═╩═╗╔═╣╔═╝║╔══╩═╗║║╔═╣╔══╝
    ║╚═╗─║║─║╚═╝║║║║║───║║─║╚═╗║╚══╗─║╚╝║─║╚══╗
    ╚═╗║─║║─║╔╗╔╣║║║║───║║─╚═╗║║╔══╝─║╔╗║─║╔══╝
    ╔═╝║─║║─║║║║║╚╝║╚═╗─║║─╔═╝╠╣╚══╦═╝║║╚═╣╚══╗
    ╚══╝─╚╝─╚╝╚╝╚══╩══╝─╚╝─╚══╩╩═══╩══╝╚══╩═══╝
    
The program for working with data structures
Select the type of structure you need:  1 - List
                                        2 - Hash table (WIP)
                                        3 - Exit
)";

    cout << RawStr;
    char answer;
    enum {LIST = 1 + '0',HASH,EXIT};
SwichAnswerGotoMark:
    answer = 0;
    cin >> answer;


    switch (answer)
    {
    case LIST:
        WorkWithListFunc(RawStr);
        break;
    case HASH:
        WorkWithHashTableFunc(RawStr);
        goto SwichAnswerGotoMark;
        break;
    case EXIT:
        break;
    
    default:
        cout << " Incorrect option! Please retry..." << endl;
        goto SwichAnswerGotoMark;
        break;
    }

    return 0;
}
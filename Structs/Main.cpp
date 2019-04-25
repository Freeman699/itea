#include <iostream>

#include "Struct.hpp"

using std::cout;
using std::cin;
using std::endl;



void WorkWithHashTableFunc(const char* RawStr) {
    cout << "Functionality is in development. Select another option..." << endl;
}


void EnterKey(int32_t &key) {
    cout << "Enter your number: ";
    cin >> key;
    cout << endl;
}


ListNode *AddInList(ListNode *head) {

    int32_t key;

    if(!head) {
        cout << "Your list is empty. Creating a list." << endl;
        EnterKey(key);
        head = ListAddNode(key,nullptr);
        return head;
    }

    EnterKey(key);
    uint32_t nodeNum;
    cout << "After which node add a new one? " << endl;
    ListPrint(head);
    cout << "Enter node num (0 - Before first): ";
    cin >> nodeNum;
    cout << endl;
    if(nodeNum==0) {
        head = ListAddInHead(key,head);
    }else {
        ListNode *temp = ListFindNode(nodeNum,head);
        if(!temp) {
            cout << "There is no node with this number!" << endl;
        }else {
            ListAddNode(key,temp);
        }
    }
        return head;
}


void AddInTail(ListNode *head) {
    
    if(!head) {
        cout << "Your list is empty! Please use \"Add node in list\" option to create list..." << endl;
        return;
    }

    int32_t key;
    EnterKey(key);
    ListAddInTail(key,head);
}


ListNode *DeleteFromList(ListNode *head) {

    if(!head) {
        cout << "Your list is empty!" << endl;
        return nullptr;
    }
    uint32_t nodeNum;
    cout << "Which node you want to delete?" << endl;
    ListPrint(head);
    cout << "Enter node num: ";
    cin >> nodeNum;
    cout << endl;

    if(nodeNum == 1) {
        head = ListDeleteHead(head);
    }else {
        ListNode *temp = ListFindNode(nodeNum,head);
        ListNode *l_temp = ListFindNode(nodeNum-1,head);
        if(!temp) {
            cout << "There is no node with this number!" << endl;
        }else {
            ListDeleteNode(temp,l_temp);
        }
    }
    return head;
}


ListNode *DeleteTailList(ListNode *head) {

    if(!head) {
        cout << "Your list is empty!" << endl;
        return nullptr;
    }

    ListNode *temp = ListDeleteTail(head);
    if(!temp) {
        return temp;
    }
    return head;
}

void FindKeyList(ListNode *head) {

    if(!head) {
        cout << "Your list is empty!" << endl;
        return;
    }

    ListNode *temp;
    int32_t key;
    uint32_t cnt = 0;
    bool keyWasFound = false;
    cout << "Enter the number that you want to find in list: ";
    cin >> key;
    cout << endl;

    while(head) {
        temp = ListFindKey(key,head,cnt);
        if(temp) {
            cout << "Key was found! Node num: " << cnt << endl;
            keyWasFound = true;
            head = temp->nextNode;
        }   
    }

    if(!keyWasFound) {
        cout << "The list does not contain a node with a number " << key << "..." << endl;
    }
}


void WorkWithListFunc(const char* RawStr) {
    
    ListNode *head = nullptr;

    int32_t answer;
    bool SwitchExit = false;
    enum { 
        AddInListEnum = 1,
        AddInTailListEnum,
        PrintListEnum,
        FindListEnum,
        DeleteNodeListEnum,
        DeleteTailListEnum,
        AvailableOptionsEnum,
        ExitEnum
    };

    RawStr = R"(
Selected mode: List
Available options:  1 - Add node in list
                    2 - Add node as last in list
                    3 - Display the entire list
                    *4 - Find the number in list
                    5 - Delete node from list
                    6 - Delete last node
                    7 - Available options list
                    8 - Exit)";

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
            
            case AddInTailListEnum:
                AddInTail(head);
                break;

            case PrintListEnum:
                ListPrint(head);
                break;

            case FindListEnum:
                FindKeyList(head);
                break;

            case DeleteNodeListEnum:
                head = DeleteFromList(head);
                break;
            
            case DeleteTailListEnum:
                head = DeleteTailList(head);
                break;

            case AvailableOptionsEnum:
                        goto AvailableOptionsListFuncGotoMark;
                        break;

            case ExitEnum:
                SwitchExit = true;
                break;

            default:
                cout << " Incorrect option! Please retry..." << endl;
                break;
        }
    }

    ListFree(head);
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
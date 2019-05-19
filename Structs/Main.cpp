#include <iostream>

#include "Struct.hpp"

using std::cout;
using std::cin;
using std::endl;



void WorkWithHashTableFunc(const char* RawStr) {
    cout << "Functionality is in development. Select another option..." << endl;
}


int32_t EnterKey() {
    int32_t key;
    cout << "Enter your key: ";
    cin >> key;
    cout << endl;
    return key;
}


ListNode *AddInHead(ListNode *head) {
    int32_t key = EnterKey();
    return ListAddInHead(key,head);
}


ListNode *AddInTail(ListNode *head) {
    int32_t key = EnterKey();
    if(!head) return ListAddInHead(key,head);
    ListAddInTail(key,head);
    return head;
}


ListNode *InsertInList(ListNode *head) {
    if(!head) {
        cout << "Your list is empty!" << endl;
        return head;
    }

    cout << "Enter the key after wich you want to insert new one." << endl;
    int32_t seekkey = EnterKey();
    ListNode *temp = ListFindKey(seekkey,head);

    if(!temp) {
        cout << "The list does not contain entered key " << seekkey << "..." << endl;
    }else {
        cout << "Enter new key" << endl;
        int32_t newKey = EnterKey();
        if(head == temp) {
            head = ListInsertNode(newKey,head);
        }else {
            ListInsertNode(newKey,temp);
        }
    }

    return head;
}


void FindKey(ListNode *head) {
    if(!head) {
        cout << "Your list is empty!" << endl;
        return;
    }

    uint32_t cnt = 0;
    cout << "Enter the key that you want to find in list" << endl;
    int32_t key = EnterKey();

    while(head) {
        head = ListFindKey(key,head);
        if(head) {
            head = head->nextNode;
            ++cnt;
        }   
    }

    if(cnt == 0) {
        cout << "The list does not contain entered key " << key << "..." << endl;
    }else {
        cout << "Key " << key << " was found! Number of keys: " << cnt << endl;
    }
}


ListNode *DeleteHead(ListNode *head) {
    if(!head) {
        cout << "Your list is empty!" << endl;
        return  head;
    }
    return ListDeleteHead(head);
}


ListNode *DeleteTail(ListNode *head) {
    if(!head) {
        cout << "Your list is empty!" << endl;
        return head;
    }

    if(!ListDeleteTail(head)) {
        head = nullptr;
        return head;
    }

    return head;
}


ListNode *DeleteSpecificKey(ListNode *head) {
    if(!head) {
        cout << "Your list is empty!" << endl;
        return head;
    }
 
    cout << "Enter the key that you want to delete from list." << endl;
    int32_t key = EnterKey();

    ListNode *temp = ListFindKey(key,head);

    if(!temp) {
        cout << "The list does not contain entered key " << key << "..." << endl;
    }else {
        if(temp == head) {
            head = ListDeleteHead(head);
        }else {
            ListDeleteNode(temp,head);
        }
    }

    return head;
}



void WorkWithListFunc(const char* RawStr) {
    
    ListNode *head = nullptr;

    int32_t answer;
    bool SwitchExit = false;
    enum { 
        AddInTailEnum = 1,
        AddInHeadEnum,
        InsertEnum,
        PrintListEnum,
        FindKeyEnum,
        DeleteHeadEnum,
        DeleteTailEnum,
        DeleteSpecificEnum,
        AvailableOptionsEnum,
        ExitEnum = 0
    };

    RawStr = R"(
Selected mode: List
Available options:  1 - Add key as last
                    2 - Add key as first
                    3 - Insert after specific key
                    4 - Display the entire list
                    5 - Find key
                    6 - Delete first key
                    7 - Delete last key
                    8 - Delete specific key
                    9 - Available options
                    0 - Exit)";

AvailableOptionsListFuncGotoMark:
    cout << RawStr << endl;

    while(!SwitchExit) {
        cout << "Option:";
        cin >> answer;
        cout << endl;
        switch (answer) {

            case AddInTailEnum:
                head = AddInTail(head);
                break;
            
            case AddInHeadEnum:
                head = AddInHead(head);
                break;

            case InsertEnum:
                head = InsertInList(head);
                break;

            case PrintListEnum:
                ListPrint(head);
                break;

            case FindKeyEnum:
                FindKey(head);
                break;

            case DeleteHeadEnum:
                head = DeleteHead(head);
                break;
            
            case DeleteTailEnum:
                head = DeleteTail(head);
                break;
            
            case DeleteSpecificEnum:
                head = DeleteSpecificKey(head);
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
    int16_t answer;
    enum {LIST = 1,HASH,EXIT};
SwichAnswerGotoMark:

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
#include <iostream>

#include "Struct.hpp"


bool BadAllocCheckFunc(ListNode *node) {
    if(!node) {
            std::cout << "WARNING! Bad allocation!" << std::endl;
            return false;
        }
    return true;
}


ListNode* ListInsertNode(int32_t enteredKey,ListNode *node) { 
    if(!node) return node;

    ListNode *tempNode = (ListNode*)malloc(sizeof(ListNode));
    if(!BadAllocCheckFunc(tempNode)) return nullptr;

    tempNode->key = enteredKey;
    tempNode->nextNode = node->nextNode;
    node->nextNode = tempNode;

    return tempNode;
}


ListNode *ListAddInHead(int32_t enteredKey,ListNode *head) {

    ListNode *tempNode = (ListNode*)malloc(sizeof(ListNode));
    if(!BadAllocCheckFunc(tempNode)) {
            return nullptr;
    }
    tempNode->key = enteredKey;
    tempNode->nextNode = head;
    head = tempNode;

    return head;
}


ListNode *ListAddInTail(int32_t enteredKey,ListNode *head) {
    if(!head) return ListAddInHead(enteredKey,head);

    while(head->nextNode) {
        head = head->nextNode;
    }

    ListNode *tempNode = (ListNode*)malloc(sizeof(ListNode));
    if(!BadAllocCheckFunc(tempNode)) {
            return nullptr;
    }
    head->nextNode = tempNode;
    tempNode->nextNode = nullptr;
    tempNode->key = enteredKey;

    return tempNode;
}


void ListFree(ListNode *head) {
    if(!head) {
        ;
    }else {
        ListNode *temp;
        while(head) {
            temp = head;
            head = head->nextNode;
            free(temp);
        }
    }
}


void ListPrint(ListNode *head) {   
    if(!head) {
        std::cout << "List is empty!" << std::endl;
        return;
    }
    
    std::cout << "List: ";
    while(head) {
        std::cout << head->key;
        if(head->nextNode) std::cout << ", ";
        head=head->nextNode;
    }
    std::cout << std::endl;
}

ListNode *ListDeleteHead(ListNode *head) {
    if(!head) return head;
    
    ListNode *temp = head->nextNode;
    head->nextNode = nullptr;
    ListFree(head);

    return temp;
}


ListNode *ListDeleteNode(ListNode *node,ListNode *head) {
    if(!node || !head) {
        return nullptr;
    }else if(node == head) {
        return ListDeleteHead(head);
    }
    
    while(head->nextNode != node) {
        head=head->nextNode;
    }
    head->nextNode = node->nextNode;
    node->nextNode = nullptr;
    ListFree(node);
    return head;
}


ListNode *ListDeleteTail(ListNode *head) {
    if(!head) {
        return head;
    }else if(!head->nextNode) {
        ListFree(head);
        return nullptr;
    }

    ListNode *beforeLastNode = head;
    while(head->nextNode) {
        beforeLastNode = head;
        head = head->nextNode;
    }
    ListFree(head);
    beforeLastNode->nextNode = nullptr;

    return beforeLastNode;
}


ListNode *ListFindKey(int32_t seekKey,ListNode *head) {
    if(!head) {
        ;
    }else {
        while(head) {
            if((head->key) == seekKey) {
                return head;
            }
            head = head->nextNode;
        }
    }

    return head;
}
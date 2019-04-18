#include <iostream>

#include "Struct.hpp"


bool BadAllocCheckFunc(ListNode *node) {
    if(!node) {
            std::cout << "WARNING! Bad allocation!" << std::endl;
            return false;
        }
    return true;
}


ListNode* ListAddNode(int32_t enteredKey,ListNode *node) {

    if(!node) {
        ListNode *tempNode;
        tempNode = (ListNode*)malloc(sizeof(ListNode));
        if(!BadAllocCheckFunc(tempNode)) {
            return nullptr;
        }
        tempNode->key = enteredKey;
        tempNode->nextNode = nullptr;
        return tempNode;
    }

    ListNode *tempNode,
             *nextElem = node->nextNode;

    tempNode = (ListNode*)malloc(sizeof(ListNode));
    if(!BadAllocCheckFunc(tempNode)) {
            return nullptr;
    }
    tempNode->key = enteredKey;
    tempNode->nextNode = nextElem;
    node->nextNode = tempNode;

    return tempNode;
}


ListNode *ListAddInHead(int32_t enteredKey,ListNode *head) {

    if(!head) {
        return nullptr;
    }
    ListNode *tempNode;

    tempNode = (ListNode*)malloc(sizeof(ListNode));
    if(!BadAllocCheckFunc(tempNode)) {
            return nullptr;
    }

    tempNode->key = enteredKey;
    tempNode->nextNode = head;
    head = tempNode;

    return head;
}


void ListDelete(ListNode *head) {

    if(!head) {
        return;
    }else if(head->nextNode) {
        ListDelete(head->nextNode);
    }

    free(head);

    return;
}


void ListPrint(ListNode *head) {
    
    if(!head) {
        std::cout << "List is empty!" << std::endl;
    }

    uint32_t numOfNode = 0;
    while(head) {
        std::cout  << ++numOfNode << "# Node" << " Key:" << head->key << std::endl;
        head=head->nextNode;
    }
    std::cout << std::endl;
}

ListNode *ListFindNode(uint32_t nodeNum,ListNode *head) {

    if(!head) {
        return nullptr;
    }

    uint32_t realNodeNum = 0;
    while(head) {
        if( (++realNodeNum) == nodeNum ){
            return head;
        }
        head = head->nextNode;
    }
    return nullptr;
}
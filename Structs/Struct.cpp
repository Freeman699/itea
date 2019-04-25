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

ListNode *ListAddInTail(int32_t enteredKey,ListNode *head) {

    if(!head) {
        return nullptr;
    }

    while(head->nextNode) {
        head = head->nextNode;
    }
    ListNode *tail = ListAddNode(enteredKey,head);

    return tail;
}


void ListFree(ListNode *head) {

    if(!head) {
        return;
    }else if(head->nextNode) {
        ListFree(head->nextNode);
    }

    free(head);

    return;
}


void ListPrint(ListNode *head) {
    
    if(!head) {
        std::cout << "List is empty!" << std::endl;
        return;
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

ListNode *ListDeleteHead(ListNode *head) {

    if(!head) {
        return nullptr;
    }

    ListNode *temp = head->nextNode;
    head->nextNode = nullptr;
    ListFree(head);

    return temp;
}

void ListDeleteNode(ListNode *node,ListNode *l_node) {

    if(!node || !l_node) {
        return;
    }

    l_node->nextNode = node->nextNode;
    node->nextNode = nullptr;
    ListFree(node);
}

ListNode *ListDeleteTail(ListNode *head) {
    
    if(!head) {
        return nullptr;
    }

    if(!head->nextNode) {
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

ListNode *ListFindKey(int32_t enteredKey,ListNode *head,uint32_t &nodeNum) {

    if(!head) {
        return nullptr;
    }

    while(head) {
        ++nodeNum;
        if(head->key == enteredKey) {
            return head;
        }
        head = head->nextNode;
    }

    return nullptr;
}
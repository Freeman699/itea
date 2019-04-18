#pragma once

struct ListNode{
    int32_t key;
    ListNode *nextNode;
};


void ListPrint(ListNode *head);
void ListDelete(ListNode *head);
ListNode *ListAddNode(int32_t enteredKey,ListNode *head);
ListNode *ListFindNode(uint32_t nodeNum,ListNode *head);
ListNode *ListAddInHead(int32_t enteredKey,ListNode *head);

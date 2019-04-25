#pragma once

struct ListNode{
    int32_t key;
    ListNode *nextNode;
};


void ListPrint(ListNode *head);
void ListFree(ListNode *head);
void ListDeleteNode(ListNode *node,ListNode *l_node);
ListNode *ListDeleteTail(ListNode *head);
ListNode *ListDeleteHead(ListNode *head);
ListNode *ListAddNode(int32_t enteredKey,ListNode *head);
ListNode *ListAddInHead(int32_t enteredKey,ListNode *head);
ListNode *ListAddInTail(int32_t enteredKey,ListNode *head);
ListNode *ListFindNode(uint32_t nodeNum,ListNode *head);
ListNode *ListFindKey(int32_t key,ListNode *head,uint32_t &nodeNum);

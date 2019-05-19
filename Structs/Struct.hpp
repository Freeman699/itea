#pragma once

struct ListNode{
    int32_t key;
    ListNode *nextNode;
};


void ListPrint(ListNode *head);
void ListFree(ListNode *head);
ListNode *ListDeleteNode(ListNode *node,ListNode *head);
ListNode *ListDeleteTail(ListNode *head);
ListNode *ListDeleteHead(ListNode *head);
ListNode *ListInsertNode(int32_t enteredKey,ListNode *node);
ListNode *ListAddInHead(int32_t enteredKey,ListNode *head);
ListNode *ListAddInTail(int32_t enteredKey,ListNode *head);
ListNode *ListFindKey(int32_t seekKey,ListNode *head);
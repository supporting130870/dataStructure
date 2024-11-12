//
// Created by Jiwon on 24. 7. 5.
//

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct tagNode {
    ElementType Data;
    struct tagNode* PrevNode;
    struct tagNode* NextNode;
} Node;

Node* DLL_CreateNode(ElementType NewData);
void DLL_DestroyNode(Node* Node);
void DLL_AppendNode(Node** Head, Node* NewNode);
Node* DLL_GetNodeAt(Node* Head, int Location);
void DLL_RemoveNode(Node** Head, Node* Remove);
void DLL_InservAfter(Node* Current, Node* NewNode);
void PrintNode(Node* _Node);
int DLL_GetNodeCount(Node* Head);
#endif //DOUBLYLINKEDLIST_H

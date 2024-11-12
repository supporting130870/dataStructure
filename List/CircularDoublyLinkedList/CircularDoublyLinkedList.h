//
// Created by Jiwon on 24. 7. 8.
//

#ifndef CIRCULARDOUBLYLINKEDLIST_H
#define CIRCULARDOUBLYLINKEDLIST_H

#include <stdlib.h>
#include <stdio.h>

typedef int ElementType;
typedef struct tagNode {
    ElementType Data;
    struct tagNode* PrevNode;
    struct tagNode* NextNode;
} Node;

Node* CDLL_CreateNode(ElementType NewData);
void CDLL_DestroyNode(Node* Node);
void CDLL_AppendNode(Node** Head, Node* NewNode);
void CDLL_InsertAfter(Node* Current, Node* NewNode);
void CDLL_RemoveNode(Node** Head, Node* Remove) ;
Node* CDLL_GetNodeAt(Node* Head, int Location);
int CDLL_GetNodeCount(Node* Head);
void PrintNode(Node* _Node);
#endif //CIRCULARDOUBLYLINKEDLIST_H

//
// Created by Jiwon on 24. 7. 9.
//

#ifndef LINKEDLISTSTACK_H
#define LINKEDLISTSTACK_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tagNode {
    char* Data;
    struct tagNode* NextNode;

}Node;

typedef struct tagLinkedListStack {
    Node* List;
    Node* Top;

}LinkedListStack;


void LSS_CreateStack(LinkedListStack** Stack);
int LSS_IsEmpty(LinkedListStack* Stack);
void LSS_DestroyStack(LinkedListStack* Stack);
Node* LSS_CreateNode(char* NewData);
void LSS_DestroyNode(Node* _Node) ;
void LSS_Push(LinkedListStack* Stack, Node* NewNode);
Node* LSS_Pop(LinkedListStack* Stack);
Node* LSS_Top(LinkedListStack* Stack);
int LSS_GetSize(LinkedListStack* Stack);


#endif //LINKEDLISTSTACK_H

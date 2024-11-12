//
// Created by Jiwon on 24. 7. 9.
//

#include "LinkedListStack.h"

void LSS_CreateStack(LinkedListStack** Stack){
    (*Stack) = (LinkedListStack*)malloc(sizeof(LinkedListStack));
    (*Stack) -> List = NULL;
    (*Stack) -> Top = NULL;
}

void LSS_DestroyStack(LinkedListStack* Stack) {
    while(!LSS_IsEmpty(Stack)) {
        Node* Popped = LSS_Pop(Stack);
        LSS_DestroyNode(Popped);
    }
    free(Stack);

}

Node* LSS_CreateNode(char* NewData) {
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode -> Data = (char*)malloc(strlen(NewData) +1);

    strcpy(NewNode -> Data, NewData);

    NewNode -> NextNode = NULL;
    return NewNode;
}

void LSS_DestroyNode(Node* _Node) {
    free(_Node -> Data);
    free(_Node);
}

void LSS_Push(LinkedListStack* Stack, Node* NewNode) {
    if(Stack -> List == NULL) {
        Stack -> List = NewNode;
    }
    else {
        Stack -> Top -> NextNode = NewNode;
    }
    Stack -> Top = NewNode;
}

Node* LSS_Pop(LinkedListStack* Stack) {
    Node* TopNode = Stack -> Top;

    if(Stack -> List == Stack -> Top) {
        Stack -> List = NULL;
        Stack -> Top = NULL;
    }
    else {
        Node* CurrentTop = Stack -> List;
        while(CurrentTop != NULL && CurrentTop -> NextNode != Stack ->Top) {
            CurrentTop = CurrentTop -> NextNode;
        }
        Stack -> Top = CurrentTop;
        Stack -> Top -> NextNode = NULL;
    }
    return TopNode;
}

Node* LSS_Top(LinkedListStack* Stack) {
    return Stack -> Top;
}

int LSS_GetSize(LinkedListStack* Stack) {
    int Count = 0;
    Node* Current = Stack -> List;

    while(Current != NULL) {
        Current = Current -> NextNode;
        Count++;
    }
    return Count;
}

int LSS_IsEmpty(LinkedListStack* Stack) {
    return(Stack -> List == NULL);
}


//
// Created by Jiwon on 24. 7. 8.
//

#include "CircularDoublyLinkedList.h"

Node* CDLL_CreateNode(ElementType NewData) {
    Node* NewNode = (Node*)malloc(sizeof(Node));

    NewNode -> Data = NewData;
    NewNode -> PrevNode = NULL;
    NewNode -> NextNode = NULL;
    return NewNode;
}

void CDLL_DestroyNode(Node* Node) {
    free(Node);
}

void CDLL_AppendNode(Node** Head, Node* NewNode) {
    if((*Head) == NULL) {
        (*Head) = NewNode;
        (*Head) -> NextNode = NewNode;
        (*Head) -> PrevNode = NewNode;

    }
    else {
        //테일과 헤드 사이에 NewNode를 삽입한다.
        Node* Tail = (*Head) -> PrevNode;
        Tail -> NextNode -> PrevNode = NewNode;
        Tail -> NextNode = NewNode;

        NewNode -> NextNode = *Head;
        NewNode -> PrevNode = Tail; // 새로운 테일의 PrevNode가 기존의 테일을 가르킨다.
    }
}

void CDLL_InsertAfter(Node* Current, Node* NewNode) {
    NewNode -> NextNode = Current -> NextNode;
    NewNode -> PrevNode = Current;

    if(Current -> NextNode != NULL) {
        Current -> NextNode -> PrevNode = NewNode;
        Current -> NextNode = NewNode;
    }
}


void CDLL_RemoveNode(Node** Head, Node* Remove) {
    if(*Head == Remove) {
        (*Head) -> PrevNode -> NextNode = Remove -> NextNode;
        (*Head) -> NextNode -> PrevNode = Remove -> PrevNode;

        (*Head) = Remove -> NextNode;

        Remove -> PrevNode == NULL;
        Remove -> NextNode == NULL;
    }
    else {
        Remove -> PrevNode -> NextNode = Remove -> NextNode;
        Remove -> NextNode -> PrevNode = Remove -> PrevNode;

        Remove -> PrevNode = NULL;
        Remove -> NextNode = NULL;
    }
}

Node* CDLL_GetNodeAt(Node* Head, int Location) {
    Node* Current = Head;
    while(Current != NULL && (--Location >= 0)) {
        Current = Current -> NextNode;
    }
    return Current;
}

int CDLL_GetNodeCount(Node* Head) {
    unsigned int Count = 0;
    Node* Current = Head;
    while(Current != NULL) {
        Current = Current -> NextNode;
        Count++;
        if(Current == Head) {
            break;
        }
    }
    return Count;
}

void PrintNode(Node* _Node) {
    if(_Node -> PrevNode == NULL) {
        printf("Prev: NULL");
    }
    else {
        printf("Prev: %d", _Node ->PrevNode -> Data);
    }
    printf("Current: %d", _Node -> Data);

    if(_Node -> NextNode == NULL) {
        printf("Next: NULL");
    }
    else {
        printf("Next: %d", _Node -> NextNode -> Data);
    }
}
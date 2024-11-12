#include "CircularDoublyLinkedList.h"

int main(void) {
    int i = 0;
    int Count = 0;
    Node* List = NULL;
    Node* NewNode = NULL;
    Node* Current = NULL;

    for(i = 0; i < 5; i ++) {
        NewNode = CDLL_CreateNode(i);
        CDLL_AppendNode(&List, NewNode);
    }
    Count = CDLL_GetNodeCount(List);
    for(i = 0; i < Count; i ++) {
        Current = CDLL_GetNodeAt(List, i);
        printf("List[%d] : %d\n", i, Current -> Data);
    }

    Count = CDLL_GetNodeCount(List);
    for(i = 0; i < Count*2; i ++) {
        Current = CDLL_GetNodeAt(List, i);
        printf("List[%d] : %d\n", i, Current -> Data);
    }
}

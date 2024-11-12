#include "LinkedListStack.h"


int main(void) {
    int i = 0;
    int Count = 0;
    Node* Popped = NULL;
    LinkedListStack* Stack = NULL;

    LSS_CreateStack(&Stack);



    LSS_Push(Stack, LSS_CreateNode("abc"));
    LSS_Push(Stack, LSS_CreateNode("def"));
    LSS_Push(Stack, LSS_CreateNode("efg"));
    LSS_Push(Stack, LSS_CreateNode("hij"));

    Count = LSS_GetSize(Stack);
    printf("Size: %d, Top: %s\n\n", Count, LSS_Top(Stack)->Data);

    for (i = 0; i < Count; i++) {
        if(LSS_IsEmpty(Stack)) {
            break;
        }
        Popped = LSS_Pop(Stack);
        printf("Popped: %s  ", Popped -> Data);
        LSS_DestroyNode(Popped);

        if(!LSS_IsEmpty(Stack)) {
            printf("Current Top: %s\n", LSS_Top(Stack) -> Data);
        }
        else {
            printf("Stack Is Empty\n");
        }
    }

    LSS_DestroyStack(Stack);

    return 0;
}

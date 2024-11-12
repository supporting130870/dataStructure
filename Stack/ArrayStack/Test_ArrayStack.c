#include "ArrayStack.h"

int main(void)
{
    int i = 0;
    ArrayStack* Stack = NULL;
    AS_CreateStack(&Stack, 10);

    AS_Push(Stack, 10);
    AS_Push(Stack, 12);
    AS_Push(Stack, 14);
    AS_Push(Stack, 16);

    printf("Capacity: %d, Size: %d, Top: %d\n", Stack -> Capacity, AS_GetSize(Stack), AS_Top(Stack));

    for(i =  0; i < 4; i ++) {
        if(AS_IsEmpty(Stack)) {
            break;
        }
        printf("Popped: %d, ", AS_Pop(Stack));

        if(!AS_IsEmpty(Stack)) {
            printf("Current Top: %d\n", AS_Top(Stack));
        }
        else {
            printf("Stack Is Empty.\n");
        }
    }
    for (i =0; i < 10; i ++) {
        AS_Push(Stack, 10);
    }
    if(AS_IsFull(Stack)) {
        printf("Stack Is Full");
    }
    AS_DestroyStack(Stack);
    return 0;

}

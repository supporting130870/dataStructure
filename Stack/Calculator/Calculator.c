//
// Created by Jiwon on 24. 7. 12.
//

#include "Calculator.h"


char NUMBER[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.'};

int IsNumber (char Cipher) {
    int i = 0;
    int ArrayLength = sizeof(NUMBER);

    for (i = 0; i < ArrayLength; i++) {
        if(Cipher == NUMBER[i]) {
            return 1;
        }
    }
    return 0;
}

unsigned int GetNextToken (char* Expression, char* Token, int* TYPE) {
    unsigned int i = 0;
    for (i = 0; 0 != Expression[i]; i++) {
        Token[i] = Expression[i];

        if(IsNumber(Expression[i]) == 1) {
            *TYPE = OPERAND;

            if (IsNumber(Expression[i + 1]) != 1) {
                break;
            }
        }
        else {
            *TYPE = Expression[i];
            break;
        }
        Token[++i] = '\0';
        return i;

    }
}

int GetPriority(char Operator, int InStack) {
    int Priority = -1;
    switch(Operator) {
        case LEFT_PARENTHESIS:
            if(InStack) {
                Priority = 3;
            }
        else {
            Priority = 0;
        }
        break;

        case MULTIPLY:
        case DIVIDE:
            Priority = 1;
            break;

        case PLUS:
        case MINUS:
            Priority = 2;
        break;
    }

    return Priority;

}

int IsPrior(char OperatorInStack, char OperatorInToken) {
    return (GetPriority(OperatorInStack, 1) > GetPriority(OperatorInToken, 0));
}

void GetPostfix(char* InfixExpression, char* PostfixExpression) {
    LinkedListStack* Stack = NULL; // 스택 포인터를 NULL로 초기화
    char Token[32];
    int Type = -1;
    unsigned int Position = 0;
    unsigned int Length = strlen(InfixExpression);

    LSS_CreateStack(&Stack);

    while (Position < Length) {
        Position += GetNextToken(&InfixExpression[Position], Token, &Type);

        if (Type == OPERAND) {
            strcat(PostfixExpression, Token);
            strcat(PostfixExpression, " ");
        } else if (Type == RIGHT_PARENTHESIS) {
            while (!LSS_IsEmpty(Stack)) {
                Node* Popped = LSS_Pop(Stack);

                if (Popped->Data[0] == LEFT_PARENTHESIS) {
                    LSS_DestroyNode(Popped);
                    break;
                } else {
                    strcat(PostfixExpression, Popped->Data);
                    strcat(PostfixExpression, " "); // 공백 추가
                    LSS_DestroyNode(Popped);
                }
            }
        } else {
            while (!LSS_IsEmpty(Stack) && !IsPrior(LSS_Top(Stack)->Data[0], Token[0])) {
                Node* Popped = LSS_Pop(Stack);
                if (Popped->Data[0] != LEFT_PARENTHESIS) {
                    strcat(PostfixExpression, Popped->Data);
                    strcat(PostfixExpression, " "); // 공백 추가
                }
                LSS_DestroyNode(Popped);
            }
            LSS_Push(Stack, LSS_CreateNode(Token));
        }
    }

    // 남아있는 연산자를 후위 표현식에 추가
    while (!LSS_IsEmpty(Stack)) {
        Node* Popped = LSS_Pop(Stack);
        if (Popped->Data[0] != LEFT_PARENTHESIS) {
            strcat(PostfixExpression, Popped->Data);
            strcat(PostfixExpression, " "); // 공백 추가
        }
        LSS_DestroyNode(Popped);
    }

    LSS_DestroyStack(Stack);
}

double Calculate(char* PostfixExpression) {
    LinkedListStack* Stack = NULL;
    Node* ResultNode = NULL;
    double Result = 0;
    char Token [32];
    int Type = -1;
    unsigned int Read = 0;
    unsigned int Length = strlen(PostfixExpression);
    LSS_CreateStack(&Stack);
    while(Read < Length) {
        Read += GetNextToken(&PostfixExpression[Read], Token, &Type);
        if(Type == SPACE)
            continue;

        if(Type == OPERAND) {
            Node* NewNode = LSS_CreateNode(Token);
            LSS_Push(Stack, NewNode);
        }
        else {
            char ReusltString[32];
            double Operator1, Operator2, TempResult;
            Node* OperatorNode;

            OperatorNode = LSS_Pop(Stack);
            Operator2 = atof(OperatorNode -> Data);
            LSS_DestroyNode(OperatorNode);

            OperatorNode = LSS_Pop(Stack);
            Operator2 = atof(OperatorNode -> Data);
            LSS_DestroyNode(OperatorNode);

            switch(Type) {
                case PLUS
            }

        }

    }
}
#include "auto.h"

typedef struct st {
    element values[10000];
    int top;
}stack;


element TopS(stack *S){
    if(S->top==9999){
        cout<<"POGRESKA: Stog je prazan"<<endl;
        exit(1);
    }
    return S->values[S->top+1];
};

void PushS(element x, stack *S){
    if(S->top==-1){
        cout<<"POGRESKA: Stog je pun"<<endl;
        exit(1);
    };
    memcpy((void*) &(S->values[S->top]), (void*) &(x), sizeof(element)); //S->values[S->top]=x;
    S->top--;
};

void PopS(stack *S){
    if(S->top==9999){
        cout<<"POGRESKA: Stog je prazan"<<endl;
        exit(1);
    };
    S->top++;
};

int IsEmptyS(stack *S){
    if(S->top==9999) return 1;
    else return 0;
};

stack * InitS(void){
    stack *S;
    S=(stack *)malloc(sizeof(stack));
    S->top=9999;
    return S;
};

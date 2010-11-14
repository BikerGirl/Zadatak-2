#include "auto.h"

typedef struct st{
    element value;
    struct st *next;
}stack;

element TopS(stack *S){
    stack *Top;
    if(S->next==NULL){
        cout<<"POGRESKA: Stog je prazan"<<endl;
        exit(1);
    };
    Top=S->next;
    return Top->value;
};

void PushS(element x, stack *S){
    stack *New;
    New=(stack *)malloc(sizeof(stack));
    memcpy((void*) &(New->value), (void*) &(x), sizeof(element)); //New->value=x;
    New->next=S->next;
    S->next=New;
};

void PopS(stack *S){
    stack *Tmp;
    if(S->next==NULL){
        cout<<"POGRESKA: Stog je prazan"<<endl;
        exit(1);
    };
    Tmp=S->next;
    S->next=Tmp->next;
    free(Tmp);
};

stack * InitS(void){
    stack *S;
    S=(stack *)malloc(sizeof(stack));
    memset ( (void*) &(S->value), 0, sizeof(element) );
    S->next=NULL;
    return S;
};

int IsEmptyS(stack *S){
    if(S->next==NULL) return 1;
    else return 0;
};

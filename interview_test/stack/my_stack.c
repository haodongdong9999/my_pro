#include<stdio.h>
#include<stdlib.h>


typedef struct LNODE
{
    int iData;
    struct LNODE *next;
}_LNODE;

static _LNODE * pstStack; 
void stack_init(_LNODE *pstStack)
{
    
}

_LNODE * stack_push(int iData)
{
    _LNODE * pstList = NULL;
    pstList = (_LNODE *)malloc(sizeof(_LNODE));
    pstList->iData = iData;
    pstList->next = pstStack;
    pstStack = pstList;
}

void print_stack( void )
{
    while( NULL != pstStack )
    {
        printf("%d->",pstStack->iData);
        pstStack = pstStack->next;
    }
    printf("ok\n");

}
void stack_pop(void)
{
    _LNODE *pstList;
    if( NULL!= pstStack)
    {  
        pstList = pstStack;
        pstStack = pstList->next;
        free(pstList);
    }
    
}
int main()
{
    _LNODE * pstStack1;
    int iLoop;
    pstStack1 = pstStack;
    stack_init(pstStack);
    for( iLoop=0;iLoop<5;iLoop++ )
    {
        stack_push(iLoop);  
    }
    print_stack();
    stack_pop();
    print_stack();
}





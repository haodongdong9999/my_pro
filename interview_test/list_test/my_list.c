#include<stdio.h>
#include<stdlib.h>

typedef struct LIST_STR
{
    int iData;
    struct LIST_STR *next;
}_LIST_STR;

_LIST_STR *create_link( void )
{
    _LIST_STR *pstList = NULL;
    pstList = (_LIST_STR *)malloc(sizeof(_LIST_STR));
    if( NULL == pstList )
    {
        printf("error\n");
    }
    pstList->iData = 0 ;
    pstList->next = NULL;
    return pstList;
}

void add_list( _LIST_STR *psthead,int iNum )
{
    _LIST_STR *pstNewList = NULL;
    pstNewList = (_LIST_STR *)malloc(sizeof(_LIST_STR));
    pstNewList->iData = iNum;
    psthead->next = pstNewList;
    pstNewList->next = NULL;
}

void insert_list_tail(_LIST_STR *psthead,int iNum)
{
    _LIST_STR *pstList = NULL;
    _LIST_STR *pstNewList = NULL;
    pstList = psthead;
    pstNewList = (_LIST_STR *)malloc(sizeof(_LIST_STR));
    pstNewList->iData = iNum;
    while( NULL != pstList->next )
    {
        pstList = pstList->next;
    }
    pstList->next = pstNewList;
    pstNewList->next = NULL;
   
}

void insert_list_head(_LIST_STR *psthead,int iNum)
{
    _LIST_STR *pstList = NULL;
    _LIST_STR *pstNewList = NULL;
    pstList = psthead;
    pstNewList = (_LIST_STR *)malloc(sizeof(_LIST_STR));
    pstNewList->iData = iNum;
    pstNewList->next = psthead->next;
    psthead->next = pstNewList;
}
void del_list( _LIST_STR *psthead,int iNum )
{
    _LIST_STR *pstList = NULL;
    _LIST_STR *pstTmp = NULL;
    pstList = psthead;
    while( pstList->iData != iNum && pstList != NULL )
    {
        pstTmp = pstList;
        pstList = pstList->next;
    }
    pstTmp->next = pstList->next;
    free(pstList);
}

void print_list( _LIST_STR *psthead )
{
    while( psthead != NULL )
    {
        printf( "%d-->",psthead->iData );
        psthead = psthead->next;
    }
 printf("ok\n");
}
int main()
{
    _LIST_STR *psthead = NULL;
    _LIST_STR *pstList = NULL;
    int iDelNum;
    int iAddNum;
    int iAddNum2;
    int iLoop;
    psthead = create_link();
    pstList = psthead;
    for( iLoop = 1; iLoop <= 5; iLoop++ )
    {
        add_list(pstList,iLoop);
        pstList = pstList->next;
    }
    print_list(psthead);
    printf("Tell me which num will you insert by head:\n");
    scanf("%d",&iAddNum);
    insert_list_head(psthead,iAddNum);
    printf("insert by head way:\n");
    print_list(psthead);
    printf("Tell me which num will you insert by tail:\n");
    scanf("%d",&iAddNum2);
    insert_list_tail(psthead,iAddNum2);
    printf("insert by tail way:\n");
    print_list(psthead);
    printf("Tell me which num will you delete:\n");
    scanf("%d",&iDelNum);
    del_list(psthead,iDelNum);
    print_list(psthead);

}





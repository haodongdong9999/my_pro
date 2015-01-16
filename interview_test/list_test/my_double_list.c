#include<stdio.h>
#include<stdlib.h>

typedef struct LIST_STR
{
    int iData;
    struct LIST_STR *prev;
    struct LIST_STR *next;
    
}_LIST_STR ;

_LIST_STR * create_list( void )
{
    _LIST_STR *pstListHead = NULL;
    _LIST_STR *pstHead = NULL;
    pstListHead = (_LIST_STR *)malloc(sizeof(_LIST_STR));
    pstHead = pstListHead ;
    if( NULL == pstListHead )
    {
        printf("error\n");
        return ;
    }
    pstListHead->iData= 0 ;
    pstListHead->next = pstListHead;
    pstListHead->prev = pstListHead;
    printf("create list is succ\n");
    return pstHead;
}

_LIST_STR * add_list( _LIST_STR *pstNowList,_LIST_STR *psthead,int iNum )
{
    _LIST_STR * pstNewList = NULL;
    _LIST_STR * pstTmp = NULL;
    pstTmp = pstNowList ;
    pstNewList = (_LIST_STR *)malloc(sizeof(_LIST_STR));
    pstNewList->iData = iNum ;
    pstTmp->next = pstNewList;
    pstNewList->prev = pstTmp;
    pstNewList->next = psthead;
    psthead->prev = pstNewList;
    pstTmp = pstNewList;
    return pstTmp;
}

int num_in_list(_LIST_STR * psthead,int iNum)
{
    
    _LIST_STR *pstTmp = NULL;
    int iRet = 0;
 
    pstTmp = psthead;
    while( pstTmp->next != psthead )
        {
            pstTmp = pstTmp->next;
            if( pstTmp->iData == iNum )
            {
                iRet = 1;
            }
        
        }
  
    return iRet;

}
void del_list_by_num( _LIST_STR * psthead,int iNum )
{
    _LIST_STR *pstTmp = NULL;
    pstTmp = psthead;
    while( pstTmp->iData != iNum && pstTmp->next != psthead )
        {
            pstTmp = pstTmp->next;
        }
    if( num_in_list(psthead,iNum) )
    {
        pstTmp->prev->next = pstTmp->next;
        pstTmp->next->prev = pstTmp->prev;
        free( pstTmp );
        printf("Del num is succ\n");
    }
    else
    {
        printf("The num is not exit\n");
    }
    

}

void insert_num_by_tail(_LIST_STR * psthead,int iNum)
{
    _LIST_STR *pstTmp = NULL;
    _LIST_STR *pstNewList = NULL;
    pstNewList = (_LIST_STR *)malloc(sizeof(_LIST_STR));
    pstNewList->iData = iNum;
    pstTmp = psthead;
    while( pstTmp->next != psthead )
    {
        pstTmp = pstTmp->next;
    }
    pstTmp->next = pstNewList;
    pstNewList->prev = pstTmp;
    pstNewList->next = psthead;
    psthead->prev = pstNewList;
}
int get_allnum_list( _LIST_STR *pstHead)
{
     _LIST_STR * pstTmp = NULL;
    int iAllNum = 0;
    pstTmp = pstHead ;
    while( pstTmp->next != pstHead )
    {
        iAllNum++;
        pstTmp = pstTmp->next;
    }
  return iAllNum;

}
void insert_list_by_num(_LIST_STR * psthead,int iNum,int iNum1)
{
    _LIST_STR *pstTmp = NULL;
    _LIST_STR *pstNewList = NULL;
    int iLoop;
    pstTmp = psthead;
    pstNewList = (_LIST_STR *)malloc(sizeof(_LIST_STR));
    pstNewList->iData = iNum1;
    if( iNum > (get_allnum_list(psthead)))
    {
        printf("ERROR:NUM is too big\n");
        return ;
    }
    for( iLoop = 0; iLoop < iNum ; iLoop++ )
    {
        pstTmp = pstTmp->next;
    }
    pstNewList->next = pstTmp->next;
    pstTmp->next->prev = pstNewList;
    pstTmp->next = pstNewList;
    pstNewList->prev = pstTmp;
     
}
void list_print( _LIST_STR *pstHead )
{
    _LIST_STR * pstTmp = NULL;
    int iAllNum = 0;
    pstTmp = pstHead ;
    while( pstTmp->next != pstHead )
    {
        iAllNum++;
        printf("%d-->",pstTmp->next->iData);
        pstTmp = pstTmp->next;
    }
    printf("ok\n");
    printf("list have %d nums.\n",iAllNum);
}

void del_all_list( _LIST_STR *pstHead )
{
    _LIST_STR *pstTmp = NULL;
    static int iLoop = 1;
    _LIST_STR *pstSaveList = NULL;
    pstTmp = pstHead;
    while( pstTmp->next != pstHead )
    {
        pstSaveList = pstTmp;
        printf("Now del the %d node,num = %d\n",iLoop,pstSaveList->next->iData);
        pstSaveList->iData = 0;
        pstSaveList->prev = pstSaveList;
        pstSaveList->next = pstSaveList->next;
        free(pstSaveList);
        iLoop++;
        pstTmp = pstTmp->next;
       
    }
}
int main()
{

    _LIST_STR *pstHead = NULL;
    _LIST_STR *pstNowList = NULL;
    int iLoop;
    int iDelNum;
    int iInsertNum;
    int iNow,iNow1;
    pstHead = create_list();
    pstNowList = pstHead;
    for( iLoop = 1;iLoop <= 5 ; iLoop++ )
    {
        pstNowList = add_list( pstNowList,pstHead,iLoop );
    }
    list_print( pstHead );
    printf("Which num will you insert:\n");
    scanf("%d",&iInsertNum);
    insert_num_by_tail(pstHead,iInsertNum);
    list_print( pstHead );
    printf("After [] node insert [] :\n");
    scanf("%d%d",&iNow,&iNow1);
    insert_list_by_num(pstHead,iNow,iNow1);
    list_print( pstHead );
    printf("Which num will you delete:\n");
    scanf("%d",&iDelNum);
    del_list_by_num(pstHead,iDelNum);
    list_print( pstHead );
    printf("NOW DEL ALL LIST\n");
    del_all_list(pstHead);
}

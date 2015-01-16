#include<stdio.h>
#include<stdlib.h>

#define MAX_QUEUE 60
typedef struct STR_QUEUE
{
    int *ipMaxNum;
    int QueueHead;
    int QueueTail;
    int AllNum;
}_STR_QUEUE;

void init_queue(_STR_QUEUE *pstQue)
{
      pstQue->ipMaxNum = (int*)malloc( MAX_QUEUE * sizeof(int) );
      pstQue->QueueHead =0;
      pstQue->QueueTail = 0;
      pstQue->AllNum = 0;
}

int is_full_queue(int tail)
{
    return;

}
void in_queue(_STR_QUEUE *pstQue,int iNum)
{
    pstQue->ipMaxNum[pstQue->QueueTail] = iNum;
    pstQue->QueueTail= pstQue->QueueTail + 1;
    if( (pstQue->QueueTail)% MAX_QUEUE == pstQue->QueueHead )
    {
        printf("The queue is full\n");
        return ;
    }
  
     pstQue->AllNum =  pstQue->AllNum + 1;
}

void print_queue(_STR_QUEUE *pstQue)
{
    int iTest = pstQue->QueueHead;
    while( ((iTest + 1)% MAX_QUEUE != pstQue->QueueHead ) && ( pstQue->AllNum > 0))
    {
        printf("%d->",pstQue->ipMaxNum[iTest]);
        iTest = iTest +1;
        pstQue->AllNum = pstQue->AllNum -1 ;
    }
    printf("ok\n");
    printf("the queue have %d nums\n",pstQue->QueueTail - pstQue->QueueHead);
}

int main()
{
    _STR_QUEUE *pstQue;
    int iLoop;
    pstQue = (_STR_QUEUE *)malloc(sizeof(_STR_QUEUE ));
    init_queue(pstQue);
    for(iLoop=1;iLoop<16;iLoop++)
    {
        in_queue(pstQue,iLoop);
    }
   print_queue(pstQue); 
}

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
	/* TODO: put a new process to queue [q] */
	int sizeOfQueue=q->size;
	if(sizeOfQueue< MAX_QUEUE_SIZE && sizeOfQueue>=0)
	{
		q->proc[sizeOfQueue]=proc;
		q->size=sizeOfQueue+1;
	}
}

struct pcb_t * dequeue(struct queue_t * q) {
	/* TODO: return a pcb whose prioprity is the highest
	 * in the queue [q] and remember to remove it from q
	 * */
	 int SizeOfQueue=q->size;
	 if(SizeOfQueue==1)
	 {	
	 	struct pcb_t* temp=q->proc[0];
	 	q->size=0;
	 	q->proc[0]=NULL;
	 	return temp;
	 }
	 else if(SizeOfQueue>1 && SizeOfQueue<=MAX_QUEUE_SIZE)
	 {
	  	uint32_t highest_prior=q->proc[0]->priority;
	  	int position=0;
	  	for(int i=0;i<SizeOfQueue;i++)
	  	{
	  		if(q->proc[i]->priority>highest_prior)
	  		{
	  			position=i;
	  			highest_prior=q->proc[i]->priority;
	  		}
	  	}
	  	struct pcb_t*temp=q->proc[position];
	  	if(position==SizeOfQueue-1)
	  	{
	  		q->proc[position]=NULL;
	  		q->size--;
	  		return temp;
	  	}
	  	else
	  	{
	  		for(int i=position+1;i<SizeOfQueue;i++)
	  		{
	  			q->proc[i-1]=q->proc[i];
	  		}
	  		q->proc[SizeOfQueue-1]=NULL;
	  		q->size=SizeOfQueue-1;
	  		return temp;
	  	}
	 }
	return NULL;
}



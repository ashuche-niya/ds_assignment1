#include <stdlib.h>
#include <stdio.h>
struct deque
{
	int front,rear;
	int capacity;
	int *array;
};


struct deque* createdeque(int cap)// this function create the deque
{
	struct deque* dequeptr;
	dequeptr = (struct deque*)malloc(sizeof(struct deque));
	dequeptr->front= -1;
	dequeptr->rear= -1;
	dequeptr->capacity= cap;
	dequeptr->array=(int*)malloc(sizeof(int)*cap);
	return(dequeptr);
} 

int showcapacity(struct deque* dequeptr)// this fuction show the capacity of the deque
{
	return dequeptr->capacity;
}

int currentsize(struct deque* dequeptr)// this function show the no of elements in the deque
{
	int size=0;
	int f=dequeptr->front;
	int r=dequeptr->rear;
	while(f!=r)
	{
		f++;
		size++;
	}
	return size+1;
}


void insertfront(struct deque* dequeptr,int data)// this function insert the element from the front side
{
	if(currentsize(dequeptr)==dequeptr->capacity)// condition for doubling the capacity when the current size equals to its capacity
	{
		dequeptr->capacity=dequeptr->capacity*2;
		dequeptr->array=(int*)realloc(dequeptr->array,sizeof(int)*dequeptr->capacity);	
	}
	int f=dequeptr->front;
	int r=dequeptr->rear;

	if(dequeptr->front==-1&&dequeptr->rear==-1)
	{
		
		dequeptr->rear=0;
		dequeptr->front =0;
		dequeptr->array[dequeptr->rear]=data;
	}
	else if(dequeptr->front==0)
	{

		dequeptr->rear=currentsize(dequeptr);
		for (int i = currentsize(dequeptr); i>f; i--)
		{
			dequeptr->array[i]=dequeptr->array[i-1];
		}
		dequeptr->array[f]=data;	
	}
	else
	{
		dequeptr->front--;
		dequeptr->array[dequeptr->front]=data;
	}
}


void insertrear(struct deque* dequeptr,int data)// this function insert the element from the rear side
{
	if(currentsize(dequeptr)==dequeptr->capacity)// condition for doubling the capacity when the current size equals to its capacity
	{
		dequeptr->capacity=dequeptr->capacity*2;
		dequeptr->array=(int*)realloc(dequeptr->array,sizeof(int)*dequeptr->capacity);	
	}

	if(dequeptr->front==-1&&dequeptr->rear==-1)
	{
		dequeptr->array[dequeptr->rear+1]=data;
		dequeptr->rear++;
		dequeptr->front =0;
	}
	else
	{
		dequeptr->array[dequeptr->rear+1]=data;
		dequeptr->rear++;
	}
}


void deletefront(struct deque* dequeptr)// this function delete the element from the front side
{


	if(dequeptr->front==-1&&dequeptr->rear==-1)// checking whether deque is empty or not
	{
		printf("queue is empty\n");
	}
	else if(dequeptr->front>dequeptr->rear)// checking whether deque is empty or not
	{
		printf("queue is empty\n");
	}
	else
	{
		printf("deleted element = %d",dequeptr->array[dequeptr->front]);
		dequeptr->front++;
	}



	if (currentsize(dequeptr)==dequeptr->capacity/2)//checking whether the current size is half of the capacity or not 
	{											
		dequeptr->capacity=dequeptr->capacity/2;//if it's half then dividing the capacity by 2
		dequeptr->array=(int*)realloc(dequeptr->array,sizeof(int)*dequeptr->capacity);
	}
}

void deleterear(struct deque* dequeptr)// this function delete element from the rear side
{
	if(dequeptr->front==-1&&dequeptr->rear==-1)// checking whether deque is empty or not
	{
		printf("queue is empty\n");
	}
	else if(dequeptr->front>dequeptr->rear)// checking whether deque is empty or not
	{
		printf("queue is empty\n");
	}
	else
	{
		printf("deleted element = %d",dequeptr->array[dequeptr->rear]);
		dequeptr->rear--;
	}
	if (currentsize(dequeptr)==dequeptr->capacity/2)//checking whether the current size is half of the capacity or not
	{
		dequeptr->capacity=dequeptr->capacity/2;//if it's half then dividing the capacity by 2
		dequeptr->array=(int*)realloc(dequeptr->array,sizeof(int)*dequeptr->capacity);
	}
}

void displaylist(struct deque* dequeptr){// this function display all elements of the deque
	int f=dequeptr->front;
	int r=dequeptr->rear;

	if(dequeptr->front==-1&&dequeptr->rear==-1)// checking whether deque is empty or not
	{
		printf("queue is empty\n");
	}
	else if(dequeptr->front>dequeptr->rear)// checking whether deque is empty or not
	{
		printf("queue is empty\n");
	}
	else
	{
		while(f!=r)
		{
			printf("%d",dequeptr->array[f]);
			printf(" ");
			f++;
		}
		printf("%d",dequeptr->array[f]);
		printf("\n");

	}
}



int main(int argc, char const *argv[])// main function
{
	struct deque *dequenew;
	dequenew =createdeque(10);// creating a deque 
	while(1)
	{
		int n;
		printf("press 1 for insertfront\n");
		printf("press 2 for insertrear\n");
		printf("press 3 for deletefront\n");
		printf("press 4 for deleterear\n");
		printf("press 5 for display list\n");
		printf("press 6 for currentsize of list\n");
		printf("press 7 for capacity of list\n");
		printf("press 8 for exit\n");
		scanf("%d", &n);
		switch(n)
		{
			case 1:
			{
				int data;
				printf("enter value\n");
				scanf("%d", &data);
				insertfront(dequenew,data);// calling insertfront function
				break;
			}

			case 2:
			{
				int data;
				printf("enter value\n");
				scanf("%d", &data);
				insertrear(dequenew,data);// calling insertrear function
				break;
			}

			case 3:
			{
				deletefront(dequenew);// calling deletefront function
				printf("\n");
				break;
			}

			case 4:
			{
				deleterear(dequenew);// calling deletefront function
				printf("\n");
				break;
			}

			case 5:
			{
				displaylist(dequenew);// calling display function to show all elements of deque
				break;
			}
			case 6:
			{
				printf("%d",currentsize(dequenew));// printing no of elements in the deque
				printf("\n");
				break;
			}
			case 7:
			{
				printf("%d",showcapacity(dequenew));// printing present capacity of the deque
				printf("\n");
				break;
			}
			case 8:
			{
				exit(0);
				break;
			}
            default:
            {
                printf("please enter value from the above values\n");
                break;
            }

		}
	} 
	return 0;
}
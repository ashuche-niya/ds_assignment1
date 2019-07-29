#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
bool listsortedornot=false; //to check whether list is sorted or not by name
int maxsize=13;
int* unusedRollNo;
int front =-1,rear=-1;
struct student // struct node to contain student details 
{
	int rollno;
	long phoneno;
	char name[50],dob[50],address[100];
	struct student *next,*previous;
};
struct student *first=NULL;
int numofstudent=1;
struct student* createnode(long phoneno,char name[50],char dob[50],char address[100])/*this finction is to create a new node with given student details*/
{
	struct student* newstudent;
	newstudent=(struct student*)malloc(sizeof(struct student));
	newstudent->phoneno=phoneno;
	newstudent->rollno=100+numofstudent;
	strcpy(newstudent->name,name);
	strcpy(newstudent->dob,dob);
	strcpy(newstudent->address,address);
	newstudent->next=first;
	newstudent->previous=first;
	return newstudent;
}

int listsize()//this function return the list size 
{
	struct student* p=first;
	if (p==NULL)
	{
		return 0;
	}
		int size =1;
		while(p->next!=first)
		{
			size++;
			p=p->next;
		}
	return size;

}


void printdeletedrollnolist() // this function print the deleted roll no. queue
{
	int f=front,r=rear;
	if ((f==-1&&r==-1)||front>rear)
	{
		printf("queue is empty\n");
	}
	else
	{
	while(f<=r)
	{
		printf("%d",unusedRollNo[f]);
		printf(" ");
		f++;
	}		
	}

}
int first_element() { return unusedRollNo[front]; }// this function return the first element of the queue
void insertdeletedrollno(int roll)// this function use to insert unused roll no. in deleted roll no. queue 
{
if (rear == 13 - 1)
printf("Queue Overflow \n"); //condition for the overflow
else { 
 if (front == -1)
 	front = 0;
 	rear = rear + 1;
  	unusedRollNo[rear] =roll;
  }
}


void deletefromqueue()// this function delete element form the unused roll no. queue
{
	if (front == - 1 || front > rear)// condition for underflow
	{
		printf("Queue Underflow \n");
	return ;
} 
else
 { front = front + 1; 
 } 
}

int sizeofqueue(){// this function return size of unused roll no. queue
	int size=0;
	int f=front,r=rear;
	if(f==-1&&r==-1)
		return 0;
	while(f<=r)
	{
		size++;
		f++;
	}

	return size;
}
int studentexist(long phoneno,char name[50]) // this function check whether student with entered details already exist or not
{
	struct student* p=first;
	int i=0;
	while(i<listsize())
	{
			if (strcmp(p->name,name)==0&&phoneno==p->phoneno)
			{
				return 1;
			}
		p=p->next;
		i++;
	}
	return 0;
}
void insert(long phoneno,char name[50],char dob[50],char address[100])// this function insert the new node in the circular list
{																	// with given details	
	if (studentexist(phoneno,name)==1)//condition for checking whether student with entered details already exist or not
	{
		printf("this student already exist\n");
		return;
	}
	else
	{
		int deletehap=0;
		int rollnonew=0;
		int structoflist=0;
		struct student* newstudent;
		newstudent=createnode(phoneno,name,dob,address);//  creating a new node 

		if(first==NULL) // checking whether circuler list empty or not
		{
			first =newstudent;
			first->next = first;
			first->previous = first;
			numofstudent++;
		}
		else if (listsortedornot) // checking whether list is sorted by name our not 
		{							// and if sorted then add new element at the back
			struct student* p=first;
			while(p->next!=first)
			{
				p=p->next;
			}
				p->next=newstudent;
				newstudent->previous=p;
				first->previous=newstudent;	
				newstudent->next=first;		
		}
		else
		{
			if(sizeofqueue()!=0)// checking whether unused roll no. queue is empty or not
			{					// if not empty then taking element from that 
				newstudent->rollno=first_element();
				rollnonew=first_element();
				deletefromqueue();
				deletehap++;
			}
			else
				numofstudent++;
			if (deletehap==0)
			{
			struct student* p=first;
			while(p->next!=first)
			{
				p=p->next;
			}
				p->next=newstudent;
				newstudent->previous=p;
				first->previous=newstudent;	
				newstudent->next=first;	
			}
			else
			{
				if ((first->previous)->rollno==(100+listsize()))
				{
					structoflist++;
				}
				if (structoflist==1)
				{
						struct student* w=first;
						while(w->next!=first)
						{
							w=w->next;
						}
							w->next=newstudent;
							newstudent->previous=w;
							first->previous=newstudent;	
							newstudent->next=first;
				}
				else
				{
					struct student* q=first;
					while(!(q->rollno>rollnonew))
					{
						q=q->next;
					}
					struct student* r=q->previous;
					r->next=newstudent;
					newstudent->previous=r;
					newstudent->next=q;
					q->previous=newstudent;				
				}

			}

		}	
	}

}

void delete123(int rollno)//  this function use to delete the element having roll no given by user from the circular list  
{
	int j=0;
	if(first==NULL)
	{
		printf("list is empty\n");// checking whether list empty or not
		return;
	}
	else
	{
		struct student* p=first;
		while(p->rollno!=rollno)
		{
			p=p->next;
			if(p==first)
			{
				printf("student with this rollno not exist \n");// checking whether student with roll no. exit or not
				j++;
				break;
			}
		}
		if (j==0)
		{
		struct student* q=p->previous;
		q->next=p->next;
		(p->next)->previous=q;
		if (first->rollno==rollno)
		{
			first=first->next;
		}
		free(p);// free the memory of the deleted node 
		insertdeletedrollno(rollno);// inserting the deleted roll no. into unused roll no. queue
		}
	}
}

void print() // this function display all the nodes of circular list
{
	struct student* p=first;
	if(first==NULL)// checking whether list empty or not
	{
		printf("list is empty\n");
	}
	else
	{
		while(p->next!=first)
		{
			printf("%d \n",p->rollno);
			printf("%ld \n",p->phoneno);
			printf("%s",p->name);
			printf("\n");
			printf("%s",p->dob);
			printf("\n");
			printf("%s",p->address);
			printf("\n");
			printf(" \n");
			p=p->next;
		}
			printf("%d \n",p->rollno);
			printf("%ld \n",p->phoneno);
			printf("%s",p->name);
			printf("\n");
			printf("%s",p->dob);
			printf("\n");
			printf("%s",p->address);
			printf("\n");
	}
}
void search(char name[50]) // this fuction search node by given name and if found then display it
{
	struct student* p=first;
	int length=0;
	int i=0;
	char name2[50];
	char name1[50];
	strcpy(name2,name);
	name[strlen(name)-1]='\0';
	name2[(int)strlen(name2)-1]=' ';
	printf("\n");
	while(i<listsize())
	{
		strcpy(name1,p->name);
		if (name1[strlen(name1)-1]==' ')
		{
			if (strcmp(name1,name2)==0)
			{
				printf("%d \n",p->rollno);
				printf("%ld \n",p->phoneno);
				printf("%s",p->name);
				printf("\n");
				printf("%s",p->dob);
				printf("\n");
				printf("%s",p->address);
				printf("\n");
				printf(" \n");
				length++;
			}
		}
		else
		{
			if (strcmp(name1,name)==0)
			{
				printf("%d \n",p->rollno);
				printf("%ld \n",p->phoneno);
				printf("%s",p->name);
				printf("\n");
				printf("%s",p->dob);
				printf("\n");
				printf("%s",p->address);
				printf("\n");
				printf(" \n");
				length++;
			}	
		}

		p=p->next;
		i++;
	}
	if(length==0)// checking whether student with this name exist or not
	{
		printf("student with this name not exist\n");
	}
}
void sortbyname() // this finction sort the list by name 
{
	struct student* temp;
	temp=(struct student*)malloc(sizeof(struct student));
	struct student *p,*q;
	p=first;
    for(int i=0;i<listsize();i++)
    {
   		q=p->next;
        for(int j=i+1;j<listsize();j++)
      	{
       		
	        if(strcmp(p->name,q->name)>0)
	        {
	             strcpy(temp->name,p->name);
	             strcpy(temp->dob,p->dob);
	             strcpy(temp->address,p->address);
	             temp->rollno=p->rollno;
	             temp->phoneno=p->phoneno;

	             strcpy(p->name,q->name);
	             strcpy(p->dob,q->dob);
	             strcpy(p->address,q->address);
	             p->rollno=q->rollno;
	             p->phoneno=q->phoneno;	     


	             strcpy(q->name,temp->name);
	             strcpy(q->dob,temp->dob);
	             strcpy(q->address,temp->address);
	             q->rollno=temp->rollno;
	             q->phoneno=temp->phoneno;

	         }
	         q=q->next;
       	}
       p=p->next;
    }
    listsortedornot=true;// making listsortedornot equals to true means list is sorted 
    printf("sorted successfully\n"); // showing that list is sorted 
}
void modify(int rollno,long phoneno,char name[50],char dob[50],char address[50])//this function use to modify details of the student with given roll no
{

	int j=0;
	if(first==NULL)// checking whether list empty or not
	{
		printf("list is empty\n");
	}
	else
	{
	struct student* p=first;
	while(p->rollno!=rollno)
	{
		p=p->next;
		if(p==first)// checking whether student with this roll no exist or not
		{
			printf("student with this rollno not exist \n");
			j++;
			break;
		}
	}
	if(j==0)
	{
	p->phoneno=phoneno;
	strcpy(p->name,name);
	strcpy(p->dob,dob);
	strcpy(p->address,address);
	}
	}
}

int main(int argc, char const *argv[])// main function
{
	unusedRollNo=(int*)malloc(sizeof(int)*13);// making a queue of size 13 
	long phoneno;
	char ch[200];
	char name[50],dob[50],address[100];
	int n;
    FILE *in_file = fopen("studentdata.csv", "r");// creating pointer to retrieve data from the file studentdata.csv 
          if (in_file == NULL) 
            {   
              printf("Error! Coud not create the file\n"); 
              exit(0);
            } 
    
	while(1){
		printf("press 1 for insert\n");
		printf("press 2 for delete\n");
		printf("press 3 for search\n");
		printf("press 4 for modify\n");
		printf("press 5 for display list\n");
		printf("press 6 for display deleted rollno queue\n");
		printf("press 7 for display sorted list \n");
		printf("press 8 for sort list by name\n");
		printf("press 9 for exit\n");

		scanf("%d", &n);
		switch(n)
		{
			case 1:
			{
				
				printf("enter the row \n");
				int row;
				scanf("%d",&row);// taking row value from the user 
				for (int i = 0; i <=row; ++i)
				{
					fgets(ch ,200,in_file);
				}
    			char* token = strtok(ch, ","); 
 				token = strtok(NULL, ",");
 				strcpy(name,token);
 				token = strtok(NULL, ",");
 				strcpy(dob,token);
 				token = strtok(NULL, "\"");
 				strcpy(address,token);
 				token = strtok(NULL, ",");
 				phoneno=atol(token);
				insert(phoneno,name,dob,address);// calling the insert function 
				rewind(in_file);
				break;
			}
			case 2:
			{
				int rollno;
				printf("enter rollno\n");
				scanf("%d", &rollno);
				delete123(rollno); //calling the delete function and passing roll no with it
				break;
			}

			case 3:
			{
				char username[50];
				printf("enter the name\n");
				getchar();
				fgets(username,50, stdin);
				search(username);//  calling search method
				printf("\n");
				break;
			}
			case 4:
			{
				int rollnum;
				printf("enter rollno whose details you want to modify\n");
				scanf("%d",&rollnum);
				printf("enter new phone no\n");
				scanf("%ld",&phoneno);
				printf("enter new name\n");
				getchar();
				fgets(name,50, stdin);
				name[strlen(name)-1]='\0';
				printf("enter new date of birth\n");
				scanf("%s",dob);
				printf("enter new address\n");
				getchar();
				fgets(address,50, stdin);
				address[strlen(address)-1]='\0';
				modify(rollnum,phoneno,name,dob,address);// calling modify function with new enteries
				break;
			}

			case 5:
			{
				print();// calling print function to display the circular list
				printf("\n");
				break;
			}
			case 6:
			{
				printdeletedrollnolist();// calling printdeletedrollnolist to display unusedrollno queue
				printf("\n");
				break;
			}
			case 7:
			{
				sortbyname();// calling sortbyname function to sort list by name
				print();// calling print function to show the sorted circular list
				printf("\n");
				break;
			}
			case 8:
			{
				sortbyname();// calling sortbyname function to sort list by name
				break;
			}
			case 9:
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
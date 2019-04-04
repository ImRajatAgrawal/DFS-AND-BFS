#define mx 8
void insert_q(int queue[],int *front,int *rear,int key){
	*rear=*rear+1;
	queue[*rear]=key;
	if(*front==-1)
		*front=0;
	return;
}
int delete_q(int queue[],int *front,int *rear){
	int key;
	key=queue[*front];
	if(*front==0 && *rear==0)
		*front=*rear=-1;
	else
		*front=(*front)+1;
	return key;
}
void initialize_q(int queue[],int *front,int *rear){
	*front=-1;
	*rear=-1;
}
int isempty_q(int queue[],int front,int rear){
	if(front==-1)
		return 1;
	return 0;
}
/*int isfull_q(int queue[],int front,int rear){
	if(rear==maxsize-1)
		return 1;
	return 0;
}*/
void display_q(int queue[],int front,int rear){
	int i;
	printf("QUEUE CONTENTS:");
	if(front==-1){
		for(i=front;i<mx*mx-1;i++)
		printf("\t__");
		return;
	}
	else{
		printf("[front]");
		for(i=front;i<=rear;i++)
			printf("%2d",queue[i]);
		printf(" [Rear]");
	printf("\n");
	return;
    }
}


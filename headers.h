//queue definition
struct queue{
		int data[mx];
		int f;
		int r;
	};
	typedef struct queue Q;
//graph definition
struct adjlstnode{
		int vertex;
		struct adjlstnode *link;
	};
	typedef struct adjlstnode gnode;
	typedef gnode *graph;	
/*function declarations*/
void insert_q(int [],int *front,int *rear,int key);
graph insertorderedll(graph first[],int u,int key);
void dfsll(graph first[],int src,char a[],int visited[]);
void bfsll(graph first[],int src,char a[],int visited[],Q *q);
graph createnode();
void displayll(graph first[],int ver);
void display_q(int [],int front,int rear);
int delete_q(int [],int *front,int *rear);
int isfull_q(int [],int front,int rear);
void initialize_q(int [],int *front,int *rear);
void dfs(int adj[][mx],int src,char a[],int ver,int visited[]);
void initialize(int adj[][mx],int v);
void createadj(int adj[][mx],int u,int v,int type);
void bfs(int adj[][mx],int src,char a[],int ver,int visited[],int [],int *,int *);
void initialize_Q(Q *q);
int dequeue(Q *p);
void enqueue(Q *p,int key);
int isempty(Q *p);

//display adjacancy matrix
void displaymatrix(int ver,int adj[][mx]){
	int i,j;
	 printf("\nADJACENCY MATRIX :\n");
	 printf("\n u|v |");
	 for(i=0;i<ver;i++)
		 printf(" %d ",i);
		 printf("\n");
		 for(i=0;i<5*ver;i++)
	 			printf("-");
	 	printf("\n");		
  for(i=0;i<ver;i++){
  	printf("  %d  | ",i);
	 for(j=0;j<ver;j++)
		  printf("%d  ",adj[i][j]);
  	printf("\n");
  }
}
//input src vertex
int source(int ver,char a[],int visited[]){
	int i,src;
		printf("\nAVAILABLE VERTICES:");
		for(i=0;i<ver;i++)
			printf("\n%d %c",i,a[i]);
		do{
			for(i=0;i<ver;i++)
				visited[i]=0;
		   printf("\nEnter source vertex(0-%d):",ver-1);
			scanf("%d",&src);
		}while(src==-1 || src>=ver);
	
	return src;	
} 
//initialize adjacancy matrix
void initialize(int adj[][mx],int v){											
    int i,j;
    for(i=0;i<v;i++)
        for(j=0;j<v;j++)
            adj[i][j]=0;
 }
 //create adjacancy matrix
 void createadj(int adj[][mx],int u,int v,int type){
	 if(type==1)
	 adj[u][v]=1;
	 else if(type==2)
		adj[u][v]=adj[v][u]=1;
	 else
		printf("\nInvalid graph type");
 }
 
//depth first search using adjacancy matrix
 void dfs(int adj[][mx],int src,char a[],int ver,int visited[]){
    int cnt;
    printf("%c ",a[src]);
    visited[src]=1;
    for(cnt=1;cnt<ver;cnt++)
        if(!visited[cnt] && adj[src][cnt]==1)
        dfs(adj,cnt,a,ver,visited);
 }
//breadth first search using adjacancy matrix 
void bfs(int adj[][mx],int src,char a[],int ver,int visited[],int q[],int *front,int *rear){
	int temp,j,w;
	insert_q(q,front,rear,src);
	visited[src]=1;
	while(!(isempty_q(q,*front,*rear))){
		temp=delete_q(q,&*front,&*rear);
		if(visited[temp]==1){
			printf("%c ",a[temp]);
		}			
			for(j=0;j<ver;j++){
				if(adj[temp][j]==1){
						w=j;
					if(visited[w]==0){
						visited[w]=1;
						insert_q(q,front,rear,w);
					}		
				}
				if(*front==ver-1)
					*front=-1;	
			}		
	}
}	

//depth first search using adjacancy list
void dfsll(graph first[],int src,char a[],int visited[]){
	graph w;
	visited[src]=1;
	printf("%c ",a[src]);
	for(w=first[src];w;w=w->link)
		if(!visited[w->vertex])
			dfsll(first,w->vertex,a,visited);
}

//breadth first search using adjacancy list
void bfsll(graph first[],int src,char a[],int visited[],Q *q){
	int temp,w;
	graph p;
	enqueue(q,src);
	visited[src]=1;
	while(!(isempty(q))){
		temp=dequeue(q);
		if(visited[temp]==1)
			printf("%c ",a[temp]);
			for(p=first[temp];p!=NULL;p=p->link){
				w=p->vertex;
				if(visited[w]!=1){
					visited[w]=1;
					enqueue(q,w);
				}
			}
		}									
	return;	
}		
//create a graph node 	
graph createnode(){
	graph neww;
	neww=(graph)malloc(sizeof(gnode));
	if(neww==NULL)
		printf("AVAIL STACK UNDERFLOW");
	return neww;
}
//insert in ordered linked list
graph insertorderedll(graph first[],int u,int key){
	graph neww,temp;
	neww=createnode();
	if(neww==NULL){
		printf("\nNode not allocated,insert failed");
		return first[u];
	}
	neww->vertex=key;
	neww->link=NULL;
	if(first[u]==NULL){
		return neww;
	}
	if(first[u]->vertex>=neww->vertex){
		neww->link=first[u];
		return neww;
	}
	temp=first[u];
	while(temp->link!=NULL && temp->link->vertex<=neww->vertex)
		temp=temp->link;
	neww->link=temp->link;	
	temp->link=neww;
	return first[u];
}		
//display adjacancy list		
void displayll(graph first[],int ver){
	graph neww;
	int i,j;
	printf("\nEDGE|\n");
   for(i=0;i<5.5*ver;i++)
		printf("-");
	for(i=0;i<ver;i++){
		printf("\n  %d ",i);
		neww=first[i];
		for(j=i;j<ver;j++){
			if(first[j]==NULL)
				printf(" ");
			else{
					while(neww!=NULL){
						printf("->");
						printf(" %d ",neww->vertex);
						neww=neww->link;
					}
			}	
		}
	}						
}
//initialize queue
void initialize_Q(Q *q){
	q->f=-1;
	q->r=-1;
	q->data[0]=-1;
}
//insert at front of queue
void enqueue(Q *p,int key){
	if(p->r==-1){
		p->r=p->f=0;
		p->data[p->r]=key;
	}
	else{
		p->r=p->r+1;
		p->data[p->r]=key;
	}	
}
//delete from queue
int dequeue(Q *p){
	int x;
	x=p->data[p->f];
	if(p->r==p->f){
		p->r=-1;
		p->f=-1;
	}
	else
		p->f=p->f+1;
	return x;		
}	
//check if queue is empty
int isempty(Q *p){
	if(p->r==-1)
		return 1;
	return 0;
}

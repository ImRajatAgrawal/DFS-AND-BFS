/***********************************************************************************************

	AUTHOR NAME: RAJAT AGRAWAL
	
	DATE: 14/10/17
	
	STATEMENT : TO STUDY GRAPH DATA STRUCTURE AND 
				DEMONSTRATE SIMULATION OF DIFFERENT TRAVERSALS ON IT-DFS AND BFS 
	
************************************************************************************************/

/*HEADER FILE INCLUSION*/

#include<bits/stdc++.h>
#include"queueadt.h"
#include"headers.h"

using namespace std;

/*PRE-PROCESSOR DIRECTIVES*/
	#define mx 8

 /*DRIVER FUNCTION*/        
int main(){
	int adj[mx][mx],ver,v,u,front=-1,rear=-1;
	char a[41],c;
	int visited[mx],q[mx*mx],i,j,src,type,choice;
	graph first[mx],temp;
	Q q1;
	initialize_Q(&q1);
	srand(time(NULL));
	//generate a char array of random alphabets
	for(i=0;i<40;i++)		
		a[i]='A'+random()%26;
	a[40]=(char)0;
	do{
		ver=0;
		printf("\n______GRAPH TRAVERSALS______");
		printf("\n0.EXIT");
		printf("\n1.EXECUTE USING ADJACENCY MATRIX");
		printf("\n2.EXECUTE USING ADJACENCY LIST");
		cout<<"\nEnter operation to perform:";
		cin>>choice;
		switch(choice){
			case 0:
				printf("\nYou have opted to exit\n");
				exit(0);
			case 1:
				//initialize queue
				initialize_q(q,&front,&rear);
				do{
					printf("\n______EXECUTION USING ADJACENCY MATRIX________");
					printf("\n0.EXIT");
					printf("\n1.PRINT ADJACENCY MATRIX");
					printf("\n2.EXECUTE DFS");
					printf("\n3.EXECUTE BFS");
					cout<<"\nEnter operation to perform:";
					cin>>choice;
					switch(choice){
						case 0:	
							printf("\nYou have opted to exit\n");
							break;
						case 1:
							printf("\nEnter type of graph:");
							printf("\n1.DIRECTED");
							printf("\n2.UN-DIRECTED\n");	
							cout<<"\nEnter your choice:";
							cin>>type;	
							do{
								 printf("\nEnter no of vertices:(<=%d)",mx);
								 scanf("%d",&ver);
							  }while(ver>mx || ver<0);
							  initialize(adj,ver);
							  printf("\nEnter edges as(u,v) & -1 to terminate:");
							  printf("\n\t\tNODE  |  ADJACENT NODE\n");
							  printf("\t   --------------------------------\n");
							  do{
							  	  printf("\t\t  ");
								  scanf("%d%d",&u,&v);
								  if(u==-1 || v==-1)
									  break;
									else if(adj[u][v]==1)
										  printf("\t\tEdge already exists\n");
								  else if((u<ver && v<ver) && (u>-1 || v>-1))
									  createadj(adj,u,v,type);
									else
									  printf("\t\tInvalid edges\n");
								 }while(u<mx && v<mx);
								 
								displaymatrix(ver,adj);
							  break;
						case 2:
							if(ver!=0){
							  src=source(ver,a,visited);
							  printf("\nDEPTH FIRST SEARCH TRAVERSAL:");
							  dfs(adj,src,a,ver,visited);
							 }   
							break;
	 					case 3:
							if(ver!=0){
	 							src=source(ver,a,visited);
 								printf("\nBREADTH FIRST SEARCH TRAVERSAL:");
								bfs(adj,src,a,ver,visited,q,&front,&rear);
	 						}	
	 							break;
						default:
								printf("\nINVALID CHOICE");
					}
					}while(choice>0 && choice<=3);
					break;
				case 2:
					do{
						printf("\n________EXECUTION USING ADJACENCY LIST_______");
						printf("\n0.EXIT");
						printf("\n1.PRINT ADJACENCY LIST");
						printf("\n2.EXECUTE DFS");
						printf("\n3.EXECUTE BFS");
						cout<<"\nEnter operation to perform:";
						cin>>choice;

						switch(choice){
							case 0:	
								printf("\nYou have opted to exit\n");
								break;
							case 1:
								printf("\nEnter type of graph:");
								printf("\n1.DIRECTED");
								printf("\n2.UN-DIRECTED\n");	
								cout<<"Enter your choice:";
								cin>>type;	
								do{
									 printf("\nEnter no of vertices:(<=%d)",mx);
									 scanf("%d",&ver);
								  }while(ver>mx || ver<0);
								  for(i=0;i<ver;i++){
										first[i]=NULL;
									}

								  do{
									  printf("Enter edges as(u,v) & -1 to terminate:");
									  scanf("%d%d",&u,&v);
									  if(u==-1 || v==-1)
										  break;
									  else if(first[u]!=NULL && u<ver && v<ver){
										temp=first[u];
										while(temp!=NULL){
										   if(temp->vertex==v){	
								  		   	 printf("Edge already exists\n");
								  		   	 temp=temp->link;
								  		 	 break;	
										   }													  		
									  	   else{
								  		      temp=temp->link;
								  			  if(temp==NULL){
							  					first[u]=insertorderedll(first,u,v);
							  					if(type==2 && u!=v)
												 first[v]=insertorderedll(first,v,u);	
							  				  }
									  		}	  	
										}
									  }		
									  else if((u<ver && v<ver) && (u>-1 || v>-1)){
										first[u]=insertorderedll(first,u,v);
										if(type==2 && u!=v)
											first[v]=insertorderedll(first,v,u);	
				 						}						 	
										else
										  printf("Invalid edges\n");
									 }while(u<mx && v<mx);
									 printf("\nADJACENCY LIST:\n"); 
									 displayll(first,ver);
								  break;
								case 2:
									if(ver!=0){
									  src=source(ver,a,visited);
									  printf("\nDEPTH FIRST SEARCH TRAVERSAL:");
									  dfsll(first,src,a,visited);
									}   
	 								break;
		 						case 3:
	 									if(ver!=0){
		 									src=source(ver,a,visited);
		 									printf("\nBREADTH FIRST SEARCH TRAVERSAL:");
											bfsll(first,src,a,visited,&q1);   
		 								}
		 							break;
								default:
											printf("\nINVALID CHOICE");
							}
					}while(choice>0 && choice<=3);
					break;
					default:
							printf("\nINVALID CHOICE");				
				}
					
		}while(choice>=0);
	return 0;
}   
 


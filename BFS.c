/*
this is a c code contain BFS
copyright:Rookie Hou
data:2016/12/7
*/
#include<stdio.h>
#include<stdlib.h>
#define max 100
#define INF 999
int grap[max][max];
int d[max];//discover time

//define a simple queue with a max size max
int queue[max]={0};
int head=0;
int tail=0;


void enterqueue(int n){
	queue[tail]=n;
	tail=(tail+1)%max; //when the node reach the end, it move to the front
}
int dequeue(){
	int ret=queue[head];
	head=(head+1)%max;
	return ret; //return the head value
}
int is_empty(){
	if(head==tail)return 1; //we ingore the full case, since it is useless in this function 
	else return 0;
}

BFS(int vetex_num,int s){
	int i,j;
	
	for(i=0;i<vetex_num;i++){
		d[i]=INF;
	}
	d[s]=0;//s is the start point
	enterqueue(s);
	while(!is_empty()){   //loop until queue finish
		int u=dequeue(); //dequeue a vetex from the queue
		for(i=0;i<vetex_num;i++){
			if(grap[u][i]!=0&&d[i]==INF){  //i and j are adjacence meanwhile undiscovered
				d[i]=d[u]+1; //discover i , and set the discover time
				enterqueue(i); //enter all the adjacence vetex into the queue
				printf("vetex %d visit vetex %d\n",u,i);
			}
		}
	}
}

int main(){
	int edge_num,vetex_num;
	FILE *fin  = fopen ("graph.in", "r");
    FILE *fout = fopen ("graph.out", "w");
    
	char buf[10];
	fgets(buf,10,fin);
	edge_num=atoi(buf);
	
	printf("edge_num:%d\n",edge_num);
	fgets(buf,10,fin);
	vetex_num=atoi(buf);

	
	printf("vetex_num:%d\n",vetex_num);
	int i;
	for(i=0;i<edge_num;i++){
		int start,end,weight;//start point,end point and the weight of edge
		fgets(buf,10,fin);
		sscanf(buf,"%d %d %d",&start,&end,&weight);
		
		printf("start:%d end:%d weight:%d\n",start,end,weight);
		grap[start][end]=grap[end][start]=weight;//init the graph matrix no direct
		
	}
	
	BFS(vetex_num,0); //BFS search
	
	for(i=0;i<vetex_num;i++){
		printf("d[%d],%d\n",i,d[i]);
	}
	
	return 0;
} 

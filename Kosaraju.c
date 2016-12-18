/*
discription:use kosaraju method to solve SCC problem
copyright:Rookie Hou
date:2016/12/7
*/
#include<stdio.h>
#include<stdlib.h>
#define max 100
#define INF 999
int grap[max][max];
int grap2[max][max];
int edge_num;
int vertex_num;

int d[max];//discover time
int f[max];//finish time
int color[max];//DFS mark,0 white,1 gray,2 black
int time=0;
int tmp[2*max];//index:finish time,value:vertex ID 

DFS_Visit(int u){
	color[u]=1;//visit the vertex u,mark its color
	time++;
	d[u]=time;
	int i;
	//recursive DFS, visit adjacence unvisited vertex
	//and then visit adjacence unvisited vertex's adjacence unvisited vertex
	//until there are no white vetex
	for(i=0;i<vertex_num;i++){
		if(grap[u][i]!=0&&color[i]==0){ 
			DFS_Visit(i);  
		}
	}
	color[u]=2;//then turn the current vertex into black
	time++;
	f[u]=time;//turn black and finsish, never visit it again
	tmp[f[u]]=u;//finish time as index, vertex ID as value,so we can get the vertex ID directly according to finish time
}
DFS(){
	int i;
	for(i=0;i<vertex_num;i++){
		color[i]=0;       //init the color,all white
	}
	
	for(i=0;i<vertex_num;i++){
		if(color[i]==0){
			DFS_Visit(i);//DFS visit all the vertex
		} 
	}
}

DFS_Visit2(int u){
	color[u]=1;//visit the vertex u,mark its color
	time++;
	d[u]=time;
	int i;
	//recursive DFS, visit adjacence unvisited vertex
	//and then visit adjacence unvisited vertex's adjacence unvisited vertex
	//until there are no white vertex
	for(i=0;i<vertex_num;i++){
		if(grap2[u][i]!=0&&color[i]==0){ 
			DFS_Visit2(i);  
		}
	}
	color[u]=2;//then turn the current vertex into black
	time++;
	f[u]=time;//turn black and finsish, never visit it again
	
	printf("%d ",u);
}

DFS2(){
	int i,j;
	for(i=0;i<vertex_num;i++){
		color[i]=0;       //init the color,all white
	}
	
	for(i=2*vertex_num;i>0;i--){
		j=tmp[i]; //i from the largest finish time to the smallest one,j is vertex ID

		if(j==-1)continue;
         
		if(color[j]==0){
			printf("a strong connected component: ");
			DFS_Visit2(j);//DFS visit all the vertex
			printf("\n");
		} 
	}
}

Kosaraju(){
	DFS();  //DFS graph matrix
	DFS2(); //DFS inverted graph matrix
} 
int main(){

	FILE *fin  = fopen ("graph2.in", "r");
    FILE *fout = fopen ("graph2.out", "w");
    
	char buf[10];
	fgets(buf,10,fin);
	edge_num=atoi(buf);
	
	printf("edge_num:%d\n",edge_num);
	fgets(buf,10,fin);
	vertex_num=atoi(buf);
	
	printf("vetex_num:%d\n",vertex_num);
	int i;
	for(i=0;i<edge_num;i++){
		int start,end,weight;//start point,end point and the weight of edge
		fgets(buf,10,fin);
		sscanf(buf,"%d %d %d",&start,&end,&weight);
		
		printf("start:%d end:%d weight:%d\n",start,end,weight);
		grap[start][end]=weight;//init the graph matrix
		grap2[end][start]=weight;//init the inverted graph matrix
	}
	for(i=0;i<=vertex_num*2;i++){
		tmp[i]=-1;
	}
	Kosaraju();        
	return 0;
} 

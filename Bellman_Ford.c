#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define max 100
#define INF 999
struct edge{
	int u;
	int v;
	int w;
}e[max];
int vertex_num,edge_num;
int d[max];
void relax(int u,int v,int w){
	if(d[v]>d[u]+w)d[v]=d[u]+w;
}
bool Bellman_Ford(int s){
	int i,j;
	
	//Part 1:init 
	for(i=0;i<vertex_num;i++){
		d[i]=INF;
	}
	d[s]=0;
	
	//Part 2:relax
	for(i=0;i<vertex_num;i++){
		for(j=0;j<edge_num;j++){
			relax(e[j].u,e[j].v,e[j].w);
		}
	}
	
	//Part 3:determine whether there exist a negative cirlce
	for(i=0;i<edge_num;i++){
		if(d[e[i].u]>d[e[i].v]+e[i].w)return false;
	}
	return true;
}
int main(){
	int i,j;
	FILE *fin  = fopen ("dij.in", "r");
    FILE *fout = fopen ("dij.out", "w");
    
	char buf[10];
	fgets(buf,10,fin);
	edge_num=atoi(buf);
	printf("edge_num:%d\n",edge_num);
	
	fgets(buf,10,fin);
	vertex_num=atoi(buf);
	printf("vertex_num:%d\n",vertex_num);
	
	for(i=0;i<edge_num;i++){
		int start,end,weight;//start point,end point and the weight of edge
		fgets(buf,10,fin);
		sscanf(buf,"%d %d %d",&e[i].u,&e[i].v,&e[i].w);
		printf("start:%d end:%d weight:%d\n",e[i].u,e[i].v,e[i].w);
	}
	
	Bellman_Ford(0);
	for(i=0;i<vertex_num;i++){
		printf("%d ",d[i]);
	}
	return 0;
} 

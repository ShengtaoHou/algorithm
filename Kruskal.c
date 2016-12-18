/*
desription:use Kruskal method to solve mini span tree problem
copyright:Hou Shengtao
data:2016/12/7
*/
#include<stdio.h>
#include<stdlib.h>
#define max 100
#define INF 999
int edge_num,vertex_num;
int p[max];//record SET ID
struct edge{
	int a;
	int b;
	int w;
}e[max];
void sort(){
	int i,j;
	
	for(i=1;i<edge_num;i++){
		j=i-1;
		int x=e[i].w;
		int aa=e[i].a;
		int bb=e[i].b;
		
		while(j>=0&&e[j].w>x){
			e[j+1].a=e[j].a;
			e[j+1].b=e[j].b;
			e[j+1].w=e[j].w;
			j--;
		}
		e[j+1].a=aa;
		e[j+1].b=bb;
		e[j+1].w=x;	
	}
}
//find() use to find the ancester node
int find(int x){
	return x==p[x]?x:(p[x]=find(p[x])); 
}
//unioned() use to pass the ancester ID to its children
//so that all the mini tree vertex have the same ID
void unioned(int x,int y){
	p[find(x)]=find(y);
}
void Kruskal(){
	//init
	int i,j;
	for(i=0;i<vertex_num;i++){
		p[i]=i;//init the SET ID
	} 
    //sorting according to edge's weight
	sort();
	printf("\n");
	for(i=0,j=0;i<vertex_num&&j<edge_num;i++,j++){
		if(find(e[j].a)==find(e[j].b))continue;//form circle,skip
		
		unioned(e[j].a,e[j].b);
		
		printf("start:%d end:%d weight:%d\n",e[j].a,e[j].b,e[j].w);	
	}
}

int main(){
	
	FILE *fin  = fopen ("mst.in", "r");
    FILE *fout = fopen ("mst.out", "w");
    
	char buf[10];
	fgets(buf,10,fin);
	edge_num=atoi(buf);	
	fgets(buf,10,fin);
	vertex_num=atoi(buf);
	printf("edge_num:%d\n",edge_num);
	printf("vertex_num:%d\n",vertex_num);
	
	int i;
	for(i=0;i<edge_num;i++){
		int start,end,weight;//start point,end point and the weight of edge
		fgets(buf,10,fin);
		sscanf(buf,"%d %d %d",&start,&end,&weight);
		printf("start:%d end:%d weight:%d\n",start,end,weight);
		e[i].a=start;
		e[i].b=end;
		e[i].w=weight;
	}
	Kruskal();

	return 0;
} 

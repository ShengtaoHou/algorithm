#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100
#define INF 999
int graph[max][max];
int vertex_num;
int edge_num;
int d[max];
int v[max];
int p[max];

Dijkstra(int s){
	int i,j,k;
	//init part
	for(i=0;i<vertex_num;i++){
		if(graph[s][i]!=0){ //if vertex i next to source vertex s
			d[i]=graph[s][i];//update the distance array
			p[i]=s;
			v[i]=0;
		}else{
			d[i]=INF;
			p[i]=-1;
			v[i]=0;
		}
		
	}
	d[s]=0;
	p[s]=0;
	v[s]=1;
	
	for(i=1;i<vertex_num;i++){
		int min=INF;
		int u;
		for(j=0;j<vertex_num;j++){  //find the shortest distance vertex form all the unvisited vertex
			if(v[j]==0&&d[j]<min){
				min=d[j];   //mini distance
				u=j;        //mini distance vertex u
			}
		}
		v[u]=1; //visit u
		for(k=0;k<vertex_num;k++){
			if(v[k]==0&&graph[u][k]>0&&d[u]+graph[u][k]<d[k]){ //graph[u][k]>0 make sure u and k are connected;
				d[k]=d[u]+graph[u][k];
				p[k]=u;
			}
		}
	}
	printf("Shortest distance form %d:\n",s);
	for(i=0;i<vertex_num;i++){
		printf("%d ",d[i]);
	} 
	printf("\n\n");
}
void show_path(int s,int d){
	int cur=d;
	int tmp[vertex_num];
	
	int i=0;
	while(cur!=s){
		tmp[i++]=cur;
		cur=p[cur];
	}
	tmp[i]=s;
	printf("The shortest path:\n");
	while(i>0){
		printf("%d ->",tmp[i]);
		i--;
	}
	printf("%d",tmp[i]);
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
		sscanf(buf,"%d %d %d",&start,&end,&weight);
		
		printf("start:%d end:%d weight:%d\n",start,end,weight);
		graph[start][end]=weight;//init the graph matrix no direct
		
	}

	printf("\n");
	printf("Graph matrix:\n");
	for(i=0;i<vertex_num;i++){
		for(j=0;j<vertex_num;j++){
		printf("%-5d",graph[i][j]);
	   }
	   printf("\n");
	}
	printf("\n");
	Dijkstra(0);
	show_path(0,3);
	return 0;
} 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100
#define INF 999
int graph[max][max];
int vertex_num;
int edge_num;
int d[max][max];
int p[max][max];

void Floyd(){
	int i,j,k;
	for(i=0;i<vertex_num;i++){
		for(j=0;j<vertex_num;j++){
			d[i][j]=graph[i][j];
			p[i][j]=-1;
		}
	}
	for(k=0;k<vertex_num;k++){
		for(i=0;i<vertex_num;i++){
			for(j=0;j<vertex_num;j++){
				if(d[i][j]>d[i][k]+d[k][j]){
					d[i][j]=d[i][k]+d[k][j];
					p[i][j]=k;
				}
			}
		}
	}	
	
}
void find_path(int i,int j){
	int k;
	k=p[i][j];
	if(k==-1)return;
	find_path(i,k);
	printf("%d ",k);
	find_path(k,j);
}
void show_path(){
	int i,j;
	printf("Shortest path matrix:\n");
	for(i=0;i<vertex_num;i++){
		for(j=0;j<vertex_num;j++){
			printf("%-5d",d[i][j]);
		}
		printf("\n");
	}
	
	printf("\nPath matrix:\n");
	for(i=0;i<vertex_num;i++){
		for(j=0;j<vertex_num;j++){
			printf("%-5d",p[i][j]);
		}
		printf("\n");
	}
	
	printf("Output:\n");
	for(i=0;i<vertex_num;i++){
		for(j=0;j<vertex_num;j++){
			if(d[i][j]==INF){
				if(i!=j)printf("No path from %d to %d\n",i,j);
			}else{
				printf("Path from %d to %d: ",i,j);
				printf("%d ",i);
				find_path(i,j);
				printf(" %d",j);
				printf(" distance:%-5d\n",d[i][j]);
			}
		}
		printf("\n");
	}
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
		graph[start][end]=weight;//init the graph matrix
		
	}

	printf("\n");
	printf("Graph matrix:\n");
	for(i=0;i<vertex_num;i++){
		for(j=0;j<vertex_num;j++){
			if(graph[i][j]==0)graph[i][j]=INF;
		    printf("%-5d",graph[i][j]);
	   }
	   printf("\n");
	}
	printf("\n");
	Floyd();
	show_path();
	return 0;
} 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define INF 9999;

void Optimal_BST(double p[],int n){
	int i,j,l,r;
	int root[n+1][n+1];
    double e[n+2][n+2];
    double w[n+2][n+2];
	for(i=1;i<=n+1;i++){
		e[i][i-1]=0;
		w[i][i-1]=0;
	}
	
	for(l=1;l<=n;l++){
		for(i=1;   i<=n-l+1;  i++){  // i,j between 1 and n+1，i是左边界，j是右边界 
			j=i+l-1;
			e[i][j]=INF;
			w[i][j]=w[i][j-1]+p[j];	 
			for(r=i;r<=j;r++){
				double temp=e[i][r-1]+e[r+1][j]+w[i][j];
				if(temp<e[i][j]){
					e[i][j]=temp;
					root[i][j]=r;
				}
			}
		}
	}
	printf("\n\ne table\n");	
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i>j)printf("          ");
			else printf("%f  ",e[i][j]);
		}
		printf("\n");
	}
	
	printf("\n\nw table\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i>j)printf("          ");
		    else printf("%f  ",w[i][j]);
		}
		printf("\n");
	}

	printf("\n\nroot table\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i>j)printf("  ");
			else printf("%d ",root[i][j]);
		}
		printf("\n");
	}
}

int main(){
	int n=5;
	double p[6]={-1,0.25,0.2,0.05,0.2,0.3};
	Optimal_BST(p,n);
	return 0;
}

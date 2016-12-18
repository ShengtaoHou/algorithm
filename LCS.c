#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int LCS(char*a,char*b){
	int m=strlen(a);
	int n=strlen(b);
	int L[m][n];
	int i,j;
	char res[20];
	int k=0;
		
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(i==0||j==0){
				L[i][j]=0;      //case 1 	
			}else{
				if(a[i]==b[j]){
					L[i][j]=L[i-1][j-1]+1;  //case 2
				}else{
					L[i][j]=L[i-1][j]>L[i][j-1]?L[i-1][j]:L[i][j-1]; // case 3
				}	
			}
			printf("%d ",L[i][j]);	
		}
		printf("\n");
	}
	
	for(i=m-1,j=n-1;i>=0&&j>=0;){
		if(a[i]==b[j]){
			res[k++]=a[i];
			i--;
			j--;
			
		}else{
			if(L[i-1][j]>L[i][j-1]){
				i--;
			}else{
				j--;
			}	
		}
	}

	printf("\nLCS:");
	for(i=strlen(res)-1;i>=0;i--){
		printf("%c",res[i]);
	}
	printf("\n");
		
	return L[m-1][n-1];	
}
int main(){
	char str1[50];
	char str2[50];
	strcpy(str1,"SIMPLE");
	strcpy(str2,"NAIVE");
	int ret;
	
	ret=LCS(str1,str2);
	printf("length of LCS:%d\n",ret);
	return 0;
}

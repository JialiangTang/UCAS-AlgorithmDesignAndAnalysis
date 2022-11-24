#include<stdio.h>
#include <stdlib.h>
#include<math.h>
#define MAX 1000000
int cmp(const void* a, const void* b) 
{
	return (*(int*)a > *(int*)b)?1:-1;
}

int main(){
	int n,m;
	scanf("%d %d\n",&n,&m);
	int matrix[n*m];
	for(int i=0;i<n*m;i++){
		scanf("%d",&matrix[i]);
	}
	qsort(matrix, n*m, sizeof(matrix[0]), cmp);
	int sum = 0;
//	for(int i=0;i<n*m;i++){
//		printf("%d ",matrix[i]);
//	}
	int count = 0;
	for(int i = n*m-m/2-1;count<n;i-=m/2+1){
		sum += matrix[i];
		//printf("%d ",matrix[i]);
		count++;
	}
	printf("%d\n",sum);
	return 0;
} 


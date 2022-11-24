#include<stdio.h>
#include <stdlib.h>
#include<math.h>
#define MAX 1000000
typedef struct{
		int a;
		int b;
	}wodi;
int cmp(const void* a, const void* b) 
{
	wodi ac = *(wodi*)a;
	wodi bd = *(wodi*)b;
//	if (ac.a != bd.a)
//		return (ac.a > bd.a)?1:-1;
//	else return (ac.b > bd.b)?1:-1; 
	return (ac.a - bd.b - bd.a + ac.b);
}

int main(){
	int n;
	scanf("%d\n",&n);
	
	wodi p[n];
	//int a[n+1],b[n+1];
	for(int i=0;i<n;i++){
		scanf("%d %d",&(p[i].a),&(p[i].b));
	} 
	int explore[n];
	for(int i=0;i<n;i++){
		explore[i] = 0;
	}
	qsort(p, n, sizeof(p[0]), cmp);
	int fair = 0;
	int attack[n];
	for(int i=0;i<n;i++){
		attack[i] = p[i].a - fair;
		fair += p[i].b;
	}
	int min=0x7fffffff;
	for(int i=0;i<n;i++){
		if(attack[i]<min)
		min = attack[i];
	}
	printf("%d\n",min);
	return 0;
} 


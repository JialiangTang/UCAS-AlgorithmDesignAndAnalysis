#include<stdio.h>
#include <stdlib.h>
#define MAX 1000000
//只过了9个测试点，第十个测试点规模n=10000，为过这个测试点，需要同时修改数据结构和算法
//应采用邻接表，并使用优先队列
int main(){
	int n,m,s,t;
	scanf("%d %d %d %d\n",&n,&m,&s,&t);
	int dis[n+1][n+1];
	int dist[n+1],explore[n+1];
	for(int i=1;i<n+1;i++){
		explore[i] = 0;
		dist[i] = 0x7fffffff;
		for(int j=1;j<n+1;j++){
			if(i!=j)
			dis[i][j] = 0x7fffffff;
			if(i==j)
			dis[i][j] = 0; 
		}
	}
	int count = 0;
	dist[s] = 0;
	for(int i=0;i<m;i++){
		int x,y,d;
		scanf("%d %d %d",&x,&y,&d);
		dis[x][y] = d;
	}
	while(count!=n){
		int pos;
		int min = 0x7fffffff;
		for(int i=1;i<n+1;i++){
			if(explore[i] == 0){
				if(dist[i]<min){
					min = dist[i];
					pos = i;
				}
			}
		}
		explore[pos] = 1;
		count++;
		for(int i=1;i<n+1;i++){
			if(explore[i] == 0){
				int minn = 0x7fffffff;
				for(int j=1;j<n+1;j++){
					if(dis[j][i]!=0x7fffffff && explore[j]==1){
						int d = dist[j] + dis[j][i];
						if(d<minn)
						minn = d;
					}
				}
				dist[i] = (dist[i]>minn)?minn:dist[i];
			}
		}
	}
//	for(int i=1;i<n+1;i++){
//		printf("%d ",dist[i]);
//	}
//	for(int i=1;i<n+1;i++){
//		printf("%d ",explore[i]);
//	}
//	for(int i=1;i<n+1;i++){
//		for(int j=1;j<n+1;j++){
//			printf("%d ",dis[i][j]); 
//		}
//	}
	if(dist[t]!=0x7fffffff)
	printf("%d\n",dist[t]);
	else
	printf("-1\n");
	return 0;
} 


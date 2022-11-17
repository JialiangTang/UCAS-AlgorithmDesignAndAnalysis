#include<stdio.h>
int main(){
	int x, y;
	scanf("%d %d",&x,&y);
	int n;
	scanf("%d",&n);
	int nu[n+1],ta[n+1],cost[n+1];
	for(int i=1;i<=n;i++){
		scanf("%d %d %d",&nu[i],&ta[i],&cost[i]);
	}
	
	int dp[x+1][y+1][n+1];//在前k种食品里，满足营养大于等于i,美味大于等于j的最小花费 
	for(int i=1;i<n+1;i++){
		dp[0][0][i] = 0;
	}
	for(int i=0;i<x+1;i++){
		for(int j=0;j<y+1;j++){
			dp[i][j][0] = 0x7fffffff;
		}
	}
	for(int k=1;k<n+1;k++){
		for(int i=0;i<x+1;i++){
			for(int j=0;j<y+1;j++){
				if(nu[k]>=i && ta[k]>=j){
					dp[i][j][k] = (dp[i][j][k-1]>cost[k])?cost[k]:dp[i][j][k-1];
				}else if(nu[k]>=i){
					if(dp[0][j-ta[k]][k-1] == 0x7fffffff){
						dp[i][j][k] = dp[i][j][k-1];
					}else{
						dp[i][j][k] = (dp[i][j][k-1]>(dp[0][j-ta[k]][k-1]+cost[k]))?(dp[0][j-ta[k]][k-1]+cost[k]):dp[i][j][k-1];
					}
				}else if(ta[k]>=j){
					if(dp[i-nu[k]][0][k-1] == 0x7fffffff){
						dp[i][j][k] = dp[i][j][k-1];
					}else{
						dp[i][j][k] = (dp[i][j][k-1]>(dp[i-nu[k]][0][k-1]+cost[k]))?(dp[i-nu[k]][0][k-1]+cost[k]):dp[i][j][k-1];
					}
				}else{
					if(dp[i-nu[k]][j-ta[k]][k-1] == 0x7fffffff){
						dp[i][j][k] = dp[i][j][k-1];
					}else{
						dp[i][j][k] = (dp[i][j][k-1]>(dp[i-nu[k]][0][k-1]+cost[k]))?(dp[i-nu[k]][j-ta[k]][k-1]+cost[k]):dp[i][j][k-1];
					}
				}
			}
		}
	}
	printf("%d\n",dp[x][y][n]);
	return 0;
} 

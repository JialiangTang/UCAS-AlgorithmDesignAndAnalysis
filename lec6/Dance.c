#include<stdio.h>
#include <stdlib.h>
#define MAX 1000000
int main(){
	int n;
	scanf("%d\n",&n);
	int res[n];
	for(int i=0;i<n;i++){
		res[i] = energy();//计算第i行序列的最小能量 
	}
	for(int i=0;i<n;i++){
		printf("%d\n",res[i]);
	}
	return 0;
} 

int num(char c){
	if(c=='U'){
		return 0;
	}
	if(c=='L'){
		return 1;
	}
	if(c=='D'){
		return 2;
	}
	if(c=='R'){
		return 3;
	}
}

//int dp[MAX][4][4];

int energy(){
	int i=0;
	char array[1000000];
	scanf("%s",array);  
	int len = strlen(array); 
	 
	// U:0  L:1  D:2  R:3
	int dp[len+1][4][4];//踩前k个字符消耗的最小能量 ,后两个索引记录左右脚在踩之后的位置 
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			dp[0][i][j] = 1000000; //初始已经确定了左右脚位置，其他位置不可能，1000000代表不可能 
		}
	} 
	dp[0][1][3] = 0;//啥也没踩，耗费为0 
	for(int k=1;k<len+1;k++){
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				if((i!=num(array[k-1]) && j!=num(array[k-1])) || i==j){
					dp[k][i][j] = 1000000;//不可能两脚在一个箭头上，也不可能这步之后没有脚在要踩的箭头上 
				}else{
					//dp[k][i][j]完全由k-1层的同行或者同列的数据决定 
					int min1=1000000,min2=1000000;
					//找来源 
					for(int m=0;m<4;m++){
						if(dp[k-1][i][m] + shift(m,j)+1 < min1){
							min1 = dp[k-1][i][m] + shift(m,j) + 1;
						}
					}//同行 
					for(int l=0;l<4;l++){
						if(dp[k-1][l][j] + shift(l,i)+1 < min2){
							min2 = dp[k-1][l][j] + shift(l,i) + 1;
						}
					}//同列 
					dp[k][i][j] = (min1 < min2)? min1:min2;	
				}
			}
		} 
	}
	//dp已经计算完毕，应该返回最后一步的最小值 
	int min=1000000;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(dp[len][i][j]<min){
				min = dp[len][i][j];
			}
			//printf("%d ",dp[1][i][j]); // 打印某一层dp数组，用于debug 
		}
	}
	return min;
}

int shift(int i,int j){//i->j的能量花费 
	if(i==j){
		return 0;
	}
	if(i==1 && j==3){//L->R
		return 3;
	}
	if(i==1 && j==0){//L->U
		return 2;
	}
	if(i==1 && j==2){//L->D
		return 4;
	}
	if(i==3 && j==1){//R->L
		return 1;
	}
	if(i==3 && j==0){//R->U
		return 3;
	}
	if(i==3 && j==2){//R->D
		return 2;
	}
	if(i==0 && j==1){//U->L
		return 3;
	}
	if(i==0 && j==3){//U->R
		return 2;
	}
	if(i==0 && j==2){//U->D
		return 2;
	}
	if(i==2 && j==1){//D->L
		return 1;
	}
	if(i==2 && j==3){//D->R
		return 3;
	}
	if(i==2 && j==0){//D->U
		return 2;
	}
}

#include<stdio.h>
#include <stdlib.h>
#define MAX 1000000
int main(){
	int n;
	scanf("%d\n",&n);
	int res[n];
	for(int i=0;i<n;i++){
		res[i] = energy();//�����i�����е���С���� 
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
	int dp[len+1][4][4];//��ǰk���ַ����ĵ���С���� ,������������¼���ҽ��ڲ�֮���λ�� 
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			dp[0][i][j] = 1000000; //��ʼ�Ѿ�ȷ�������ҽ�λ�ã�����λ�ò����ܣ�1000000�������� 
		}
	} 
	dp[0][1][3] = 0;//ɶҲû�ȣ��ķ�Ϊ0 
	for(int k=1;k<len+1;k++){
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				if((i!=num(array[k-1]) && j!=num(array[k-1])) || i==j){
					dp[k][i][j] = 1000000;//������������һ����ͷ�ϣ�Ҳ�������ⲽ֮��û�н���Ҫ�ȵļ�ͷ�� 
				}else{
					//dp[k][i][j]��ȫ��k-1���ͬ�л���ͬ�е����ݾ��� 
					int min1=1000000,min2=1000000;
					//����Դ 
					for(int m=0;m<4;m++){
						if(dp[k-1][i][m] + shift(m,j)+1 < min1){
							min1 = dp[k-1][i][m] + shift(m,j) + 1;
						}
					}//ͬ�� 
					for(int l=0;l<4;l++){
						if(dp[k-1][l][j] + shift(l,i)+1 < min2){
							min2 = dp[k-1][l][j] + shift(l,i) + 1;
						}
					}//ͬ�� 
					dp[k][i][j] = (min1 < min2)? min1:min2;	
				}
			}
		} 
	}
	//dp�Ѿ�������ϣ�Ӧ�÷������һ������Сֵ 
	int min=1000000;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(dp[len][i][j]<min){
				min = dp[len][i][j];
			}
			//printf("%d ",dp[1][i][j]); // ��ӡĳһ��dp���飬����debug 
		}
	}
	return min;
}

int shift(int i,int j){//i->j���������� 
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

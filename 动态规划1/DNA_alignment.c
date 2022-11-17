#include<stdio.h>
#include<string.h>
int scores(char x,char y){
	if(x==y){
		return 0;
	}
	if((x=='A'&&(y=='T'||y=='C'||y=='G')) || (y=='A'&&(x=='T'||x=='C'||x=='G'))){
		return 5;
	}
	if((x=='T'&&(y=='C'||y=='G')) || (y=='T'&&(x=='C'||x=='G'))){
		return 5;
	}
	if((x=='C'&&y=='G') || (y=='C'&& x=='G')){
		return 4;
	}
	return 0;
}

int main(){
    char a[1000];
    char b[1000];
    scanf("%s",a);
    scanf("%s",b);
    int m = strlen(a);
    int n = strlen(b);
//    char c;
//	while((c=getchar())!='\n'){
//		*(a+m) = c;
//		m++;
//	}
//	while((c=getchar())!='\n'){
//		*(b+n) = c;
//		n++;
//	}
	int dp[m+1][n+1];
	dp[0][0] = 0;
	for(int i=1;i<=m;i++){
		dp[i][0] = 3*i;
	}
	for(int i=1;i<=n;i++){
		dp[0][i] = 3*i;
	}
	for(int j=1;j<=n;j++){
		for(int i=1;i<=m;i++){
			int min1 = (dp[i-1][j-1] + scores(a[i-1],b[j-1]) < (dp[i-1][j] + 3)) ? dp[i-1][j-1] + scores(a[i-1],b[j-1]):(dp[i-1][j] + 3);
			dp[i][j] = (min1 < (dp[i][j-1]+3)) ? min1:dp[i][j-1]+3;
		} 
	}
	printf("%d\n",dp[m][n]);
    return 0;
}



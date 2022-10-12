#include <stdio.h>
int main(){
	int t;
	scanf("%d",&t);
	//getchar()
	int num[t];
	int i=0,j=0,m=0;
	while(i<t){
		scanf("%d",&num[i++]);
		//getchar();
	} 
	/*for(m=0;m<t;m++){
		printf("%d ",num[m]);
	}*/
	for(j=0;j<t;j++){
		if(prime(num[j])==1){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	return 0;
}


int prime(int num){
	int k=0;
	if(num == 1){
		return 0;
	}
	if(num == 2){
		return 1;
	}
    if(num%2==0){
  		return 0;
    }
	for(k=3;k*k<=num;k+=2){
		if(num%k==0){
			return 0; 
		}
	}
	return 1;
}

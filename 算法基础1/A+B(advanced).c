#include <stdio.h>
#include <string.h>
#define MAXLEN 210
int res[MAXLEN];
int main(){
	int a[MAXLEN],b[MAXLEN];
	int sign_a=1,sign_b=1;
	int i=0,j=0;
	char c;
	while((c=getchar())!='\n'){
		if(c=='-'){
			sign_a=-1;
		}
		else{	
			a[i++]=c-'0';
		}
	}
	while((c=getchar())!='\n'){
		if(c=='-'){
			sign_b=-1;
		}
		else{	
			b[j++]=c-'0';
		}
	}
	int index_a = i-1;
	int index_b = j-1;
	int a_big=big(a,b,index_a,index_b);
	//printf("%d",strlen(a));
	//reverse(a);
	/*for(int m=0;m<strlen(a);m++){
		printf("%d",a[m]);
	}*/
	//reverse(b);
	if((sign_a==1 && sign_b==1)||(sign_a==-1 && sign_b==-1)){
		plus(a,b,sign_a,index_a,index_b);
	}else{
		minus(a,b,a_big,sign_a,index_a,index_b);
	}
	return 0;
} 

/*
void reverse(int* a){
	int b[MAXLEN];
	int len = strlen(a);
	for(int i=0;i<len;i++){
		b[i]=a[len-i-1];
	}
	for(int j=0;j<len;j++){
		a[j]=b[j];
	}
}*/

void plus(int a[],int b[],int sign_a,int index_a,int index_b){
	int c=0,index_res=0,s;
	//printf("%d\n%d\n",index_a,index_b);
	while(index_a>=0 && index_b>=0){
		s=a[index_a] + b[index_b] + c;
		c=(s>=10)?1:0;
		if(s>=10){
			s=s-10;
		}
		
		res[index_res++]=s;
		index_a-=1;
		index_b-=1;
	}
	//printf("%d\n",c);
	while(index_a>=0){
		s=a[index_a--]+c;
		c=(s>=10)?1:0;
		if(s>=10){
			s=s-10;
		}
		
		res[index_res++]=s;
	}
	while(index_b>=0){
		s=b[index_b--]+c;
		c=(s>=10)?1:0;
		if(s>=10){
			s=s-10;
		}
		//c=(s>=10)?1:0;
		res[index_res++]=s;
	}
	if(c!=0){
		res[index_res]=1;
	}else{
		res[index_res]=0;
	}

	while(res[index_res]==0 && index_res>0){
		index_res--;
	}//deal with the front 0,but leave the situation that res is all 0!!!
	if(sign_a<0){
		printf("-");
	}//res is minus??
	while(index_res>=0){
		printf("%d",res[index_res]);
		index_res--;
	}//print the res
	printf("\n");
}

/////1111
/////1000
/////0000
void minus(int a[],int b[],int a_big,int sign_a,int index_a,int index_b){
	if(a_big == 0){//a==b, result is 0
		printf("0\n");
	}else if(a_big == 1){//|a|>|b|
	int c=0,index_res=0,s;
	while(index_a>=0 && index_b>=0){
		s=a[index_a] - b[index_b] + c;
		c=(s<0)?-1:0;
		if(s<0){
			s=s+10;
		}
		
		res[index_res++]=s;
		index_a-=1;
		index_b-=1;
	}
	while(index_a>=0){
		s=a[index_a--]+c;
		c=(s<0)?-1:0;
		if(s<0){
			s=s+10;
		}
		
		res[index_res++]=s;
	}
	index_res--;
	while(res[index_res]==0 && index_res>0){
		index_res--;
	}//deal with the front 0,but leave the situation that res is all 0!!!
	if(sign_a<0){
		printf("-");
	}//res is minus??
	while(index_res>=0){
		printf("%d",res[index_res]);
		index_res--;
	}//print the res
	printf("\n");
	}else if(a_big == -1){//|a|<|b|
	int c=0,index_res=0,s;
	while(index_a>=0 && index_b>=0){
		s=b[index_b] - a[index_a] + c;
		c=(s<0)?-1:0;
		if(s<0){
			s=s+10;
		}
		
		res[index_res++]=s;
		index_a-=1;
		index_b-=1;
	}
	while(index_b>=0){
		s=b[index_b--]+c;
		c=(s<0)?-1:0;
		if(s<0){
			s=s+10;
		}
		
		res[index_res++]=s;
	}
	index_res--;
	while(res[index_res]==0 && index_res>0){
		index_res--;
	}//deal with the front 0,but leave the situation that res is all 0!!!
	if(sign_a>0){
		printf("-");
	}//res is minus??
	while(index_res>=0){
		printf("%d",res[index_res]);
		index_res--;
	}//print the res
	printf("\n");
	}
}

int big(int a[],int b[],int index_a,int index_b){
	int i=0;
	if(index_a>index_b)
		return 1;
	else if(index_a<index_b){
		return -1;
	}else{
		while(i<=index_a){
			if(a[i]>b[i]){
				return 1;
			}else if(a[i]<b[i]){
				return -1;
			}
			i++;
		}
	}
	return 0;
}

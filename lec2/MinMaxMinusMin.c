#include<stdio.h>
//#define MAXLEN 100000
int main(){
    int n,k;
	scanf("%d %d",&n,&k);
	char c;
	int s[n];
	int i=0;
	for(i=0;i<n;i++){
		scanf("%d",&s[i]);
	}
	int f_max[n],f_min[n],b_max[n],b_min[n];
	b_min[n-1]=s[n-1];
	b_max[n-1]=s[n-1];
	i=n-2;
	while(i>=0){
		if(s[i]<b_min[i+1]){
			b_min[i]=s[i];
		} else{
			b_min[i]=b_min[i+1];
		}
		if(s[i]>b_max[i+1]){
			b_max[i]=s[i];
		} else{
			b_max[i]=b_max[i+1];
		}
		i--;
	} 
	
	f_min[0]=s[0];
	f_max[0]=s[0];
	i=1;
	while(i<=n-1){
		if(s[i]<f_min[i-1]){
			f_min[i]=s[i];
		} else{
			f_min[i]=f_min[i-1];
		}
		if(s[i]>f_max[i-1]){
			f_max[i]=s[i];
		} else{
			f_max[i]=f_max[i-1];
		}
		i++;
	} 
	
	//int min_all[n-k+1];
	int min_min;
	int res;
	for(i=0;i<n-k+1;i++){
		if(i==0){
			res=b_max[k]-b_min[k];
			min_min=res;
		}else if(i==n-k){
			res=f_max[n-k-1]-f_min[n-k-1];
			if(res<min_min){
				min_min=res;
			}
		}else{
			int max=(f_max[i-1]>b_max[i+k])?f_max[i-1]:b_max[i+k];
			int min=(f_min[i-1]>b_min[i+k])?b_min[i+k]:f_min[i-1];
			res=max-min;
			if(res<min_min){
				min_min=res;
			}
		}
	}
	
	
	
	/*for(i=0;i<n;i++){
		printf("%d ",f_max[i]);
	}
	for(i=0;i<n;i++){
		printf("%d ",f_min[i]);
	}
	for(i=0;i<n;i++){
		printf("%d ",b_max[i]);
	}
	for(i=0;i<n;i++){
		printf("%d ",b_min[i]);
	}*/
	/*for(i=0;i<n-k+1;i++){
		printf("%d ",min_all[i]);
	}*/
	printf("%d\n",min_min);
	
    return 0;
}

	

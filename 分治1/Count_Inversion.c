#include<stdio.h>

int main(){
    int n;
	scanf("%d",&n);
	long a[n];
	//long temp[n];
	int i=0;
	for(i=0;i<n;i++){
		scanf("%ld",&a[i]);
	}
	int num = countinverse(a,0,n-1,n);
	printf("%d\n",num);
    return 0;
}

int merge_sort(long a[],int i,int j)//归并排序，并计算两个部分之间的强逆序对 
{	
	int num=0;
	long res[j-i+1];
    if(i==j){
    	return 0;
	}else if(i==(j-1)){
		int big = (a[i]>3*a[j]);
		if(a[i]>a[j]){
			long tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}
		return big?1:0;
	}else{
		 
		merge_sort(a,i,(i+j)/2);
		merge_sort(a,(i+j)/2+1,j);//先给两大块分别排好序 
		//再计算强逆序对数量
		int mid = (i+j)/2;
		int left = i;
		int right = mid+1;
		int resdex = 0;
		while(left<=mid && right<=j){
			if(a[left]>3*a[right]){
				num+=mid-left+1;
				right++;
			}else{
				if(left<mid){
					do{
						left++;
					}while(a[left]<=3*a[right] && left<mid+1);
					//直到找到比右边大三倍的（此时left为第一个比右边大三倍的下标）
					//或者找到底了也没找到（此时left为mid+1） 
					num+=mid-left+1;
				}
				right++;
			}
		}
		//最后进行总排序 
		left = i;
		right = mid+1;
		while(left<=mid && right<=j){
			if(a[left]>a[right]){
				res[resdex++] = a[right++];
			}else{
				res[resdex++] = a[left++];
			}
		}
		if(left==mid+1){
			while(right<=j){
				res[resdex++] = a[right++];
			}
		}
		if(right==j+1){
			while(left<=mid){
				res[resdex++] = a[left++];
			}
		}
		resdex=0;
		for(int w=i;w<=j;w++){
			a[w] = res[resdex++];
		}
	}
	return num;
}

int countinverse(long a[],int i,int j,int n){
	if(i==j){
		return 0;
	}else if(j==i+1){
		long ajj = 3*a[j];
		return (a[i]>ajj)?1:0;
	}else{
		int mid = (i+j)/2;
		int num1 = countinverse(a,i,mid,mid-i+1);
		int num2 = countinverse(a,mid+1,j,j-mid);
		int num3 = merge_sort(a,i,j);
		//printf("%d %d %d\n",num1,num2,num3);
		/*for(int w=i;w<=j;w++){
			printf("%d,",a[w]);
		} 
		printf("\n");*/
		//用于debug的输出
		return num1+num2+num3;
	}
}
	


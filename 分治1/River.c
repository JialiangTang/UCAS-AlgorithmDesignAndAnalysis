//思路：二分答案，每次确认mid是不是可以作为跳跃的最短距离，这样一直搜下去，最后得到的是最大的mid，即最大的最短距离 
#include<stdio.h> 
#include<stdlib.h>
int ans;
int l,n,m,max,min,mid;
int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;//这是从小到大排序，若是从大到小改成： return *(int *)b-*(int *)a;
}
int main(){
	scanf("%d %d %d",&l,&n,&m);
	int a[n+2];
	a[0] = 0;
	a[n+1] = l;
	for(int i=1;i<n+1;i++){
		scanf("%d",&a[i]);
	}
	qsort(a,n+2,sizeof(a[0]),cmp);//(数组，需要排序的数字个数，单个数字所占内存大小，比较函数）
	int dis[n+1];
	for(int i=0;i<n+1;i++){
		dis[i] = a[i+1] - a[i];
	}
	//qsort(dis,n+1,sizeof(dis[0]),cmp);
	min = 0x7fffffff;
	max = l;
	for(int i=0;i<n+1;i++){
		if(dis[i]<min){
			min = dis[i];
		}
	}
	/*for(int i=0;i<n+1;i++){
		printf("%d ",dis[i]);
	}//check array dis[]*/
	search_ans(dis);
	printf("%d\n",ans); 
}

void search_ans(int dis[]){
	while(min<=max){
		mid = (max+min)/2;
		if(okk(dis)){
			ans = mid;
			min = mid+1;
		}else{
			max = mid-1;
		}
	}
}

int okk(int dis[]){
	int tot = 0,i = 0, t = 0;
 	while (i<=n)
  	{
        tot = dis[i++];
        while (i <= n && tot < mid)
        {
            tot += dis[i++];
            t++;
        }
        if (t > m) return 0;//合并到大于mid需要的次数大于m，不符合 
  	}//合并较小的距离，直到没有距离段小于mid 
  	if (tot < mid && t == m) return 0; 
	//有可能最后的几段合并起来小于mid，此时若没有合并次数可以用了，那么不符合；
	//否则可以和最后几段之前的一段大于等于mid的段合并 
   	return 1;
}



//˼·�����ִ𰸣�ÿ��ȷ��mid�ǲ��ǿ�����Ϊ��Ծ����̾��룬����һֱ����ȥ�����õ���������mid����������̾��� 
#include<stdio.h> 
#include<stdlib.h>
int ans;
int l,n,m,max,min,mid;
int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;//���Ǵ�С�����������ǴӴ�С�ĳɣ� return *(int *)b-*(int *)a;
}
int main(){
	scanf("%d %d %d",&l,&n,&m);
	int a[n+2];
	a[0] = 0;
	a[n+1] = l;
	for(int i=1;i<n+1;i++){
		scanf("%d",&a[i]);
	}
	qsort(a,n+2,sizeof(a[0]),cmp);//(���飬��Ҫ��������ָ���������������ռ�ڴ��С���ȽϺ�����
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
        if (t > m) return 0;//�ϲ�������mid��Ҫ�Ĵ�������m�������� 
  	}//�ϲ���С�ľ��룬ֱ��û�о����С��mid 
  	if (tot < mid && t == m) return 0; 
	//�п������ļ��κϲ�����С��mid����ʱ��û�кϲ������������ˣ���ô�����ϣ�
	//������Ժ���󼸶�֮ǰ��һ�δ��ڵ���mid�Ķκϲ� 
   	return 1;
}



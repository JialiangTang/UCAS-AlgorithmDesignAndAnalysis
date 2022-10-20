#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct{
	double x;
	double y;
}node;
double distance(node point[],int left, int right)//计算两点的距离的函数 
{
	return sqrt((point[left].x - point[right].x) * (point[left].x - point[right].x) + ((point[left].y - point[right].y) * (point[left].y - point[right].y)));
}
double findmin(node point[],int left,int right){
	double min = 2147483647;
	int i = 0, j = 0, k = 0;//循环变量 
	if (left == right)//只有一个点的时候，返回无穷大 
		return 2147483647;
		
	if (right - left == 1)// 刚好两个点的时候，返回两点的距离即可 
		return distance(point,left, right);
		
	int mid = (left + right) / 2;//大于等于三个点的时候
	double distanceleft = findmin(point,left, mid);//左边递归
	double distanceright = findmin(point,mid + 1, right);//右边递归
	double distanceleftright = (distanceleft>distanceright)?distanceright:distanceleft;//左右两边的最小值 
	//// 
	int temp[right];//储存宽度为d的点 
	for (i = left; i <= right; i++)//找出符合要求的距离mid横坐标小于等于d的点 
	{
		if (fabs(point[mid].x - point[i].x) <= distanceleftright)
			temp[k++] = i;//temp用于暂时储存符合要求的点的序号 
	}
	for (i = 0; i <= k - 1; i++)//纵坐标寻找最短距离 
		for (j = i + 1; j <= k - 1 && j < i + 10; j++)
			if (fabs(point[temp[j]].y - point[temp[i]].y) < distanceleftright)
				distanceleftright = (distanceleftright>distance(point,temp[i],temp[j]))?distance(point,temp[i],temp[j]):distanceleftright;
	return distanceleftright;
	//// 
}

int cmp(const void* a, const void* b)//结构体的快排调用 
{
	node ac = *(node*)a;
	node bd = *(node*)b;
	if (ac.x != bd.x)
		return ac.x - bd.x;//按照x从小到大的顺序排序
	else return ac.y - bd.y;//当x相等的时候，按照y的从大到小的顺序排序 
}

int n;
int main(){
	scanf("%d",&n);
	node point[n];
	int i=0;
	for(i=0;i<n;i++){
		scanf("%lf %lf",&point[i].x,&point[i].y);
	}
	qsort(point, n, sizeof(point[0]), cmp);
	double min = findmin(point,0,n-1);//最短距离，即直径 
	double min_r = min/2;
	printf("%.3lf\n",min_r);//半径
    return 0;
}


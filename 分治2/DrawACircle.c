#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct{
	double x;
	double y;
}node;
double distance(node point[],int left, int right)//��������ľ���ĺ��� 
{
	return sqrt((point[left].x - point[right].x) * (point[left].x - point[right].x) + ((point[left].y - point[right].y) * (point[left].y - point[right].y)));
}
double findmin(node point[],int left,int right){
	double min = 2147483647;
	int i = 0, j = 0, k = 0;//ѭ������ 
	if (left == right)//ֻ��һ�����ʱ�򣬷�������� 
		return 2147483647;
		
	if (right - left == 1)// �պ��������ʱ�򣬷�������ľ��뼴�� 
		return distance(point,left, right);
		
	int mid = (left + right) / 2;//���ڵ����������ʱ��
	double distanceleft = findmin(point,left, mid);//��ߵݹ�
	double distanceright = findmin(point,mid + 1, right);//�ұߵݹ�
	double distanceleftright = (distanceleft>distanceright)?distanceright:distanceleft;//�������ߵ���Сֵ 
	//// 
	int temp[right];//������Ϊd�ĵ� 
	for (i = left; i <= right; i++)//�ҳ�����Ҫ��ľ���mid������С�ڵ���d�ĵ� 
	{
		if (fabs(point[mid].x - point[i].x) <= distanceleftright)
			temp[k++] = i;//temp������ʱ�������Ҫ��ĵ����� 
	}
	for (i = 0; i <= k - 1; i++)//������Ѱ����̾��� 
		for (j = i + 1; j <= k - 1 && j < i + 10; j++)
			if (fabs(point[temp[j]].y - point[temp[i]].y) < distanceleftright)
				distanceleftright = (distanceleftright>distance(point,temp[i],temp[j]))?distance(point,temp[i],temp[j]):distanceleftright;
	return distanceleftright;
	//// 
}

int cmp(const void* a, const void* b)//�ṹ��Ŀ��ŵ��� 
{
	node ac = *(node*)a;
	node bd = *(node*)b;
	if (ac.x != bd.x)
		return ac.x - bd.x;//����x��С�����˳������
	else return ac.y - bd.y;//��x��ȵ�ʱ�򣬰���y�ĴӴ�С��˳������ 
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
	double min = findmin(point,0,n-1);//��̾��룬��ֱ�� 
	double min_r = min/2;
	printf("%.3lf\n",min_r);//�뾶
    return 0;
}


#include <bits/stdc++.h>
#define MAX (5000+7) //7�Ŵ������˹����ŵ�����ɶ��ࣨC�ޣ������º��룬��������ϲ��������
using namespace std; //ǡ��2022���������籭��ϣ���ܲõ����һ���������չ٣� 

//ɨ�跨,ʱ�临�Ӷ�O(n^2)
struct Node{
	int x;
	int y;
	} a[MAX];
int N,M,K,ans;

inline int cmp1(Node a,Node b){return a.x!=b.x ? a.x<b.x : a.y<b.y;}
inline int cmp2(Node a,Node b){return a.y < b.y;}

int main()
{
	scanf("%d%d%d",&N,&M,&K);
	for (int i=1; i<=K; i++)
		scanf("%d%d",&a[i].x,&a[i].y);
	a[++K] = Node{N,0}; 
	a[++K] = Node{N,M};
	a[++K] = Node{0,M}; 
	a[++K] = Node{0,0};//�����ĸ����� 
	sort(a+1,a+K+1,cmp1);//�������������� 
	
	for (int i=1; i<=K; i++)
	{
		int h1 = M, h2 = 0, v = N - a[i].x, fa = 0;
		for (int j=i+1; j<=K; j++)
			if (a[j].y<=h1 && a[j].y>=h2){//���±߽�������� 
				if (v * (h1 - h2) <= ans) 
					break;//��֦,����ѭ���Ѿ������ܸ������ֵ�� 
				ans = max(ans, (h1-h2) * (a[j].x-a[i].x));
				if (a[j].y > a[i].y) 
					h1 = min(h1,a[j].y);
				else 
					h2 = max(h2,a[j].y);
			}
		ans = max(ans, v*(h1 - h2));
		h1 = M, h2 = 0, v = a[i].x, fa = 0;
		for (int j=i-1; j>=1; j--)
			if (a[j].y<=h1 && a[j].y>=h2)
			{
				if (v * (h1 - h2) <= ans) 
					break;//��֦,����ѭ���Ѿ������ܸ������ֵ�� 
				ans = max(ans, (h1-h2) * (a[i].x-a[j].x));
				if (a[j].y > a[i].y) 
					h1 = min(h1,a[j].y);
				else 
					h2 = max(h2,a[j].y);
			} 
		ans = max(ans, v*(h1 - h2));
	}
	
	sort(a+1,a+K+1,cmp2);
	for (int i=1; i<K; i++)
		ans = max(ans, (a[i+1].y-a[i].y) * N);
	printf("%d\n",ans);
}

#include <bits/stdc++.h>
#define MAX (5000+7) //7号代表克里斯蒂亚诺·罗纳尔多（C罗）的球衣号码，他是我最喜欢的球星
using namespace std; //恰逢2022卡塔尔世界杯，希望总裁的最后一舞能完美收官！ 

//扫描法,时间复杂度O(n^2)
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
	a[++K] = Node{0,0};//补上四个顶点 
	sort(a+1,a+K+1,cmp1);//横坐标优先排序 
	
	for (int i=1; i<=K; i++)
	{
		int h1 = M, h2 = 0, v = N - a[i].x, fa = 0;
		for (int j=i+1; j<=K; j++)
			if (a[j].y<=h1 && a[j].y>=h2){//上下边界更新条件 
				if (v * (h1 - h2) <= ans) 
					break;//剪枝,本次循环已经不可能更新最大值了 
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
					break;//剪枝,本次循环已经不可能更新最大值了 
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

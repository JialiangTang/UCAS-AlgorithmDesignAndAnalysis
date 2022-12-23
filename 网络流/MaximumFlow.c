//dinic算法
#include<bits/stdc++.h>
using namespace std;
#define INF 2147483
#define MAXN 30001
int n,m,s,t;
struct node{
	int net,to;
	int w;
}e[MAXN];
int head[MAXN],tot;
void add(int x,int y,int z){
	e[++tot].net=head[x];
	e[tot].to=y;
	e[tot].w=z;
	head[x]=tot;
}
int de[MAXN]; //层次 
int now[MAXN]; 

bool bfs(){
	queue<int>q;
	for(int i=1;i<=n;i++) de[i]=INF;
	q.push(s);
	de[s]=0;
	now[s]=head[s]; //副本 
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=head[x]; i; i=e[i].net){
			int y=e[i].to,z=e[i].w;
			if(z!=0 && de[y]==INF){
				q.push(y);
				now[y]=head[y];
				de[y]=de[x]+1; //更新层次 
				if(y==t) return true;
			}
		}
	}
	return false;
}

int dfs(int x,int ff){ 
	if(x==t) return ff;
	int k,ans=0;
	for(int i=now[x] ;i && ff; i=e[i].net){
		now[x]=i; 
		int y=e[i].to;
		if(e[i].w!=0 && (de[y]==de[x]+1)){
			k=dfs(y,min(ff,e[i].w));  
			if(!k) de[y]=INF;   //剪枝 
			e[i].w-=k;
			e[i^1].w+=k; //更新 
			ans+=k;  
			ff-=k; 
		}
	}
	return ans;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&s,&t);
	tot=1;
	for(int i=0;i<m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
		add(y,x,0);
	}//加边
	int maxx=0;
	while(bfs()!=0) //bfs找多路
		maxx += dfs(s,INF); 
	printf("%d\n",maxx);
	return 0;
}
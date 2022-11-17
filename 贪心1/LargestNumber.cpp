#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define max 100000 
bool cmp(string x,string y)
{
    return (x+y>y+x)?1:0;
}
int main()
{
    int n;
    string num[max];
    scanf("%d\n",&n);
    for(int i=0; i<n; ++i){
        cin>>num[i];
    }
    sort(num,num+n,cmp);
    for(int i=0; i<n; ++i)
        cout<<num[i];
    return 0;
}



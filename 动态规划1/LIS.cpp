#include<iostream>
#include<algorithm>
#define MAX 1000000
using namespace std;
int n,a[MAX+1],l[MAX];

int lis(){
	l[0] = a[0];
	int length = 1;
	for(int i=1;i<n;i++){
		if(l[length-1]<a[i]){
			l[length++] = a[i];
		}else{
			*lower_bound(l,l+length,a[i]) = a[i];
		}
	}
	return length;
} 

int main(){
	cin >> n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<< lis() << endl;
}

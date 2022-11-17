#include <stdio.h> 
#include <string.h>
#define MAXLEN 10000
int main(){
	char s[MAXLEN];
	char cin;
	int  j = 0;
	while((cin=getchar())!=EOF){
		if((cin>='0' && cin<='9')||(cin>='A' && cin<='Z')||(cin>='a' && cin<='z')){
			s[j++] = cin;
		}
	}
	j--;
	//int len = strlen(s);
	int i = 0;
	int flag = 0;
	for(;i<=j;i++,j--){
		if((s[i] == s[j]) || (s[i]>='A' && s[i]<='Z' && s[j] == s[i] + 'a'-'A') || (s[j]>='A' && s[j]<='Z' && s[i] == s[j] + 'a'-'A'))
		;
		else{
			flag = 1;
		}
	}
	printf(flag?"NO\n":"YES\n");
	return 0;
}
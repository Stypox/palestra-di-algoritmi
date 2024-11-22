#include<bits/stdc++.h>

using namespace std;

char remap['z'-'a'+1];

void gen(){
	const char row1[] = "qwertyuiop";
	for(int a=1; a<strlen(row1); a++){
		remap[row1[a-1]-'a']=row1[a];
	}
	
	const char row2[] = "asdfghjkl";
	for(int a=1; a<strlen(row2); a++){
		remap[row2[a-1]-'a']=row2[a];
	}
	
	const char row3[] = "zxcvbnm";
	for(int a=1; a<strlen(row3); a++){
		remap[row3[a-1]-'a']=row3[a];
	}
}

int main(){
	gen();
	int n;
	string s;
	cin>>n>>s;
	for(int a=0; a<n; a++){
		cout<<remap[s[a]-'a'];
	}
	
}

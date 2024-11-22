#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;

int64_t mod = 1000000007;

int main(){
	string s;
	cin>>s;
	int64_t pow=1;
	int64_t val=0;
	for(int a=s.size()-1; a>=0;a--){
		val = (val+((s[a]-'a'+1)*pow))%mod;
		pow = (pow*26)%mod;
	}
	cout<<val-1<<endl;
}

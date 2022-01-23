#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int start, end;
	cin>>start>>end;
	for(int a=1; a<n; a++){
		int start2, end2;
		cin>>start2>>end2;
		if(max(start, start2)>min(end, end2)){
			cout<<"NO"<<endl;
			return 0;
		}
		start=start2;
		end=end2;
	}
	cout<<"YES"<<endl;
}

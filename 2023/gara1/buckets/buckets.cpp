#include<bits/stdc++.h>
using namespace std;
int arra[100000];
int main(){
	int n;
	
	cin>>n;
	for(int a=0;a<n;a++)
	{
		cin>>arra[a];
	}
	sort(arra, arra+n);
	for(int a=0;a<n-1;a++)
	{
		if(arra[a]==arra[a+1]){
			cout<<"Impossible"<<endl;
			return 0;
		}
	}
	cout<<"Ok"<<endl;
	return 0;
}
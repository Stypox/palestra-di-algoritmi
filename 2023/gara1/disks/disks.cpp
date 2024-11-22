#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int a, b, t;
	
	cin >> a >> b >> t;
	int giorni = t/24;
	
	int ore = giorni * (b-a);
	t %= 24;
	t -= (24-b);
	if(t >= a) ore += t-a;
	
	cout << ore << endl;
	
	return 0;
}
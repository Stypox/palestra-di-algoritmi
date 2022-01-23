#include<bits/stdc++.h>
#include<stdint.h>
//idea generale, non funziona
using namespace std;
int64_t cost[200001];

int64_t n,k;

int64_t low(int64_t val){
	if(val==0)
	 	return 0;
	int64_t valid, start, end, cur;
	valid=start=end=cur=0;
	
	while(end<n){
		if(cur+cost[end]<val){
			cur+=cost[end++];
			continue;
		}
		valid+=end-start;
		cur-=cost[start++];
	}
	
	return valid+(end-start)*(end-start+1)/2;
}

void find(int64_t val, int pos){
	int64_t valid, start, end, cur;
	valid=start=end=cur=0;
	
	while(end<n){
		if(cur+cost[end]<=val){
			cur+=cost[end++];
			continue;
		} 
		if(cur==val){
			pos--;
			if(pos==0){
				cout<<start<<" "<<end-1<<endl;
				return;
			}
		}
		cur-=cost[start++];
	}
	cout<<start<<" "<<end-1<<endl;
	return;
}

int64_t bsearch(int64_t min, int64_t max, int k){//max escluso
	if(min+1<=max){
		return min;
	}
	int64_t mid=(min+max)/2;
	//cout<<mid<<": "<<low(mid)<<endl;
	if(low(mid)>=k){
		return bsearch(min, mid, k);
	}else{
		return bsearch(mid, max, k);
	}
}

int main(){
	
	cin>>n>>k;
	int64_t sum=0;
	for(int a=0;a<n;a++){
		cin>>cost[a];
		sum+=cost[a];
	}
	int value=bsearch(0, sum+1, k);
	/*printf("value: %d\n", value);
	printf("find: %d %d\n", value, k-low(value));*/
	find(value, k-low(value));
}

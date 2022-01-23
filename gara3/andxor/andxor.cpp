#include<bits/stdc++.h>

using namespace std;

int bit[20];
int bitxor[20];
int arr[200000];

void add(int tmp){
	int h=0;
	int cur=tmp;
	while(cur!=0){
		if(cur%2==1){
			bit[h]++;
			bitxor[h]^=tmp;
		}
		cur>>=1;
		h++;
	}
}

void sub(int tmp){
	int h=0;
	int cur = tmp;
	while(cur!=0){
		if(cur%2==1){
			bit[h]--;
			bitxor[h]^=tmp;
		}
		cur>>=1;
		h++;
	}
}

void resp(){
	int maxi=0;
	for(int h=0; h<20; h++){
		if(bitxor[h]!=0){
			maxi = max(maxi, bit[h]);
		}else{
			maxi = max(maxi, bit[h]-1);
		}
	}
	cout<<maxi<<endl;

}

void print(){
	for(int a=2; a>=0; a--){
		printf("(%d, %d)", bit[a], bitxor[a]);
	}
	printf("\n");
}

int main(){
	int n, q;
	cin>>n>>q;
	for(int a=0; a<n; a++){
		cin>>arr[a];
		add(arr[a]);
	}
	resp();
	for(int a=0; a<q; a++){
		int pos, tmp;
		cin>>pos>>tmp;
		pos--;
		sub(arr[pos]);
		arr[pos]=tmp;
		add(arr[pos]);
		resp();
	}
}

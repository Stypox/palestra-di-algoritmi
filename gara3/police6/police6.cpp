#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;

int64_t inizio[100002];
int64_t fine[100002];

int main(){
	int64_t n, m, l;
	cin>>n>>m>>l;
	for(int64_t a=0;a<n; a++){
		int64_t tmp;
		cin>>tmp;
		inizio[a]=tmp-m;//incluso
		fine[a]=tmp+m+1;//non incluso
	}
	int64_t curstart=0;
	int64_t curend=0;
	int64_t pos=0;
	int64_t visibilita=0;
	int64_t minVisibilita=n;

	inizio[n]=0;
	fine[n]=0;
	//inizio[n+1]=l;
	//fine[n+1]=l;

	sort(inizio,inizio+n+1);
	sort(fine, fine+n+1);
	while(curend<n+1){
		if(curstart!=n+1){
			pos=min(inizio[curstart], fine[curend]);
		}else{
			pos= fine[curend];
		}
		if(pos>l)
			break;
		while(inizio[curstart]==pos && curstart<n+1){
			curstart++;
			visibilita++;
		}
		while(fine[curend]==pos && curend<n+1){
			curend++;
			visibilita--;
		}
		
		if(pos>=0){
			minVisibilita= min(minVisibilita, visibilita);
		}
	}
	cout<<minVisibilita;
}

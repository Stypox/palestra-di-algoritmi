#include<bits/stdc++.h>
using namespace std;

int N;
int arr[100000];
int mem[100000][2];

int semafori(int i, bool hoSaltatoIlPrecedente) {
	if (i==N) {
		return 0;
	}
	if (mem[i][hoSaltatoIlPrecedente] != -1) {
		return mem[i][hoSaltatoIlPrecedente];
	}
	
	int seLoAspetto = arr[i] + semafori(i+1, false);
	if (hoSaltatoIlPrecedente) {
		return mem[i][hoSaltatoIlPrecedente] = seLoAspetto;
	} else {
	    int seLoSalto = semafori(i+1, true);
	    return mem[i][hoSaltatoIlPrecedente] = min(seLoSalto, seLoAspetto);
	}
}

int main(){
	cin>>N;
	memset(mem, -1, 100000 * 2 * sizeof(int));
	
	for(int n=0;n<N;++n){
		cin>>arr[n];
	}
	
	cout<<semafori(0, false)<<endl;
}
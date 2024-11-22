#include<bits/stdc++.h>
using namespace std;
long long int full[200000];
long long int half[200000];
int main(){
    int t;
    cin>>t;
    
    for (int i=0; i<t; i++){
        int n;
        cin>>n;
        long long int lower_bound=0;
        long long int upper_bound=0;

        for(int j=0; j<n; j++){
            cin>>full[j];
            upper_bound=max(upper_bound, full[j]+1);
        }
        for(int j=0; j<n-1; j++){
            cin>>half[j];
            upper_bound=max(upper_bound, half[j]+1);
        }
        half[n-1]=0;
        upper_bound*=2;
        while(lower_bound<upper_bound-1){
            long long int mid=(lower_bound+upper_bound)/2;
            bool possible=true;
            long long int unused=0;
            for(int j=0; j<n; j++){
                long long int fixed = full[j]+unused;
                long long int movable=max(mid-fixed, (long long int)0);
                if(movable > half[j]){
                    possible=false;
                    break;
                }
                unused=half[j]-movable;
            }
            
            if(possible){
                lower_bound=mid;
            }else{
                upper_bound=mid;
            }
        }
        cout<<lower_bound<<endl;
    }
    return 0;
}
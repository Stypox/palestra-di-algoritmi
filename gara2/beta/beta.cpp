#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    unordered_map<int, int> visti;
    cin>>n;
    int admin=-1;
    for(int a=0;a<n; a++){
        int tmp;
        cin>>tmp;
        if(tmp!=admin){

            //printf("%d %d", tmp, admin);
            auto test = visti.find(tmp);
            visti.insert(make_pair(tmp, 0));
            if(test != visti.end()){
                if(admin==-1){
                    admin=tmp;
                    continue;
                }
                cout<<"YES"<<endl;
                return 0;
            }
        }
       
    }
    cout<<"NO"<<endl;
}
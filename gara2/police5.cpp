#include<bits/stdc++.h>

using namespace std;

int n, m, t;

class vertex{
    public:
        int dest, t;
        bool exp;
    
        vertex(int desti, int ti, int expi){
            dest=desti;
            t=ti;
            exp=(expi==1);
        }

};

class node{
    public:
        vector<vertex> adj;
        int time=-1;
        bool exp=false;
};

vector<node> graph;

void dijikstra(){
    multimap<int, int> buff;
    buff.insert(make_pair(0,0));
    while(buff.size()>0){
        auto cur = *buff.begin();
        int nodo = cur.second;
        int time = cur.first;
        buff.erase(buff.begin());
        if(!graph[nodo].exp){
            graph[nodo].exp=true;
            for(int a=0; a<graph[nodo].adj.size(); a++){
                vertex ver = graph[nodo].adj[a];
                if(ver.exp&&time+ver.t>t){
                    continue;
                }
                if(graph[ver.dest].time==-1){
                    graph[ver.dest].time=time+ver.t;
                    buff.insert(make_pair(graph[ver.dest].time, ver.dest));
                }else{
                    if(time+ver.t<graph[ver.dest].time){
                        graph[ver.dest].time=time+ver.t;
                        buff.insert(make_pair(graph[ver.dest].time, ver.dest));
                    }
                }
            }
        }
        
    }
}

int main(){
    cin>>n>>m>>t;
    graph.resize(n);
    for(int a=0; a<m; a++){
        int from, to, t, exp;
        cin>>from>>to>>t>>exp;
        graph[from].adj.push_back(vertex(to, t, exp));
    }
    dijikstra();
    cout<<graph[n-1].time;
}
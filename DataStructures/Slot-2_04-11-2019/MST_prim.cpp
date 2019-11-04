#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

vector<pair<int,pair<int,int>>> prim(vector<pair<int,int>> adjancency_weight_pair_list[],int number_of_nodes)
{
    //This function works for 1-indexed nodes
    vector<pair<int,pair<int,int>>> final_weight_edge_pair_list;
    priority_queue<pair<int,pair<int,int>>> precedence_order;
    bool visited[number_of_nodes+1]={};
    visited[1]=1;
    for(auto node_weight_pair:adjancency_weight_pair_list[1])
    {
        precedence_order.push(make_pair(-node_weight_pair.second,make_pair(1,node_weight_pair.first)));
    }
    while(!precedence_order.empty())
    {
        pair<int,pair<int,int>> weight_edge_pair=precedence_order.top();
        precedence_order.pop();
        if(visited[(weight_edge_pair.second).second])
            continue;
        visited[(weight_edge_pair.second).second]=1;
        weight_edge_pair.first=(-weight_edge_pair.first);
        final_weight_edge_pair_list.push_back(weight_edge_pair);
        for(auto node_weight_pair:adjancency_weight_pair_list[(weight_edge_pair.second).second])
        {
            precedence_order.push(make_pair(-node_weight_pair.second,make_pair((weight_edge_pair.second).second,node_weight_pair.first)));
        }
    }

    return final_weight_edge_pair_list;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> ad[n+1];
    while(m--)
    {
        int u,v,w;
        cin>>u>>v>>w;
        ad[u].push_back(make_pair(v,w));
        ad[v].push_back(make_pair(u,w));
    }
    auto v=prim(ad,n);
    long long ans=0;
    for(auto x:v)
    {
        ans+=x.first;
    }
    cout<<ans;

    return 0;
}
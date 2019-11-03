#include<iostream>
#include<vector>
using namespace std;

void dfs(int root,vector<int> adjancency_list[],int visited[])
{
    visited[root]=1;
    cout<<root<<' ';
    for(auto node:adjancency_list[root])
    {
        if(!visited[node]) dfs(node,adjancency_list,visited);
    }
    return;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> ad[n+1];
    int f[n+1]={};
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        ad[u].push_back(v);
        ad[v].push_back(u);
    }
    dfs(1,ad,f);

    return 0;
}
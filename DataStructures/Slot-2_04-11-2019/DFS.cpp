#include<iostream>
#include<vector>
using namespace std;

vector<int> dfs(int root,vector<int> adjancency_list[],int visited[])
{
    visited[root]=1;
    vector<int> dfs_order;
    dfs_order.push_back(root);
    for(auto node:adjancency_list[root])
    {
        if(!visited[node])
        {
            vector<int> temp_list=dfs(node,adjancency_list,visited);
            for(auto temp_node:temp_list)
            {
                dfs_order.push_back(temp_node);
            }
        }
    }
    return dfs_order;
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
    vector<int> v=dfs(1,ad,f);
    for(auto x:v)
    {
        cout<<x<<' ';
    }

    return 0;
}
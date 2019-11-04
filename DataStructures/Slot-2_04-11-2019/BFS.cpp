#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> bfs(int root,vector<int> adjancency_list[],int n)
{
    bool visited[n+1]={};
    queue<int> precedence_list;
    vector<int> bfs_order;
    precedence_list.push(root);
    while(!precedence_list.empty())
    {
        root=precedence_list.front();
        precedence_list.pop();
        if(visited[root])
            continue;
        visited[root]=1;
        bfs_order.push_back(root);
        for(auto node:adjancency_list[root])
        {
            precedence_list.push(node);
        }
    }
    return bfs_order;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> ad[n+1];
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        ad[u].push_back(v);
        ad[v].push_back(u);
    }
    vector<int> v=bfs(1,ad,n);
    for(auto x:v)
    {
        cout<<x<<' ';
    }


    return 0;
}
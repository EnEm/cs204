#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int find_root(int node,int parent_list[])
{
    if(node==parent_list[node]) 
        return node;
    else
        return parent_list[node]=find_root(parent_list[node],parent_list);
}

bool union_set(int node1,int node2,int parent_list[],int set_size[])
{
    node1=find_root(node1,parent_list);
    node2=find_root(node2,parent_list);
    if(node1==node2)
        return false;
    if(set_size[node1]<set_size[node2])
    {
        int temp_node=node1;
        node1=node2;
        node2=temp_node;
    }
    parent_list[node2]=node1;
    set_size[node1]+=set_size[node2];
    return true;
}

vector<pair<int,pair<int,int>>> kruskal(vector<pair<int,int>> adjancency_weight_pair_list[],int number_of_nodes)
{
    //This function works for 1-indexed nodes
    vector<pair<int,pair<int,int>>> total_weight_edge_pair_list;
    vector<pair<int,pair<int,int>>> final_weight_edge_pair_list;
    int parent_list[number_of_nodes+1];
    int set_size[number_of_nodes+1];
    for(int root=1;root<=number_of_nodes;root++)
    {
        for(auto node_weight_pair:adjancency_weight_pair_list[root])
        {
            total_weight_edge_pair_list.push_back(make_pair(node_weight_pair.second,make_pair(root,node_weight_pair.first)));
        }
        parent_list[root]=root;
        set_size[root]=1;
    }
    sort(total_weight_edge_pair_list.begin(),total_weight_edge_pair_list.end());
    for(auto weight_edge_pair:total_weight_edge_pair_list)
    {
        if(union_set((weight_edge_pair.second).first,(weight_edge_pair.second).second,parent_list,set_size))
            final_weight_edge_pair_list.push_back(weight_edge_pair);
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
    auto v=kruskal(ad,n);
    long long ans=0;
    for(auto x:v)
    {
        ans+=x.first;
    }
    cout<<ans;

    return 0;
}
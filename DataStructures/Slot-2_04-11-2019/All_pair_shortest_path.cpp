#include<iostream>
#include<vector>
using namespace std;

int** floyd_warshall(vector<pair<int,int>> adjancency_weight_pair_list[],int number_of_nodes)
{
    //This function works for 1-indexed nodes
    int INF=1<<30-1;
    int (*distance)[number_of_nodes+1]=(int (*)[number_of_nodes+1])(malloc(sizeof(int [number_of_nodes+1][number_of_nodes+1])));
    for(int root=1;root<=number_of_nodes;root++)
    {
        for(int node=1;node<=number_of_nodes;node++)
        {
            distance[root][node]=INF;
        }
        for(auto node_weight_pair:adjancency_weight_pair_list[root])
        {
            distance[root][node_weight_pair.first]=node_weight_pair.second;
        }
        distance[root][root]=0;
    }
    for(int middle_node=1;middle_node<=number_of_nodes;middle_node++)
    {
        for(int left_node=1;left_node<=number_of_nodes;left_node++)
        {
            for(int right_node=1;right_node<=number_of_nodes;right_node++)
            {
                if(distance[left_node][middle_node]+distance[middle_node][right_node]<distance[left_node][right_node])
                {
                    distance[left_node][right_node]=distance[left_node][middle_node]+distance[middle_node][right_node];
                }
            }
        }
    }
    for(int root=1;root<=number_of_nodes;root++)
    {
        for(int node=1;node<=number_of_nodes;node++)
        {
            if(distance[root][node]==INF) distance[root][node]=-1;
        }
    }

    return (int**)distance;
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
    }
    int (*a)[n+1];
    a=(int (*)[n+1])(floyd_warshall(ad,n));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<a[i][j]<<' ';
        }
        cout<<'\n';
    }
    free(a);

    return 0;
}
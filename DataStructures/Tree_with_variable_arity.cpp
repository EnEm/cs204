#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

template<typename data_type>

class tree
{
    public:
        int size;
        struct var_node
        {
            data_type data;
            vector<struct var_node*> children;
            struct var_node* parent;
        };
        struct var_node* make_node()
        {
            return (struct var_node*)(malloc(sizeof(struct var_node)));
        }
        struct var_node* root;
        tree()
        {
            root=NULL;
            size=0;
        }
        bool insert_root(data_type data)
        {
            if(root!=NULL)
                return false;
            root=make_node();
            root->data=data;
            root->parent=NULL;
            return true;
        }
        bool insert_this(data_type data,struct var_node* temp_node)
        {
            struct var_node* new_node=make_node();
            (temp_node->children).push_back(new_node);
            new_node->data=data;
            new_node->parent=temp_node;
            return true;
        }
        void dfs(struct var_node* v)
        {
            cout<<v->data<<' ';
            for(auto it:v->children) dfs(it);
            return;
        }
        bool delete_node(struct var_node* temp_node)
        {
            if(temp_node->parent==NULL)
            {
                free(temp_node);
                root=NULL;
                return true;
            }
            ((temp_node->parent)->children).erase(find(((temp_node->parent)->children).begin(),((temp_node->parent)->children).end(),temp_node));
            free(temp_node);
            return true;
        }
};

int main()
{
    tree<int> v;
    v.insert_root(1);
    v.insert_this(2,v.root);
    v.insert_this(3,v.root);
    v.insert_this(4,v.root);
    v.insert_this(5,v.root);
    v.insert_this(6,(v.root)->children[0]);
    v.delete_node((v.root)->children[2]);
    v.dfs(v.root);
    return 0;
}
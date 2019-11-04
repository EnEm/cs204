#include<iostream>
using namespace std;

template<typename data_type>

class BST
{
    private:
        int number_of_nodes;
        struct node
        {
            data_type key;
            struct node* left_child;
            struct node* right_child;
            struct node* parent;
        };
        struct node* create_node()
        {
            return (struct node*)(malloc(sizeof(struct node)));
        }
        struct node* root;
        struct node* find_node(struct node* temp_root,data_type value)
        {
            if(temp_root==NULL)
                return NULL;
            else if(value==temp_root->key)
                return temp_node;
            else if(value<temp_root->key)
            {
                if(temp_root->left_child==NULL) return temp_root;
                else return find_node(temp_root->left_child,value);
            }
            else if(value>temp_root->key)
            {
                if(temp_root->right_child==NULL) return temp_root;
                else return find_node(temp_root->right_child,value);
            }
            else
                return NULL;
        }
    public:
        BST()
        {
            root=NULL;
            number_of_nodes=0;
        }
        struct node* search_node(data_type value)
        {
            return find_node(root,value);
        }
        bool count_node(data_type value)
        {
            struct node* temp_node=search_node(value);
            if(temp_node==NULL)
                return false;
            else if(temp_node->key!=value)
                return false;
            else
                return true;
        }
        bool insert_node(data_type value)
        {
            if(count_node(value))
            {
                return false;
            }
            else if(root==NULL)
            {
                root=create_node();
                root->parent=NULL;
                root->left_child=NULL;
                root->right_child=NULL;
                root->key=value;
                return true;
            }
            else
            {
                struct node* temp_root=search_node(value);
                struct node* temp_node=create_node();
                temp_node->parent=temp_root;
                temp_node->left_child=temp_node->right_child=NULL;
                temp_node->key=value;
                if(value<temp_root->key)
                {
                    temp_root->left_child=temp_node;
                }
                else
                {
                    temp_root->right_child=temp_node;
                }
                return true;
            }
        }
        bool delete_node(data_type value)
        {
            if(!count_node(value))
                return false;
            struct node* temp_root=search_node(value);
            if(temp_root->left_child==NULL)
            {
                if(temp_root->parent==NULL)
                {
                    root=temp_root->right_child;
                    if(root!=NULL) root->parent=NULL;
                    free(temp_root);
                    return true;
                }
                else
                {
                    (temp_root->parent)->right_child=temp_root->right_child;
                    if(temp_root->right_child!=NULL) (temp_root->right_child)->parent=temp_root->parent;
                    free(temp_root);
                    return true;
                }
            }
            else if(temp_root->right_child==NULL)
            {
                if(temp_root->parent==NULL)
                {
                    root=temp_root->left_child;
                    if(root!=NULL) root->parent=NULL;
                    free(temp_root);
                    return true;
                }
                else
                {
                    (temp_root->parent)->left_child=temp_root->left_child;
                    if(temp_root->left_child!=NULL) (temp_root->left_child)->parent=temp_root->parent;
                    free(temp_root);
                    return true;
                }
            }
            else
            {

            }
        }
};

int main()
{
    BST v;
    return 0;
}

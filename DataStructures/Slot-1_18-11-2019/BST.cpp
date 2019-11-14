#include <iostream>
using namespace std;
template <typename T>
class BST
{
    public:
        struct BST_node 
        { 
            int key; 
            struct BST_node *LEFT, *RIGHT; 
        }; 
        struct BST_node *ROOT=NULL;
        struct BST_node *newNode(int item) 
        { 
            struct BST_node *temp =  new struct BST_node; 
            temp->key = item; 
            temp->LEFT = temp->RIGHT = NULL; 
            return temp; 
        } 
        void inorder(struct BST_node *root) 
        { 
            if (root != NULL) 
            { 
                inorder(root->LEFT); 
                cout<<root->key<<" ";
                inorder(root->RIGHT); 
            } 
        } 

        struct BST_node* insert(struct BST_node* node, int key) 
        { 
            if (node == NULL) return newNode(key); 
            if (key < node->key) 
                node->LEFT  = insert(node->LEFT, key); 
            else if (key > node->key) 
                node->RIGHT = insert(node->RIGHT, key);    
            return node; 
        } 
        struct BST_node * successor(struct BST_node* node) 
        { 
            struct BST_node* current = node; 
            while (current && current->LEFT != NULL) 
                current = current->LEFT; 
            return current; 
        } 
        struct BST_node* deletenode(struct BST_node* root, int key) 
        { 
            if (root == NULL) return root; 
            if (key < root->key) 
                root->LEFT = deleteNode(root->LEFT, key); 
            else if (key > root->key) 
                root->RIGHT = deleteNode(root->RIGHT, key); 
            else
            { 
                if (root->LEFT == NULL) 
                { 
                    struct BST_node *temp = root->RIGHT; 
                    free(root); 
                    return temp; 
                } 
                else if (root->RIGHT == NULL) 
                { 
                    struct BST_node *temp = root->LEFT; 
                    free(root); 
                    return temp; 
                } 
                struct BST_node* temp = successor(root->RIGHT); 
                root->key = temp->key; 
                root->RIGHT = deleteNode(root->RIGHT, temp->key); 
            } 
            return root; 
        } 
};

int main() 
{ 
    
    return 0; 
}
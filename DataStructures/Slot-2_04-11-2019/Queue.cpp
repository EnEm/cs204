#include<iostream>
using namespace std;

template<typename data_type>

class queue
{
    private:
        int queue_size;
        struct queue_node
        {
            data_type value;
            queue_node* next_node;
            queue_node* prev_node;
        };
        queue_node* head;
        queue_node* tail;
        queue_node* make_node()
        {
            return (queue_node*)(malloc(sizeof(queue_node)));
        }
    public:
        queue()
        {
            queue_size=0;
            head=NULL;
            tail=NULL;
        }
        bool push(data_type data)
        {
            queue_node* new_node=make_node();
            new_node->value=data;
            new_node->next_node=NULL;
            new_node->prev_node=head;
            if(head==NULL)
            {
                tail=new_node;
                head=new_node;
            }
            else
            {
                head->next_node=new_node;
            }
            head=new_node;
            queue_size++;
            return true;
        }
        bool pop()
        {
            if(tail==NULL)
            {
                return false;
            }
            else
            {
                queue_node* second_last_node=tail->next_node;
                free(tail);
                if(second_last_node==NULL)
                {
                    tail=NULL;
                    head=NULL;
                }
                else
                {
                    tail=second_last_node;
                    tail->prev_node=NULL;
                }
                queue_size--;
                return true;
            }
        }
        data_type front()
        {
            return tail->value;
        }
        data_type back()
        {
            return head->value;
        }
        bool empty()
        {
            if(queue_size==0) return true;
            else return false;
        }
        int size()
        {
            return queue_size;
        }
};

int main()
{
    queue<int> v;
    v.push(10);
    v.push(20);
    v.push(30);
    v.push(40);
    v.pop();
    v.push(50);
    v.pop();
    cout<<v.front()<<endl;
    cout<<v.back()<<endl;
    cout<<v.size()<<endl;

    return 0;
}
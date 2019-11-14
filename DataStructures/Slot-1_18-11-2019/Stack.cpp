#include<iostream>
using namespace std;

template<typename data_type>

class stack
{
    private:
        int stack_size;
        struct stack_node
        {
            data_type value;
            stack_node* next_node;
            stack_node* prev_node;
        };
        stack_node* head;
        stack_node* tail;
        stack_node* make_node()
        {
            return (stack_node*)(malloc(sizeof(stack_node)));
        }
        struct stack_node* find(data_type key)
        {
            struct stack_node* pointer=head;
            while(pointer!=NULL)
            {
                if(pointer->value==key)
                    return pointer;
                pointer=pointer->next_node;
            }
            return NULL;
        }
    public:
        stack()
        {
            stack_size=0;
            head=NULL;
            tail=NULL;
        }
        bool push_after(data_type data,stack_node* pointer)
        {
            if(pointer==NULL) 
                return false;
            stack_node* new_node=make_node();
            new_node->value=data;
            new_node->prev_node=pointer;
            new_node->next_node=pointer->next_node;
            pointer->next_node=new_node;
            if(new_node->next_node!=NULL)
                (new_node->next_node)->prev_node=new_node;
            stack_size++;
            if(head==pointer)
                head=new_node;
            return true;
        }
        bool push_before(data_type data,stack_node* pointer)
        {
            if(pointer==NULL) 
                return false;
            stack_node* new_node=make_node();
            new_node->value=data;
            new_node->next_node=pointer;
            new_node->prev_node=pointer->prev_node;
            pointer->prev_node=new_node;
            if(new_node->prev_node!=NULL)
                (new_node->prev_node)->next_node=new_node;
            stack_size++;
            if(tail==pointer)
                tail=new_node;
            return true;
        }
        bool push(data_type data)
        {
            if(stack_size==0)
            {
                stack_node* new_node=make_node();
                new_node->value=data;
                new_node->prev_node=NULL;
                new_node->next_node=NULL;
                head=tail=new_node;
                stack_size++;
            }
            else
            {
                push_after(data,head);
            }
            return true;
        }
        bool push_front(data_type data)
        {
            if(stack_size==0)
            {
                stack_node* new_node=make_node();
                new_node->value=data;
                new_node->prev_node=NULL;
                new_node->next_node=NULL;
                head=tail=new_node;
                stack_size++;
            }
            else
            {
                push_before(data,tail);
            }
            return true;
        }
        bool pop_this(stack_node* pointer)
        {
            if(pointer==NULL)
                return false;
            if(pointer->prev_node!=NULL)
                (pointer->prev_node)->next_node=pointer->next_node;
            if(pointer->next_node!=NULL)
                (pointer->next_node)->prev_node=pointer->prev_node;
            if(head==pointer)
                head=pointer->prev_node;
            if(tail==pointer)
                tail=pointer->next_node;
            free(pointer);
            stack_size--;
            return true;
        }
        bool pop()
        {
            if(stack_size==0)
                return false;
            else
            {
                pop_this(head);
            }
            return true;
        }
        bool pop_front()
        {
            if(stack_size==0)
                return false;
            else
            {
                pop_this(tail);
            }
            return true;
        }
        data_type front()
        {
            return tail->value;
        }
        data_type back()
        {
            return head->value;
        }
        bool count(data_type key)
        {
            struct stack_node* pointer=head;
            while(pointer!=NULL)
            {
                if(pointer->value==key)
                    return true;
                pointer=pointer->next_node;
            }
            return false;
        }
        bool pop_key(data_type key)
        {
            struct stack_node* pointer;
            while((pointer=find(key))!=NULL)
            {
                pop_this(pointer);
            }
            return true;
        }
        bool empty()
        {
            if(stack_size==0) 
                return true;
            else 
                return false;
        }
        int size()
        {
            return stack_size;
        }
};

int main()
{
    stack<int> v;
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
    cout<<v.count(42)<<endl;

    return 0;
}
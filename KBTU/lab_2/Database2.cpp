#include <iostream>

using namespace std; 

struct Node 
{  
    string data;  
    Node* next;  
};  
  
void remove_duplicates(Node* head)  
{  
    Node * cur = head;
    Node * next_next;
    if(!cur) return;
    while(cur->next){
        if(cur -> data == cur->next->data){
            next_next = cur->next->next;
            free(cur->next);
            cur->next = next_next;
        }
        else{
            cur = cur->next;
        }
    }
    
}  
Node* reverse(Node* head){
    Node * next = NULL;
    Node * prev = NULL;
    Node * cur = head;
    while(cur){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

int get_count(Node* head)  
{  
    int cnt = 0; 
    Node*cur = head;
    while(cur){
        cnt++;
        cur= cur->next;
    }
    return cnt;  
}  

void push(Node** head_ref, string new_data)  
{ 
    Node* new_node = new Node(); 
    new_node->data = new_data;  
    new_node->next = (*head_ref);      
    (*head_ref) = new_node;  
}  
 
void print(Node *node)  
{  
    while (node!=NULL)  
    {  
        cout<<node->data<<"\n";  
        node = node->next;  
    }  
}  
int main()  
{  
    int n;
    string s;
    cin>>n;
    Node* head = NULL;  
    for(int i =0;i<n;i++){
        cin>>s;
        push(&head,s);
    }                               
    remove_duplicates(head);  
    // reverse(head);
    cout<<"All in all: "<<get_count(head); 
    cout<<"\nStudents:\n";      
    print(head);              
    return 0;  
}
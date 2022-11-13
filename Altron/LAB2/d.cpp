#include <iostream>
#include <vector>

using namespace std;

struct Node{
    string val;
    Node* next;
    int cnt;
    Node(string v){
        val = v;
        cnt = 1;
        next = nullptr;
    }
};



class LinkedList{
    int size;
public:
    Node * head;
    LinkedList(){
        head = nullptr;
    }

    void push(string val){
        Node * newNode = new Node(val);
        if (head == nullptr){head = newNode;}
        else{
           Node * cur = head;
           while(cur != nullptr){
               if (cur -> val == val){
                   cur -> cnt++;
                   break;
               }
               if (cur -> next == nullptr){
                   cur -> next = newNode;
                   break;
               }
               cur = cur -> next;
           }
        }
    }



    void print(){
        Node * cur = head;
        while(cur != nullptr){
            cout << cur -> val << " " << cur -> cnt << endl;
            cur = cur -> next;
        }
    }


    void sort(){
        Node * first = head;
        Node * second = nullptr;
        if (head == nullptr){
            return;
        }
        while(first -> next != nullptr){
            second = first -> next;
            while(second != nullptr){
                if (first -> cnt  < second -> cnt){
                    swap(first->val, second->val);
                    swap(first -> cnt, second -> cnt); 
                }
                if(first -> cnt == second ->cnt){
                        if(first -> val > second -> val){
                            swap(first->val, second->val);
                            swap(first -> cnt, second -> cnt);
                        }
                    }
                second = second -> next;
            }
            first = first -> next;
        }
    }

};



int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    LinkedList list;
    string s;
    while(cin >> s){
        string s1 = "";
        for(int i = 0;i < s.size();i++){
            if(s[i] != '.' && s[i] != '?' && s[i] != '!' && s[i] != ';' && s[i] != ':' && s[i] != ','){
                s1 += tolower(s[i]);
            }
        }
        list.push(s1);
    }
    list.sort();
    list.print();
}
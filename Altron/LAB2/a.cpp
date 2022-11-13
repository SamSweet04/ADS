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



//    void addFront(int val){
//        Node * newNode = new Node(val);
//        if (head == nullptr){ head = newNode; }
//        else{
//            newNode -> next = head;
//            head = newNode;
//        }
//        size++;
//    }

    void print(){
        Node * cur = head;
        while(cur != nullptr){
            cout << cur -> val << " " << cur -> cnt << endl;
            cur = cur -> next;
        }
    }

//    void del(int val){
//        if (head == nullptr){
//            cout << "Linked List is empty";
//            return;
//        }
//        if (head -> val == val){
//            head = head -> next;
//        }
//        else{
//            Node * cur = head;
//            Node * prev = nullptr;
//            while(cur != nullptr){
//                if (cur -> val == val){
//                    prev -> next = cur -> next;
//                    delete cur;
//                    return;
//                }
//                prev = cur;
//                cur = cur -> next;
//            }
//            cout << "No such element " << val << endl;
//        }
//    }


    void del1(int pos){
        if (head == nullptr){
            cout << "Linked List is empty";
            return;
        }
        if (pos == 1){
            head = head -> next;
        }
        else{
            int i = 1;
            Node * cur = head;
            Node * prev = nullptr;
            while(cur != nullptr){
                if (i == pos){
                    prev -> next = cur -> next;
                    delete cur;
                    return;
                }
                prev = cur;
                cur = cur -> next;
                i++;
            }
            cout << "No such pos " << pos << endl;
        }
    }

//    bool contains(int val){
//        Node * cur = head;
//        while(cur != nullptr){
//            if (cur -> val == val){
//                return true;
//            }
//            cur = cur -> next;
//        }
//        return false;
//    }

    //1 тип функции
    //тип функции = тип возвращаемого значения

//    vector<int> search(int val){
//        vector<int> ans;
//        Node * cur = head;
//        int i = 1;
//        while(cur != nullptr){
//            if (cur -> val == val){
//                ans.push_back(i);
//            }
//            cur = cur -> next;
//            i++;
//        }
//        return ans;
//    }

//    void reverse(){
//        vector<int> rave;
//        Node * cur = head;
//        while(cur != nullptr){
//            rave.push_back(cur -> val);
//            cur = cur -> next;
//        }
//        for (int i = 0; i < rave.size(); i++){
//            cout << rave[i] << " ";
//        }
//        cur = head;
//        int i = rave.size() - 1;
//        while(cur != nullptr){
//            cur -> val = rave[i];
//            cur = cur -> next;
//            i--;
//        }
//
//    }

    void reversePRO(){
        Node * next = nullptr;
        Node * prev = nullptr;
        Node * cur = head;
        while(cur != nullptr){
            next = cur -> next;
            cur -> next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;
    }


    void sort1(){
        Node * first = head;
        Node * second = nullptr;
        while(first -> next != nullptr){
            second = first -> next;
            while(second != nullptr){
                if (first -> cnt < second -> cnt){
                    swap(first -> val, second -> val);
                    swap(first->cnt, second->cnt);
                }
                if (first -> cnt == second -> cnt){
                    if (first -> val > second -> val){
                        swap(first -> val, second -> val);
                        swap(first->cnt, second->cnt);
                    }
                }
                second = second -> next;
            }
            first = first -> next;
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
                if (first -> val > second -> val){
                    swap(first->val, second->val);
                    swap(first -> cnt, second -> cnt);
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
        list.push(s);
    }
    list.sort();
    list.print();
}


#include <bits/stdc++.h>
using namespace std;
struct Node{ // ����� �������� ����
    int k;
    int count; // ������� ������� ��� �������� ����� ������� �����������
    Node *next;
    Node(){
        this->k = 0;
        this->count = 0; // �� ��������� � ��������� ��� ����� 0
        next = 0;
    }
    Node(int k){
        this->k = k;
        this->count = 0;
        next = 0;
    }
};
struct LinkedList{
    Node *head;
    Node *tail;
    int max; // ������� ���������� ��������
    LinkedList(){
        head = 0;
        tail = 0;
        this->max = 0; // ���������� �������� ����� 0 �� ���������
    }
    void push_back(int k){
        Node *tmp = new Node(k);
        if(head == 0){ // ���� ���� ��������� ������(� ��� ������ ������ :) )
            head = tmp;// ��������� ����� ���
            tail = tmp; //������� �� ���� �� �����, �� �� ���� ����� ���
        }
        else{
            Node *cur = head; // ������� ��� ������� ����� ���������
            while(cur != 0){ //���� ���� ��� �� ����� 0
                if(cur->k == tmp->k) { // ��������� ���� ������� ������� ����� �������� ������� ���������
                    cur->count++; // ������ ��������� �������
                    break;
                }
                if(cur->next == NULL){
                        cur->next = tmp;
                        break;
               }
            cur = cur->next;
        }
    }
    }
    void search_max_mode(){
        Node *cur = head; // ��������� �� ��������
        while(cur != 0){ // ���� ��������� �� ����� 0 
            if(cur->count > max){ // ���� ������� � �������� �������� ������ ��� ���
                max = cur->count; // ������ � ����� ���� ����� ����� ��� ����� ������� �������
            }
            cur = cur->next;
        }
    }
    void print(){
        search_max_mode();
        vector <int> v;
        Node *cur = head; // ������� ��� �� ����
        while(cur != 0){ // ���� ��� �� ����� 0 
            if(cur->count == max){ // ���� � ���� ������� ����� ���
                v.push_back(cur->k); // ��� ������ � ��� ������
            }
            cur = cur->next;
        }
        sort(v.rbegin(),v.rend()); 
        for(auto i: v){
            cout << i << " ";
        }
    }
};
    int main(){
        LinkedList *ll = new LinkedList();
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            int k;
            cin >> k;
            ll->push_back(k);
        }
        ll->print();
    }
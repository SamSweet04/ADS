#include <bits/stdc++.h>
using namespace std;
struct Node{ // пишем структур Ноды
    int k;
    int count; // заведем коунтер для подсчета чисел которые встречались
    Node *next;
    Node(){
        this->k = 0;
        this->count = 0; // по умолчанию у указателя она равна 0
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
    int max; // заведем переменную максимум
    LinkedList(){
        head = 0;
        tail = 0;
        this->max = 0; // переменная максимум равна 0 по умолчанию
    }
    void push_back(int k){
        Node *tmp = new Node(k);
        if(head == 0){ // если наша головушка пустая(а она всегда пустая :) )
            head = tmp;// головушка равна тмп
            tail = tmp; //хвостик по сути не нужен, но он тоже равен тмп
        }
        else{
            Node *cur = head; // создаем кур который равен головушке
            while(cur != 0){ //пока этот кур не равен 0
                if(cur->k == tmp->k) { // проверяем если текущий элемент равен элементу который добавился
                    cur->count++; // курдын коунтерын косамыз
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
        Node *cur = head; // указатель на головшку
        while(cur != 0){ // пока головушка не равна 0 
            if(cur->count > max){ // если коунтер у текщийго элеменат больше чем мах
                max = cur->count; // теперь у макса есть новое число как самый большой коунтер
            }
            cur = cur->next;
        }
    }
    void print(){
        search_max_mode();
        vector <int> v;
        Node *cur = head; // создаем кур на хэда
        while(cur != 0){ // пока кур не равен 0 
            if(cur->count == max){ // если у кура коунтер равен мах
                v.push_back(cur->k); // пуш бэкаем в наш вектор
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
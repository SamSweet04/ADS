// Задача №1164. Увеличение приоритета
#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Heap{
    int a[100005];
    int size;
public:
    Heap(){
        a[0] = INT_MAX;
        size = 0;
    }

    void insert(int val){
        size++;
        a[size] = val;
        sift_up(size);
    }

        int parent(int i){
        return i/ 2;
    } 

    int sift_up(int i){
        while(i > 0 && a[parent(i)] < a[i]){
            swap(a[parent(i)],a[i]);
            i = parent(i);
            } 
        return i;  
    }

    void increase(int pos,int val){
        a[pos]+=val;
        cout << sift_up(pos) << endl;
}

     void print(){
        for (int i = 1; i <= size; i ++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
};


int main(){
    Heap heap;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        heap.insert(x);
    }
    int l; cin >> l;
    for(int i = 0 ; i < l; i++){
        int pos,val; cin >> pos >> val;
        heap.increase(pos,val);
    }    
    heap.print();
}
#include <bits/stdc++.h>
using namespace std;
class Heap{
    int a[100005];
    int size;
public:
    Heap(){
        size = 0;
        a[0] = INT_MAX;
 }
    int parent(int i){
        return i / 2;
    }
    int left(int i){
        return i * 2;
    }
    int right(int i){
        return i * 2 + 1;
    }
    void insert(int val){
        size++;
        a[size] = val;
        sift_up(size); 
    }
    int sift_up(int i){
        while (i > 1 && a[parent(i)] < a[i]){
            swap(a[parent(i)], a[i]);
            i = parent(i);
        }
        return i;
    }
    void increase(int pos, int val){
        a[pos] += val;
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
    for (int i = 0; i < n; i ++){
        int x;
        cin >> x;
        heap.insert(x);
    }
    int k,i,j;
    cin >> k;
    while(k--){
        cin >> i >> j;
        heap.increase(i, j);
    }
    heap.print();

}
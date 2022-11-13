#include<bits/stdc++.h>

using namespace std;

class Heap{
    int a[100005];
    int size;
public:
    Heap(){
        a[0] = INT_MAX;
        size = 0;
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
        // sift_up(size);
    }

    int sift_up(int i){
        while(i > 0 && a[parent(i)] < a[i]){
            swap(a[parent(i)], a[i]);
            i = parent(i);
        }
        return i;
    }

    void sift_down(int i){
        int l = left(i);
        int r = right(i);
        int maxChild = left(i);
        if(l > size){
            return;
        }
        if(r <= size){
            if(a[r] > a[l]) maxChild = r;
        }
        if(a[i] < a[maxChild]){
            swap(a[i], a[maxChild]);
            sift_down(maxChild);
        }
   
    }

    void heapify(int i, int SZ){
        int l = left(i);
        int r = right(i);
        int maxChild = left(i);
        if(l > SZ){
            return;
        }
        if(r <= SZ){
            if(a[r] > a[l]) maxChild = r;
        }
        if(a[i] < a[maxChild]){
            swap(a[i], a[maxChild]);
            heapify(maxChild, SZ);
        }
    }

    int extractMax(){
        int ans = a[1];
        swap(a[1], a[size]);
        sift_down(1);
        return ans;
    }

    void del(int i){
        swap(a[i], a[size]);
        size--;
        if(size > 0){
            if(parent(i) > 0 and a[parent(i)] < a[i]){
                sift_up(i);
            }
            else{
                sift_down(i);
            }
        }
    }

    void heapSort(){
        for(int i = size; i > 1; i--){
            swap(a[1], a[i]);
            heapify(1, i - 1);
        }
    }

    void increase(int pos, int val){
        a[pos] += val;
        cout << sift_up(pos) << endl;
    }

    void decrease(int pos, int val){
        a[pos] -= val;
        sift_down(pos);
    }

    void change(int pos, int val){
        if(val > a[pos]){
            a[pos] = val;
            cout << sift_up(pos) << endl;
        }
        else if(val < a[pos]){
            a[pos] = val;
            sift_down(pos);
        }
    }

    void print(){
        for(int i = 1; i <= size; i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }

    void print_2(int sz){
        for(int i = 1; i <= sz; i++) cout << a[i] << " ";
        cout << endl;
    }

    void build_heap(){
        for(int i = size / 2; i >= 1; i--){
            sift_down(i);       
        }
    }
};

int main(){
    Heap heap;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        heap.insert(x);
    }
    heap.build_heap();
    heap.print();
    int m = n;
    while(m > 1){
        heap.del(1);
        heap.print();
        m--;
    }
    heap.heapSort();
    heap.print_2(n);
   
}
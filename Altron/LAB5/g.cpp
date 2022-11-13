#include <bits/stdc++.h>
using namespace std;
class Heap{
public:
    vector <int> a;
    int size;
    Heap(){
        size = 0;
    }
    int parent(int i){
        return (i-1) / 2;
    }
    int left(int i){
        return (i*2) + 1;
    }
    int right(int i){
        return (i*2) + 2;
    }

    void insert(int val){
        a.push_back(val);
        shift_up(a.size() - 1);
    }
    int shift_up(int i){
        while(i > 0 && a[parent(i)] < a[i]){
            swap(a[parent(i)],a[i]);
            i = parent(i);
        }
        return i + 1;
    }
    void shift_down(int i){
        if(left(i) > a.size() - 1) return;
        int child = left(i);
        if(right(i) < a.size() && a[left(i)] < a[right(i)]) child = right(i);
        if(a[i] < a[child]) {
        swap(a[i],a[child]);
        shift_down(child);
        }
    }
    int extractMax(){
        int ans = a[0];
        swap(a[0], a[a.size()-1]);
        a.pop_back();
        shift_down(0);
        return ans;
    }
    void sort(){
        vector <int> ans;
        int size = a.size();
        for(int i = 1; i <= size; i++){
            ans.push_back(extractMax());
        }
        for(int i = ans.size() - 1; i >= 0; i--){
            cout << ans[i] << " ";
        }
    }
    void decrease(int i, int x){
        a[i] -= x;
        shift_down(i);
    }
    void increase(int i, int x){
        a[i] += x;
        cout << shift_up(i) << endl;
    }
    void print(){
        for(int i = 0; i < a.size(); i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
};
    int main(){
        Heap heap;
        vector<int> a; 
        int n; cin >> n;
        for(int i = 0; i < n; i++){
            int val;
            cin >> val;
            heap.a.push_back(val);
        }
        for(int i = heap.a.size() - 1; i >= 0;i--){
            heap.shift_down(i);
        }
        heap.print();
    }


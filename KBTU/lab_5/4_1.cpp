#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,cnt = 0;

class Heap{
    ll a[1000005];
    ll size;
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
        return i * 2 +1;
    }
    
    void insert(ll val){
        size++;
        a[size] = val;
        sift_up(size);
    }

    void sift_up(int i){
        while(i > 1 && a[parent(i)] > a[i]){
            swap(a[parent(i)],a[i]);
            i = parent(i);
        }
    }
    void sift_down(int i){
        int l = left(i);
        int r = right(i);
        if(l > size) return ;
        int minChild = l;
        if(r <= size) {
            if(a[r] < a[l]) r = minChild;
        }
        if(a[i] > a[minChild]){
            swap(a[i],a[minChild]);
            sift_down(minChild);
        }
    }
    ll extractMin(){
        ll min = a[1];
        swap(a[1],a[size]);
        size--;
        sift_down(1);
        return min;
    }

    void mix(){
        while(a[1] < m && cnt < n){
            cnt++;
            ll A = extractMin();
            ll B = extractMin();
            ll AB = A + B*2;
            cout << A << " " << B;
            insert(AB);
        }
        if(cnt >= n){
            cout << -1 << endl;
        }
        else{
            cout << cnt << endl;
        }
    }

    void print(){
        for(int i = 1; i <= size; i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    Heap heap;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        heap.insert(x);
    }
    heap.mix();
}
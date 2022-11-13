#include<bits/stdc++.h>

using namespace std;
int k;
class Heap{
    unsigned long long a[200005];
public:
    int size;
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

    void insert(unsigned long long val){
        if(size < k){
            size++;
            a[size] = val;
            sift_up(size);
        }
        else{
            if(a[1] < val){
                a[1] = val;
                sift_down(1);
            }
        }
    }

    void sift_up(int i){
        while(i > 1 && a[parent(i)] > a[i]){
            swap(a[parent(i)], a[i]);
            i = parent(i);
        }
    }

    void sift_down(int i){
        int l = left(i);
        int r = right(i);
        if(l > size) return;
        int minChild = l;
        if(r <= size){
            if(a[r] < a[l]) minChild = r;
        }
        if(a[i] > a[minChild]){
            swap(a[i], a[minChild]);
            sift_down(minChild);
        }
    }

    unsigned long long extractMin(){
        unsigned long long ans = a[1];
        swap(a[1], a[size]);
        size--;
        sift_down(1);
        return ans;
    }

    unsigned long long getMin(){
        return a[1];
    }

    void print(){
        long long sum = 0;
        for(int i = 1; i <= size; i++){
            sum+=a[i];
        }
        cout << sum << endl;
    }

    void change(int pos, int val){
        if(val > a[pos]){
            a[pos] = val;
        }
        else if(val < a[pos]){
            a[pos] = val;
            sift_down(pos);
        }
    }
    int sz(){
        return size;
    }

};

int main(){
    Heap h;
    unsigned long long n;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        string s; unsigned long long num;
        cin >> s;
        if(s == "insert"){
            cin >> num;
            h.insert(num);
        }
        else{
            if(h.sz() == 0){
                cout << 0 << endl;
            }
            else{
                h.print();
            }
        }
    }
    }
#include <iostream>
#include <vector>
using namespace std;
int cnt= 0;
struct Heap {
    vector<int> heap;

    int parent(int i) {
        return (i - 1) / 2;
    }
    int left(int i) {
        return 2 * i + 1;
    }
    int right(int i) {
        return 2 * i + 2;
    }
    void insert(int value) {
        this->heap.push_back(value);
        int i = this->heap.size() - 1;
        while (i != 0 && this->heap[parent(i)] < this->heap[i]) {
        swap(this->heap[parent(i)], this->heap[i]);
        i = parent(i);
        }
    }
    
        void count(int i) {
            int l = left(i);
            int r = right(i);
            if(l>= heap.size() || r>=heap.size()) return;
            if(heap[left(i)] < heap[right(i)]) cnt++;
            count(left(i));
            count(right(i));
        }

    };

int main() {
    int n;cin>>n;
    Heap h;
    for(int i = 0;i < n;i++) {
        int x;cin>>x;
        h.insert(x);
    }
    h.count(0);
    cout << cnt;
}
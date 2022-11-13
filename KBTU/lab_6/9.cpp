#include <iostream>
using namespace std;

int partition(string & ar, int low, int high) {
	char pivot = ar[high];
	int i = low-1;
	for (int j = low; j <= high-1; j++) {
        if (ar[j] < pivot) {
			i++;
			swap(ar[j], ar[i]);
		}
	}
	swap(ar[i+1], ar[high]);
	return i+1;
}

void quick_sort(string& ar, int low, int high) {
	if (low < high) {
		int p = partition(ar, low, high);
		quick_sort(ar, low, p - 1);
		quick_sort(ar, p + 1, high);
	}
}

int main() {
	string s;
	cin >> s;
	quick_sort(s, 0, s.size() - 1);
    cout << s;
	return 0;
}
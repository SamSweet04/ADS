#include <bits/stdc++.h>
using namespace std;

bool comp(pair<string, string> &a, pair <string, string> &b) {
	return a.first < b.first;
}

int partition(vector<pair<string, string>> &v, int left, int right) {
	pair<string, string> pivot = v[right];
	int index = left;
	for (int i = left; i < right; i++) {
		if (comp(v[i], pivot)) {
			swap(v[i], v[index]);
			index++;
		}
	}
	swap(v[index], v[right]);
	return index;
}

void quick_sort(vector < pair < string, string> >& v, int left, int right) {
	if (left < right) {
		int p = partition(v, left, right);
		quick_sort(v, left, p - 1);
		quick_sort(v, p + 1, right);
	}
}

int main(){
	int n;
	cin >> n;
	vector < pair < string, string>> v; // Arystanbek Saule // Arystanbek Arystan 
	while(n--){                        // Ahadilov Ajar
                                        // Saule Arystan
		string oldnick, newnick;
		bool check = false;
		cin >> oldnick >> newnick;
		for (int i = 0; i < v.size(); i++) {
			if (oldnick == v[i].second) { 
				v[i].second = newnick;
				check = true;
				break;
			}
		}
		if (!check) {
			v.push_back(make_pair(oldnick, newnick)); // v[i].first = oldnick
		}
	}
	quick_sort(v, 0, v.size() - 1);
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << " " << v[i].second << endl;
	}
}
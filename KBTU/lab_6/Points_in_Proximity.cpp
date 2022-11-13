#include <bits/stdc++.h>
using namespace std;

int part(int arr[], int low, int high) {
	int pivot = arr[high];
	int i = low - 1;
	for (int j = low; j < high; j++) {
		if(arr[j] < pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i+1], arr[high]);
	return i+1;
}

void quick_sort(int arr[], int low, int high) {
	if (low < high) {
		int pi = part(arr, low, high);
		quick_sort(arr, low, pi - 1);
		quick_sort(arr, pi + 1, high);
	}
}
int main(){
    int number; cin>>number;
    int min = INT_MAX;
    int arr[number];
    vector <int> vec;
    for(int i = 0 ; i < number ; i++){
          scanf("%d", &arr[i]);
    }

    quick_sort(arr, 0 , number - 1);

    for(int i = 0 ; i < number ; i++){
        int diff = abs(arr[i+1] - arr[i]);
        if(diff < min){
            min = diff;
            vec.clear();
            vec.push_back(arr[i]);
            vec.push_back(arr[i+1]);
        }
        else if(abs(arr[i+1] - arr[i]) == min){
            vec.push_back(arr[i]);
            vec.push_back(arr[i+1]);
        }
    }
    for(int i = 0; i < vec.size(); i++){
         printf("%d ",vec[i]);
    }
}
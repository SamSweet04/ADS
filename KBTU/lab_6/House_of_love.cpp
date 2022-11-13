#include <iostream>
using namespace std;

int part(int arr[], int low, int high){ // partition implementation
    int index = low-1; // ind = -1
    int pivot = arr[high]; // pivot = arr[3] = 1
    for(int j = low ; j < high ; j++){ 
        if(arr[j] < pivot){ //  1 < 1 | 2 < 1 | 2 < 1 
            index++; // index = -1
            swap(arr[index], arr[j]) ; 
        }

    }
    swap(arr[index+1], arr[high]); 
    return index+1; // return 1
}
// 4 2
// 1 2 2 1
// 2 2

// 2 2

void quickSort(int arr[], int low , int high){ // quick sort implementation 
    if(low < high){
        int pi = part(arr, low, high);
        // cout << low << " " << high << endl;
        quickSort(arr, low , pi-1); // typical recursion of quick sorting algorithm
        quickSort(arr, pi+1, high);
    }
}


int main(){ // driver code
    int friend_1, friend_2, tmp = 0;
    cin >> friend_1;
    cin >> friend_2;
    int a[friend_1];
    int b[friend_2];
    for(int i = 0 ; i < friend_1 ; i++){
        cin>>a[i];
    }
    for(int i = 0 ; i < friend_2 ; i++){
        cin>>b[i];
    }
    quickSort(a, 0, friend_1 - 1); // 1 1 2 2
    quickSort(b, 0, friend_2 - 1); // 2 2
    for(int i = 0 ; i < friend_1 ; i++){ // i = 2; i < 4; i++
        for(int j = tmp ; j < friend_2 ; j++){ // j = 1; j < 2; j++
            // cout << i << " " << j << endl;
                if(a[i] == b[j]){ 
                    printf("%d ", b[j]); // 2 
                    tmp = j+1; // tmp = 1
                    // cout << a[i] << " " << b[j] << "loop" << tmp<< endl;
                    break;
                }
                // cout << a[i] << " " << b[j] << " " << tmp<< endl;
            }
    }
}
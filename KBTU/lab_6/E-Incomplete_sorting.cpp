#include<bits/stdc++.h>
using namespace std;

int partition(vector<vector<int>> &v, int low, int high, int col){
    int pivot = v[high][col];
    // cout << pivot << " " << high << " " << col << endl;
    int index = low - 1;
    for(int j = low; j < high; j++){
        if(v[j][col] > pivot){
            index++;
            swap(v[index][col], v[j][col]);
            // cout << v[index][col] << " " << v[j][col] << " "<< pivot << endl;
        }
    }
    swap(v[index + 1][col], v[high][col]);
    return index + 1;
}

void quickSort(vector<vector<int>> &v, int low, int high, int col){
    if(low < high){
        int pi = partition(v, low, high, col);
        quickSort(v, low, pi - 1, col);
        quickSort(v, pi + 1, high, col);
    }
}

int main(){
    int row, col;
    scanf("%d%d", &row, &col);
    vector<vector<int>> v;
    for(int i = 0; i < row; i++){
         vector<int> rows(col);
        for(auto &j : rows) scanf("%d",&j);
        v.push_back(rows);
    }
    for(int i = 0; i < col; i++){
        quickSort(v, 0, row-1, i);
    }
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            printf("%d ", v[i][j]);
        }
        printf("\n");
    }
}
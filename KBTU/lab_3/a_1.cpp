#include <bits/stdc++.h>
using namespace std;
int find(int arr[],int x,int left, int right){ // объ€вл€ем функцию
    if(left > right) return -1;  // если левый индекс больше чем правый, мы вышли из отрезка, -1 выодим
    int mid = left + (right - left)/2;   // индекс среднего элемента
    if(arr[mid] == x) return mid;  // если найдем тот самый элемент выводим его индекс
    else if(arr[mid] < x) return find(arr,x,mid+1,right);  // если не нашли то провер€ем элемент меньше чем х? если да то возрвращаем функцию 
    // но уже с элементом лефт = мид+1, теперь значение левого элемента приравнено к среднему индексу больше на 1
    else return find(arr,x,left,mid-1);  // если значение не меньше а больше искомого числа, то лефт остаетс€, но мы уменьшаем правую часть как средний индекс меньше на 1
}

int des_find(int arr[],int x, int left, int right){
     int mid = left + (right - left)/2;
     if(left > right) return -1;
     if(arr[mid] == x) return mid;
     else if(arr[mid] < x) return des_find(arr,x,left,mid-1);
     else return des_find(arr,x,mid+1,right);
}

int main(){
    int t, n , m;
    cin >> t;
    int a[t];
    for(int i = 0; i < t; i++) cin >> a[i]; // отдельный массив чисел индекст которых нужно найти
    cin >> n >> m;
    int b[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> b[i][j]; // вводим элементы массива
        } 
    }
    int k = 0;
    while(true){
        if(k == t) break;
        bool found = false;
        for(int i = 0; i < n; i++){
            int temp;
            if(i % 2 == 0) temp = des_find(b[i],a[k], 0, m - 1); // если четна€ строка то вызываем дес функцию
            else temp = find(b[i],a[k], 0, m-1);
            if(temp != -1) {
                found = true;
                cout << i << " " << temp;
                break;
        }
        }
        if(!found) cout << -1;
        k++;
        cout << endl;
    }
}

#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t; // 5
    int test[t]; 
    for(int i = 0 ; i < t ; i++)
        cin >> test[i];  // 10 15 13 8 23
    int n, m;
    cin >> n >> m; // 3 4
    int arr[n][m];
    for(int i = 0 ; i < n; i++) {
        for(int j = 0 ; j < m;  j++) {
            cin >> arr[i][j]; // 25 23 2o 19
                            // 13 15 17 18
                            // 12 1o 9 8
        }
    }

    for(int i = 0 ; i < t; i++) { // i < 5
        int x = test[i]; // x = 10 x = 15...
        int li = 0, ri = n;
        while(li + 1 < ri) { // 0+1<3  0+1<3  
            int mid = (li + ri)/2; // 0+3 / 2 = 1  4/2 = 2  1+3 / 2 = 2
            int midNum;
            if(mid % 2 == 0) { // 1 0 0
                midNum = arr[mid][0];  // midNum = arr[2][0] midNum = arr[0][0]
            } else {
                midNum = arr[mid][m-1]; //midNum = arr[1][3]
            }
            if(midNum >= x) // 18 >= 10 13 > 10
                li = mid; // li = 1; li = 1; li = 2
            else
                ri = mid; // ri = 1
        }
        int lj = 0, rj = m;
        if(li%2 == 0) {
            while(lj + 1 < rj) { 
                int mid = (lj + rj)/2; // 2 1 3
                int midNum = arr[li][mid]; // arr[2][2] arr[2][1] qrr[2][3]
                if(midNum >= x) // 9 < 10
                    lj = mid;  // lj = 1
                else
                    rj = mid; // rj = 2
            }
        } else {
            while(lj + 1 < rj) { // 1 < 4
                int mid = (lj + rj)/2; // mid = (0+4)/2 = 2
                int midNum = arr[li][mid]; // arr[2][2]
                if(midNum <= x) 
                    lj = mid; // lj = 2 ;
                else
                    rj = mid;
            }
        }
        int res = arr[li][lj]; // res = arr[2][1]
        if(res == x)
            cout << li << " " << lj << endl; // 2 1
        else
            cout << -1 << endl;
    }

    return 0;
}
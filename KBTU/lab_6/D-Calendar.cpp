#include<bits/stdc++.h>
using namespace std;

struct Date{
    int year;
    int month;
    int day;
};

bool comp(Date a,Date b){ // year, (day, month)
    if(a.year == b.year){ // (a.year == b.year)
        if(a.month == b.month){ // (a.month)
            if(a.day == b.day) return true;
            return a.day < b.day;
        }
        return a.month < b.month;
    }
    return a.year < b.year;
}

int partition(vector<Date> &v, int low, int high){
    Date pivot = v[high];
    int i = low - 1;
    for(int j = low; j < high; j++){
        if(comp(v[j], pivot)){
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[high]);
    return i + 1;
}

void quick_sort(vector<Date> &v, int low, int high){
    if(low < high){
        int pi = partition(v, low, high);
        quick_sort(v, low, pi - 1);
        quick_sort(v, pi + 1, high);
    }
}

int main(){
    int n; cin >> n;
    vector<Date> v(n);
    for(auto &dates : v){
        int d, m, y;
        char z;
        cin >> d >> z >> m >> z >> y;
        dates.year = y;
        dates.month = m;
        dates.day = d;
    }
    quick_sort(v, 0, v.size()-1);
    for(auto i : v){
        (i.day < 10) ? cout << 0 << i.day << "-" : cout << i.day << "-";
        (i.month < 10) ? cout << 0 << i.month << "-" : cout << i.month <<"-";
        cout << i.year<< endl;
    }
}
#include <iostream>
#include <algorithm>
using namespace std;

bool comp(string a, string b){
    string yearsA = a.substr(6, 4);
    string yearsB = b.substr(6, 4);
    
    if(yearsA.compare(yearsB) != 0){
        if(yearsA.compare(yearsB) < 0) return true;
        return false;
    } 


    string monthsA = a.substr(3,2);
    string monthsB = b.substr(3,2);

    if(monthsA != monthsB) return monthsA < monthsB;

    string daysA = a.substr(0, 2);
    string daysB = b.substr(0, 2);

    if(daysA.compare(daysB) < 0) return true;
    return false;
}


int main(){
    int n;
    cin>>n;
    string dates[n];
    for(int i = 0 ; i < n ; i++){
        cin>>dates[i];
    }
    sort(dates, dates + n, comp);
    for(int i = 0 ; i < n ; i++){
        cout<<dates[i]<<endl;
    }
}
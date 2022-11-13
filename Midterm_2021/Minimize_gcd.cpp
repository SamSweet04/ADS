#include <bits/stdc++.h>  
using namespace std;  
int GCD(int x, int y){  
    int gcd = 1;  
    for (int i = 2; i <= min(x,y); i++)  
    {  
        if((x % i == 0) && (y % i == 0)){  
            gcd = i;  
        }  
    }  
    return gcd;  
}  
int main(){  
    int k;  
    cin >> k;  
      
    for (int i = 2; i < k; i++)  
    {  
        for (int j = 3; j <= k / i; j++)  
        {  
            int res = GCD(i, j);  
            if(res == 1){  
                // cout << i << " " << j << endl;  
                if(i * j == k){  
                    cout << i << " " << j;  
                    return 0;  
                }  
        }  
          
    }  
    }  
      
    cout << -1;  
    return 0;  
}

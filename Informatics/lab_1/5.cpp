#include <iostream>
#include <string>
#include <cctype>
#include <stack>
using namespace std;
int main() {
    string s;
    getline(cin, s);
    stack<int> stack;
    for (int i = 0; i < s.size(); i++)
        if (isdigit(s[i]))
            stack.push(s[i] - '0');
        else if (s[i] != ' ') {
            const int a = stack.top();
            stack.pop();
            const int b = stack.top();
            stack.pop();
            if (s[i] == '+')
                stack.push(a + b);
            else if (s[i] == '-')
                stack.push(b - a);
            else
                stack.push(a * b);
        }
    cout << stack.top();
}
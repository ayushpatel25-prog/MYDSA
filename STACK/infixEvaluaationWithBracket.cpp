#include<iostream>
#include<stack>
using namespace std;

int prio(char ch) {
    if(ch == '+' || ch == '-') return 1;
    if(ch == '*' || ch == '/') return 2;
    return 0;
}

int solve(int a, int b, char ch) {
    if(ch == '+') return a + b;
    else if(ch == '-') return a - b;
    else if(ch == '*') return a * b;
    else return a / b;
}

int main() {

    string s = "(2+6)*4/8-3";

    stack<int> val;
    stack<char> op;

    for(int i = 0; i < s.length(); i++) {

        // Digit
        if(s[i] >= '0' && s[i] <= '9') {
            val.push(s[i] - '0');
        }

        // Operator / bracket
        else {

            if(op.size() == 0) {
                op.push(s[i]);
            }

            else if(s[i] == '(') {
                op.push(s[i]);
            }

            else if(op.top() == '(') {
                op.push(s[i]);
            }

            else if(s[i] == ')') {

                // Solve until '('
                while(op.size() > 0 && op.top() != '(') {

                    int a2 = val.top();
                    val.pop();

                    int a1 = val.top();
                    val.pop();

                    char ch = op.top();
                    op.pop();

                    int ans = solve(a1, a2, ch);

                    val.push(ans);
                }

                // Remove '('
                if(op.size() > 0) {
                    op.pop();
                }
            }

            else if(prio(s[i]) > prio(op.top())) {
                op.push(s[i]);
            }

            else {

                while(op.size() > 0 &&
                      op.top() != '(' &&
                      prio(s[i]) <= prio(op.top())) {

                    int a2 = val.top();
                    val.pop();

                    int a1 = val.top();
                    val.pop();

                    char ch = op.top();
                    op.pop();

                    int ans = solve(a1, a2, ch);

                    val.push(ans);
                }

                op.push(s[i]);
            }
        }
    }

    // Remaining operators
    while(op.size() > 0) {

        int a2 = val.top();
        val.pop();

        int a1 = val.top();
        val.pop();

        char ch = op.top();
        op.pop();

        int ans = solve(a1, a2, ch);

        val.push(ans);
    }

    cout << "val is " << val.top();

    return 0;
}
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    stack<int>stack;
    int n;
    
    cin >> n;

    for (int i = 0; i < n; i++){
        int j = 0;
        cin >> j;
        if (j == 1){
            int x;
            cin >> x;
            stack.push(x);
        }
        else if (j == 2){
           if (stack.empty()){
            cout << -1 << '\n';
           }
           else {
            cout << stack.top() << '\n';
            stack.pop();
           }
        }
        else if (j == 3){
            cout << stack.size() <<'\n';
        }
        else if (j == 4){
            if(stack.empty()) cout << 1 <<'\n';
            else cout << 0 << '\n';
        }
        else if (j == 5){
            if(!stack.empty()){
                cout << stack.top() << '\n';
            }
            else cout << -1 << '\n';
        }
    }
    return 0;
}
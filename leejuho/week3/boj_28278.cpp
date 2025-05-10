#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; 
    cin >> n;
    stack<int> s; 
    while(n--){
        int cmd; 
        cin >> cmd; 
        if(cmd==1){
            int x;
            cin >> x;
            s.push(x); 
        }
        else if(cmd ==2){
            if(s.empty()) cout <<-1 <<"\n";
            else { 
                cout << s.top()<< "\n";
                s.pop();
            }
        }
        else if(cmd==3) cout << s.size()<<"\n";

        else if(cmd==4){
            if(s.empty()) cout <<"1"<<"\n";
            else cout << "0"<< "\n";
        }
        else if(cmd==5){
            if(s.empty())cout <<"-1"<<"\n";
            else cout << s.top()<< "\n";
        }
        
    }
    return 0;
}
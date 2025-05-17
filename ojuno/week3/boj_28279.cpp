#include <iostream>
#include <deque>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    deque<int>d;
    int n;
    
    cin >> n;

    for (int i = 0; i < n; i++){
        int j = 0;
        cin >> j;
        if (j == 1){
            int x;
            cin >> x;
            d.push_front(x);
        }
        else if (j == 2){
            int x;
            cin >> x;
            d.push_back(x);
        }
        else if (j == 3){
            if (d.empty()){
                cout << -1 << '\n';
               }
               else {
                cout << d.front() << '\n';
                d.pop_front();
               }
        }
        else if (j == 4){
            if (d.empty()){
                cout << -1 << '\n';
               }
               else {
                cout << d.back() << '\n';
                d.pop_back();
               }
        }
        else if (j == 5){
            cout << d.size() << '\n';
        }   
        else if (j == 6){
            if (d.empty()){
                cout << 1 << '\n';
               }
               else {
                cout << 0 << '\n';
               }
        }
        else if (j == 7){
            if (d.empty()){
                cout << -1 << '\n';
               }
               else {
                cout << d.front() << '\n';
               }
        }
        else if (j == 8){
            if (d.empty()){
                cout << -1 << '\n';
               }
               else {
                cout << d.back() << '\n';
               }
        }
    }
    return 0;
}


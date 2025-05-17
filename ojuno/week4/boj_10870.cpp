// a-1 + a+2 재귀

#include <iostream>
using namespace std;

int fibo(int a);

int main(){

    int a;
    

    cin >> a;

    cout << fibo(a) << endl;


}

int fibo(int a){

    if(a<=1){
        return a;
    }

    return fibo(a-1) + fibo(a-2);
}
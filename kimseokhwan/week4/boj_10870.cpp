#include <iostream>
using namespace std;

int GetFibonacci(int n);


int main(){
int n;
cin>>n;

cout<<GetFibonacci(n);


return 0;

}



int GetFibonacci(int n){

    if(n==0){
        return 0;
    }
    else if(n==1){
        return 1;
    }
    else{
        return GetFibonacci(n-1)+GetFibonacci(n-2);
    }
}
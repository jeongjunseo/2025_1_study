#include <iostream>
#include <string>
using namespace std;

//상태전환을 하기 위한 bool 전역변수
bool mode=false;

int total(string a,int size);

int main(){
    string a;
    cin>>a;
    int size=a.size();
    cout<<total(a,size);

    return 0;

}

//처음 '-'가 나오는 시점 이후에 수를 모두 빼주는 작업을 수행하는 함수수
int total(string a,int size){
    int total=0;
    int num=0;
    string num_str="";
    for(int i=0;i<size;i++){
        if(isdigit(a[i])){
            num_str+=a[i];
        }
        else{
            num=stoi(num_str);
            if(mode){
                total-=num;
            }
            else{
                total+=num;
            }
            if(a[i]=='-'){
                mode=true;
            }
            num_str="";
        }
    }
    num=stoi(num_str);
    if(mode){
        total-=num;
    }
    else{
        total+=num;
    }
    return total;
}
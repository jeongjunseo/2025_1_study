#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

void CantorSet(int n,char *array,int left_idx,int right_idx);

int main(){
int n=0;
while(cin>>n){
    int size=pow(3.0,double(n));
    char *array=new char[size+1];
    for(int i=0;i<size;i++){
        array[i]='-';
    }
    array[size]='\0';
    CantorSet(n,array,0,size-1);
    cout<<array<<endl;
    delete[]array;
}


    return 0;
}




void CantorSet(int n,char *array,int left_idx,int right_idx){
    if(n==0){
        return;
    }    

        int size=right_idx-left_idx+1;
        int division_size=size/3;  //3으로 나눈 사이즈
        int mid_idx=left_idx+division_size;
        for(int i=0;i<division_size;i++){
            array[mid_idx+i]=' ';
        }
        CantorSet(n-1,array,left_idx,mid_idx-1);
        CantorSet(n-1,array,mid_idx+division_size,right_idx);
    
    }


#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int binary_search(string no_hear,string *no_see,int m);


int main(){
int n,m;
cin>>n>>m;
int big_size=n<m ? m:n;

string *no_hear=new string[n];
string *no_see=new string[m];

for(int i=0;i<n;i++){
    cin>>no_hear[i];
}
for(int i=0;i<m;i++){
    cin>>no_see[i];
}

sort(no_hear,no_hear+n);
sort(no_see,no_see+m);

int *idx_array=new int[big_size];
int count=0;


for(int i=0;i<n;i++){
    int k=binary_search(no_hear[i],no_see,m);
    if(k!=m+1){
        count++;
        idx_array[count-1]=k;
    }
}

cout<<count<<endl;
for(int i=0;i<count;i++){
    cout<<no_see[idx_array[i]]<<endl;
}

delete[] no_hear;
delete[] no_see;
delete[] idx_array;

return 0;
}



int binary_search(string no_hear,string *no_see,int m){

int right=m-1;
int left=0;
int middle=0;

while(left<=right){
    middle=(right+left)/2;


    if(no_hear==no_see[middle]){
        return middle;
    }
    else if(no_hear>no_see[middle]){
        left=middle+1;
    }
    else{
        right=middle-1;
    }
}
return m+1;
}
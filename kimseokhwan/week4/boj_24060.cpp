#include <iostream>
using namespace std;

void MergeSort(int array[],int left,int right);
void Merge(int array[],int left,int mid,int right);
int target=0;
int count=1;

int main(){
int n;
int k;
cin>>n>>k;
target=k;
int *array=new int[n];
for(int i=0;i<n;i++){
    cin>>array[i];
}
MergeSort(array,0,n-1);
delete[]array;
if(count<=target){
    cout<<"-1"<<endl;
}
return 0;
}


void MergeSort(int array[],int left,int right){
    int mid=0;
    if(left<right){
        mid=(left+right)/2;
        MergeSort(array,left,mid);
        MergeSort(array,mid+1,right);
        Merge(array,left,mid,right);
    }
}

void Merge(int array[],int left,int mid, int right){
int i=left;
int j=mid+1;
int t=0;
int *temp=new int[right-left+1];
while((i<=mid)&&(j<=right)){
if(array[i]<=array[j]){
temp[t++]=array[i++];
}
else{
    temp[t++]=array[j++];
}

}
while(i<=mid){
    temp[t++]=array[i++];
}
while(j<=right){
    temp[t++]=array[j++];
}
i=left;
t=0;
while(i<=right){
    array[i]=temp[t];
    if(count==target){
        cout<<array[i]<<endl;
    }
    i++;
    t++;
    count++;
}

delete[]temp;
}
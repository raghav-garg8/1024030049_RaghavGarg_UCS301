#include<iostream>
using namespace std;
int missingNum(int arr[], int size){
    for(int i=0; i<size-1; i++){
        if(arr[i+1]-arr[i]!=1){
            return arr[i]+1;
            break;
        }
    }
   return -1; 
}

int missingNum_Binary(int arr[], int size){
    int l=0, r= size-1;
    while(l<=r){
        int mid= l+(r-l)/2;
        if(arr[mid]!=mid+1 && arr[mid-1]==mid){
            return mid+1;
            break;
        }
        if (arr[mid]== mid+1){
            l= mid+1;
        }
        else{
            r= mid-1;
        }
    }
    return -1;
}


int main(){
    int arr[]={1,2,3,5,6};
    int size= sizeof(arr)/sizeof(arr[0]);

    cout<<"The missing number is: "<< missingNum(arr,size) << endl;
    cout<<"The missing number(binary) is: "<< missingNum_Binary(arr,size) << endl; 
    return 0;
}
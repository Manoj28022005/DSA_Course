#include<bits/stdc++.h>
using namespace std;
//THIS CODE WORKS ONLY WHEN THE ELEMENTS ARE IN SORETED ORDER
int binary_search(int arr[],int n,int target) //NON RECURSIVE CODE
{
    int low=0;
    int high=n-1;
    while(low<=high)
    {
       int mid=(low+high)/2;
       if(arr[mid]==target)
       {
        return arr[mid];
       }
       else if(target<arr[mid])
       {
         high=mid-1;
       }
       else
       {
          low=mid+1;
       }
    }
    return -1; 
}

int binary_search_(int arr[],int low,int high,int target) //recursive code
{
    if(low>high)
    return -1;
    else{
        int mid=(low+high)/2;
        if(arr[mid]==target)
        {
            return arr[mid];
        }
        else if(target>arr[mid])
        {
           return binary_search_(arr,mid+1,high,target);
        }
        else{
           return binary_search_(arr,low,mid-1,target);
        }
    }
}

int main()
{
    int arr[100];
    cout<<"ENTER THE SIZE OF AN ARRAY"<<endl;
    int size;
    cin>>size;
    cout<<"ENTER THE ELEMENTS IN AN ARRAY IN SORTED ORDER"<<endl;
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    cout<<"ENTER A NUMBER TO SEARCH FOR"<<" :";
    int k;
    cin>>k;
    int a=binary_search_(arr,0,size-1,k);
    if(a!=-1)
    {
        cout<<"ELEMENT FOUND"<<" :"<<a;
    }
    else
    {
        cout<<"ELEMENT NOT FOUND"<<" :"<<a;
    }
    return 0;
}
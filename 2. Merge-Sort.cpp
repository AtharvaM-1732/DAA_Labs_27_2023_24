#include <iostream>
using namespace std;

#define MAX 99

int merge_R(int a[], int low, int up);
int merge(int a[], int temp[], int low1, int up1, int low2, int up2);
int copy(int a[], int temp[], int low, int up);

int main() {
   int a[]={1,10,5,7,6};
   
   merge_R(a,0,4);

   for(int i=0; i<5; i++)
   {
       cout<<a[i]<<" ";
   }
    return 0;
}

int merge_R(int a[], int low, int up)
{
    int temp[MAX];
    int mid=(low+up)/2;
    if(low<up){
        int mid=(low+up)/2;
    merge_R(a,low, mid);
    merge_R(a,mid+1,up);
    merge(a,temp,low,mid,mid+1,up);
    copy(a,temp,low,up);
    }
}

int merge(int a[], int temp[], int low1, int up1, int low2, int up2)
{
    int i=low1;
    int j=low2;
    int k=low1;
    while(i<=up1 && j<=up2)
        {
            if(a[i]<=a[j])
            {
                temp[k++]=a[i++];
            }
            else
            {
                temp[k++]=a[j++];
            }
            
        }    
    while(i<=up1)
    {
        temp[k++]=a[i++];
    }
    while(j<=up2)
    {
        temp[k++]=a[j++];
    }
    
}

int copy(int a[], int temp[], int low, int up)
{
   for(int i=low; i<=up; i++)
   {
       a[i]=temp[i];
   } 
}

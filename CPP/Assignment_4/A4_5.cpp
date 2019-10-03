// Example program
#include <iostream>
#include <string>
#define MAX 100 //maximam size of array
using namespace std;

int main()
{
  int arr[MAX],n,*p,*q;//declare variables
  
  cout<<"enter size of array: "; //take size of array from user
  cin>>n;
  cout<<"\nenter "<<n<<" values separated by space or newline: ";
  for(int i=0;i<n;++i) // take n values fro user and store it in arr
	  cin>>arr[i];
  
  p = arr; // asign base address of arr to pointer p
  q = &arr[n-1];
 
  for(int i=0;i<(n/2);++i,p++,q--) // print arr values using pointer
  {
	p = (*p) + (*q);
	q = (*p) - (*q);
	p = (*p) - (*q);
  }
  cout<<"\nvalues in reverse order: ";
  for(int i=0;i<n;++i) // take n values fro user and store it in arr
	  cin>>arr[i];
  return 0;
}

// Example program
#include <iostream>
#include <string>
#define MAX 100 //maximam size of array
using namespace std;

int main()
{
  int arr[MAX],n,*p;//declare variables
  
  cout<<"enter size of array: "; //take size of array from user
  cin>>n;
  cout<<"\nenter "<<n<<" values separated by space or newline: ";
  for(int i=0;i<n;++i) // take n values fro user and store it in arr
	  cin>>arr[i];
  
  p = arr; // asign base address of arr to pointer p
  cout<<"\nyou entred this vales: ";
  for(int i=0;i<n;++i) // print arr values using pointer
	  cout<<*(p+i)<<" - ";
  return 0;
}

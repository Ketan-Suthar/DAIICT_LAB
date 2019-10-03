// Example program
#include <iostream>
#include <string>
#define MAX 1000 //maximam size of array
using namespace std;

int main()
{
  int arr[MAX]={-1},n,*p,*q;//declare variables
  
  cout<<"enter size of array: "; //take size of array from user
  cin>>n;
  cout<<"\nenter "<<n<<" values separated by space or newline: ";
  for(int i=0;i<n;++i) // take n values fro user and store it in arr
	  cin>>arr[i];
  
  p = arr; // asign base address of arr to pointer p
  cout<<"\nyou entred this vales: ";
  for(int i=0;i<n;++i) // print arr values using pointer
	  cout<<*(p+i)<<" - ";
	while(1)
	{
		cout<<"===MENU===\n";
		cout<<"1. place order\n";
		cout<<"2. pending orders\n";
		cout<<"3. pick up order";
		cout<<"\n\n\tchoose your option: ";
		
	}
		
  return 0;
}

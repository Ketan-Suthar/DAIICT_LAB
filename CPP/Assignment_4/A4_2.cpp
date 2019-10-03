// Example program
#include <iostream>
#include <string>
#define MAX 100 //maximam size of array
using namespace std;

int main()
{
  int arr[3][4],*p;//declare variables
  
  //cout<<"enter size of array (row and coloum): "; //take size of array from user
  //cin>>m>>n;
  cout<<"\nenter 3X4 values separated by space or newline: ";
  for(int i=0;i<3;++i) // take m*n values fro user and store it in arr
	for(int j=0;j<4;++j)
	  cin>>arr[i][j];
  
  p = arr[0]; // asign base address of arr to pointer p
  cout<<"\nyou entred this vales:\n";
  for(int i=0;i<3;++i) // print arr values using pointer
  {
	for(int j=0;j<4;++j)
	  cout<<*(*(arr+i)+j)<<" - ";
	cout<<"\n";
  }
  return 0;
}

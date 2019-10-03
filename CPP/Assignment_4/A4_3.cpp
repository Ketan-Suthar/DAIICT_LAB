// Example program
#include <iostream>
#include <string>
#define MAX 100 //maximam size of array
using namespace std;

int main()
{
  int arr[2][3][4],*p;//declare variables
  
  //cout<<"enter size of array (row and coloum): "; //take size of array from user
  //cin>>m>>n;
  cout<<"\nenter 3X4 values separated by space or newline: ";
	for(int k=0;k<2;++k)// take m*n values fro user and store it in arr 
	  for(int i=0;i<3;++i) 
		for(int j=0;j<4;++j)
		  cin>>arr[k][i][j];
  
  p = arr[0]; // asign base address of arr to pointer p
  cout<<"\nyou entred this vales:\n";
  for(int k=0;k<2;++k)// print arr values using pointer
	  for(int i=0;i<3;++i) 
	  {
		for(int j=0;j<4;++j)
		  cout<<*(*(*(p+k)+i)+j)<<" - ";
		cout<<"\n";
	  }
  return 0;
}

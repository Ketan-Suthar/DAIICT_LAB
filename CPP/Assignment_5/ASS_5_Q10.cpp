/*
10. then takes a number, say i, as input. It then splits the string into substrings of size i.
 Use two dimensional
 array to store the split substrings and then iterate through this array to display the substrings.*/

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

inline int sizeofstr(char str[])
{
    return strlen(str);
}
void splitString(char str[],char substr[][50],int size)
{
    int ind=0,slen=strlen(str);

    for(int i=0;i<slen;i+=size)
    {
        for(int j=0;j<size && (i+j)<slen;++j)
            substr[ind][j]=str[i+j];
        
        ++ind;
    }
}

int main()
{
    int strlen,substrlen,splitsize,slen=0;
    char str[50]={},substr[50][50]={}; // to store string from user
    cin.getline(str,50);
    slen=sizeofstr(str);
    cout<<"\nEnter split size:: ";
    cin>>splitsize;
    
    if(splitsize<1)
         cout<<"please Enter number greater than 0!!";
    else
    {
        cout<<"string \""<<str<<"\" is split into size of "<<splitsize<<"\n";
        splitString(str,substr,splitsize);
        for(int i=0;i<(slen/splitsize)+1;++i)
            cout<<"\""<<substr[i]<<"\"\n";
    }
	return 0;
}
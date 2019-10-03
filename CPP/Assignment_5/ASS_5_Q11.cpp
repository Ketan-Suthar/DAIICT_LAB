/*
9. then takes another string as input. It then searches for the
 second string in the first string. Do not use library functions for searching in the string.*/

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int isSubstring(char str[],char substr[])
{
	int strind=0,substrind=0,whereFind=0,len=strlen(str)-1,substrlen=strlen(substr)-1;
	bool found=false;

	while(strind<=len && substrind<=substrlen)
	{
		while((str[strind]!=substr[substrind]) && (strind<=len && substrind<=substrlen))
		{
			++strind;
			++whereFind;
			
		}
		while(str[strind]==substr[substrind]  && (strind<=len && substrind<=substrlen))
		{
			
			if(substrind==substrlen)
			{
				found=true;
				break;
			}
			++strind;
			++substrind;
		}
		if(found==true)
			break;
		else
			substrind=0;
		cout<<endl;
	}
	if(found==false)
		return -1;
	else
		return whereFind+1;
}

int main()
{
    int strlen,substrlen,found;
    char str[50]={},substr[50]={}; // to store string from user
    cin.getline(str,50);
    
    cout<<"\nEnter substring:: ";
    cin.getline(substr,50);
    found = isSubstring(str,substr);
    if(found==-1)
         cout<<"\nstring \""<<substr<<"\" is NOT SUBTRING of \""<<str<<"\"";
    else
        cout<<"\nstring \""<<substr<<"\" is SUBTRING of \""<<str<<"\""<<"\n strart at: "<<found;
	return 0;
}

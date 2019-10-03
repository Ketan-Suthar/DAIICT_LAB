/*
4. counts the number of words in it.
*/

#include <iostream>
#include <cstring>
#include <string>
using namespace std;
//to count lenth of words
//return size of word
int countSizeOfWord(char *start,char *end)
{
    int len=0;
    char *temp=start;//point temp to start of word
    //increament len by 1 till temp reaches the end of word
    while(temp<end)
        ++len,++temp;
    return len;
}

int main()
{
    int words[4]={0},len;

    char str[50]={};; // to store string from user
    cin.getline(str,50);
    len = strlen(str);
    char *start;
    for(int i=0;i<len;) // iterate through every word
    {
        start=str+i;
        if(str[i]!=' ')//if letter is not space 
        {
            /* increament i till reach the end of word */
            while(((str[i]>=65 && str[i]<=90) || (str[i]>=97 && str[i]<=122)) && i<len)
                ++i;
            int cnt=countSizeOfWord(start,str+i);//store size of word
            //if size of word is less than 3 then
            //increament count of that size by 1
            if(cnt<4)
                ++words[cnt];
        }
        /* increament i till consecutive space occures */
        while((str[i]==' '|| str[i]=='.'|| str[i]=='!'|| str[i]=='?') && i<len)
                ++i;
    }        
    cout<<"\nIn string string \""<<str<<"\"";
    cout<<"\nNumber of 1 digit words are:: "<<words[1];
    cout<<"\nNumber of 2 digit words are:: "<<words[2];
    cout<<"\nNumber of 3 digit words are:: "<<words[3];
	return 0;
}

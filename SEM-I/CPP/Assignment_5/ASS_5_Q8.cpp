/*
8. checks if string is a palindrome. i.e. symetric about central character.
 Eg. if input is "ABCDCBA" then it is a palindrome. 
*/

#include <iostream>
#include <cstring>
#include <string>
using namespace std;
//recursive function 
bool isPalRec(char str[], int s, int e) 
{ 
    // If there is only one character 
    if (s == e) 
        return true; 

    // If first and last 
    // characters do not match 
    if (str[s] != str[e]) 
        return false; 

    // If there are more than 
    // two characters, check if 
    // middle substring is also 
    // palindrome or not. 
    if (s < e + 1) 
        return isPalRec(str, s + 1, e - 1); 
    return true; 
} 

bool isPalindrome(char str[]) 
{ 
    int n = strlen(str); 

    // An empty string 
    if (n == 0) 
        return false; 
    return isPalRec(str, 0, n - 1); 
} 
int main()
{
    int len;
    char str[50]={}; // to store string from user
    cin.getline(str,50);
    len = strlen(str);
    if(isPalindrome(str))
         cout<<"\nstring \""<<str<<"\" IS PALINDROME";
     else
        cout<<"\nstring \""<<str<<"\" IS NOT PALINDROME";
	return 0;
}

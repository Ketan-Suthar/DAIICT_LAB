/*
2. Write a function that takes two dimensional array of names. It then modifies the array with each name reversed
(i.e. from First-Name <space> Last-Name to Last-Name <space> First-Name.
*/

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

void display(char names[][20])
{
    for(int i=0;i<5;++i)
		cout<<names[i]<<" ";
}
void reverse(char* begin, char* end) 
{ 
    char temp; 
    while (begin < end) { 
        temp = *begin; 
        *begin++ = *end; 
        *end-- = temp; 
    }
} 

// Function to reverse words*/ 
void reverseWords(char* s) 
{ 
    char* word_begin = s; 

    // Word boundary 
    char* temp = s; 

    //to Reversing individual words
    while (*temp) { 
        temp++; 
        if (*temp == '\0') {
            reverse(word_begin, temp - 1); 
        } 
        else if (*temp == ' ' || *temp=='.'|| *temp=='!'|| *temp=='?') { 
            reverse(word_begin, temp - 1); 
            word_begin = temp + 1; 
        } 
    } 

    // Reverse the entire string 
    reverse(s, temp - 1); 
} 

int main()
{
	char names[5][20]={};
	for(int i=0;i<5;++i)
		cin.getline(names[i],20);
	cout<<"\nbefore reversing the names:: ";
	display(names);
	for(int i=0;i<5;++i)
	    reverseWords(names[i]);
	cout<<"\nafter reversing the names:: ";
	display(names);
	
	return 0;
}
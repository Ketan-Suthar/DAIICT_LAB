/*
6. reverses the words in the string. eg. If "this is good" is input, then output should be "good is this".
*/
#include <stdio.h>

// Function to reverse 
//which take starting of word and ending of word
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

// Driver Code 
int main() 
{ 
    char s[] = "hii, i am ketan suthar!how are you?"; 
    char* temp = s; 
    reverseWords(s);
    printf("%s", s); 
    getchar(); 
    return 0; 
} 

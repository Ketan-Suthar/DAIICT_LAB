/*
12. Write a program that takes an input which is a linear equation in two or more variables in
form of a string. It then takes input of variable values. The program then calculates the value
of the variable for whom the input value was not given by user.
Eg. Let's say input string is "y = 15x + 20z + 30". Then, user inputs "y=10", "x=10". So,
the program should find the value of variable 'z'. i.e z = (y - 15x - 30)/20. Substitute the
values and evaluate. You can use library functions that convert strings to numbers etc.
*/

#include <stdio.h> 

// Function to reverse 
//whihc take starting of word and ending of word
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

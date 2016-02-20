#include<iostream>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

const int MAX_STRING_LENGTH = 100;
char* doubleChar(char * source);
void doOneString();

int main()
{
    doOneString();
    // doStringArray();

    return 0;
}

void doOneString()
{
    char input[MAX_STRING_LENGTH];

    cout << "Please enter your string\n";
    // http://stackoverflow.com/a/318799/2750743
    scanf("%[^\n]", input);

    char* result = doubleChar(input);
    cout << "your result is=" << result << endl;

    free(result);
}
/* Например у нас есть слово "хуй" , если мы удвоим каждый
символ этой строки, то у нас получиться "ххууйй"*/
char* doubleChar(char * source)
{
    char* result = (char*)malloc(MAX_STRING_LENGTH * 2);
    for(int i=0; source[i] != 0; ++i) {
        result[i * 2] = source[i];
        result[i * 2 + 1] = source[i];
    }
    return result;
}

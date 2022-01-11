#include <stdio.h>
#include <string.h>

int main(){

    int i ;
    float f;

    int sizeInt = sizeof(int);
    int sizeFloat = sizeof(float);
    int sizeChar = sizeof(char);

    char text[2];
    text[0] = 'h';
    text[1] = 'i';
    printf("%s\n", text);

    int charArr = sizeof(text);

    printf("size of int: %d\n", sizeInt);
    printf("size of float: %d\n", sizeFloat);
    printf("size of char: %d\n", charArr);

    
    char word[] = "hi";
    strcat(word, "hello");

    return 0;
}
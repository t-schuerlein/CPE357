#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;


class math{
        
    int i;
    char c;
};


int main(){
    int a;
    a= 9;
    int arr[10];
    int i;
    for(i = 0; i < 10; i++){
        arr[i] = i *2;
    }

    struct school
    {
        /* data */
        int i;
        char c;
    };

    math v;
    
    int size = sizeof(v);

    printf("size is %d\n", size );

    printf("%d\n", arr[1]);
    printf("I am alive\n");
    return 0;
}
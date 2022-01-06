#include <stdio.h>

struct Player
{

    int i;
    char c;
};

char globe;

int main()
{

    struct Person
    {
        int i;
        char c;
    };

    struct Player goalie;
    int size = sizeof(goalie);

    printf("size of goalie: %d\n", size);

    struct Person john;
    int per_size = sizeof(john);

    printf("size of person: %d\n", per_size);

    printf("size of global char: %d\n", sizeof(globe) );

    return 0;
}
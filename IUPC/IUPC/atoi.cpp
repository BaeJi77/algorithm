#include <cstdio>
#include <stdlib.h>

using namespace std;

int main()
{
    int number = 10;
    char string[25];

    itoa(number, string, 2);
    printf("integer = %d string = %s\n", number, string);
    return 0;
}






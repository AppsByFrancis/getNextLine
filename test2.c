#include <stdio.h>
char *changeArr(char **str)
{
    *str = "pepa";
    return *str;
}

int main ()
{
    char *str;

    str = "ahoj";

    changeArr(&str);
    printf("%s", str);
    return 0;
}
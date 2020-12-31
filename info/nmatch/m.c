#include <stdio.h>

int nextMatch(char *s1, char *s2);
int matchCounter(char *s1, char *s2, int stars);

int combination(int p, int n)
{
    int a;
    int b;
    int i;

    if(p < 0 || p > n)
        return 0;
    a = 1; // a = n * (n - 1) * ... * (n - p + 1)
    i = n - p;
    while(++i <= n)
        a = a * i;
    b = 1; // b = 1 * 2 * 3 * ... * p
    i = 0;
    while(++i <= p)
        b = b * i;
    return (a / b);
}

int nextMatch(char *s1, char *s2)
{
    int starts;

    if(*s2 != '*' && *s1 == *s2)
        return nextMatch(s1 + 1, s2 + 1);
    else if (*s2 != '*')
        return 0;
    starts = 0;
    while(*s2++ == '*')
        starts++;
    return matchCounter(s1, s2 - 1, starts);
}

int matchCounter(char *s1, char *s2, int stars)
{
    int i;
    int r;
    int temp;

    i = 0;
    r = 0;
    while(*s1 != 0)
    {
        while(*s1++ != *s2 && *(s1 - 1) != 0)
            i++;
        s1--;
        if(*s1 == 0 && *s2 != 0)
            return r;
        temp = combination(i, stars + i - 1);
        if(*s1 != 0 || *s2 != 0)
            temp *= nextMatch(s1 + 1, s2 + 1);
        else
            return r + temp;
        r += temp;
        i++;
        s1++;
    }
    return r;
}

int main(int ac, char **av)
{
    /*
    char *s1 = (char *)".bc...bq..bc..c...c..";
    char *s2 = (char *)".*bc**c*";
     f(char, starts) = combination(char, starts + char - 1)
     f(0, 1) * [ f(8, 2) * [ f(9, 1) ] + f(11, 2) * [ f(6, 1) ] + f(15, 2) * [ f(2, 1) ] ]
     + f(5, 1) * 0
     + f(1, 1) * [ f(2, 2) * [ f(6, 1) ] + f(6, 2) * [ f(2, 1) ] ]


     */
    char *s1 = (char *)".bc...bq..bc..c...c..";
    char *s2 = (char *)".*bc**c*";

    int result = nextMatch(av[1], av[2]);
    int com = combination(0, 0);
    printf("%d\n", result);
    return 0;
}

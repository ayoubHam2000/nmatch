#include <stdio.h>


int			nmatch(char *str, char *pat)
{
	if (*str == '\0' && *pat == '\0')
		return (1);
	if (*str == '\0' && *pat == '*')
		return (nmatch(str, pat + 1));
	if (*str == *pat)
		return (nmatch(str + 1, pat + 1));
	if (*pat == '*')
		return (nmatch(str + 1, pat) + nmatch(str, pat + 1));
	return (0);
}

int main(int ac, char **av){
    char *str = ".bc...bq..bc..c...c..";
    char *nn  = ".*bc**c*";

    printf("%d \n", nmatch(av[1], av[2]));
    return 0;
}
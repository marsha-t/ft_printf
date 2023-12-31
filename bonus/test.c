typedef struct test
{
	int x;
}	teststruct;

void ft_put0(teststruct *copy)
{
	teststruct sname;
	sname.x = 0;
	copy = &sname;

}

char *ft_return0(char *str)
{
	return (0);
}

#include <stdio.h>
int main(void)
{
	char *str = "abc";
	str = ft_return0(str);
	if (str == 0)
		printf("null");
}
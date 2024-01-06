#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	int	c;

	c = 65;
	write(1, &c, 1);
	c += 256;
	write(1, &c, 1);
	c -= (256 * 2);
	write(1, &c, 1);
	return (0);
}
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *p = NULL;
	puts("before");
	*p = 0;
	puts("after");
	exit(EXIT_SUCCESS);
}


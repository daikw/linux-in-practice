#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <err.h>

static void chiled()
{
	printf("I'm child! my pid is %d.\n",getpid());
	exit(EXIT_SUCCESS);
}
static void parent(pid_t pid_c)
{
	printf("I'm parent! my pid is %d and the pid of my child is %d.\n", getpid(), pid_c);
	exit(EXIT_SUCCESS);
}

int main(void)
{
	pid_t ret;
	ret = fork();
	if (ret == -1)
		err(EXIT_FAILURE, "fork() failed");
	if (ret == 0) {
		chiled();
	} else {
		parent(ret);
	}
	err(EXIT_FAILURE, "shouldn't reach here");
}


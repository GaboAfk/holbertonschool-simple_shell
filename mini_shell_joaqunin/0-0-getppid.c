#include <stdio.h>
#include <unistd.h>

/**
 *
 */

int main (void)
{
	pid_t ppid, pid;

	ppid = getppid();
	pid = getpid();

	printf("Parent procces of %u %u\n",pid, ppid);

	return (0);
}

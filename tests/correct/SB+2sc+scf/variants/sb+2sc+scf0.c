#include <stdlib.h>
#include <pthread.h>
#include <stdatomic.h>

#include "../sb+2sc+scf.c"

int main()
{
	pthread_t t1, t2;

	if (pthread_create(&t1, NULL, thread_1, NULL))
		abort();
	if (pthread_create(&t2, NULL, thread_2, NULL))
		abort();

	return 0;
}

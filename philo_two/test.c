#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <semaphore.h>

sem_t	forks;
int		counter = 0;

void	*test(void *arg)
{
	sem_wait(&forks);
	counter++;
	(void)arg;
	struct timeval	time;

	gettimeofday(&time, NULL);
	printf("in\n");
//	printf("start %d\n", counter);

	usleep(3000000);
	
	printf("end %d\n", counter);

	sem_post(&forks);

	pthread_exit(NULL);
}

int		main(void)
{
	pthread_t	thread1;
	pthread_t	thread2;
	pthread_t	thread3;
	pthread_t	thread4;
	pthread_t	thread5;

	printf("before\n");

/*	if (pthread_create(&thread1, NULL, test, NULL) != 0)
	{
			perror("pthread_create");
			return (EXIT_FAILURE);
	}

	if (pthread_join(thread1, NULL))
	{
		perror("pthread_join");
		return (EXIT_FAILURE);
	}*/

	sem_init(&forks, 0, 2);

	pthread_create(&thread1, NULL, test, NULL);
	pthread_create(&thread2, NULL, test, NULL);
	pthread_create(&thread3, NULL, test, NULL);
	pthread_create(&thread4, NULL, test, NULL);
	pthread_create(&thread5, NULL, test, NULL);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);
	pthread_join(thread4, NULL);
	pthread_join(thread5, NULL);

	printf("after\n");

	return (EXIT_SUCCESS);
}

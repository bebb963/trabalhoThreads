#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t luke;
sem_t leia;
sem_t vader;
sem_t pula;
sem_t marg;

int a = 0, qtd = 0, i = 0, b = 0;
int rep = 0;

void *thr_Hidrogenio (void *arg)
{
  sem_wait (&vader);
  
  a = 1;

  if (a == 1)
    {
      printf ("H");
      a++;
    }
  if (a == 2)
    {
      printf ("H");
      a++;
    }


  sem_post (&luke);
  a++;

}

void *thr_Enxofre (void *arg)
{
  a = 3;
  sem_wait (&luke);

  printf ("S");
  sem_post (&leia);

  a++;

}

void *thr_Oxigenio (void *arg)
{
  int margem=0;
  sem_wait (&leia);
  a = 4;
  
  if (a == 4)
    {
      printf ("O");
      a++;
      margem++;
    }
  if (a == 5)
    {
      printf ("O");
      a++;
      margem++;
    }
  if(a==6){
        printf("O");
        a++;
        margem++;
    }
  if(a==7){
        printf("O");
        a++;
        margem++;
    }
    sem_post(&marg);
    sem_wait(&marg);
    if(margem==2){
        printf("O");
        margem++;
        a++;
    }
    if(margem==3){
        printf("O");
        margem=0;
        a++;
    }
    a++;
  sem_post (&pula);

}
void *pularlinha (void *arg)
{
    sem_wait(&pula);
    printf("\n");
    a=0;
    sem_post (&vader);
}


int
main ()
{
  pthread_t t1, t2, t3,t4,t5;

  sem_init (&luke, 0, 0);
  sem_init (&leia, 0, 0);
  sem_init (&vader, 0, 2);
  sem_init (&pula, 0, 0);
  sem_init (&marg, 0, 0);

  
  printf ("Numero de linhas: ");
  scanf ("%d", &qtd);

  for (b = 0; b < qtd; b++)
    {

      for (rep = 0; rep < 1; rep++)
	{

	  pthread_create (&t1, NULL, thr_Hidrogenio, NULL);
	  pthread_create (&t2, NULL, thr_Enxofre, NULL);
	  pthread_create (&t3, NULL, thr_Oxigenio, NULL);
	  pthread_create (&t4, NULL, pularlinha, NULL);
	  

	}
      pthread_join (t1, NULL);
      pthread_join (t2, NULL);
      pthread_join (t3, NULL);
      pthread_join (t4, NULL);
      

    }

  return 0;
}

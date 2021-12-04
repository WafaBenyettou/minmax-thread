#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>


int t[10];



void *max(void *arg)
{
    (void) arg;
int i=0;
int maxx=t[i];
while (i<=10)
     if(t[i++]>maxx)
        maxx=t[i];

printf("max est :  %d",maxx);
pthread_exit(NULL);

}


void *min(void *arg)
{
   (void) arg;
int j=0;
int minn=t[j];

while (j<=10)
  if(t[j++]<minn)
    minn=t[j];
    printf("min est :  %d",minn);
    pthread_exit(NULL);
}

int main(void)
{
    int a;
    int i;
    pthread_t thread1;
    pthread_t thread2;

    for(i=0;i<10;i++)
    {
        printf("donner a.\n");
        scanf("%d",&a);
        t[i]=a;
    }

    pthread_create(&thread1, NULL, min,NULL);
    pthread_create(&thread2, NULL, max,NULL);


    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return EXIT_SUCCESS;
}

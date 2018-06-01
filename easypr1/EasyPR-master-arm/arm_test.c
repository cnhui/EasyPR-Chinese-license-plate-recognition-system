#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>



#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <sys/un.h>
#include <pthread.h>
#include <semaphore.h>

char cname[100];

static void connectPthread(void *arg)
{
	//char cname[100];
	//strcpy(cname, (char*)arg);
	system(cname);		
}

int main()
{

	int num = 1,iRet;
	static pthread_t connect_thread;
	int i = 1;
	for(i = 1; i < 8; i++)
	{
		//sprintf(cname, "resources/image/%d.jpg", num++); 
		sprintf(cname, "./demo_arm recognize -p resources/image/test/%d.jpg --svm resources/model/svm.xml --ann resources/model/ann.xml", num++);
		iRet = pthread_create(&connect_thread, NULL, (void *)connectPthread, NULL);
		if (iRet != 0)
		{
			printf("pthread_create detectPthread error.\n");
		}
		sleep(1);
	}
	pthread_join(connect_thread,NULL);

	return 0;
}
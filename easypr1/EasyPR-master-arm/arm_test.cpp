#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <errno.h>
#include <sys/un.h>
#include <pthread.h>
#include <semaphore.h>


void* connectPthread(void *arg)
{
	char cname[1024];
	int num = 1;
	int i;
	for(i = 1; i < 8; i++)
	{
		//sprintf(cname, "resources/image/%d.jpg", num++); 
		sprintf(cname, "./demo_arm recognize -p resources/image/test/%d.jpg --svm resources/model/svm.xml --ann resources/model/ann.xml", num++);
		system(cname);	
		//sleep(1);
	}
	
}

int main()
{
	static pthread_t connect_thread;
		
	//remove("./example.txt");
	int iRet = pthread_create(&connect_thread, NULL, connectPthread, NULL);
	if (iRet != 0)
	{
		printf("pthread_create detectPthread error.\n");
	}
	
	pthread_join(connect_thread,NULL);
	return 0;
}
#if 0
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <errno.h>
#include <sys/un.h>
#include <pthread.h>
#include <semaphore.h>

// /services/data/zhuhairuicapture
//  /services/data/zhuhairuicapture/Cam0

void* connectPthread(void *arg)
{
	char cname[1024];
	int num = 1;
	for(int i = 1; i < 65535; i++)
	{
		//sprintf(cname, "resources/image/%d.jpg", num++); 
		sprintf(cname, "./demo_arm recognize -p resources/image/test/%d.jpg --svm resources/model/svm.xml --ann resources/model/ann.xml", num++);
		system(cname);	
		//sleep(1);
	}
	
}

void* connectPthread1(void *arg)
{
	char cname[1024];
	int num = 1;
	for(int i = 1; i < 65535; i++)
	{
		//sprintf(cname, "resources/image/%d.jpg", num++); 
		sprintf(cname, "./demo_arm recognize -p resources/image/test/Cam0_%d.jpg --svm resources/model/svm.xml --ann resources/model/ann.xml", num++);
		system(cname);	
		//sleep(1);
	}
	
}

int main()
{
	static pthread_t connect_thread;
	static pthread_t connect_thread1;
	
	//remove("./example.txt");
	int iRet = pthread_create(&connect_thread, NULL, connectPthread, NULL);
	if (iRet != 0)
	{
		printf("pthread_create detectPthread error.\n");
	}

	int iRet1 = pthread_create(&connect_thread1, NULL, connectPthread1, NULL);
	if (iRet != 0)
	{
		printf("pthread_create detectPthread error.\n");
	}
	
	pthread_join(connect_thread,NULL);
	pthread_join(connect_thread1,NULL);
	return 0;
}
#endif
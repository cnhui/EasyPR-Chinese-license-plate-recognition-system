#include <stdio.h>
#include <time.h>
#include <stdlib.h>

FILE *in;
#define MAX_LINE_SIZE 1024

int main()
{	
	if ((in = fopen("access_log","wb")) == NULL) //access_log输入文件
	{
		printf("canot find the access_log file!\n");
		exit(0);
	}	
	
	char msg[] = "蓝牌:川A5061WP";
	char msg1[] = "蓝牌:川A5261WP";
	char msg2[] = "蓝牌:川A5361WP";
	
	fwrite(msg,strlen(msg),1,in);//把字符串内容写入到文件
	fwrite(msg1,strlen(msg1),1,in);//把字符串内容写入到文件
	fwrite(msg2,strlen(msg2),1,in);//把字符串内容写入到文件
	
	fclose(in); 

	//puts("");
	
	fflush(NULL);
	return 0;
}
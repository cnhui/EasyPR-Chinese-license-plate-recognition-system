#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/wait.h>  
#include <sys/types.h>

typedef int BOOL;
#define TRUE 1
#define FALSE 0

#define FILE_NAME_LEN_MAX 1000 

int doEasyPR(char* fileName){
    pid_t status;                  
    BOOL doDel = FALSE;
    char delFileCmd[FILE_NAME_LEN_MAX];
    char licenseRecg[FILE_NAME_LEN_MAX];
Del:
    if (doDel == TRUE)
    {
        memset(delFileCmd, 0, sizeof(delFileCmd));
        sprintf(delFileCmd, "rm -fr %s", fileName);
        printf("begin delFileCmd = %s\n", delFileCmd);  
        status = system(delFileCmd);        
        printf("end delFileCmd = %s\n", delFileCmd);  
    }else{
        printf("sleep 30 begin!\n"); 
		memset(licenseRecg, 0, sizeof(licenseRecg));
        sprintf(licenseRecg, "./demo recognize -p %s", fileName);	
        status = system(licenseRecg); 
        printf("sleep 30 end!\n");  
    }

    if (-1 == status){  
        printf("system error!");  
        return -1;
    }  
    else{  
        printf("exit status value = [0x%x]\n", status);  
         
        if (WIFEXITED(status)){  
            if (0 == WEXITSTATUS(status)){  
                printf("run shell script successfully.\n");
                if(!doDel)
                {
                    //doDel = TRUE;    
                    //goto Del;
                }  
            }  
            else{  
                printf("run shell script fail, script exit code: %d\n", WEXITSTATUS(status));  
                return -2;
            }  
        }  
        else{  
            printf("exit status = [%d]\n", WEXITSTATUS(status));  
            return -3;
        }  
    }
    doDel = FALSE;

    return 0;  
}

int readFileList(char *basePath)
{
    DIR *dir;
    struct dirent *ptr;
    char base[FILE_NAME_LEN_MAX];
    char fileName[FILE_NAME_LEN_MAX];

    if ((dir = opendir(basePath)) == NULL){
        perror("Open dir error...");
        exit(1);
    }

    while ((ptr = readdir(dir)) != NULL){
        if(strcmp(ptr->d_name,".") == 0 || strcmp(ptr->d_name, "..") == 0)    ///current dir OR parrent dir
            continue;
        else if(ptr->d_type == 8){    ///file
            memset(fileName, 0, sizeof(fileName));
            sprintf(fileName, "%s/%s", basePath, ptr->d_name);
            printf("d_name file:%s/%s\n", basePath, ptr->d_name);
            doEasyPR(fileName);
        }
        else if(ptr->d_type == 10){    ///link file
            printf("d_name link file:%s/%s\n", basePath, ptr->d_name);
        }
        else if(ptr->d_type == 4){    ///dir
            memset(base, '\0', sizeof(base));
            strcpy(base, basePath);
            strcat(base, "/");
            strcat(base, ptr->d_name);
            readFileList(base);
        }
    }
    closedir(dir);
    return 1;
}

int main(void)
{
    DIR *dir;
    char basePath[1000];

    ///get the current absoulte path
    memset(basePath, '\0', sizeof(basePath));
    getcwd(basePath, 999);
    printf("the current dir is : %s\n", basePath);

    ///get the file list
    memset(basePath, '\0', sizeof(basePath));
    //strcpy(basePath, "./XL");
    strcpy(basePath, "./resources/image/native_test/");
    readFileList(basePath);
    return 0;
}

      

#ifndef __basic_h__
#define  __basic_h__
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <iterator> 
#include <string>
using namespace std; 
#ifdef  __cplusplus
extern  "C" {
#endif 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <fcntl.h> //O_CREATE O_EXCL
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/socket.h>
#include <sys/un.h> 
#include <netinet/in.h>
#include <arpa/inet.h>
#include <getopt.h>
#include <stdarg.h>
#include <sys/ioctl.h>
#include <sqlite3.h>
#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#define FUNCINFO {printf("%s(): '%s'@%d\n", __FUNCTION__, __FILENAME__, __LINE__);}
#define FUNCPRINTF(...) {printf("%s()@'%s'@%d:", __FUNCTION__, __FILENAME__, __LINE__);printf(__VA_ARGS__);fflush(stdout);}
#define CLASSINFO {printf("%s(%p): '%s'@%d\n", __FUNCTION__, (void *)this, __FILENAME__, __LINE__);}
#ifdef  __cplusplus
}
#endif 
#endif /*__basic_h__*/


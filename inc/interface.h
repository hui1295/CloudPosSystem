/*******************************************************************************
*Author:   mahonesun
*E-mail:   vipszp@vip.qq.com
*Add:      https://github.com/mahonesun/CloudPosSystem
*Version:  v1.0
*******************************************************************************/
#ifndef _INTERFACE_H_
#define _INTERFACE_H_
#ifdef __cplusplus
extern "C"{
#endif

/*------------------------------------------------------------头文件包含------------------------------------------------------------*/
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <netdb.h>
#include <iconv.h>
#include <memory.h>
#include <sqlite3.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

/*------------------------------------------------------------宏定义----------------------------------------------------------------*/
//-----------------网络--------------------//
#define PORT 13401
//#define IP "192.168.0.9"
#define MAX_LOG 20
#define MAX_CN_CNT 1024
#define BUF_LEN 2048  //接收缓冲区大小
#define MSG_LEN 128	//一条信息的长度大小

//-----------------本地文件---------------//
#define FILE_PATH "/dev/usb/lp0"
#define DATABASE_PATH "./BD4P-Base.db"

//-----------------命令处理---------------//
#define START "#"
#define MAO ":"
#define DOU ","	
#define END "\n"

//-----------------返回码-----------------//
//打印机相关错误
#define PRN_OFFLINE_ERR 601		//打印机离线
#define PRN_BUSY_ERR 503			//打印机忙
#define PRN_PAPER_LACK_ERR 602		//打印机缺纸
#define PRN_UNKNOWN_ERR 998		//打印机未知错误
#define PRN_SUCCESS 200			//打印成功

//连接相关
#define CON_SUCCESS 200
#define CON_FAILED 201
#define CON_AUTHOR_ERR 401		//授权错误

//RPS响应码，同HTTP响应码
#define RPS_SUCCESS 200			//成功
#define RPS_REQUEST_ERR 400		//错误请求（通常是不认识命令）
#define RPS_AUTHOR_ERR 401		//授权错误
#define RPS_UNABLE_ERR 503			//服务不允许，通常是设备忙


#define NOT_CONNECT 6  //随便定义一个整数，用作resolve返回值

/*------------------------------------------------------------函数声明--------------------------------------------------------------*/
int utf8togb2312(char *sourcebuf,size_t sourcelen,char *destbuf,size_t destlen);
int print(int fd, char* buf);
int print_GB(int fd, char* buf);
int print_head(int fd,char* EmployeeID, char* PointID,char* SaleID,char* processNum);
int print_tail(int fd,char* ShoudPay, char*ActualPay);
char *getCurrentTime();
int print_sline(int fd);
int print_dline(int fd);
int print_bitmap(int fd,const char src[625]);
int callback(void* bmp_buff, int count, char** value, char** name);
int print_single(int fd,char* ProductName, char* ProductCnt, char* ProductUnitPrice, char* SumMoney);

int resolve(int sockfd, char* msg);
int RPS_send(int socdfd, char* dev,char* ser, char* last_cmd, int rps_code, int rps_refer);
void charge_ret(int sockfd, int ret);
void* pthread_func(void* arg);



#ifdef __cplusplus
}
#endif
#endif



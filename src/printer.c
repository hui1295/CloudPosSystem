/*******************************************************************************
*Author:   mahonesun
*E-mail:   vipszp@vip.qq.com
*Add:      https://github.com/mahonesun/CloudPosSystem
*Version:  v1.0
*******************************************************************************/
#include "../inc/interface.h"


/***************************************************************************************************************
*函数功能：UTF-8编码转换成GB2312编码
*传入参数：sourcebuf：源数据缓冲区
*		    sourcelen：源数据长度
* 		    destbuf：	存放转换后数据的目标缓冲区	
* 		   destlen：	目标数据长度
*返回值：    正常为0
***************************************************************************************************************/
int utf8togb2312(char *sourcebuf,size_t sourcelen,char *destbuf,size_t destlen)
{
	iconv_t cd;
   	 char **source = &sourcebuf;
	char **dest = &destbuf;
	if( (cd = iconv_open("gb2312","utf-8")) ==0 )		   
	{
		printf("UTF-to-GB2312 trans error!\n");
		return -1;
	}
	memset(destbuf,0,destlen);
	if(-1 == iconv(cd,source,&sourcelen,dest,&destlen))
	{
		printf("UTF-to-GB2312 trans error!\n");
		return -1;
	}
	iconv_close(cd);
	/*sprintf(destbuf,"%s",sourcebuf);*/
	return 0;
}


/***************************************************************************************************************
*函数功能：打印UTF-8编码的数据
*传入参数：fd：打印机的设备文件
*		    buf：将打印的UTF-8数据
*返回值：    正常为PRN_SUCCESS，出错为PRN_UNKNOWN_ERR
***************************************************************************************************************/
int print(int fd, char* buf)
{
	/*if( (strcmp(mode,"left")!=0) && (strcmp(mode,"middle")!=0) && (strcmp(mode,"right")!=0) )//模式判断
	{
		
	}*/
	int k = 0;
	int len = strlen(buf)+1;
	if(len > MAX_CN_CNT)
	{
		len = MAX_CN_CNT;//限制最大长度
	}	 

	int i = 0;
	unsigned char gb[MAX_CN_CNT] = {0};
	unsigned short gb2[MAX_CN_CNT] = {0};
	
	utf8togb2312(buf, len, gb,MAX_CN_CNT);
	while(gb[i] != 0)	
	{
		if(gb[i] & 0x80)
		{
			gb2[k] = gb[i+1];
			gb2[k] = (gb2[k] << 8);
			gb2[k] += gb[i];
			i+=2;
			k++;
		}
		else
		{
			gb2[k++] = gb[i++];
		}
	}
	i = 0;
	while(gb2[i]!= 0)
	{
		write(fd, &gb2[i], 2);
		i++;
	}
	if(write(fd, "\x0d\x0a", 2)==0);
	{
		return PRN_UNKNOWN_ERR;
	}
	return PRN_SUCCESS;
	/*
	 打印机缺纸返回：PRN_PAPER_LACK_ERR
	 打印机忙返回：PRN_BUSY_ERR
	 以上两种状态需要打印机接口为串口或者以太网口，此处是USB接口，无法用read函数获取信息
	*/
}

/***************************************************************************************************************
*函数功能：打印GB2312编码的数据
*传入参数：fd：打印机的设备文件
*		    buf：将打印的GB2312数据
*返回值：    正常为PRN_SUCCESS，出错为PRN_UNKNOWN_ERR
***************************************************************************************************************/
/***************************************************************************************************************
*关于print函数和print_GB的说明：
*1、前者是用于打印UTF-8编码的，后者是用于打印GB2312编码的，
*2、前者在函数中调用了UTF-8转GB2312的函数即utf8togb2312，而后者此调用语句用sprintf(gb,"%s",buf);语句
*	来替换，其它地方完全一样
*3、前者主要用于非外来字符打印，后者用于外来字符打印。
*	如：直接在代码中写死的中英文调用前者，外来数据的打印（可中英文混输）采用后者
*4、总结：非外来字符（即本linux中使用的）在linux系统中默认是UTF-8编码，因此需要转换成GB2312打印
*	   外来字符默认是以GB2312编码发送过来的，因此不需要转换即可完成打印
*	   因为打印机只支持GB2312编码打印
***************************************************************************************************************/
int print_GB(int fd, char* buf)
{
	/*if( (strcmp(mode,"left")!=0) && (strcmp(mode,"middle")!=0) && (strcmp(mode,"right")!=0) )//模式判断
	{
		
	}*/
	int k = 0;
	int len = strlen(buf)+1;
	if(len > MAX_CN_CNT)
	{
		len = MAX_CN_CNT;//限制最大长度
	}	 

	int i = 0;
	unsigned char gb[MAX_CN_CNT] = {0};
	unsigned short gb2[MAX_CN_CNT] = {0};
	
	sprintf(gb,"%s",buf);
	//utf8togb2312(buf, len, gb,MAX_CN_CNT);
	while(gb[i] != 0)	
	{
		if(gb[i] & 0x80)
		{
			gb2[k] = gb[i+1];
			gb2[k] = (gb2[k] << 8);
			gb2[k] += gb[i];
			i+=2;
			k++;
		}
		else
		{
			gb2[k++] = gb[i++];
		}
	}
	i = 0;
	while(gb2[i]!= 0)
	{
		write(fd, &gb2[i], 2);
		i++;
	}
	if(write(fd, "\x0d\x0a", 2)==0);
	{
		return PRN_UNKNOWN_ERR;
	}
	return PRN_SUCCESS;
	/*
	 打印机缺纸返回：PRN_PAPER_LACK_ERR
	 打印机忙返回：PRN_BUSY_ERR
	 以上两种状态需要打印机接口为串口或者以太网口，此处是USB接口，无法用read函数获取信息
	*/
}
/*工号，收银终端号，销售单号,流水号*/
/***************************************************************************************************************
*函数功能：打印头部（即“BEG”命令的具体操作，开始打印）
*传入参数：fd：   打印机设备文件
*	   	   EmployeeID：          工号
*		   PointID：                 收银终端号	
*	 	   SaleID： 		 销售单号
*		   processNum： 	流水号
*返回值：	成功为PRN_SUCCESS
***************************************************************************************************************/
int print_head(int fd,char* EmployeeID, char* PointID,char* SaleID,char* processNum)
{
	char buf1[MAX_CN_CNT]={0};
	char buf2[MAX_CN_CNT]={0};
	
	sprintf(buf1,"工号%8s         机号%s",EmployeeID,PointID);
	sprintf(buf2,"单号%8s         流水号%s",SaleID,processNum);	
	print(fd,"                         ");
	print(fd,"        欢迎来到本商店 ");
	print(fd,"                         ");
	print(fd,buf1);
	print(fd,buf2);	
	print(fd,"                         ");
	print(fd,"品名      数量    单价    金额 ");
	print_sline(fd);
	return PRN_SUCCESS;
	
}
/*打印尾部，参数列表：种类数量，总件数，金额总数(即应收金额)，现金收入*/
//#TRP:END,<单号>,<流水号>,<应收>,<实付>,<找零>,<税金>\n
/***************************************************************************************************************
*函数功能：打印尾部（即“END”命令的具体操作，结束打印）
*传入参数：fd：   打印机设备文件
*	   	   ShoudPay：          应收
*		   ActualPay：          实付
*返回值：	成功为PRN_SUCCESS
***************************************************************************************************************/
int print_tail(int fd,char* ShoudPay, char*ActualPay)
{
	char buf[MAX_CN_CNT]={0};
	sprintf(buf,"应付:%s  实付:%s  找零:%d  ",ShoudPay,ActualPay,atoi(ActualPay)-atoi(ShoudPay));
	print_dline(fd);
	print(fd,buf);
	print(fd,"请保留此小票作为唯一退换货凭证");
	print(fd,"小票限一个月内可开发票");
	print(fd,getCurrentTime());
	write(fd, "\x0a\x0a",2 );/*换行走纸*/
	return PRN_SUCCESS;
	
}
/***************************************************************************************************************
*函数功能：获取当前时间
*传入参数：无
*返回值：返回当前时间的字符串，并以回车符结束
***************************************************************************************************************/
char *getCurrentTime()
{
		time_t now;
		struct tm *timenow;/*在标准C/C++中，我们可通过tm结构来获得日期和时间*/
		time(&now);								
		/*函数名: asctime   功 能: 转换日期和时间为相应的ASCII码，返回字符串格式：星期，月，日，小时，分，秒，年*/
		timenow=localtime(&now);
		return asctime(timenow);
}
/*设置当前店面电话，传入新电话字符串*/
/*
char* SetPhoneNum(char* NewPhoneNum)
{
	PHONENUM=NewPhoneNum;
	return PHONENUM;
}
*/
/***************************************************************************************************************
*函数功能：打印单横线（即“SLI”命令的具体操作）
*传入参数：fd：   打印机设备文件
*返回值：	成功为PRN_SUCCESS，失败为PRN_UNKNOWN_ERR
***************************************************************************************************************/
int print_sline(int fd)
{	
	if(print(fd,"-------------------------------")==0);	//纸宽31
	{
		return PRN_UNKNOWN_ERR;
	}
	return PRN_SUCCESS;	
}
/***************************************************************************************************************
*函数功能：打印双横线（即“DLI”命令的具体操作）
*传入参数：fd：   打印机设备文件
*返回值：	成功为PRN_SUCCESS，失败为PRN_UNKNOWN_ERR
***************************************************************************************************************/
int print_dline(int fd)
{	
	if(print(fd,"===============================")==0);
	{
		return PRN_UNKNOWN_ERR;
	}
	return PRN_SUCCESS;	
}


/***************************************************************************************************************
*函数功能：打印位图（即“BMP”命令的具体操作）
*传入参数：fd：  				 打印机设备文件
*                    const char src[625]：     位图数据
*返回值：   成功为PRN_SUCCESS
*特别说明：位图像素应为 200*25，设置为单色编码，生成的数据数组大小为625
***************************************************************************************************************/
int print_bitmap(int fd,const char src[625])
{
	write(fd, "\x1b\x40", 2);	//初始化
	//write(fd, "\x1d\x76\x30\x3\x19\x0\xc8\x0", 8);
	write(fd, "\x1d\x76\x30\x3\x19\x0\x19\x0", 8);
	int i=0;	
	for(i=0;i<625;i++)//<625
	{	
		write(fd,&src[i],1);	
		//if(write(fd,&src[i],1)==0);
			//return PRN_UNKNOWN_ERR;		
	}	
	return PRN_SUCCESS;

}
/*数据库查询的回调函数*/
int callback(void* bmp_buff, int count, char** value, char** name)
{
	
	char* temp=(char*)bmp_buff;	
	strcpy(temp,value[0]);
	bmp_buff=temp;						

	return 0;
}
/***************************************************************************************************************
*函数功能：打印单行销售记录（即“REC”命令的具体操作）
*传入参数：fd：  			 打印机设备文件
*          ProductName：     品名
*          ProductCnt：      数量
*          ProductUnitPrice：单价
*          SumMoney：        金额
*返回值：  成功为PRN_SUCCESS
***************************************************************************************************************/
int print_single(int fd,char* ProductName, char* ProductCnt, char* ProductUnitPrice, char* SumMoney)
{
	char buf1[MAX_CN_CNT]={0};
	char buf2[MAX_CN_CNT]={0};
	sprintf(buf1,"%s",ProductName);
	sprintf(buf2, "         %s       %s      %s ",ProductCnt,ProductUnitPrice,SumMoney);	//品名      数量    单价    金额 
	print(fd,buf1);
	print(fd,buf2);
	return PRN_SUCCESS;	
}




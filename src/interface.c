#include "../inc/interface.h"


/*
  # <三位设备码> : <三位命令码>, <序列号>, <字段1> , <字段2> , …. \n  
*/

/*-----------------------------------------------------------全局变量------------------------------------------------------------*/
const unsigned char logoimage[625]={ /* 0X00,0X01,0XC8,0X00,0X19,0X00, */
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0XFF,0XFF,0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X03,0XFF,0XFF,0XC0,0X40,
0X04,0X00,0X00,0X30,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X03,0XFF,0XFF,0XE3,0XFF,0XFF,0X87,0XF8,0X30,0X0F,0XE2,0XFC,
0X04,0X03,0X00,0X00,0X00,0X03,0XFC,0X00,0X00,0X00,0X00,0X00,0X00,0X07,0XFF,0XFF,
0XF1,0XE0,0X0F,0X06,0XFE,0X3E,0X0F,0XFF,0XFC,0X1F,0XBF,0XF8,0X00,0X00,0X07,0XFF,
0X00,0X00,0X00,0X00,0X00,0X00,0X07,0XFE,0X7F,0XF0,0X60,0X00,0X06,0XF7,0X30,0X00,
0X08,0X00,0X1F,0X30,0X00,0X00,0X00,0X0E,0X07,0X80,0X00,0X00,0X00,0X00,0X00,0X07,
0XFE,0X03,0XF3,0XFF,0XB0,0X06,0XBB,0X30,0X00,0X08,0X00,0X04,0X3F,0XE0,0X00,0X00,
0X1C,0X03,0X80,0X00,0X00,0X00,0X10,0X00,0X07,0XFE,0X03,0XF1,0X8C,0X3F,0X86,0XBF,
0X30,0X00,0X08,0X00,0X04,0X30,0X70,0X00,0X01,0XFC,0X01,0XC0,0X0F,0XE1,0XF8,0X7E,
0X00,0X07,0XFE,0X27,0XF1,0XFF,0X37,0X06,0XB2,0X30,0X00,0X08,0X00,0X04,0X20,0X18,
0X00,0X03,0XFE,0X00,0XC0,0X0F,0XF3,0X9C,0X77,0X00,0X07,0XF0,0X07,0XF1,0XA9,0XA6,
0X06,0XB2,0X78,0X00,0X08,0X00,0X04,0X20,0X18,0X00,0X07,0X0F,0X00,0XF8,0X0C,0X37,
0X0E,0XC3,0X00,0X07,0XF0,0X03,0XF1,0XFF,0X86,0X06,0XB2,0X7E,0X00,0X08,0X00,0X04,
0X20,0X18,0X00,0X06,0X03,0X00,0X7C,0X0C,0X37,0X06,0XE0,0X00,0X07,0XF3,0XE3,0XF1,
0XFF,0X86,0X07,0XFF,0X63,0X00,0X08,0X00,0X04,0X20,0X18,0X00,0X0E,0X00,0X00,0X0E,
0X0C,0X76,0X06,0X7E,0X00,0X07,0XF0,0X03,0XF1,0XCD,0X02,0X07,0XFF,0X43,0X00,0X08,
0X00,0X04,0X20,0X18,0X00,0X0C,0X00,0X00,0X07,0X0F,0XE6,0X06,0X3F,0X00,0X07,0XF0,
0X13,0XF1,0XFF,0X82,0X07,0XB0,0X42,0X00,0X08,0X00,0X06,0X20,0X18,0X00,0X0E,0X00,
0X00,0X07,0X0F,0X87,0X06,0X03,0X80,0X07,0XE0,0X03,0XF0,0XAA,0X00,0X03,0XFE,0X42,
0X00,0X08,0X00,0X06,0X20,0X18,0X00,0X0E,0X03,0X00,0X07,0X0C,0X07,0X0E,0XC3,0X80,
0X07,0XE2,0X01,0XF0,0XFF,0XFE,0X00,0X30,0X42,0X00,0X08,0X00,0X02,0X30,0X18,0X00,
0X06,0X03,0X00,0X06,0X0C,0X03,0XDC,0XF7,0X80,0X07,0XE6,0X53,0XF0,0XFE,0X3F,0X07,
0XFC,0X42,0X00,0X08,0X00,0X02,0X20,0X18,0X00,0X07,0X8F,0X00,0X0E,0X0C,0X01,0XF8,
0X7F,0X00,0X07,0XFF,0XFF,0XF0,0XC4,0X19,0X07,0XFE,0X62,0X00,0X08,0X00,0X06,0X30,
0X18,0X00,0X03,0XFF,0XFF,0XFC,0X00,0X00,0X20,0X00,0X00,0X07,0XFF,0XFF,0XF0,0XCE,
0X19,0X03,0X4E,0X7E,0X00,0X08,0X00,0X02,0X30,0X18,0X00,0X00,0XFF,0XFF,0XF8,0X00,
0X00,0X00,0X00,0X00,0X07,0XFF,0XFF,0XF3,0XFF,0XFF,0X83,0X4B,0X7E,0X0F,0XFF,0XFC,
0X1F,0X10,0X18,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X03,0XFF,0XFF,
0XE0,0X00,0X00,0X02,0X40,0X62,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X01,0XFF,0XFF,0XC0,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0XFF,0XFF,0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,};

int connectted_flag=0; //已经连接成功的标志，初始状态为 0表未连接  1表示已经连接，
char* dev,*cmd,*ser,*data;	//用作提取内容的存放
pthread_t tid;
char msg[MSG_LEN]={0};
char recv_buf[BUF_LEN]={0};
int printer_fd =0; 			//打印机设备文件


int main()
{
	printer_fd = open(FILE_PATH, O_RDWR);			//首先打开打印机设备文件
	printf("after open printer_fd= %d\n",printer_fd);
/*-----------------------------------------------------------socket------------------------------------------------------------*/
	struct sockaddr_in server_addr;	
	int sockfd=-1;
	int cnt = 0;	
	int afd = 0;
	int reuse =1;
		
	//socket
	sockfd=socket(PF_INET, SOCK_STREAM, 0);
	if(-1==sockfd)
	{
		perror("socket error!");
		return -1;
	}
	//init
	server_addr.sin_family = PF_INET;
	server_addr.sin_port = htons(PORT);
	server_addr.sin_addr.s_addr =htonl(INADDR_ANY); //inet_addr(IP);
	setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&reuse,sizeof(int));//SO_REUSEADDR 这个套接字选项通知内核，如果端口忙，但TCP状态位于 TIME_WAIT ，可以重用端口
	//bind
	if(-1==bind(  sockfd,  (struct sockaddr*)&server_addr,  sizeof(struct sockaddr_in)  )   )
	{
		perror("bind error!");
		return -1;
	}
	//listen
	if(-1== listen(sockfd, MAX_LOG))
	{
		perror("listen error!");
		return -1;
	}
	

	while(1)
	{
		memset(msg,'\0',sizeof(msg));
		printf("now is waitting accept..........\n");
		//accept		
		afd = accept(sockfd, NULL, NULL);
		if(afd < 0 )
		{
			perror("accept error!");
			continue;
		}
		pthread_create(&tid, NULL, pthread_func, (void*)afd);
		//pthread_detach(tid);	
		//pthread_join(tid, NULL);	
	}
	 shutdown(sockfd,SHUT_RDWR); 
	 close(afd);
	 
	
	return 0;
}
/***************************************************************************************************************
*函数功能：处理一条信息
*传入参数：sockfd：与这条信息对应的socket
*		    msg：  具体信息
*返回值：	正常为0
***************************************************************************************************************/
int resolve(int sockfd, char* msg)
{
	char *p = msg;
	printf("function resolve is resolving msg:%s\n",msg);	
	if( (p[0]!='#') || (p[4]!=':') || (p[8]!=',') /*|| (p[12]!=',')*/  )
	{
		printf("format error!\n");
		return -1;
	}
	p++;
/*-----------------------------------------------------------提取内容------------------------------------------------------------*/
	
	dev = strtok(p,MAO);				//设备码
	cmd = strtok(NULL,DOU);				//三位命令码
	ser = strtok(NULL,DOU);				//序列号
	data = strtok(NULL,END);				//数据	
	
	printf("dev=%s  cmd=%s  ser=%s  data=%s\n",dev,cmd,ser,data);
	
	sqlite3 *pDatabase;
	char *errmsg;	
	int ret = sqlite3_open(DATABASE_PATH, &pDatabase);	
	//-----------------------------------------------------------连接请求------------------------------------------------------------//
	
	if(strcmp(cmd,"CON")==0)    //如果是连接命令
	{
		if( (strcmp(dev,"IPA")!=0) && (strcmp(dev,"AND")!=0) )
		{
			printf("device is not ipad or android!\n");
		}
		//  #AND:CON,序列号，终端号，用户名，密码，联接码\n  //
		//printf("before data=%s\n",data);
		
		char* pdata =data;				
		char* PointID =  strtok(pdata,DOU);			//终端号		
		char* UserName = strtok(NULL,DOU);		//用户名		
		char* Pwd = strtok(NULL,DOU);			//密码		
		char* ConnectCode = data+strlen(PointID)+strlen(UserName)+strlen(Pwd)+3;	//联接码		
		//printf("PointID=%s  UserName=%s  Pwd=%s  ConnectCode=%s\n",PointID,UserName,Pwd,ConnectCode);

		if (SQLITE_OK != ret)
		{
			printf("open Database failed!\n");	
			return -1;
		}


		/*-------------从数据库获取用户名和密码--------------------
		char sql_buff[256]={0};
		char NameBuff[32]={0};
		char PwdBuff[32]={0};
		
		char **resultp={0};
		int nrow=0;
		int ncolumn=0;
		
		sprintf(sql_buff, "select * from Setting");	
		if (sqlite3_get_table(pDatabase, sql_buff, &resultp, &nrow,&ncolumn, &errmsg) != SQLITE_OK)
		{
			printf("exec fail! %s\n", errmsg);
		}
		
		int i = 0;
		for(i=0; i<(nrow+1)*ncolumn; i++)
		{
			//if(i%ncolumn==0  &&  i!=0)	//查询到一条记录完毕
			if( i%ncolumn==0 )	//查询到一条记录开始
			{
				strcpy(NameBuff,resultp[i]);
				strcpy(PwdBuff,resultp[i+1]);
			}
			
		}*/		
		//-------------对比用户名和密码--------------------//
		if( (strcmp(UserName,"admin")==0)   &&  (strcmp(Pwd,"123456")==0) && (strcmp(ConnectCode,"111111")==0) )	//	通过验证，置已连接标志为1
		{ 
			connectted_flag=1;		
			printf("username and password is right! conncet successful!\n");			
			RPS_send(sockfd,"BDD", ser,cmd, CON_SUCCESS, CON_SUCCESS);		//连接成功，描述：连接成功
		}
	
		else		//继续接收下一次请求
		{
			connectted_flag=0;
			printf("username and password is not correct! try again!\n");		
			RPS_send(sockfd,"BDD", ser,cmd, CON_FAILED,CON_AUTHOR_ERR);		//连接错误，描述：授权错误
			return NOT_CONNECT;
		}
		
	}
	else		//否则不是连接命令
	{
		if(1 == connectted_flag)		//在已经成功登录连接的情况下才处理  其它的命令，否则不处理
		{
			//printf("in the if of connectted_flag==1, msg=%s\n",msg);
			 if(strcmp(cmd,"RPS")==0)
		/*------------------------------------------------------------响应-------------------------------------------------------------------*/
			{
				//响应码用作发送，不会接收到，  不作处理
			}
		/*-----------------------------------------------------------打印字符串------------------------------------------------------------*/
			else if(strcmp(cmd,"STR")==0)
			{
				char* pdata = data;
				char* mode = strtok(pdata,DOU);			//提取模式
				char* content = (pdata+strlen(mode)+1);		//提取内容
				printf("\n in STR dev=%s  cmd=%s  ser=%s  data=%s\n",dev,cmd,ser,data);
				printf("in STR  mode=%s  content=%s \n",mode,content);
				printf("recv chinese code: %02x，%02x，%02x，%02x\n",content[0] & 0xFF,content[1] & 0xFF,content[2] & 0xFF,content[3] & 0xFF);
				if( (strcmp(mode,"left")==0) || (strcmp(mode,"middle")==0) || (strcmp(mode,"right")==0))	//判断模式，暂不处理，后期完善
					{		
						if(printer_fd <= 0) 
						{
							printf("open printer device error!\n");
							RPS_send(sockfd, "PRN", ser,cmd, RPS_UNABLE_ERR, PRN_OFFLINE_ERR);
							//发送响应,服务不允许，响应描述为：打印机离线
						}
						charge_ret(sockfd, print_GB(printer_fd,content));
						
					}
				else
					{
						RPS_send(sockfd, "BSE", ser,cmd, PRN_OFFLINE_ERR, PRN_UNKNOWN_ERR);
						//错误请求，错误描述：打印机未知错误[注意：此处响应为：错误的请求(即未识别命令)，打印机未知错误]，为BSE发送，但以打印机的错误来说明
					}
			}
		/*-----------------------------------------------------------打印位图------------------------------------------------------------*/
			else if(strcmp(cmd,"BMP")==0)
			{
				char* pdata = data;
				//char* bmpname = pdata;//提取位图名称，并查询数据库得到数据content
				char* shopid = pdata;//上述设计并不好，不如直接根据店面ID即 ShopsID 来得到它对应的LOGO，不用再修改数据库
				
				printf("\n in BMP dev=%s  cmd=%s  ser=%s  data=%s\n",dev,cmd,ser,data);
				printf("in BMP  shopid=%s \n",shopid);
				
				if (SQLITE_OK != ret)
				{
					printf("open Database failed!\n");
					return -1;
				}
				/*
				char sql_buff[256]={0};
				char bmp_buff[5000]={0};
				sprintf(sql_buff, "select LogoBmpData from Shops where ShopID = %s;", shopid);	
				if (sqlite3_exec(pDatabase, sql_buff, callback, (void*)bmp_buff, &errmsg) != SQLITE_OK)
				{
					printf("exec fail! %s\n", errmsg);
				}
							
				if(printer_fd <= 0) 
				{
					printf("open printer device error!\n");
					RPS_send(sockfd, "PRN", ser,cmd, RPS_UNABLE_ERR, PRN_OFFLINE_ERR);
						//发送响应,服务不允许，响应描述为：打印机离线
				}
				charge_ret(sockfd, print_bitmap(printer_fd,bmp_buff));*/
				//printf("ready to printf bitmap!\n");
				charge_ret(sockfd, print_bitmap(printer_fd,logoimage));
				
			}
				
		/*-----------------------------------------------------------打印单横线------------------------------------------------------------*/
			else if(strcmp(cmd,"SLI")==0)
			{		
			
					if(printer_fd <= 0) 
					{
						printf("open printer device error!\n");
						RPS_send(sockfd, "PRN", ser,cmd, RPS_UNABLE_ERR, PRN_OFFLINE_ERR);
						//发送响应,服务不允许，响应描述为：打印机离线
					}
					charge_ret(sockfd, print_sline(printer_fd));
					
			}
				
		/*-----------------------------------------------------------打印双横线------------------------------------------------------------*/
			else if(strcmp(cmd,"DLI")==0)
			{
				
				
					if(printer_fd <= 0) 
					{
						printf("open printer device error!\n");
						RPS_send(sockfd, "PRN", ser,cmd, RPS_UNABLE_ERR, PRN_OFFLINE_ERR);
						//发送响应,服务不允许，响应描述为：打印机离线
					}
					charge_ret(sockfd, print_dline(printer_fd));
					
			}
				
		/*-----------------------------------------------------------开始打单------------------------------------------------------------*/
			else if(strcmp(cmd,"BEG")==0)
			{
				/*#TRP:REC,单号，//模板，终端号，员工号，表单行数，流水号*/
				char* pdata = data;
				char* SaleID = ser;						//单号
				char* Module = strtok(pdata,DOU);			//模板
				char* PointID = strtok(NULL,DOU);			//终端号
				char* EmployeeID = strtok(NULL,DOU);		//员工号
				char* lineCnt = strtok(NULL,DOU);			//表单行数
				char* processNum = (pdata+strlen(Module)+strlen(PointID)+strlen(EmployeeID)+strlen(lineCnt)+4);	//流水号
				
				//printf("\n in BEG dev=%s  cmd=%s  ser=%s  data=%s\n",dev,cmd,ser,data);
				//printf("in BEG  SaleID=%s  Module=%s  PointID=%s  EmployeeID=%s   lineCnt=%s   processNum=%s\n",SaleID,Module,PointID,EmployeeID,lineCnt,processNum);	
				
				if(printer_fd <= 0) 
				{
					printf("open printer device error!\n");
					RPS_send(sockfd, "PRN", ser,cmd, RPS_UNABLE_ERR, PRN_OFFLINE_ERR);
						//发送响应,服务不允许，响应描述为：打印机离线
				}
				/*工号，收银终端号，销售单号，流水号*/
				charge_ret(sockfd, print_head(printer_fd,EmployeeID,  PointID, SaleID, processNum));	//打印头部，即开始打单
				
			}
				
		/*-----------------------------------------------------------表单行记录------------------------------------------------------------*/
			else if(strcmp(cmd,"REC")==0)
			{
				/*#TRP:REC,单号，//行号，名称，规格，数量，单价，金额，折扣*/
				char* pdata = data;
				char* SaleID = ser;						//单号
				char* LineNum = strtok(pdata,DOU);		//行号
				char* ProductName = strtok(NULL,DOU);		//名称
				char* Specfic = strtok(NULL,DOU);			//规格
				char* Cnt = strtok(NULL,DOU);				//数量
				char* UnitPrice = strtok(NULL,DOU);		//单价
				char* Amount = strtok(NULL,DOU);			//金额		
				char* Discount = pdata+strlen(LineNum)+strlen(ProductName)+strlen(Specfic)+strlen(Cnt)+strlen(UnitPrice)+strlen(Amount)+6;	//折扣
				
				//printf("\n in REC dev=%s  cmd=%s  ser=%s  data=%s\n",dev,cmd,ser,data);
				//printf("in REC  SaleID=%s  LineNum=%s  ProductName=%s  Specfic=%s   Cnt=%s   UnitPrice=%s  Amount=%s  Discount=%s\n",
				//SaleID,LineNum,ProductName,Specfic,Cnt,UnitPrice,Amount,Discount);
				
				if(printer_fd <= 0) 
				{
					printf("open printer device error!\n");
					RPS_send(sockfd, "PRN", ser,cmd, RPS_UNABLE_ERR, PRN_OFFLINE_ERR);
						//发送响应,服务不允许，响应描述为：打印机离线
				}
				charge_ret(sockfd, print_single(printer_fd, ProductName, Cnt, UnitPrice, Amount));	//只需4个参数，其它参数并不需要	
				
			}
				
		/*-----------------------------------------------------------打单结束------------------------------------------------------------*/
			else if(strcmp(cmd,"END")==0)//或者END
			{//#TRP:END,<单号>,<流水号>,<应收>,<实付>,<找零>,<税金>\n
				char* pdata = data;
				char* SaleID = ser;							//单号
				char* ProcessNum = strtok(pdata,DOU);		//流水号
				char* ShouldPay = strtok(NULL,DOU);			//应收
				char* ActualPay = strtok(NULL,DOU);			//实付
				char* Back = strtok(NULL,DOU);				//找零	
				char* tax = (pdata+strlen(ProcessNum)+strlen(ShouldPay)+strlen(ActualPay)+strlen(Back)+4);	//税金
						
				//printf("\n in END dev=%s  cmd=%s  ser=%s  data=%s\n",dev,cmd,ser,data);
				//printf("in END  SaleID=%s  ProcessNum=%s  ShouldPay=%s  ActualPay=%s   Back=%s   tax=%s\n",
				//SaleID,ProcessNum,ShouldPay,ActualPay,Back,tax);		
				
				if(printer_fd <= 0) 
				{
					printf("open printer device error!\n");
					RPS_send(sockfd, "PRN", ser,cmd, RPS_UNABLE_ERR, PRN_OFFLINE_ERR);
						//发送响应,服务不允许，响应描述为：打印机离线
				}
				/*打印尾部，参数列表：种类数量，总件数，金额总数(即应收金额)，现金收入*/		
				charge_ret(sockfd, print_tail(printer_fd, ShouldPay, ActualPay));		//打印尾部，即结束打单
				
			}
				
		/*-----------------------------------------------------------取得编码------------------------------------------------------------*/
			else if(strcmp(cmd,"COD")==0)
			{//#BSC:COD,<序列号>,<终端号>,<单号>\n
				char* pdata = data;
				char* PointID=strtok(pdata,DOU);//终端号
				char* saleID=(pdata+strlen(PointID)+1);//单号
				
				printf("\n in COD dev=%s  cmd=%s  ser=%s  data=%s\n",dev,cmd,ser,data);
				printf("in COD  PointID=%s  saleID=%s\n",PointID,saleID);		
				
				//todo		
						
			
			}
				
		/*-----------------------------------------------------------退出联线------------------------------------------------------------*/
			else if(strcmp(cmd,"BYE")==0)
				{//#BSC:BYE,<序列号>,<终端号>,<单号>\n
					char* pdata = data;
					char* PointID=strtok(pdata,DOU);//终端号
					char* saleID=(pdata+strlen(PointID)+1);//单号
					
					printf("\n in BYE dev=%s  cmd=%s  ser=%s  data=%s\n",dev,cmd,ser,data);
					printf("in BYE  PointID=%s  saleID=%s\n",PointID,saleID);		
				
				//断开网络连接，并置登录标志为0
						
						
			
			}
		/*--------------------------------------------------------------------------------------------------------------------------------*/
			else //未识别命令
				printf("unknown command!\n");
		}
		else  //没有成功登录连接的情况
		{
			printf("please login first!\n");
		}
		
	}
	
	return 0;
}


/*#XXX:RPS,<序列号>,<上个命令>,<响应码>,<响应描述 >\n*/
/***************************************************************************************************************
*函数功能：发送一条响应信息
*传入参数：sockfd：   对每一条接收到的信息都需要回复一条响应信息，sockfd为与这条接收到的信息对应的socket
*	   	dev：           要发送的响应信息的设备码
*		ser：            要发送的响应信息的序列号	
*	 	last_cmd：  与要发送的响应信息对应的原命令
*		rps_code： 要发送的响应信息的响应码
*		rps_refer： 要发送的响应信息的描述信息
*返回值：	正常为0
***************************************************************************************************************/
int RPS_send(int sockfd, char* dev,char* ser, char* last_cmd, int rps_code, int rps_refer)
{
	char buf[128]={0};
	sprintf(buf,"#%s:RPS,%s,%s,%d,%d\n",dev,ser,last_cmd,rps_code,rps_refer);	
	int cnt = send(sockfd, buf, sizeof(buf), 0);
        if(-1 == cnt)
        {
            perror("sendto error!");
            exit(-1); 
        }	
	return 0;
}





/***************************************************************************************************************
*函数功能：判断函数（主要是各打调用打印机的打印函数）的返回值，并根据其不同值发送不同响应命令
*传入参数：sockfd：对每一条接收到的信息都需要回复一条响应信息，sockfd为与这条接收到的信息对应的socket
*		    ret：	各类打印函数的返回值	
*返回值：    无
*特别说明：由于打印类函数要判断各打印函数的返回值，并根据其返回值生成响应并发送，此部分代码大量重复，
		    故用此函数代替
***************************************************************************************************************/
void charge_ret(int sockfd, int ret)
{
	switch(ret)//打印头部，即开始打单
		{
				case PRN_SUCCESS:
					 {
						 //发送响应码，成功
						 RPS_send(sockfd, "PRN", ser,cmd,RPS_SUCCESS, PRN_OFFLINE_ERR);
					 }break;
				case PRN_BUSY_ERR:
					 {
						 //发送响应码，打印机忙
						 RPS_send(sockfd, "PRN", ser,cmd, RPS_UNABLE_ERR, PRN_BUSY_ERR);
					 }break;
				case PRN_PAPER_LACK_ERR:
					 {
						 //发送响应码，缺纸
						  RPS_send(sockfd, "PRN", ser,cmd, RPS_UNABLE_ERR, PRN_PAPER_LACK_ERR);
					 }break;
				default:
					 {
						 //发送响应码，未知错误
						 RPS_send(sockfd, "PRN", ser,cmd, RPS_UNABLE_ERR, PRN_UNKNOWN_ERR);
					 }break;
		}
}

/***************************************************************************************************************
*函数功能：线程处理函数
*传入参数：arg：accept到的socket		   
*返回值：    无
***************************************************************************************************************/

void* pthread_func(void* arg)
{
	char *  recv_begin = 0;
	int socket = (int)arg;
	int i,recv_len ,ret;
	
	char * p ,* line_begin;
	char * buf_tail  ;
	
	recv_begin = recv_buf;
	recv_len = sizeof(recv_buf);
	
	line_begin = NULL;
	
	while(1)
	{
			 
		ret = recv(socket,recv_begin,  recv_len, 0);		//recv_begin指向接收buf的头
		buf_tail  = recv_begin+ ret;				//buf_tail指向接收buf的尾
		p = recv_begin;							//定义临时指针保存recv_begin
		
		if(ret < 0)
		{
			perror("recv error!");
			shutdown(socket,SHUT_RDWR);
			close(socket);
			break;
		}		
		while( p < buf_tail)
		{
		  	if(line_begin == NULL)   //不为空表示上次已经有半段程序在里面
			{
		     		for(; (*p != '#' ) &&  (p < buf_tail) ; p++);			
				if(*p != '#') //找不到#
				{
					continue;		
				}		         
			         line_begin = p;		//找到，更新line_begin指向此条消息的头部
			}		  
#define TAIL  '\n'		         		 
			for(; (*p != TAIL) &&  (p < buf_tail) ; p++);     
			 if(*p == TAIL)		//找到尾部
			{
				*p = 0;
				resolve(socket, line_begin);
				line_begin = NULL;
				if(p == (buf_tail -1) ) //完整一句
				{
					recv_begin = recv_buf;
					recv_len = sizeof(recv_buf);
					continue;
				}	
			}
			else			//找不到尾部，说明消息还没接收完，更新recv_begin继续接收
			{
				 recv_begin = buf_tail ;	
				 recv_len = sizeof(recv_buf) - (buf_tail - recv_buf);      	     //更新还可以接收的空的缓冲区
			}
		}	
		
	}
	 
}
/*
void* pthread_func2(void* arg)
{
	printf("create a new pthread :%d\n",pthread_self());
	int ret;
	int socket = (int)arg;
	int cnt = 0, i=0;
	int head = 0,tail =0;
	while(1)
	{
		printf("waitting for next cmd.........\n");
		memset(recv_buf,'\0',sizeof(recv_buf));				
		ret = recv(socket,recv_buf+cnt*MSG_LEN,  MSG_LEN-1, 0);
		if(ret>0)
		{
				cnt++;
				while( (recv_buf[i] != '#') && (i<BUF_LEN) )
				{
			 	    	i++;
				}
				head=i;
				printf("head=%d\n",head);
				while( (recv_buf[i] != '*') && (i<BUF_LEN) )
				{
					i++;
				}
				
				if(recv_buf[i] == '*')
				{
					tail=i;				
					memset(msg,'\0',sizeof(msg));	
					memcpy(msg, &recv_buf[head], tail-head+1);
					printf("msg=%s\n",msg);
					resolve(socket, msg);	
				}
				else
					continue;	
		}	     	
	     	else	//(ret< =0)
			{  	
				perror("recv error!");
				shutdown(socket,SHUT_RDWR);
				close(socket);
				break;
			}	 		
	}  	
	printf("phtread :%d   complete!\n",pthread_self());
	return NULL;	
}
*/

#interface

################################################################################
#Author:   mahonesun
#E-mail:   vipszp@vip.qq.com
#Add:      https://github.com/mahonesun/CloudPosSystem
#Version:  v1.0
################################################################################



TARGET    := interface
PWD        :=$(pwd)
INCLUDEDIR := $(PWD)inc
SRCDIR := $(PWD)src

CC	 	:=gcc
INCDIR      :=-I$(INCLUDEDIR)
CFLAGS	:=-Wall 
LDFLAGS :=-lsqlite3 -lpthread
SRCS 	:=$(wildcard $(SRCDIR)/*.c)
OBJS 	:=$(patsubst %.c, %.o, $(SRCS))


all: $(TARGET)

$(TARGET):$(OBJS)
	$(CC) $(OBJS)  -o $(TARGET)  $(LDFLAGS) 
	
%.o : %.c
	$(CC) $(CFLAGS)   -c $<  $(INCDIR ) -o $@		
	
clean:
	rm -rf  $(OBJS) $(TARGET)
	


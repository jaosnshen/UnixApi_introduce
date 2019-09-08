//
// Created by shen on 2019/9/8.
//
//
#include "FileDemo.h"


FileDemo::FileDemo(char *buf1,char *buf2)  {
this->buf2=buf2;
this->buf1=buf1;
}

void FileDemo::run() {


    int fd;



    char cerror[]="create error";

    if(fd=creat("f2ile.hole",FILE_MODE)<0){
        err_sys(cerror);
    }

    if (write(fd,buf1,10)!=10){
        err_sys("buf1 write error");
    }

    if (lseek(fd,16384,SEEK_SET)!=-1){
        err_sys("lseek error");
    }

    if (write(fd,buf2,10)!=10){
        err_sys("buf2 write error");
    }
    exit(0);

}

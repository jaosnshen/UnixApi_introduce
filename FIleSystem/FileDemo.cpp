//
// Created by shen on 2019/9/8.
//
//
#include "FileDemo.h"


FileDemo::FileDemo(char *buf1,char *buf2)  {
this->buf2=buf2;
this->buf1=buf1;
}

void FileDemo::fdrun() {
    int val;

    if


}

void FileDemo::run() {


    int fd;



    const char cerror[]="create error\n";

    if(fd=creat("file.hole",FILE_MODE)<0){
      printf(cerror);
    }

    fd=open("file.hole",O_RDWR);
    if (fd==-1){
        printf("open failed");
        return;
    }

    if (write(fd,buf1,10)!=10){
        printf("buf1 write error\n");
    }

    if (lseek(fd,10,SEEK_SET)!=-1){
        printf("lseek error\n");
    }

    if (write(fd,buf2,10)!=10){
        printf("buf2 write error\n");
    }
    exit(0);

}

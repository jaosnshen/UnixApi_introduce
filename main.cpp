#include <iostream>
#include "include/apue.h"
#include "FIleSystem/FileDemo.h"

int globvar=6;


char buf[]="a write to stdout\n";




int main() {
//    std::cout << "Hello, World!" << std::endl;

//    int var ;
//    pid_t  pid;
//
//    var=88;
//
//    if (write(STDIN_FILENO,buf, sizeof(buf)-1)!= sizeof(buf)-1){
//        printf("错误写入");
//    }
//       // err_sys("写入错误");
//    printf("before fork\n");
//
//    if ((pid=fork())<0){
//        //
//        printf("错误");
//    }else if (pid==0){  //child
//        globvar++;//修改变量
//    }else{
//        sleep(2);  //父亲
//    }
//
//    printf("pid = %ld ,glob=%d ,var =%d \n",(long)getpid(),globvar,var);

//    if (lseek(STDIN_FILENO,0,SEEK_CUR)==-1){
//        printf("cannot seek\n");
//    }else{
//
//        printf("seek OK\n");
//
//    }



      char buf1[]="暑期";
    char buf2[]="ABCDE";
    FileDemo *mFileDemo=new FileDemo(buf1,buf2);
    mFileDemo->run();

    delete mFileDemo;
    exit(0);


}
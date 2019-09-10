//
// Created by shen on 2019/9/10.
//

#include <signal.h>
#include "../include/apue.h"
#include "ProcessDemo.h"



ProcessDemo::ProcessDemo(char *buf) {
     this->buf=buf;
}

void ProcessDemo::run() {

    int var ;
    pid_t pid;

    var=88;

    if (write(STDOUT_FILENO,buf, sizeof(buf)-1)!= sizeof(buf)-1){

        printf("error write");
    }

    printf("before fork\n");

    if ((pid==fork())<0){
        printf("fork error");
    }else if (pid==0){
        globvar++;
        var++;
    }else{
        sleep(2);
    }

    printf("pid =%ld ,glob=%d ,var =%d\n",(long)getpid(),globvar,var);
    exit(0);



}
//
// Created by shen on 2019/9/8.
//

#ifndef UNIXAPI_FILEDEMO_H

#include "../include/apue.h"
#include <fcntl.h>
#define UNIXAPI_FILEDEMO_H


class FileDemo {

public:
    FileDemo(char *buf1,char *buf2);


public:

    char *buf1;
    char *buf2;

    void run();
//    extern C/**/ {

//    }

   void fdrun();
};


#endif //UNIXAPI_FILEDEMO_H

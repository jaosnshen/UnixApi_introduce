//
// Created by shen on 2019/9/10.
//

#ifndef UNIXAPI_PROCESSDEMO_H
#define UNIXAPI_PROCESSDEMO_H


class ProcessDemo {


public:
    char *buf;
    int globvar=6;
    void run();

    ProcessDemo(char *buf);
};


#endif //UNIXAPI_PROCESSDEMO_H

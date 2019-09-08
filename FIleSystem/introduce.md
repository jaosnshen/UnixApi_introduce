open 或者 openat 可以打开或创建一个文件

#include<fct1.h>

int open(chonst char *path,int oflag,..../*mode_t mode*/)


int openat(int fd,const char *path,int oflag,..../*mode_t mode*/)

使用mode_t

O_RONLY  只读打开
O_WRONLY 只写打开
O_RDWR  读 写打开
O_SEARCH 只搜索打开(应用于目录)

...

path 参数的指定的是绝对路径名，这种情况下fd参数被忽略，openat 函数就相当于open函数。

path 参数指定的相对路径名，fd参数指出了相对名在文件系统的开始地址。fd参数是通过打开路径名所在的目录来获取。

path 参数指定了相对路径名，fd参数具有特殊值AT_FDCWD,在这种情况下，路径名在当前工作目录中获取，openant函数在操作上与open相似。


create 函数创建一个文件  //返回为只写打开的文件描述符
//要创建一个临时文件，并要先写该文件，然后又读该文件，则必须线雕用create close，然后在调用open。
open(path,O_WRONLY|O_CREAT|O_TRUNC,mode)


close(int fd)


//可以调用lseek 显式地为一个打开文件设置偏移量
off_t lseek(int fd,off_t offset,int whence)
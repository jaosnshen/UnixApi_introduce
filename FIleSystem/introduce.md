open 或者 openat 可以打开或创建一个文件

+#include<fct1.h>

    +int open(chonst char *path,int oflag,..../*mode_t mode*/)
    +int openat(int fd,const char *path,int oflag,..../*mode_t mode*/)

  + 使用mode_t

     +O_RONLY  只读打开
     
     +O_WRONLY 只写打开
     
     +O_RDWR  读 写打开
     
     +O_SEARCH 只搜索打开(应用于目录)

     ...
  >两个函数的区别
    
  >>path 参数的指定的是绝对路径名，这种情况下fd参数被忽略，openat 函数就相当于open函数。

  >>path 参数指定的相对路径名，fd参数指出了相对名在文件系统的开始地址。fd参数是通过打开路径名所在的目录来获取。

  >>path 参数指定了相对路径名，fd参数具有特殊值AT_FDCWD,在这种情况下，路径名在当前工作目录中获取，openant函数在操作上与open相似。


create 函数创建一个文件  //返回为只写打开的文件描述符
//要创建一个临时文件，并要先写该文件，然后又读该文件，则必须线雕用create close，然后在调用open。
open(path,O_WRONLY|O_CREAT|O_TRUNC,mode)


close(int fd)


//可以调用lseek 显式地为一个打开文件设置偏移量
off_t lseek(int fd,off_t offset,int whence)

如果whence 是seek_set 则将该文件偏移量设置为距文件开始处offset个字节
          是seek_cur 偏移量为当前值加offset，offset可为正或负
        是seek_end 偏移量为当前值加offset加文件长度 offset可正可负
        若lseek成功执行，则返回新的文件偏移量，为此可以用下列方式确定打开文件的偏移量
        off_t currpos;
        currpos=lseek(fd,0,SEEK_CUR)
        
        
    + ssize_t read(int fd,void *buf,size_t nbytes);//返回读取的长度，0表示文件末尾，-1表示读取失败
    + ssize_t write(int fd,const void *buffer,size_t nbytes)
内核使用3种数据结构表示打开文件
1.每个进程都有一个记录项，记录项种包含一张打开文件描述符表，可将其是为一个矢量，每个描述符占其中一项。与每个文件描述符相关联的是：
a.文件描述符标志（close_on_exec）
b.指向一个文件表项的指针

2.内核为所有打开文件维持一张表，每个文件表项包含:
3.每个打开文件 都有一个v节点的结构。v节点包含了一个问价那类型和堆此文件进行各种操作函数的指针。
                     
    +void pwrite() pread() //同步方法
    dup(int fd) dup2(int fd,int fd2)//复制描述文件
    int fsync(int fd)
    //只是将所有修改过的块缓冲区排队写队列，然后就返回，它并等待实际写磁盘操作结束。update系统守护进程周期性调用sync函数。保证了定期冲洗(flush)
    int fdatasync(int fd)  只影响数据
    void sync(void)   影响数据和更新文件属性
        
        
        
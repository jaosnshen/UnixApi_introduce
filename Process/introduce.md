c程序的存储空间布局

正文段 这是有cpu执行的机器指令部分。可共享的。只读的  exec从程序文件中读入
初始化数据段 数据段，包含了程序中需明确地赋初值的变量。exec从程序文件中读入
未初始化数据段。此段为bss段（block started by symbol）exec初始化为0
栈 自动变量咋在每次调用函数时所需保存的信息都存放在此段中。每次函数调用时，返回值以及调用者的环境信息。
堆 通常在堆中进行动态分配。堆在段和栈之间。

共享库 不需要包含公用的库函数。

fork函数，子进程复制父进程
1.父进程复制自己，子进程同时执行不同的代码段。
2.一个进程要执行一个不同的程序。子进程从fork，使子进程立即调用exec

vfork 创建一个新的进程，新进程的目的是exec一个新程序。提高效率，只复制一部分父进程的空间到子进程。
vfork保证子进程先运行。在它调用exec或exit之后父进才可能调用运行。

exec函数只是替换了子进程的正文段，数据段，堆段和栈段
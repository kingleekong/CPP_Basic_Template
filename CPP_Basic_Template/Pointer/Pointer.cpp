//
//  Pointer.cpp
//  CPP_Basic_Template
//
//  Created by konglee on 2017/7/16.
//  Copyright © 2017年 konglee. All rights reserved.
//

#include "Pointer.hpp"
#include <iostream>

static int i = 0;

//静态、全局指针和malloc
void testP_01()
{
    //malloc
    static int *p;
    p = (int *)malloc(sizeof(int)); //如果不加(int *)在Mac编译环境下会报错
    // 因为malloc返回值是 void * 而P是 int 类型不匹配会报错
    
    //calloc
    int *pi = (int *)calloc(5, sizeof(int));
    printf("pi address is %p",&pi);
    
    int *pi_another = (int *)malloc(sizeof(int));
    memset(pi_another, 0, 5);
    //pi_another 和pi 等同
    
    /*realloc 重新分配内存 通长为变长数组重新分配内存
      realloc(void *__ptr, size_t __size)
     __ptr 为指向原内存的指针 size 为重新分配的内存大小
     realloc 可以为重新分配大内存，也可以分配小内存，如果分配了小内存，
     则多余的内存会给堆，但是不能保证这些内存会被清空，如果分配大内存，
     则可能会在当前内存附近重新分配新的内存，也有可能在别的堆分配，
     把之前的内存复制到新区域
    */
}

//指针的双重间接访问
void testP_02()
{
    int a = 12;
    int *b = &a; //b 指向a的地址 *b = a, 12
    int **c = &b; // c = &b, *c = b, **c = *b = a, 12
    printf("%d",**c);
}

//指针函数 返回值是一个指向整型的指针
int *f()
{
    int a = 10;
    int *p = &a; //p 是内存地址 *p = 10
    return p;
}

void testPointer_1()
{
    char *titles[] = {"aa","bb","cc","dd"};
    char **beginT[3];
    //    char **anotherT[4];
    beginT[0] = &titles[0];
    beginT[1] = &titles[1];
    beginT[2] = &titles[2];
    
    printf("%s\n",*beginT[1]);
}
void (*funp)(int);

void myfun(int x)
{
    std::cout << "第" << ++i << "调用此函数" <<"x is " << x << std::endl;
}
void testP_03()
{
    int *p = f();
    printf("p is %d\n",*p);
    
    myfun(10);
    funp = &myfun;
    (*funp)(200);
    //myfun 其实也是一个函数指针 和funp是一样的，myfun是一个函数指针常量，而funp是一个函数指针变量。
    // myfun只可以指向 代码70行的那个函数，而funp可以指向任意函数。
}


void testPointer()
{
    testP_03();
}



#ifndef DS_TOOLS_H
#define DS_TOOLS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#define  TRUE    (1)
#define  FALSE   (0)


typedef unsigned char Boolean;


// 包裹malloc函数
void *ds_malloc(int size);

// 自己的交换函数
void ds_swap(void *a,void *b,int length);

#endif

/*
 * ========================================================================
 *
 *       Filename:  gift.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2012年10月20日 11时11分43秒
 *       Revision:  none
 *       Compiler:  sdcc
 *
 *         Author:  Andy Scout (), andyhuzhill@gmail.com
 *   Organization:
 *
 * ========================================================================
 */
#include <8051.h>

typedef unsigned char uchar;

__sbit __at(0x91) P1M1;
__sbit __at(0x92) P1M0;
__sbit __at(0xb1) P3M1;
__sbit __at(0xb2) P3M0;

// 定义 STC11F04 I/O 口配置寄存器

const char *greet = " HAPPY BIRTHDAY GEORGIANA CHAIN SAIYA G ";

uchar __idata zimu[27][8] =
{
    {0x00, 0x00, 0xFC, 0x22, 0x22, 0xFC, 0x00, 0x00}, /*"A",0*/
    /* (8 X 8 , Terminal ) */
    {0x00, 0x00, 0xFE, 0x92, 0x92, 0x6C, 0x00, 0x00}, /*"B",1*/
    /* (8 X 8 , Terminal ) */
    {0x00, 0x00, 0x7C, 0x82, 0x82, 0x44, 0x00, 0x00}, /*"C",2*/
    /* (8 X 8 , Terminal ) */
    {0x00, 0x00, 0xFE, 0x82, 0x82, 0x7C, 0x00, 0x00}, /*"D",3*/
    /* (8 X 8 , Terminal ) */
    {0x00, 0x00, 0xFE, 0x92, 0x92, 0x82, 0x00, 0x00}, /*"E",4*/
    /* (8 X 8 , Terminal ) */
    {0x00, 0x00, 0xFE, 0x12, 0x12, 0x02, 0x00, 0x00}, /*"F",5*/
    /* (8 X 8 , Terminal ) */
    {0x00, 0x00, 0x7C, 0x82, 0x92, 0x74, 0x00, 0x00}, /*"G",6*/
    /* (8 X 8 , Terminal ) */
    {0x00, 0x00, 0xFE, 0x10, 0x10, 0xFE, 0x00, 0x00}, /*"H",7*/
    /* (8 X 8 , Terminal ) */
    {0x00, 0x00, 0x82, 0xFE, 0x82, 0x00, 0x00, 0x00}, /*"I",8*/
    /* (8 X 8 , Terminal ) */
    {0x00, 0x00, 0x60, 0x80, 0x80, 0x7E, 0x00, 0x00}, /*"J",9*/
    /* (8 X 8 , Terminal ) */
    {0x00, 0x00, 0xFE, 0x10, 0x28, 0xC6, 0x00, 0x00}, /*"K",10*/
    /* (8 X 8 , Terminal ) */
    {0x00, 0x00, 0xFE, 0x80, 0x80, 0x80, 0x00, 0x00}, /*"L",11*/
    /* (8 X 8 , Terminal ) */
    {0x00, 0x00, 0xFE, 0x0C, 0x0C, 0xFE, 0x00, 0x00}, /*"M",12*/
    /* (8 X 8 , Terminal ) */
    {0x00, 0x00, 0xFE, 0x0C, 0x30, 0xFE, 0x00, 0x00}, /*"N",13*/
    /* (8 X 8 , Terminal ) */
    {0x00, 0x00, 0x7C, 0x82, 0x82, 0x7C, 0x00, 0x00}, /*"O",14*/
    /* (8 X 8 , Terminal ) */
    {0x00, 0x00, 0xFE, 0x12, 0x12, 0x0C, 0x00, 0x00}, /*"P",15*/
    /* (8 X 8 , Terminal ) */
    {0x00, 0x00, 0x7C, 0xA2, 0xC2, 0xFC, 0x00, 0x00}, /*"Q",16*/
    /* (8 X 8 , Terminal ) */
    {0x00, 0x00, 0xFE, 0x32, 0x52, 0x8C, 0x00, 0x00}, /*"R",17*/
    /* (8 X 8 , Terminal ) */
    {0x00, 0x00, 0x4C, 0x92, 0x92, 0x64, 0x00, 0x00}, /*"S",18*/
    /* (8 X 8 , Terminal ) */
    {0x00, 0x00, 0x02, 0x02, 0xFE, 0x02, 0x02, 0x00}, /*"T",19*/
    /* (8 X 8 , Terminal ) */
    {0x00, 0x00, 0x7E, 0x80, 0x80, 0x7E, 0x00, 0x00}, /*"U",20*/
    /* (8 X 8 , Terminal ) */
    {0x00, 0x00, 0x1E, 0xE0, 0xE0, 0x1E, 0x00, 0x00}, /*"V",21*/
    /* (8 X 8 , Terminal ) */
    {0x00, 0x00, 0xFE, 0x60, 0x60, 0xFE, 0x00, 0x00}, /*"W",22*/
    /* (8 X 8 , Terminal ) */
    {0x00, 0x00, 0xC6, 0x38, 0x38, 0xC6, 0x00, 0x00}, /*"X",23*/
    /* (8 X 8 , Terminal ) */
    {0x00, 0x06, 0x08, 0xF0, 0x08, 0x06, 0x00, 0x00}, /*"Y",24*/
    /* (8 X 8 , Terminal ) */
    {0x00, 0x00, 0xC2, 0xB2, 0x9A, 0x86, 0x00, 0x00}, /*"Z",25*/
    /* (8 X 8 , Terminal ) */
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, /*" " 26*/
};

void delay(uchar);

void
character(const char *dat, uchar repeat)
{
    uchar i;
    P3 = 0xfe;
    for (i = 0; i < 8 ; i++)
    {
        if (repeat)
        {
            P1 = *dat++;
            repeat = 0;
        }
        P1 = *dat++;
        delay(15);
        __asm
        mov a, _P3
        rl a
        mov _P3, a
        __endasm;
    }
    P1 = 0x00;
    P3 = 0x00;
}

void
delay(uchar t)
{
    uchar x, y;
    for (x = 0; x < t; x++)
        for (y = 0; y < 15; y++);
}

void
print(const char *str)
{
    uchar i;
    char last = 0;
    uchar repeat;
    while (*str)
    {
        if (last == *str)
            repeat = 1;
        else
            repeat = 0;
        for (i = 0; i < 50; i++)
            if ( *str != ' ' )
            {
                character(zimu[*str - 0x41], repeat);
            }
            else
            {
                character(zimu[26], repeat);
            }
        delay(10);
        last = *str;
        str++;
    }
}

void
port_config(void)
{
    P3M0 = 0xff;
    P3M1 = 0x00; // P3各个端口设为强推挽输出
    P3 = 0x00;
    P1M0 = 0xff;
    P1M1 = 0x00; // P1 各个端口设为强推挽输出
    P1 = 0x00;;
}

void
main(void)
{
    long cnt = 0;
    port_config();
    while (1)
    {
        cnt++;
        print(greet);
        delay(25);
        if(1000 == cnt)
        {
            print(" NICE TO MEET YOU GC ");
            cnt = 0;
            delay(25);
        }
        if ((cnt % 100) == 0)
            print("THE LAZY BROWN FOX JUMPS OVER THE LAZY DOG");
    }
}

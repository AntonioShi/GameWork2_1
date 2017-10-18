/**
 * wen题描述
给定一个n*n的棋盘。现在要向棋盘中放入n个皇后，使任意的两个皇后都不在同一行、同一列或同一条对角线上。问总共有多少种放法？输出每一种方法。
n小于等于8。
输入格式
输入一个整数n，表示棋盘的大小。
输出格式
输出的第一行为一个整数m，表示不同放法的总数。
接下来m行，每行输出n个皇后所在的列号，中间以空格分隔。规定：第1个皇后放置在第1行，第2个皇后放置在第2行，以此类推。
样例输入
4
样例输出
2
2 4 1 3
3 1 4 2
 *
 */
//#include <iostream>
//using namespace std;
//
//static int gEightQueen[8] = {0};
//static int gCount = 0;
//
//
//void print()
//{
//    int outer;
//    int inner;
//
//    for(outer = 0; outer <8; outer ++){
//        for(inner = 0; inner < gEightQueen[outer]; inner ++)
//            printf("* ");
//
//        printf("# ");
//
//        for(inner = gEightQueen[outer] + 1; inner < 8; inner ++)
//            printf("* ");
//
//        printf("\n");
//    }
//
//    printf("=====================================\n");
//}
//
//int check_pos_valid(int loop, int value)
//{
//    int index;
//    int data;
//
//    for(index = 0; index < loop; index ++){
//        data = gEightQueen[index];
//
//        if(value == data)
//            return 0;
//
//        if((index + data) == (loop + value))
//            return 0;
//
//        if((index - data) == (loop - value))
//            return 0;
//    }
//
//    return 1;
//}
//
//
//
//void eight_queen(int index)
//{
//    int loop;
//
//    for(loop = 0; loop < 8; loop++){
//        if(check_pos_valid(index, loop)){
//            gEightQueen[index] = loop;
//
//            if(7 == index){
//                gCount ++, print();
//                gEightQueen[index] = 0;
//                return;
//            }
//
//            eight_queen(index + 1);
//            gEightQueen[index] = 0;
//        }
//    }
//}
//
//
//
//int main(int argc, char* argv[])
//{
//    eight_queen(0);
//    printf("total = %d\n", gCount);
//    return 1;
//}


#include "iostream"
#include "cmath"
using namespace std;

#define Max 20      //定义棋盘的最大值
int a[Max];//一维数组的方式存贮
int show(int S)    //定义输出函数
{
    int i,p,q;
    int b[Max][Max]={0};     //定义并初始化b[][]输出数组

    for(i=1;i<=S;i++)    //按横列i顺序输出a[i]数组坐标
    {
        b[i][a[i]]=1;
        printf("(%d,%d)\t",i,a[i]);
    }
    printf("\n");
    for(p=1;p<=S;p++)     //按棋盘的横列p顺序标明皇后的位置
    {
        for(q=1;q<=S;q++)
        {
            if(b[p][q]==1)     //在第p行第q列放置一个皇后棋子
                printf("●");
            else
                printf("○");
        }
        printf("\n");
    }
    return 0;
}

int check(int k)    //定义check函数
{
    int i;
    for(i=1;i<k;i++)    //将第k行与前面的第1~~k-1行进行判断
    {
        if((a[i]==a[k]) || (a[i]-a[k]==k-i) || (a[i]-a[k]==i-k))    //检查是否有多个皇后在同一条直线上
        {
            return 0;
        }
    }
    return 1;
}

void check_m(int num)    //定义函数
{
    int k=1,count=0;
    printf("The possible configuration of N queens are:\n");
    a[k]=1;
    while(k>0)
    {
        if(k<=num && a[k]<=num)    //从第k行第一列的位置开始，为后续棋子选择合适位子
        {
            if(check(k)==0)    //第k行的a[k]列不能放置皇后
            {
                a[k]++;        //继续探测当前行的下一列：a[k]+1
            }
            else
            {
                k++;         //第K行的位置已经确定了，继续寻找第k+1行皇后的位置
                a[k]=1;      //从第一列开始查找
            }
        }
        else
        {
            if(k>num)     //若满足输出数组的要求则输出该数组
            {
                count++;
                printf("[%d]:  ",count);
                show(num);    //调用输出函数show()
            }
            //如果k>num会执行下面两行代码，因为虽然找到了N皇后问题的一个解，但是要找的是所有解，需要回溯，从当前放置皇后的下一列继续探测
            //如果a[k]>num也会执行下面两行代码，就是说在当前行没有找到可以放置皇后的位置，于是回溯，从上一行皇后位置的下一列继续探测
            k--;      //棋子位置不符合要求，则退回前一步
            a[k]++;   //继续试探下一列位置
        }
    }
    printf("The count is: %d \n",count);
}

int main(void)
{
    int N,d;
    //system("color 2a");
    do
    {
        printf("********************N皇后问题系统*********************\n\n");
        printf("                  1. 四皇后问题                        \n");
        printf("                  2. 八皇后问题                        \n");
        printf("                  3. N 皇后问题(N<20)                  \n");
        printf("                  4. 退出                              \n");
        printf("******************************************************\n");
        printf("\n    从数字1-4之间的数选择需要的操作\n\n"); /*提示输入选项*/
        printf("      请输入你要选择的功能选项:__\n");
        scanf("%d",&d);
        switch(d)
        {
            case 1:
                check_m(4);      //4皇后问题
                break;
            case 2:
                check_m(8);     //8皇后问题
                break;
            case 3:
                printf("请输入N的值：_");
                fflush(stdin);      //清除缓冲
                scanf("%d",&N);
                printf("\n");
                if(N>0&&N<20)
                {
                    check_m(N);    //N皇后问题
                    break;
                }
                else
                {
                    printf("输入错误，请从新输入：");
                    printf("\n\n");
                    break;
                }
            case 4:
                exit(0);     //程序结束
        }
    }while(1);
    system("pause");
    return 0;
}
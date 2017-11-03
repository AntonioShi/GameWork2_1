/*
问题一：n皇后问题
问题描述
1.给定一个n*n的棋盘。
2.现在要向棋盘中放入n个皇后，
3.使任意的两个皇后都不在同一行、同一列或同一条对角线上。
4.问总共有多少种放法？输出每一种方法。
5.n小于等于8。

输入格式
输入一个整数n，表示棋盘的大小。

输出格式
1.输出的第一行为一个整数m，表示不同放法的总数。
2.接下来m行，每行输出n个皇后所在的列号，中间以空格分隔。
3.规定：第1个皇后放置在第1行，第2个皇后放置在第2行，以此类推。

样例输入
4
样例输出
2
2 4 1 3
3 1 4 2
 * */

#include <iostream>
#define N 8
using namespace std ;

int count = 0 ;//保存数目
int MockBoard[92][N] ;//记录最多方法时:每一种方法的元素排列--列
int BoardCol[N] ;//数组数值用于记录第i行的列坐标
int size = 5 ;//矩阵大小

bool Place(int k) ;//判断当前位置能否放置皇后
void TraceBack(int k) ;//回溯

bool Place(int k){
    int i ;
    for(i = 0; i < k; i++){
        if( (BoardCol[i] == BoardCol[k]) || abs(BoardCol[i] - BoardCol[k]) == abs(k - i) ){//行列对角线不可交叉
            return false ;
        }
    }
    return true ;
}

void TraceBack(int k){
    int i ;
    for (int i = 0; i < size; ++i) {
        BoardCol[k] = i ;

        if(Place(k)){   //如果k行BoardCol[k]可以存放皇后
            if(k == size - 1){
              //最后
                for (int j = 0; j < size; ++j) {
                    MockBoard[count][j] = BoardCol[j] + 1 ;//保存当前方法的元素位置列数
                }
                count ++ ;//方法数+1
            }
            else{
                TraceBack(k + 1) ;//回溯到下一列
            }
        }
    }
}

//fh
int main(){

    cin >> size ;

    TraceBack(0) ;

    //shuchu
    cout << count << endl ;
    for (int i = 0; i < count; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << MockBoard[i][j] << " " ;
        }
        cout << endl ;
    }

    return 0 ;
}

























//对不起,我还是希望能够自己写出这个问题的代码.致偷懒的自己

/***************************************************************
C++ナンバークロスワード(数独) 解法プログラム 06

問題例は
 0 8 0 | 0 0 2 | 0 0 0
 0 5 0 | 0 0 0 | 0 0 6
 9 0 0 | 0 7 0 | 5 0 0
-----------------------
 0 0 8 | 0 0 0 | 0 0 2
 0 1 0 | 0 2 0 | 0 4 0
 3 0 0 | 0 0 1 | 6 0 0
 -----------------------
 0 0 7 | 0 3 0 | 0 0 9
 6 0 0 | 0 0 0 | 0 8 0
 0 0 0 | 4 0 0 | 0 2 0

これが書かれてある"question"fileを読み込む

プログラム上、空白を0とする。

解法
method1,
フラグを使い、ボックスの中にそれだけしか当てはまらないフラグがあればそれを入れる。
例:
ボックス内フラグが
01001000
01001110
11001110
01011000
01011010
00000000
01011000
00000000
11011111

のとき全てのセルの右端を見ると、1つだけ1がある そのときに0000001が一番下のセルの答えである

method2,
セルの中のフラグが1つだけならそれを当てはめる
例： 000010000 ならそのセルは5

-------------------------------------------------------------------------------------

これだけではまだ解けない問題がある。


・空き直線問題
・2重線問題
・矛盾問題

これらの問題が存在するとき、これらのアルゴリズムだけでは解くことが出来ない。


005: バックトラックによる解法を組み込んだ。これにより解けない問題はなくなった。そして複数回答がある場合も出力される。
（矛盾問題による解決法）
006: 表示方法0を_にした。

予定：method3として、空き直線問題を組み込む

010: 全面書き直し flagシステムをboolにする


*****************************************************************/

#include <fstream>                    //ifstream iostream.h
#include <iostream>
#include "method.h"

int     flag[9][9]      = {0};                                                                //flag配列
bool    bFlag[9][9][9]  = {0};                                                                //flag配列
int     ans[9][9]       = {0};

int main(void){

    char qnumber[5]        = {"\0"};
    char questionN[10]    = "question" ;
    char c_text[15]        = {"\0"};
    int  method1_time   = 0;
    int  method2_time   = 0;

    /* flag all 1**/
    for(int v=0; v<9; v++){                        //すべてのflagを1 =511  Vertical
        for(int h=0; h<9; h++){                    //                        Horizon
            flag[v][h] = flag_all_one;
        }
    }

    /***** 選択 *********/
    std::cout<<"Input Question Number"<<std::endl;
    std::cin>>qnumber;
    sprintf_s(c_text, sizeof(c_text) , "%s%s", questionN, qnumber);
    strcat(questionN , qnumber);

    /** 問題入力**/

    read_file( questionN );

    std::cout<<"question:"<<std::endl;
    show( ans ,2 );
    std::cout<<"flag:"<<std::endl;
    show( flag ,10);

    /*** 当てはめ ***/
    while( method1(&method1_time) || method2(&method2_time) ){}
    std::cout<<"loop:"<<method1_time<<" "<<method2_time<<" -> "<<method1_time+method2_time<<std::endl;

    /**** 結果表示 ****/
    std::cout<<std::endl<<"heuristic anser:"<<std::endl;
    show( ans, 2);
    std::cout<<"flag:"<<std::endl;
    show(flag,10);

    back_track_method(0,0);

    return 0;
}


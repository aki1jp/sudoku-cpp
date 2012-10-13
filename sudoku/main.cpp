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

#include <fstream>					//ifstream iostream.h
#include <iostream>
#include "method.h"

int flag[9][9]          = {0};																//flag配列
bool bFlag[9][9][9]     = {0};																//flag配列
int ans[9][9]           = {0};

////////////////////mainルーチン
int main(void){

	char qnumber[5]		= {"\0"};
	char questionN[10]	="question" ;
	char c_text[15]		= {"\0"};
/* flag all 1**/
	for(int v=0; v<9; v++){						//すべてのflagを1 =511  Vertical
		for(int h=0; h<9; h++){					//						Horizon
			flag[v][h] = flag_all_one;
		}
	}

/***** 選択 *********/// char stringで詰まった。

	std::cout<<"Input Question Number"<<std::endl;
	std::cin>>qnumber;
	sprintf_s(c_text, sizeof(c_text) , "%s%s", questionN, qnumber);
//	strcat(questionN , qnumber);
	std::cout<<questionN<<std::endl<<std::endl;
	

/** 問題入力**/

	read_file( questionN );
	//read_file( "question5.txt" );
	
	std::cout<<"question:"<<std::endl;
	show( ans ,2 );
	std::cout<<"flag:"<<std::endl;
	show( flag ,10);

/*** 当てはめ ***/

	while( method1() || method2() ){}

	//int loop1 = 0,loop2 = 0;
	//do{
	//	do{
	//		++loop1;
	//	}while( method1() )	;
	//	 ++loop2;
	//}while( method2() ) ;
	//
	//
	//std::cout<<"loop:"<<loop1<<" "<<loop2<<" -> "<<loop1+loop2<<std::endl;
	
//	while( method1() || method2() );																//method 1
//																							↑
//set_number:	if( method1() && method2() ) goto set_number;					//この考えがヒントになった

/**** 結果表示 ****/
	std::cout<<std::endl<<"heuristic anser:"<<std::endl;
	show( ans, 2);
	std::cout<<"flag:"<<std::endl;
	show(flag,10);

	back_track_method(0,0);

//	std::cout<<std::endl<<"ans:"<<std::endl;
//	show( ans, 2);
//	show(flag,10);

	return 0;




// 	std::cout<<sizeof(short)<<std::endl<<sizeof(int)<<std::endl;		//size確認 ok

/*
	for (int i=0; i<9 ;i++ ){							//box確認 ok
		for(int j=0; j<9; j++){
			std::cout<<std::setw(2)<<box(i, j);
		}
		std::cout<<std::endl;
	}

	for (int i=0; i<9 ;i++ ){							//box_cell_tf確認 ok
		for(int j=0; j<9; j++){
			std::cout<<std::setw(2)<<box_cell_tf(3, i, j);
		}
		std::cout<<std::endl;
	}
*/
	
/* 演算子の確認
	int x=8;
	std::cout<<( x<<2 )<<std::endl		//ビット移動
		<<( x&2  )<<std::endl		//ビット論理積
		<<( x|2  )<<std::endl		//ビット論理和
		<<( x^2  )<<std::endl		//排他的論理和	
		<<( x * 2 )<<std::endl;	
*/	
}

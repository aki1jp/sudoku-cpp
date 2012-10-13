
#include<fstream>					//ifstream iostream.h
#include<iostream>
#include<iomanip>					//std::setw()
#include<cmath>						//std::pow()
#include<string.h>					//string 

#include<windows.h> 				//ダイアログBOXを出して警告					


//グローバル変数の定義
extern int flag[9][9];		//flag配列
extern bool bFlag[9][9][9];	//flag配列
extern int ans[9][9];

///////////サブルーチン


//10進数→2進数
//int bin(int dex){							
//	int bit = 0;
//	for(int i=0; i<9; i++){
//		bit += pow(10.0, i) * ( (dex >> i) % 2);
//	}
//	return bit;
//}

//10進数→2進数→flag number*
int flag_number(int dex){
	int bin = 0;
	for(int i=0; i<9; i++){
		bin += (i+1) * pow(10.0, i) * ( (dex >> i) % 2);
	}
	return bin;
}

////10進数→2進数→flag number* →0_
//string flag_number_0(int dex){
//	char zero[9];
//	int bin = 0;
//	for(int i=0; i<9; i++){
////		bin += (i+1) * pow(10, i) * ( (dex >> i) % 2);
//		 ( (dex >> i) % 2)?zero[i] = (char)i 	 :zero[i] = '_' ;
//	}
//	return zero;
//}

//配列表示の関数 n桁
void show( int hairetsu[9][9] , int n){				

	for(int i=0; i < 9; i++){
		for(int j=0; j < 9; j++){
			if(n<9)		hairetsu[i][j]? std::cout<<std::setw(n)<<hairetsu[i][j]: std::cout<<std::setw(n)<<"_" ; //3項演算子を使用。 0ならば _を出力
			//else		/*printf("",hairetsu[i][j])*/ std::cout<<std::setw(n)<<flag_number(hairetsu[i][j]);
			else		std::cout<<std::setw(n)<<flag_number(hairetsu[i][j]);
		}
		std::cout<<std::endl;
		if( !(i%3 -2) && 4<n ) std::cout<<"-------------------------------------------------------------------------------------------"<<std::endl;
	}
	std::cout<<std::endl;
}


int box(int v, int h){ 										//cell→Box      vh
	int x = 0;
		if(h < 2.5)						x+=1;
		else if((2.5< h) &&( h <5.5)) 	x+=2;
		else if( 5.5 < h )				x+=3;
			
		if( v < 2.5 )					x+=0;
		else if((2.5 < v)&&(v < 5.5) )	x+=3;
		else if( 5.5 < v )				x+=6;
			
	return (x);
}

//BOX+cell2→ t or f
bool box_cell_tf(int box_number, int v1, int h1){

	if( box(v1, h1) == box_number )		return true;
	else 								return false;
}

////失敗     true or false?　失敗
//int box_tf(int v, int h, int v1, int h1){
//	
//	for(int i=0; i<9; i++){
//		for(int j=0; j<9; j++){
////			if();
//		}
//	}
//}

//その数値は影響範囲に存在するか　（ansの中で矛盾するか？YES->1）			確認 ok
bool number_tf(int v, int h, int n){
	
	for(int j=0; j<9; j++){									//横
		if( ans[v][j]  == n ){
			return true;
		}
	}
	for(int i=0; i<9; i++){									//縦
		if( ans[i][h] == n ){
			return true;
		}
	}
	for (int i=0; i<9 ;i++ ){							//box_cell_tf
		for(int j=0; j<9; j++){
			if(( box_cell_tf( box(v,h), i, j)) && ( ans[i][j] == n ) ){
				return true;
			}
		}
	}
	return false;
}

//n桁目 v行 h列 flag消去
void flag_elase(int v, int h, int n){						//n桁目 v行 h列 flag消去
	for(int j=0; j<9; j++){									//横
		if( (flag[v][j] >> (n-1) )%2 ){
			flag[v][j] -= (1 << (n-1) );
		}
	}
	for(int i=0; i<9; i++){									//縦
		if( (flag[i][h] >> (n-1) )%2 ){
			flag[i][h] -= (1 << (n-1) );
		}
	}
	for (int i=0; i<9 ;i++ ){							//box_cell_tf確認  ok
		for(int j=0; j<9; j++){
			if(( box_cell_tf( box(v,h), i, j)) && ( (flag[i][j] >> (n-1) )%2 ) )
				flag[i][j] -=(1 << (n-1));
		}
	}
	flag[v][h] = 0;										//その場所のflagをall0にする
}

//cell vhのフラグ調査 数値nは1か0か？
int is_flag(int v, int h, int n){						
	if( (flag[v][h] >> (n-1) ) %2 ) return true;
	return false;
}

//box1 cell3 -> all cell 0 2
int cell_bcell( int box_number, int box_cell_number , int which ){		
	int s=0, b[2]={0};
	for( b[0]=0; b[0]<9; b[0]++){
		for( b[1]=0; b[1]<9; b[1]++){
			if( box( b[0] , b[1] ) == box_number ) { //ボックスの中だけ選択
				if( ++s == box_cell_number ) {
					return ( b[which] );
				}
			}
		}
	}
	return false;
}

//file iostream fstream
void read_file( /*void*/char* q ){
	std::ifstream fi;
//	fi.open("question");                                          //ファイルオープン
	fi.open( q );                                          //ファイルオープン mainルーチンから開ける
	if(!fi){
		std::cout<<"Can't open file"<<std::endl;
		exit(0);
	}
	for (int i=0; i<9 ;i++ ){
		for(int j=0; j<9; j++){
			fi>>ans[i][j];
			if(ans[i][j]){
					flag_elase(i, j, ans[i][j]);	//もし読み込んだ数字が0以外ならばその数字の影響のフラグ削除
				}
		}
	}
	fi.close();
	
}


//解法1
bool method1(){
	int s[9][3] = {0};

	for (int h=0; h<9; h++ ){								//h番目のBox
		for(int n=0; n<9; n++){							//s配列初期化
			s[n][0] = 0;
			s[n][1] = 0;
			s[n][2] = 0;
		}
		for (int i=0; i<9 ;i++ ){							//BOX内 のみ選択
			for(int j=0; j<9; j++){
				if( box_cell_tf( h+1, i, j)){				//box flag 1 BOX(h+1)内 のみ選択
					for(int m=0; m<9; m++){
						if((flag[i][j] >> m)%2) {
							s[m][0] +=1;
							s[m][1] = i;
							s[m][2] = j; 
						}
					}
				}
			}
		}
		for(int l=0; l<9; l++){					//sが1ならijに当てはめ
//			std::cout<<std::setw(3)<<s[l];
			if(s[l][0]==1){
				flag_elase(s[l][1], s[l][2], l+1);
				ans[ s[l][1] ][ s[l][2] ] = l+1;
				std::cout<<"method 1 : matrix "<<s[l][1]+1<<s[l][2]+1<<" -> "<<l+1<<std::endl;			//n桁目 v行 h列 flag消去
				return ( true);
			}
		}
	}
	return (false);
}

//解法2
bool method2(){
//	flag2 = 0;											//method 2
//	std::cout<<"method 2"<<std::endl;
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			for(int k=0; k<9; k++){						//2の倍数と比較
				if( flag[i][j] == (1 << k) ) {
					flag_elase(i, j, k+1);
					ans[i][j] = k+1;
					std::cout<<"method 2 : matrix "<<i+1<<j+1<<" -> "<<k+1<<std::endl;			//n桁目 v行 h列 flag消去
					return (true);
				}
			}
		}
	}
	return (false);
}

////解法3 空き直線問題 box streight
//bool method3(){
//	bool ret = false;
//	int flag_or;
//	for(int h=0; h<9; h++){				//box
//		flag_or = 0;
//		for(int i=0; i<9; i++){					//v
//			for(int j=0; j<9; j++){						//h
//				if( box_cell_tf(h, i, j) ){ 
//					//flag_or |= flag[i][j] ;		//boxの中のフラグを確認 Box内の全てのフラグをflag_orに入れる
//					flag_or += bin(flag[i][j]);
//				}
//				
//			}
//		}
//		for(int i=0;i<9; i++){				//Boxの中で注目する数字
//			int temp = (flag_or / (i+1) *10 )%10;
//			if( 2 <= temp && temp <= 3  ){				// flag_or 2以上3以下のとき
//				
//			}
//		}
//	}
//
//	return ret;
//}

//解法（最終手段） 再起呼び出しによるバックトラックでの解法 （無理やり感あるれる解き方？それとも仮定→否定の高度な方法？）
void back_track_method( int v , int h){
	static int total=0;
	if( ans[v][h] ){									//注目しているcellにすでに数値が置かれているとき
		if( h < 8 ){
			back_track_method(v, h+1);
		}
		else if( h >=8 ){		
//			std::cout<<v<<h<<" ";
			back_track_method(v+1, 0);
		}
		else return;
	}
	else{												//数値が入っていないとき
		for( int i=0; i<9; i++){							//どれかおいてみる
			if( ( flag[v][h] >> i)%2 && !number_tf(v, h, i+1) ) {		//flagを見て一番小さい数字が1 ∧ 矛盾がないならば
				ans[v][h] = i+1;										//数値を入れる
//				show(ans, 2);
//				std::cout<<v<<h<<"-"<<i<<"="<<ans[v][h]<<std::endl;
				if( h < 8 ){
//					std::cout<<v<<h<<" ";
					back_track_method(v, h+1);
				}
				else if( h ==8 ){
					if(v==8){
						std::cout<<"backtrack anser:"<<++total<<std::endl;
						show(ans, 2);								//もし88に来たときに表示
					}
					else if(v<8){
						back_track_method(v+1, 0);
					}
					else return;
				}
				else return;
			}
			ans[v][h] = 0;
		}
	}
}

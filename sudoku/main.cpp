/***************************************************************
C++�i���o�[�N���X���[�h(����) ��@�v���O���� 06

�����
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

���ꂪ������Ă���"question"file��ǂݍ���
 
�v���O������A�󔒂�0�Ƃ���B

��@
method1,
�t���O���g���A�{�b�N�X�̒��ɂ��ꂾ���������Ă͂܂�Ȃ��t���O������΂��������B
��:
�{�b�N�X���t���O��
01001000
01001110
11001110
01011000
01011010
00000000
01011000
00000000
11011111

�̂Ƃ��S�ẴZ���̉E�[������ƁA1����1������ ���̂Ƃ���0000001����ԉ��̃Z���̓����ł���

method2,
�Z���̒��̃t���O��1�����Ȃ炻��𓖂Ă͂߂�
��F 000010000 �Ȃ炻�̃Z����5

-------------------------------------------------------------------------------------

���ꂾ���ł͂܂������Ȃ���肪����B


�E�󂫒������
�E2�d�����
�E�������

�����̖�肪���݂���Ƃ��A�����̃A���S���Y�������ł͉������Ƃ��o���Ȃ��B


005: �o�b�N�g���b�N�ɂ���@��g�ݍ��񂾁B����ɂ������Ȃ����͂Ȃ��Ȃ����B�����ĕ����񓚂�����ꍇ���o�͂����B
�i�������ɂ������@�j
006: �\�����@0��_�ɂ����B

�\��Fmethod3�Ƃ��āA�󂫒�������g�ݍ���

010: �S�ʏ������� flag�V�X�e����bool�ɂ���
 

*****************************************************************/

#include<fstream>					//ifstream iostream.h
#include<iostream>
#include<iomanip>					//std::setw()
#include<cmath>						//std::pow()
#include<string.h>					//string 

#include<windows.h> 				//�_�C�A���OBOX���o���Čx��					

#define flag_all_one (1 << 9)-1

//�O���[�o���ϐ��̒�`
int flag[9][9] = {0};																//flag�z��
bool bFlag[9][9][9] = {0};																//flag�z��
int ans[9][9] = {0};

///////////�T�u���[�`��


//10�i����2�i��
//int bin(int dex){							
//	int bit = 0;
//	for(int i=0; i<9; i++){
//		bit += pow(10.0, i) * ( (dex >> i) % 2);
//	}
//	return bit;
//}

//10�i����2�i����flag number*
int flag_number(int dex){
	int bin = 0;
	for(int i=0; i<9; i++){
		bin += (i+1) * pow(10.0, i) * ( (dex >> i) % 2);
	}
	return bin;
}

////10�i����2�i����flag number* ��0_
//string flag_number_0(int dex){
//	char zero[9];
//	int bin = 0;
//	for(int i=0; i<9; i++){
////		bin += (i+1) * pow(10, i) * ( (dex >> i) % 2);
//		 ( (dex >> i) % 2)?zero[i] = (char)i 	 :zero[i] = '_' ;
//	}
//	return zero;
//}

//�z��\���̊֐� n��
void show( int hairetsu[9][9] , int n){				

	for(int i=0; i < 9; i++){
		for(int j=0; j < 9; j++){
			if(n<9)		hairetsu[i][j]? std::cout<<std::setw(n)<<hairetsu[i][j]: std::cout<<std::setw(n)<<"_" ; //3�����Z�q���g�p�B 0�Ȃ�� _���o��
			else		/*printf("",hairetsu[i][j])*/ std::cout<<std::setw(n)<<flag_number(hairetsu[i][j]);
		}
		std::cout<<std::endl;
		if( !(i%3 -2) && 4<n ) std::cout<<"-------------------------------------------------------------------------------------------"<<std::endl;
	}
	std::cout<<std::endl;
}


int box(int v, int h){ 										//cell��Box      vh
	int x = 0;
		if(h < 2.5)						x+=1;
		else if((2.5< h) &&( h <5.5)) 	x+=2;
		else if( 5.5 < h )				x+=3;
			
		if( v < 2.5 )					x+=0;
		else if((2.5 < v)&&(v < 5.5) )	x+=3;
		else if( 5.5 < v )				x+=6;
			
	return (x);
}

//BOX+cell2�� t or f
bool box_cell_tf(int box_number, int v1, int h1){

	if( box(v1, h1) == box_number )		return true;
	else 								return false;
}

////���s     true or false?�@���s
//int box_tf(int v, int h, int v1, int h1){
//	
//	for(int i=0; i<9; i++){
//		for(int j=0; j<9; j++){
////			if();
//		}
//	}
//}

//���̐��l�͉e���͈͂ɑ��݂��邩�@�ians�̒��Ŗ������邩�HYES->1�j			�m�F ok
bool number_tf(int v, int h, int n){
	
	for(int j=0; j<9; j++){									//��
		if( ans[v][j]  == n ){
			return true;
		}
	}
	for(int i=0; i<9; i++){									//�c
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

//n���� v�s h�� flag����
void flag_elase(int v, int h, int n){						//n���� v�s h�� flag����
	for(int j=0; j<9; j++){									//��
		if( (flag[v][j] >> (n-1) )%2 ){
			flag[v][j] -= (1 << (n-1) );
		}
	}
	for(int i=0; i<9; i++){									//�c
		if( (flag[i][h] >> (n-1) )%2 ){
			flag[i][h] -= (1 << (n-1) );
		}
	}
	for (int i=0; i<9 ;i++ ){							//box_cell_tf�m�F  ok
		for(int j=0; j<9; j++){
			if(( box_cell_tf( box(v,h), i, j)) && ( (flag[i][j] >> (n-1) )%2 ) )
				flag[i][j] -=(1 << (n-1));
		}
	}
	flag[v][h] = 0;										//���̏ꏊ��flag��all0�ɂ���
}

//cell vh�̃t���O���� ���ln��1��0���H
int flag_tr(int v, int h, int n){						
	if( (flag[v][h] >> (n-1) ) %2 ) return true;
}

//box1 cell3 -> all cell 0 2
int cell_bcell( int box_number, int box_cell_number , int which ){		
	int s=0, b[2]={0};
	for( b[0]=0; b[0]<9; b[0]++){
		for( b[1]=0; b[1]<9; b[1]++){
			if( box( b[0] , b[1] ) == box_number ) { //�{�b�N�X�̒������I��
				if( ++s == box_cell_number ) {
					return ( b[which] );
				}
			}
		}
	}
}

//file iostream fstream
void read_file( /*void*/char* q ){
	std::ifstream fi;
//	fi.open("question");                                          //�t�@�C���I�[�v��
	fi.open( q );                                          //�t�@�C���I�[�v�� main���[�`������J����
	if(!fi){
		std::cout<<"Can't open file"<<std::endl;
		exit(0);
	}
	for (int i=0; i<9 ;i++ ){
		for(int j=0; j<9; j++){
			fi>>ans[i][j];
			if(ans[i][j]){
					flag_elase(i, j, ans[i][j]);	//�����ǂݍ��񂾐�����0�ȊO�Ȃ�΂��̐����̉e���̃t���O�폜
				}
		}
	}
	fi.close();
	
}


//��@1
bool method1(){
	int s[9][3] = {0};

	for (int h=0; h<9; h++ ){								//h�Ԗڂ�Box
		for(int n=0; n<9; n++){							//s�z�񏉊���
			s[n][0] = 0;
			s[n][1] = 0;
			s[n][2] = 0;
		}
		for (int i=0; i<9 ;i++ ){							//BOX�� �̂ݑI��
			for(int j=0; j<9; j++){
				if( box_cell_tf( h+1, i, j)){				//box flag 1 BOX(h+1)�� �̂ݑI��
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
		for(int l=0; l<9; l++){					//s��1�Ȃ�ij�ɓ��Ă͂�
//			std::cout<<std::setw(3)<<s[l];
			if(s[l][0]==1){
				flag_elase(s[l][1], s[l][2], l+1);
				ans[ s[l][1] ][ s[l][2] ] = l+1;
				std::cout<<"method 1 : matrix "<<s[l][1]+1<<s[l][2]+1<<" -> "<<l+1<<std::endl;			//n���� v�s h�� flag����
				return ( true);
			}
		}
	}
	return (false);
}

//��@2
bool method2(){
//	flag2 = 0;											//method 2
//	std::cout<<"method 2"<<std::endl;
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			for(int k=0; k<9; k++){						//2�̔{���Ɣ�r
				if( flag[i][j] == (1 << k) ) {
					flag_elase(i, j, k+1);
					ans[i][j] = k+1;
					std::cout<<"method 2 : matrix "<<i+1<<j+1<<" -> "<<k+1<<std::endl;			//n���� v�s h�� flag����
					return (true);
				}
			}
		}
	}
	return (false);
}

////��@3 �󂫒������ box streight
//bool method3(){
//	bool ret = false;
//	int flag_or;
//	for(int h=0; h<9; h++){				//box
//		flag_or = 0;
//		for(int i=0; i<9; i++){					//v
//			for(int j=0; j<9; j++){						//h
//				if( box_cell_tf(h, i, j) ){ 
//					//flag_or |= flag[i][j] ;		//box�̒��̃t���O���m�F Box���̑S�Ẵt���O��flag_or�ɓ����
//					flag_or += bin(flag[i][j]);
//				}
//				
//			}
//		}
//		for(int i=0;i<9; i++){				//Box�̒��Œ��ڂ��鐔��
//			int temp = (flag_or / (i+1) *10 )%10;
//			if( 2 <= temp && temp <= 3  ){				// flag_or 2�ȏ�3�ȉ��̂Ƃ�
//				
//			}
//		}
//	}
//
//	return ret;
//}

//��@�i�ŏI��i�j �ċN�Ăяo���ɂ��o�b�N�g���b�N�ł̉�@ �i������芴������������H����Ƃ����聨�ے�̍��x�ȕ��@�H�j
void back_track_method( int v , int h){
	static int total=0;
	if( ans[v][h] ){									//���ڂ��Ă���cell�ɂ��łɐ��l���u����Ă���Ƃ�
		if( h < 8 ){
			back_track_method(v, h+1);
		}
		else if( h >=8 ){		
//			std::cout<<v<<h<<" ";
			back_track_method(v+1, 0);
		}
		else return;
	}
	else{												//���l�������Ă��Ȃ��Ƃ�
		for( int i=0; i<9; i++){							//�ǂꂩ�����Ă݂�
			if( ( flag[v][h] >> i)%2 && !number_tf(v, h, i+1) ) {		//flag�����Ĉ�ԏ�����������1 �� �������Ȃ��Ȃ��
				ans[v][h] = i+1;										//���l������
//				show(ans, 2);
//				std::cout<<v<<h<<"-"<<i<<"="<<ans[v][h]<<std::endl;
				if( h < 8 ){
//					std::cout<<v<<h<<" ";
					back_track_method(v, h+1);
				}
				else if( h ==8 ){
					if(v==8){
						std::cout<<"backtrack anser:"<<++total<<std::endl;
						show(ans, 2);								//����88�ɗ����Ƃ��ɕ\��
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

////////////////////main���[�`��
int main(void){

	char qnumber[5]		= {"\0"};
	char questionN[10]	="question" ;
/* flag all 1**/
	for(int v=0; v<9; v++){						//���ׂĂ�flag��1 =511  Vertical
		for(int h=0; h<9; h++){					//						Horizon
			flag[v][h] = flag_all_one;
		}
	}

/***** �I�� *********/// char string�ŋl�܂����B

	std::cout<<"Input Question Number"<<std::endl;
	std::cin>>qnumber;
	strcat(questionN , qnumber);
	std::cout<<questionN<<std::endl<<std::endl;
	

/** ������**/

	read_file( "question5.txt" );
	
	std::cout<<"question:"<<std::endl;
	show( ans ,2 );
	std::cout<<"flag:"<<std::endl;
	show( flag ,10);

/*** ���Ă͂� ***/
	int loop1 = 0,loop2 = 0;

	do{
		do{
			++loop1;
		}while( method1() )	;
		 ++loop2;
	}while( method2() ) ;
	
	
	std::cout<<"loop:"<<loop1<<" "<<loop2<<" -> "<<loop1+loop2<<std::endl;
	
//	while( method1() || method2() );																//method 1
//																							��
//set_number:	if( method1() && method2() ) goto set_number;					//���̍l�����q���g�ɂȂ���

/**** ���ʕ\�� ****/
	std::cout<<std::endl<<"heuristic anser:"<<std::endl;
	show( ans, 2);
	std::cout<<"flag:"<<std::endl;
	show(flag,10);

	back_track_method(0,0);

//	std::cout<<std::endl<<"ans:"<<std::endl;
//	show( ans, 2);
//	show(flag,10);

	return 0;




// 	std::cout<<sizeof(short)<<std::endl<<sizeof(int)<<std::endl;		//size�m�F ok

/*
	for (int i=0; i<9 ;i++ ){							//box�m�F ok
		for(int j=0; j<9; j++){
			std::cout<<std::setw(2)<<box(i, j);
		}
		std::cout<<std::endl;
	}

	for (int i=0; i<9 ;i++ ){							//box_cell_tf�m�F ok
		for(int j=0; j<9; j++){
			std::cout<<std::setw(2)<<box_cell_tf(3, i, j);
		}
		std::cout<<std::endl;
	}
*/
	
/* ���Z�q�̊m�F
	int x=8;
	std::cout<<( x<<2 )<<std::endl		//�r�b�g�ړ�
		<<( x&2  )<<std::endl		//�r�b�g�_����
		<<( x|2  )<<std::endl		//�r�b�g�_���a
		<<( x^2  )<<std::endl		//�r���I�_���a	
		<<( x * 2 )<<std::endl;	
*/	
}

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

#include <fstream>					//ifstream iostream.h
#include <iostream>
#include "method.h"

int flag[9][9]          = {0};																//flag�z��
bool bFlag[9][9][9]     = {0};																//flag�z��
int ans[9][9]           = {0};

////////////////////main���[�`��
int main(void){

	char qnumber[5]		= {"\0"};
	char questionN[10]	="question" ;
	char c_text[15]		= {"\0"};
/* flag all 1**/
	for(int v=0; v<9; v++){						//���ׂĂ�flag��1 =511  Vertical
		for(int h=0; h<9; h++){					//						Horizon
			flag[v][h] = flag_all_one;
		}
	}

/***** �I�� *********/// char string�ŋl�܂����B

	std::cout<<"Input Question Number"<<std::endl;
	std::cin>>qnumber;
	sprintf_s(c_text, sizeof(c_text) , "%s%s", questionN, qnumber);
//	strcat(questionN , qnumber);
	std::cout<<questionN<<std::endl<<std::endl;
	

/** ������**/

	read_file( questionN );
	//read_file( "question5.txt" );
	
	std::cout<<"question:"<<std::endl;
	show( ans ,2 );
	std::cout<<"flag:"<<std::endl;
	show( flag ,10);

/*** ���Ă͂� ***/

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

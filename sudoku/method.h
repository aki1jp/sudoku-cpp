#ifndef _METHOD_H_
#define _METHOD_H_

#define flag_all_one (1 << 9)-1

//�v���g�^�C�v�錾
int flag_number(int dex);
void show( int hairetsu[9][9] , int n);
int box(int v, int h);
bool box_cell_tf(int box_number, int v1, int h1);
bool number_tf(int v, int h, int n);
void flag_elase(int v, int h, int n);					//n���� v�s h�� flag����
int is_flag(int v, int h, int n);
int cell_bcell( int box_number, int box_cell_number , int which );
void read_file( /*void*/char* q );
bool method1();
bool method2();
void back_track_method( int v , int h);


#endif //_METHOD_H_

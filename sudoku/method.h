#ifndef _METHOD_H_
#define _METHOD_H_

#define flag_all_one (1 << 9)-1

//vg^Cvé¾
int flag_number(int dex);
void show( int hairetsu[9][9] , int n);
int box(int v, int h);
bool box_cell_tf(int box_number, int v1, int h1);
bool number_tf(int v, int h, int n);
void flag_elase(int v, int h, int n);					//nÚ vs hñ flagÁ
int is_flag(int v, int h, int n);
int cell_bcell( int box_number, int box_cell_number , int which );
void read_file( /*void*/char* q );
bool method1(int *time);
bool method2(int *time);
void back_track_method( int v , int h);


#endif //_METHOD_H_

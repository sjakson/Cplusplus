// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once


#include <iostream>
#include <tchar.h>

/*  bmp_io.h  16 May 1999  */

# define ERROR 1
# define SUCCESS 0

int bmp_read          ( char *filein_name, int *xsize, int *ysize, int* bsize, 
			  unsigned char **rarray, unsigned char **garray, unsigned char **barray );
int bmp_read_data     ( FILE *filein, int xsize, int ysize, int bsize, 
				   unsigned char *rarray, unsigned char *garray, unsigned char *barray );
int bmp_read_header   ( FILE *filein, int *xsize, int *ysize, int *bsize, int *psize );
int bmp_read_palette  ( FILE *filein, int psize );
int bmp_write_palette( FILE *fileout);
int bmp_read_test     ( char *filein_name );

int bmp_write         ( char *fileout_name, int xsize, int ysize, int bsize, unsigned char *rarray,
                        unsigned char *garray, unsigned char *barray );
int bmp_write_data    ( FILE *fileout, int xsize, int ysize, int bsize, 
					unsigned char *rarray, unsigned char *garray, unsigned char *barray);
int bmp_write_header  ( FILE *fileout, int xsize, int ysize, int bsize );
int bmp_write_test    ( char *fileout_name );

int read_u_long_int   ( unsigned long int *u_long_int_val, FILE *filein );
int read_u_short_int  ( unsigned short int *u_short_int_val, FILE *filein );

int write_u_long_int  ( unsigned long int u_long_int_val, FILE *fileout );
int write_u_short_int ( unsigned short int u_short_int_val, FILE *fileout );





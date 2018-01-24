/* 
	³Ë·¨ºÍµã³Ë
 */
 
#include "cv.h"
#include "highgui.h"
#include <iostream>

int main (){
	//define A mat
	double a[] = {
		1, 2, 3, 4,
		2, 3, 4, 5,
		3, 4 , 5, 6
	};
	CvMat* A = cvCreateMat(3, 4, CV_64FC1);
	cvInitMatHeader(A, 3, 4, CV_64FC1, a);
	//define B mat
	double b[] = {
		2, 2, 3, 4,
		5, 3, 2, 5,
		3, 6 , 5, 1
	};
	CvMat* B = cvCreateMat(3, 4, CV_64FC1);
	cvInitMatHeader(B, 3, 4, CV_64FC1, b);
	//define C mat
	double c[] = {
		1, 2, 3, 
		2, 3, 4, 
		3, 4 , 5,
		5, 4, 8
	};
	CvMat* C = cvCreateMat(4, 3, CV_64FC1);
	cvInitMatHeader(C, 4, 3, CV_64FC1, c);
	
	//Clone A
	CvMat* AA = cvCloneMat(A);
	
	//dot_mul = A.*B
	CvMat* dot_mul = cvCreateMat(3, 4, CV_64FC1);
	cvMul(A,B,dot_mul);
	
	//mul = A*C
	CvMat* mul = cvCreateMat(3, 3, CV_64FC1);
	cvMatMul(A, C, mul);
	//display A
	printf("A = \n");
	for (int x=0;x<A->rows;x++)
	{
		for (int y=0;y<A->cols;y++)
		{
			float value = cvmGet(A,x,y);
			printf("%f  ",value);
		}
		printf("\n");
	}
	//display B
	printf("B = \n");
	for (int x=0;x<B->rows;x++)
	{
		for (int y=0;y<B->cols;y++)
		{
			float value = cvmGet(B,x,y);
			printf("%f  ",value);
		}
		printf("\n");
	}
	//display C
	printf("C = \n");
	for (int x=0;x<C->rows;x++)
	{
		for (int y=0;y<C->cols;y++)
		{
			float value = cvmGet(C,x,y);
			printf("%f  ",value);
		}
		printf("\n");
	}
	//display dot_mul = A.*B
	printf("dot_mul = A.*B -->\n");
	for (int x=0;x<dot_mul->rows;x++)
	{
		for (int y=0;y<dot_mul->cols;y++)
		{
			float value = cvmGet(dot_mul,x,y);
			printf("%f  ",value);
		}
		printf("\n");
	}
	//display mul = A*C
	printf("mul = A*C -->\n");
	for (int x=0;x<mul->rows;x++)
	{
		for (int y=0;y<mul->cols;y++)
		{
			float value = cvmGet(mul,x,y);
			printf("%f  ",value);
		}
		printf("\n");
	}
	return 0;
}
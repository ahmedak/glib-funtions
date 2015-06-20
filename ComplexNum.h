/************************************************\
 * Filename:     complex.h                        *
 *                                                *
 * Description:                                   *
 *    This header file contains the structure     *
 * definition for a complex  type called COMPLEX  *
 * and the function prototypes for the functions  *
 * defined in complex.c, the implementation of the*
 * ADT complex                                    *
 \************************************************/

#ifndef _complex_h
#define _complex_h

/*****************
 * The COMPLEX ADT is implemented as a structure
 * that has two members real and imaginary both
 of which are integers
 *****************/

typedef struct _complex
{
    float real;
    float img;
} COMPLEX;

/************************************************
 ** Function: complex_add
 ** Input: c1 and c2 are COMPLEXs to be added
 ** Output: returns a COMPLEX (result) which is the
 **         sum of c1 and c2,
 ** The real parts and the imaginary parts are added
 respectively.
 Example  ( a + ib ) + ( c + id) = ( a + c) + i ( b + d)
 *******************************************/

COMPLEX complex_add  (COMPLEX c1, COMPLEX c2);

/************************************************
 ** Function: complex_subtract
 ** Input: c1 and c2 are COMPLEXs to be subtracted
 ** Output: returns a COMPLEX (result) which is the
 **         diference of c1 and c2,
 ** The real parts and the imaginary parts are subtracted
 respectively.
 Example  ( a + ib ) - ( c + id) = ( a - c) + i ( b - d)
 *******************************************/

COMPLEX complex_subtract  (COMPLEX c1, COMPLEX c2);


/**************************************
 ** Function: complex_multiply
 ** Input: c1 and c2 are COMPLEXs to be multiplied
 ** Output: returns a COMPLEX (result) which is the
 **         product of c1 and c2,
 Example  ( a + ib ) * ( c + id) = ( a * c - b * d ) + i ( a * d + b * c)
 **************************************/

COMPLEX complex_multiply  (COMPLEX c1, COMPLEX c2);

/**************************************
 ** Function: complex_magnitude
 ** Input: c1 is a  COMPLEX whose absolute value
 is required
 ** Output: returns a float value which is
 absolute value of the complex number
 Given a + ib
 abs = sqrt(sqr(a) + sqr(b);
 **************************************/

double  complex_magnitude  (COMPLEX c1);

/**************************************
 ** Function: complex_argument
 ** Input: c1 is a  COMPLEX whose argument is required
 ** Output: returns a float value which is 
 argument of the complex number
 Given a + ib , arg = arctan(y/x);
 **************************************/

double  complex_argument  (COMPLEX c1);


/**************************************
 ** Function: complex_init
 ** Input:    a pointer to a COMPLEX
 ** Output:   the COMPLEX pointed to is initialized
 **           real = imaginary = 0
 
 **************************************/
void complex_init (COMPLEX *fPtr);

/**************************************
 * Function: complex_assign
 * Input:    a pointer to a COMPLEX
 *           a double real
 *           a double imaginary
 *
 * Output:   the corresponding members of the COMPLEX
 *           are initialized .
 **************************************/

void complex_assign (COMPLEX *fPtr,double real , double img);

/**************************************
 * Function: complex_print
 * Input:    a COMPLEX, c
 * Ouput:    c is printed in the format
 real + i imaginary
 *           there is no return value
 *
 **************************************/
void complex_print (COMPLEX c);

#endif

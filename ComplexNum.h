/*************************************************
 * Filename:     complex.h                        
 *                                                
 * Description: 
 * Contains the structure definition for a complex 
 * type called COMPLEX and the function prototypes 
 * for the functions   
 *************************************************/

#ifndef _complex_h
#define _complex_h

/********************************************
 * The COMPLEX ADT
 *
 * Implemented as a structure that has two decimals:
 * real and imaginary.
 *******************************************/
typedef struct _complex{
    float real;
    float img;
} COMPLEX;

/*********************************************
 * Function: complex_add
 *
 * The real parts and the imaginary parts are 
 * added respectively.
 ********************************************/
COMPLEX complex_add  (COMPLEX c1, COMPLEX c2);

/********************************************
 * Function: complex_subtract
 *
 * The real parts and the imaginary parts are 
 * subtracted respectively.
 *******************************************/
COMPLEX complex_subtract  (COMPLEX c1, COMPLEX c2);

/******************************************
 * Function: complex_multiply
 *
 * Multiplies two complex numbers
 *****************************************/
COMPLEX complex_multiply  (COMPLEX c1, COMPLEX c2);

/*****************************************
 * Function: complex_magnitude
 *
 * Returns a float value which is
 * absolute value of the complex number
 *****************************************/

double  complex_magnitude  (COMPLEX c1);

/*****************************************
 * Function: complex_argument
 * 
 * Returns a float value which is 
 argument of the complex number
 *****************************************/
double  complex_argument  (COMPLEX c1);

/*****************************************
 * Function: complex_init
 *
 * Initialises the COMPLEX which Ptr is 
 * pointing to
 *****************************************/
void complex_init (COMPLEX *Ptr);

/*****************************************
 * Function: complex_assign
 * 
 * Assigns the corresponding members of 
 * the COMPLEX with the given values
 *****************************************/
void complex_assign (COMPLEX *fPtr, double real ,double img);

/*****************************************
 * Function: complex_print
 * 
 * The COMPLEX c is printed in the format
 * real + i imaginary
 *****************************************/
void complex_print (COMPLEX c);
#endif

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "complex.h"

#define PI 3.14159

/************************************************
 ** Function: complex_add
 ** Input: c1 and c2 are COMPLEXs to be added
 ** Output: returns a COMPLEX (result) which is the
 **         sum of c1 and c2,
 ** The real parts and the img parts are added
 respectively.
 *******************************************/
COMPLEX complex_add  (COMPLEX c1, COMPLEX c2)

{
    COMPLEX result;
    
    result.real = c1.real + c2.real;
    result.img = c1.img + c2.img;
    
    return result;
}

/************************************************
 ** Function: complex_subtract
 ** Input: c1 and c2 are COMPLEXs to be subtracted
 ** Output: returns a COMPLEX (result) which is the
 **         diference of c1 and c2,
 ** The real parts and the img parts are subtracted
 respectively.
 *******************************************/

COMPLEX complex_subtract  (COMPLEX c1, COMPLEX c2)
{
    COMPLEX result;
    
    result.real = c1.real - c2.real;
    result.img = c1.img - c2.img;
    
    return result;
}


/**************************************
 ** Function: complex_multiply
 ** Input: c1 and c2 are COMPLEXs to be multiplied
 ** Output: returns a COMPLEX (result) which is the
 **         product of c1 and c2,
 **************************************/

COMPLEX complex_multiply (COMPLEX c1, COMPLEX c2)
{
    COMPLEX result;
    
    result.real = c1.real * c2.real - c1.img * c2.img;
    result.img = c1.real * c2.img + c1.img * c2.real;
    return result;
}

/**************************************
 ** Function: complex_magnitude
 ** Input: c1 is a  COMPLEX whose absolute value
 is required
 ** Output: returns a float value which is
 absolute value of the complex number
 **************************************/

double complex_magnitude ( COMPLEX c1)
{
    double value;
    
    value = sqrt( (double) ( (c1.real * c1.real) + (c1.img * c1.img) ) );
    return value;
    
}


/**************************************
 ** Function: complex_argument
 ** Input: c1 is a  COMPLEX whose argument
 is required
 ** Output: returns a float value which is
 argument value of the complex number
 **************************************/

double complex_argument ( COMPLEX c1)
{
    double arg;
    double x = (c1.real);
    double y = (c1.img);
    
    if(x==0.0 && y==0)
	    ;
	    //argument undefined
    else if(x<0 && y>=0)
	    arg = PI + atan(y/x);
    else if(x<0 && y<0)
	    arg = (-1*PI) + atan(y/x);
    else if(x==0 && y<0)
	    arg = -1*(PI/2);
    else if (x==0 && y>0)
	    arg = PI/2;
    else if(x>0)
	arg = atan(y/x);
    
    return arg;
    
}
/**************************************
 ** Function: complex_init
 ** Input:    a pointer to a COMPLEX
 ** Output:   the COMPLEX pointed to is initialized
 **           real = img = 0
 
 **************************************/
void complex_init (COMPLEX *fPtr)
{
    fPtr -> real = 0.0;
    fPtr -> img = 0.0;
}

/**************************************
 * Function: complex_assign
 * Input:    a pointer to a COMPLEX
 *           a double real
 *           a double img
 *
 * Output:   the corresponding members of the COMPLEX
 *           are initialized .
 **************************************/

void complex_assign (COMPLEX *fPtr,double real , double img)
{
    fPtr -> real = real;
    fPtr -> img = img;
    
}

/**************************************
 * Function: complex_print
 * Input:    a COMPLEX, c
 * Ouput:    c is printed in the format
 real + i img
 *           there is no return value
 *
 **************************************/
void complex_print (COMPLEX c)
{
    if(c.img < 0)
    {
        printf("%f - i%f\n", c.real, -1*(c.img));
    }
    else
    {
        printf("%f + i%f\n", c.real, c.img);
    }
}

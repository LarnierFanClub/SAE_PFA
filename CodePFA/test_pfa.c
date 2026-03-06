/******************************************************/
/* Program to run and test the integration functions. */
/* Creation date: 31 July, 2025                       */
/******************************************************/

#include "pfa.h"

/* Code here anything you want to test your pfa functions and to show your numerical results */
int main()
{
	if(!init_integration("gauss3",0.08)){
		printf("a error occured while initialised variable");
	}
    Option option = {CALL,100,99,2,0.05,0.02};
    printf("%f\n",optionPrice(&option));    
    
    return 0;
}

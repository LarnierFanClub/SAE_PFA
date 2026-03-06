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

    Option option;

    printf("S0 = 100, T = 2, mu=0.05, sigma=0.02\n");
    for (double k = 99;(k<104);k++){
        option = (Option){CALL,100,k,2,0.05,0.02};
        printf("K = %f | Prix option Call  : %f\n",k,optionPrice(&option)); 
    }

    printf("-----\n");
    printf("S0 = 100, K = 101, mu=0.05, sigma=0.02\n");
    for (double t = 1.8;(t<2.3);t+=0.1){
        option = (Option){CALL,100,101,t,0.05,0.02};
        printf("T = %f | Prix option Call  : %f\n",t,optionPrice(&option)); 
    }

    printf("-----\n");



    return 0;
}

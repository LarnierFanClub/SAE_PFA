/******************************************************/
/* Program to run and test the integration functions. */
/* Creation date: 31 July, 2025                       */
/******************************************************/

#include "integration.h"

/* Code here everything you need to test the integration methods and show your numericzal results */

double fquelconque(double x){
	return 8*x+3; //Integrale f(x) [0>5] = 40
}

int main(){
	// fonction quelconque:
	printf("============================\n");
	printf("fonction quelconque f(x)=8x+3 :\n[resultat de 0 a 5 : 40]\n");
	
	printf("----------\n");
	QuadFormula* qf = malloc(sizeof(QuadFormula));
	int N = 5;
	// left :
	setQuadFormula(qf, "left");
	//bool r = setQuadFormula(qf, "left");
	//printf("\nsqf return : %s\n\n",r ? "true" : "false");
	printQuadFormula(qf);
	printf("\nApproximation avec \"%s\" de precision %d :\n>> %d\n",qf->name,N,integrate(&fquelconque, 0, 5, N, qf));
 	free(qf);
	return 0;
}

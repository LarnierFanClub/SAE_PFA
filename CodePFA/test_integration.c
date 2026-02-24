/******************************************************/
/* Program to run and test the integration functions. */
/* Creation date: 31 July, 2025                       */
/******************************************************/

#include "integration.h"

/* Code here everything you need to test the integration methods and show your numericzal results */

double fquelconque(double x){
	return sin(x*x); //Integrale f(x) [0>5] = 40
}

int main(){
	// fonction quelconque:
	printf("===============================\n");
	printf("fonction quelconque f(x)=8x+3 :\n[resultat de 0 a 5 : 115]\n");
	
	printf("-------------------------------\n");
	QuadFormula* qf = malloc(sizeof(QuadFormula));
	int precision = 500;
    for(int i = 0; i < 7; i++){
        char* name = valid[i];
        setQuadFormula(qf, name);
        printf("\n╔═════════════════════════╗\n\n");
        printQuadFormula(qf);

        printf("\n╠══════════════════════════════════════════════╗\n");
        for (int N=1;(N< precision);N+=50){
            if (N>1)printf("\n╠════╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌\n");
            printf("║ Approximation avec \"%s\" de precision %d :\n║ >> %f",
                    name,
                    N,
                    integrate(&fquelconque, 1, 5, N, qf));
        }
        printf("\n╚══════════════════════════════════════════════╝\n");
    }
	free(qf);
	return 0;
}

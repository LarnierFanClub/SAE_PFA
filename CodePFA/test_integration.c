/******************************************************/
/* Program to run and test the integration functions. */
/* Creation date: 31 July, 2025                       */
/******************************************************/

#include "integration.h"

/* Code here everything you need to test the integration methods and show your numericzal results */

double fquelconque(double x){
	return sin(x*x); //Integrale f(x) [1>5] = 0.217649
}

int main(){
	// fonction quelconque:
	printf("===============================\n");
	printf("fonction quelconque f(x)=sin(x²) :\n[resultat de 1 a 5 : 0.217649]\n");
	
	printf("-------------------------------\n");
	QuadFormula* qf = malloc(sizeof(QuadFormula));
	int precision = 500;
    int precision_list[] = {1, 5, 10, 20, 50, 100, 200, 500};
    for(int i = 0; i < 7; i++){
        char* name = valid[i];
        setQuadFormula(qf, name);
        printf("\n╔═════════════════════════╗\n\n");
        printQuadFormula(qf);

        printf("\n╠══════════════════════════════════════════════╗\n");
        for (int N=0;(N<8);N++){
            if (N>=1)printf("\n╠════╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌\n");
            printf("║ Approximation avec \"%s\" de precision %d :\n║ >> %f",
                    name,
                    precision_list[N],
                    integrate(&fquelconque, 1, 5, precision_list[N], qf));
        }
        printf("\n╚══════════════════════════════════════════════╝\n");
    }
	free(qf);
	return 0;
}

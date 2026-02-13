#define INTEGRATION_C

#include "integration.h"

char valid[7][] = {"left", "right", "middle", "trapezes", "simpson", "gauss2", "gauss3"};
QuadFormula dict[7] = {{"left",1,{1,0},{0,0}},
						{"right",1,{1,0},{1,0}},
						{"middle",1,{1,0},{0.5,0}},
						{"trapezes",2,{0.5,0},{0.5,1}}
						};

int is_valid(char* name){
	for(int i = 0; i < 7; i++){
		if(strcmp(valid[i],name)){
			return i;
		}
	}
	return -1;
}

bool setQuadFormula(QuadFormula* qf, char* name){
	int ind = is_valid(name);
	if(ind<0) return false;

	memcpy(dict+ind,qf,sizeof(QuadFormula));
	
	return true;
}

/* This function is not required ,but it may useful to debug */
void printQuadFormula(QuadFormula* qf)
{
  printf("Quadratic formula: %s\n", qf->name);
  /* Print everything else that may be useful */
}


/* Approximate the integral of function f from a to b.
   - f is a pointer to a function pointer
   - a and b are the integration bounds
   - Interval [a,b] is split in N subdivisions [ai,bi]
   - Integral of f on each subdivision [ai,bi] is approximated by the quadrature formula qf.
*/
double integrate(double (*f)(double), double a, double b, int N, QuadFormula* qf){
	
}

double integrate_dx(double (*f)(double), double a, double b, double dx, QuadFormula* qf)
{
  return 0.0;
}



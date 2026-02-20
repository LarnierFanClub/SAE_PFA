#define INTEGRATION_C

#include "integration.h"

char* valid[7] = {"left", "right", "middle", "trapezes", "simpson", "gauss2", "gauss3"};
QuadFormula dict[7] = {{"left",1,{1,0},{0,0}},
						{"right",1,{1,0},{1,0}},
						{"middle",1,{1,0},{0.5,0}},
						{"trapezes",2,{0.5,0},{0.5,1}}
						};

int is_valid(char* name){
	for(int i = 0; i < 7; i++){
		if(!strcmp(valid[i],name)){
			return i;
		}
	}
	return -1;
}

bool setQuadFormula(QuadFormula* qf, char* name){
	int ind = is_valid(name);
	
	if(ind<0) return false;

	//memcpy(dict+ind,qf,sizeof(QuadFormula));
	memcpy(qf,dict+ind,sizeof(QuadFormula));
	
	return true;
}

/* This function is not required ,but it may useful to debug */
void printQuadFormula(QuadFormula* qf)
{
  	printf("Quadratic formula : %s\n", qf->name);
  	printf("size : %d\n",qf->n);
	printf("w list: %f",qf->w[0]);
	if(qf->n >= 2)
		printf(", %f",qf->w[1]);
	printf("\n");
  	printf("x list: %f",qf->x[0]);
	if(qf->n >= 2)
		printf(", %f",qf->x[1]);
	printf("\n");
}

double sum_integ(double (*f)(double), double ai, double bi, QuadFormula* qf){
	int n = qf->n;
	double* w = qf->w;
	double* x = qf->x;
	double res = 0;
	for(int i = 0; i < n; i++){
		res+=w[i]*f(ai+(x[i]*(bi-ai)));
	}
	return res;
}

double get_simp_pol(double cur, double vals[],size_t n){
	double a = 1;
	double b = 1;
	double c = 1;
	for(size_t i = 0; i< n; i++){
		if(vals[i] == cur) continue;
		double denom = cur-vals[i];
		a /= denom;
		b = 0;
		c *= cur/denom;
	}
	return a/3+b/2+c;
}

/* Approximate the integral of function f from a to b.
   - f is a pointer to a function pointer
   - a and b are the integration bounds
   - Interval [a,b] is split in N subdivisions [ai,bi]
   - Integral of f on each subdivision [ai,bi] is approximated by the quadrature formula qf.
*/
double integrate(double (*f)(double), double a, double b, int N, QuadFormula* qf){
	if(a==b || f == NULL || qf == NULL || qf->n == 0) return 0;
	double range = (b-a)/N;
	double bi = a + range;
	double res = 0;
	for(int ai = a; ai < b; bi+=range){
		if(bi > b) bi = b;
		res = (bi-ai)*sum_integ(f,ai,bi,qf);
		ai = bi;
	}
	return res;
}

double integrate_dx(double (*f)(double), double a, double b, double dx, QuadFormula* qf)
{
  return 0.0;
}



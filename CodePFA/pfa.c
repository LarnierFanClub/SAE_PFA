

// #define GRAPHIC

#define PFA_C

#include "pfa.h"
/* Initialize the integration variables.
   Arguments :
   - quadrature : name of the quadrature formula that will be used. It can be "left", "right", 
     "middle", "trapezes", "simpson", "gauss2" or "gauss3".
   - dt : a positive value, which will be used to decide the number of subdivisions of an 
          interval [a,b], when computing the integration.
          The number of subdivisions will be N such that (b-a)/N ~ dt
*/
bool init_integration(char* quadrature, double dt)
{
    QuadFormula *ptr = malloc(sizeof(QuadFormula));
    bool res = setQuadFormula(ptr,quadrature);
    if(!res) return false;
    pfaQF = *ptr;
    pfa_dt = dt;
    return true;
}



/* Density of the normal distribution */
double phi(double x)
{
  return 0.398942280401433 * exp( -x*x/2 );
}

/* Cumulative distribution function of the normal distribution */
double PHI(double x)
{
  return 0.5+integrate_dx(*phi,0,x,pfa_dt,&pfaQF);
}

/* =====================================
   Finance function: price of an option 
*/
double optionPrice(Option* option)
{
    if(option == NULL) return 0.0;
    double S0 = option->S0;
    double mu = option->mu;
    double sig = option->sig;
    double T = option->T;
    double Z = 0.5;
    OptionType type = option->type;
    double z0 = (log(K/S0) - (mu - sig*sig/2.0)*T)/(sig*sqrt(T));
    if(type == CALL){
        return S0*exp(mu*T)*PHI(sig*sqrt(T)-z0) - K*PHI(-z0);
    }
    else if (type == PUT){
        return K*PHI(z0)-S0*exp(mu*T)*PHI(z0-sig*sqrt(T));
    }
    return 0.0;
}



/* ===============================================*/
/* Insurance functions */

/* Probability density function (PDF) of variable X.
   X is the reimbursement in case of a  claim from the client.
*/
double clientPDF_X(InsuredClient* client, double x)
{
    if (x <= 0.0) {
        return 0.0;
    }
    double m = client->m;
    double s = client->s;
    double res = (log(x) - m) / s;
    return (1.0 / (s * x)) * PHI(res);
}


/* Cumulative distribution function (CDF) of variable X.
   X is the reimbursement in case of a claim from the client.
*/
double clientCDF_X(InsuredClient* client, double x)
{
  return 0.0;
}


/* Probability density function (PDF) of variable X1+X2.
   X1 and X2 are the reimbursements of the two claims from the client (assuming there are 
   two claims).
*/
double clientPDF_X1X2(InsuredClient* client, double x)
{
  return 0.0;
}


/* Cumulative distribution function (CDF) of variable X1+X2.
   X1 and X2 are the reimbursements of the two claims from the client (assuming there are 
   two claims).
*/
double clientCDF_X1X2(InsuredClient* client, double x)
{
  return 0.0;
}



/* Cumulative distribution function (CDF) of variable S.
   Variable S is the sum of the reimbursements that the insurance company will pay to client.
*/
double clientCDF_S(InsuredClient* client, double x)
{
  return 0.0;
}





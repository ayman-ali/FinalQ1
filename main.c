/* 
 * Monte Carlo calculation of the volume of superellipsoids
 */
 
#include <stdio.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_statistics.h>
#include <math.h>

/* super.c */

double super(long m, int n, gsl_rng * r);

#define NEXP 64  /* number of experiments for each value of points */
#define M 11     /* number of different points values */

int
main (void)
{
    double vol[NEXP];           /* calculated values of volume */
    gsl_rng *r;
    double volume, error;
    int j, n;
    unsigned long seed = 1UL;
    long p = pow (2, 19.); /*number of points that we will generate*/

    /* allocate random number generator */
    r = gsl_rng_alloc (gsl_rng_taus2);

    /* seed the random number generator */
    gsl_rng_set (r, seed);

    for (n = 1; n < 10; n++) /*same n as in the given equation*/

    {


            for (j = 0; j < NEXP; j++) 
            
            {
                /* calculate volume using Monte Carlo algorithm */
                vol[j] = super(p, n, r);
            }
            
            
            volume = gsl_stats_mean (vol, 1, NEXP);        /*answer */
            error = gsl_stats_sd_m (vol, 1, NEXP, volume);    /*error */
            printf ("%15ld		 %10d		 %14.8f     %14.8f\n", p, n, volume, error);
            /* p *= 2; double points for the next iteration, but the program takes too long to run */
            
        }

    gsl_rng_free(r);

    return (0);
}

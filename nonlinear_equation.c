#include <stdio.h>
#include <math.h>

#include "main.h"
#include "nonlinear_equation.h"

double nonlinear_equation(double *radioactivity, double *time, int N)
{
    double interval1 = 0.2, interval2 = 8.2, decay_time = 0, decay_time0 = -153.153153;
    int i = 0;
    //scanf("%lg%lg", &interval1, &interval2);

    for(i; i < N; i++)
    {
        decay_time = (interval2 + interval1)/2;
        if ((model(radioactivity, time, N, decay_time) * model(radioactivity, time, N, interval1)) < 0)
        {
            interval2 = decay_time;
        }
        else if ((model(radioactivity, time, N, decay_time) * model(radioactivity, time, N, interval2)) < 0)
        {
            interval1 = decay_time;
        }

        if (fabs(interval2 -interval1) <= 2 * precision)
        {
            decay_time0 = decay_time;
        }
    }

    if (IsEqual(decay_time0, -153.153153))
    {
        // printf("\n<<<The root of nonlinear equation was not found!>>>\n");
        // printf("%lg\n", decay_time0);
    }

    return decay_time0;
}

int IsEqual(double elem1, double elem2)
{
    return (fabs(elem1 - elem2) <= precision);
}

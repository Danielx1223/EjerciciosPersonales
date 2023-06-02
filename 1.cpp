#include <stdio.h>
#define GNUPLOT "gnuplot -persist"

int main(int argc, char **argv)
{
  FILE *gp;
  gp = popen(GNUPLOT,"w"); /* 'gp' is the pipe destrictor */
  if (gp==NULL)
	{
	  printf("Error opening pipe to GNU plot. Check if you have it! \n");
	  return 0;
	}
 
             fprintf(gp, "set terminal wxt persist\n");
             fprintf(gp,  "set parametric \n");
             fprintf(gp, "unset key\n");
 
              fprintf(gp, "set xtics 1\n");
              fprintf(gp, "set ytics 1\n");

              fprintf(gp, "set size ratio -1\n");

  fprintf(gp, "set trange [0:(2*pi)]\n");
  fprintf(gp, "plot  exp(3*log(cos(t))),exp(3*log(sin(t))) \n");
  fclose(gp);
  return 0;
}

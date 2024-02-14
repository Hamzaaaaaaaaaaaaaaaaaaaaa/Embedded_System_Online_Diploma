
#include "stdio.h"
  
int
main () 
 { 
 
float sum, avrg;
  
int k, i;
  
printf ("Enter the numbers of data : ");
  
scanf ("%d", &k);
  
for (i = 0; i < k; i++)
	
	{
	  
float arr[k];
	  
printf ("%d.Enter number:", i + 1);
	  
scanf ("%f", &arr[i]);
	  
sum += arr[i];
	
 
} 
avrg = sum / k;
  
printf ("Average = %f", avrg);

 
 
}

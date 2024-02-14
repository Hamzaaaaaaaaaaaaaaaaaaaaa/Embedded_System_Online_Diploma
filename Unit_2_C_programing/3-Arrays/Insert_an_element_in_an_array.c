#include "stdio.h"

 int
main () 
 { 
int n, e, l, i;
  
printf ("Enter no of elements : ");
  
scanf ("%d", &n);
  
int arr[n];
  
for (i = 0; i < n; i++)
	{
	  
arr[i] = i + 1;
	  
printf ("%d\t", arr[i]);
	
}
  
printf ("\n");
  
printf ("Enter the element to be inserted : ");
  
scanf ("%d", &e);
  
printf ("Enter the location : ");
  
scanf ("%d", &l);
  
n++;
  
for (i = n - 1; i >= l; i--)
	{
	  
arr[i] = arr[i - 1];
	
}
  
arr[l - 1] = e;
  
 
for (i = 0; i < n; i++)
	{
	  
printf ("%d ", arr[i]);
	
}
  
printf ("\n");

}

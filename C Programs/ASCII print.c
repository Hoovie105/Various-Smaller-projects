#include <stdio.h>
#include <assert.h>
int print_xbox(int n);
int i, j, n, evencheck;
 
int main ()
{
    assert(print_xbox(1)==1);
    
    assert(print_xbox(4)==4);
    
    assert(print_xbox(5)==5);
    
    assert(print_xbox(6)==6);
    
    assert(print_xbox(7)==7);
    
    assert(print_xbox(11)==11);
    
}
int print_xbox(int n)
{
    if (n % 2 == 0)
    {
      evencheck = 1;
    }
  else
    {
      evencheck = 0;
    }
  for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++)
	{
	  if (i == 0 || i == n - 1 || j == 0 || j == n - 1)
	    {
	      printf ("*");
	    }
	  else
	    {
	      if (i == j && i != 0 && j != n - 1)
		{
		  if (i != (n - 1) / 2 && evencheck == 0)
		    {
		      printf ("\\");
		    }
		  else if (evencheck == 0 && i == j && i == (n - 1) / 2)
		    {
		      printf ("X");
		    }
		  else
		    {
		      printf ("\\");
		    }
		}
	      else if (evencheck == 0 && i == j && i == (n - 1) / 2)
		{
		  printf ("X");
		}
	      else if (i + j == n - 1 && i != 0 && j != n - 1)
		{

		  if (i != (n - 1) / 2 && evencheck == 0)
		    {
		      printf ("/");
		    }
		  else
		    {
		      printf ("/");
		    }
		}
	      else
		{
		  printf (" ");
		}
	    }

	}
      printf ("\n");
    }
}

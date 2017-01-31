/*
** my_putnbr_base.c for a in /home/soucan_d/All
**
** Made by DImitri Soucanye de Landevoisin
** Login   <soucan_d@epitech.net>
**
** Started on  Wed Nov 11 14:35:13 2015 DImitri Soucanye de Landevoisin
** Last update Sun Feb 21 21:30:34 2016 Dimitri
*/

#include <signal.h>

int	my_putnbr_base(unsigned int nb, int pid)
{
  int	result;
  int	diviseur;

  diviseur = 1;
  while ((nb / diviseur) >= 2)
    diviseur = diviseur * 2;
  while (diviseur > 0)
    {
      result = (nb /diviseur) % 2;
      if (result == 0)
	{
	  if (kill(pid, SIGUSR1) == -1)
	    return (0);
	}
      else if (result == 1)
	{
	  if (kill(pid, SIGUSR2) == -1)
	    return (0);
	}
      diviseur = diviseur / 2;
      usleep(5000);
    }
}

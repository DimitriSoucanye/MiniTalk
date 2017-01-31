/*
** main.c for a in /home/soucan_d/soucan_d/Projets/PSU_2015_minitalk/client
**
** Made by Dimitri
** Login   <soucan_d@epitech.net>
**
** Started on  Fri Jan 29 17:20:50 2016 Dimitri
** Last update Sun Feb 21 21:30:24 2016 Dimitri
*/

#include <signal.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	calibrage(int a, int pid)
{
  int	b;

  b = 0;
  while (b != a)
    {
      if (kill(pid, SIGUSR1) == -1)
	return (0);
      b = b + 1;
      usleep(5000);
    }
}

void	height_char(int nb, int pid)
{
  if (nb < 2)
    calibrage(7, pid);
  else if (nb >= 2 && nb < 4)
    calibrage(6, pid);
  else if (nb >= 4 && nb < 8)
    calibrage(5, pid);
  else if (nb >= 8 && nb < 16)
    calibrage(4, pid);
  else if (nb >= 16 && nb < 32)
    calibrage(3, pid);
  else if (nb >= 32 && nb < 64)
    calibrage(2, pid);
  else
    calibrage(1, pid);
}

int	display_asciicode(char *str)
{
  int	a;
  static int	b;

  a = 0;
  while (a < str[b])
    {
      a = a + 1;
    }
  b = b + 1;
  return (a);
}

void	my_send(int pid, char *str)
{
  int	a;
  int	ascii;

  a = 0;
  while (str[a] != 0)
    {
      if ((ascii = display_asciicode(str)) == 10)
	{
	  height_char(ascii, pid);
	  display_return(pid);
	  a = a + 1;
	}
      else
	{
	  height_char(ascii, pid);
	  my_putnbr_base(ascii, pid);
	  a = a + 1;
	}
    }
  if (str[a] == 0)
    {
      height_char(10, pid);
      display_return(pid);
    }
}

int	main(int argc, char **argv)
{
  int	pid;

  if (argc != 3)
    my_help2();
  pid = my_atoi(argv[1]);
  if (pid <= 0)
    {
      write(2, "Wrong PID\n", 10);
      exit(1);
    }
  if (argc == 3)
    {
      my_send(pid, argv[2]);
    }
}

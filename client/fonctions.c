/*
** fonctions.c for a in /home/soucan_d/soucan_d/Projets/PSU_2015_minitalk/client
**
** Made by Dimitri
** Login   <soucan_d@epitech.net>
**
** Started on  Fri Jan 29 17:26:11 2016 Dimitri
** Last update Sun Feb 21 21:30:43 2016 Dimitri
*/

#include <signal.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	a;

  a = 0;
  while (str[a] != 0)
    {
      my_putchar(str[a]);
      a = a + 1;
    }
}

int	display_return(int pid)
{
  int	a;

  a = 0;
  while (a != 4)
    {
      if (kill(pid, SIGUSR2) == -1)
	return (0);
      a = a + 1;
      usleep(5000);
      if (kill(pid, SIGUSR1) == -1)
	return (0);
      a = a + 1;
      usleep(5000);
    }
}

int	my_strlen(char *str)
{
  int	a;

  while (str[a] != 0)
    a = a + 1;
  return (a);
}

void	my_help2()
{
  my_putstr("\033[31mAttention, le serveur client s'utilise \033[37m");
  my_putstr("\033[31mselon ce modèle :\n\033[37m");
  my_putstr("[exécutable] [PID de serveur] [chaîne de caractère ");
  my_putstr("-> en caractère Ascii]\n");
  exit(1);
}

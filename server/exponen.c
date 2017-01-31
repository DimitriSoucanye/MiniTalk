/*
** exponen.c for a in /home/soucan_d/soucan_d/Projets/PSU_2015_minitalk/server
**
** Made by Dimitri
** Login   <soucan_d@epitech.net>
**
** Started on  Thu Feb  4 13:11:06 2016 Dimitri
** Last update Thu Feb  4 15:25:44 2016 Dimitri
*/

int	exponen(int nb, int power)
{
  int	a;
  int	nb_tmp;

  a = 0;
  nb_tmp = 1;
  while (a != power)
    {
      nb_tmp = nb_tmp * nb;
      a = a + 1;
    }
  return (nb_tmp);
}

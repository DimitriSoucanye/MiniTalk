/*
** my_atoi.c for a in /home/soucan_d/Projets/CPE_2015_Pushswap/final
**
** Made by DImitri Soucanye de Landevoisin
** Login   <soucan_d@epitech.net>
**
** Started on  Thu Nov 19 16:40:03 2015 DImitri Soucanye de Landevoisin
** Last update Sun Feb  7 13:39:12 2016 Dimitri
*/

int	my_atoi(const char *str)
{
  int	i;
  int	j;
  int	idx;

  idx = 0;
  i = 0;
  j = 0;
  if (str[0] == '-')
    {
      idx = 1;
      i = 1;
    }
  while (str[i] != 0)
    {
      if (str[i] >= '0' && str[i] <= '9')
	{
	  j = j * 10;
	  j = j + str[i] - '0';
	}
      i = i + 1;
    }
  if (idx == 1)
    j = j * -1;
  return (j);
}

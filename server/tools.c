/*
** fonction.c for a in /home/soucan_d/soucan_d/Projets/PSU_2015_minitalk/serveur
**
** Made by Dimitri
** Login   <soucan_d@epitech.net>
**
** Started on  Fri Jan 29 17:43:20 2016 Dimitri
** Last update Thu Feb  4 20:07:46 2016 Dimitri
*/

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

int	my_put_nbr(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * -1;
    }
  if (nb >= 10)
    {
      my_put_nbr(nb / 10);
      my_put_nbr(nb % 10);
    }
  else
    my_putchar(48 + nb);
}

void	my_error_2()
{
  my_putstr("\033[31mAttention, le serveur s'utilise \033[37m");
  my_putstr("\033[31mselon ce modèle :\n\033[37m");
  my_putstr("[exécutable]\n");
}

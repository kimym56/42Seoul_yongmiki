#include <stdio.h>

char *ft_strcapitalize(char *str);

int main()
{
	char str[100] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un Arirang   aRaRiYo!horangE!";
	printf("[expected result is below]\n");
	puts("\tSalut, Comment Tu Vas ? 42mots Quarante-Deux; Cinquante+Et+Un Arirang   Arariyo!Horange!\n");

	puts("[below is your result]");
	printf("\t%s", ft_strcapitalize(str));
}

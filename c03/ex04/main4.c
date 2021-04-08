#include <string.h>
#include <stdio.h>

char     *ft_strstr(char *str, char *to_find);

int main()
{
    char s1[10][30] = {"ABABABCDEFG", "Hello", "H", "", "ABCDEFG"};
    char s2[10][10] = {"CDE", "H", "   i", "HelloAb", "G"};
    int size = 5;
    
    puts("===== expected result=====");
    puts("return: [CDEFG]");
    puts("return: [Hello]");
    puts("return: [(null)]");
    puts("return: [(null)]");
    puts("return: [G]");
    
    puts("\n===== your result=======");
    for(int i=0; i<size; i++) {
        printf("return: [%s] ", ft_strstr(s1[i], s2[i]));
        puts("");
    }
}

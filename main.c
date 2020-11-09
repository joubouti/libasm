#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <stdlib.h>

int		ft_strlen(char *str);
int		ft_strcpy(char *dest, char *src);
int		ft_putstr(char *str);
int		ft_strcmp(char *s1, char *s2);
int		ft_write(int fd, char *str, size_t nbyte);
int		ft_read(int fd, char *buff, size_t nbyte);
char 	*ft_strdup(char *str);

// int		ft_strcpy(char *dest, char *src);

int main(void)
{

	char hello[15] = "Hello";
	//char src[] = " World";
	char *src = ft_strdup(hello);
	printf("|%s|", src);
    return (0);
}

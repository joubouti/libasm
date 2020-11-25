#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <string.h>

size_t	ft_strlen(const char *str);
char*	ft_strcpy(char *dest, const char *src);
int		ft_strcmp(char *s1, char *s2);
ssize_t	ft_write(int fd, const void *str, size_t nbyte);
ssize_t	ft_read(int fd, void *buff, size_t nbyte);
char 	*ft_strdup(const char *str);


int main(void)
{

	/* ft_strlen */
	printf("ft_strlen: %ld\n", ft_strlen("Hello World"));
	printf("   strlen: %ld\n",	  strlen("Hello World"));

	printf("ft_strlen: %ld\n", ft_strlen(""));
	printf("   strlen: %ld\n",	  strlen(""));

	printf("ft_strlen: %ld\n", ft_strlen("Hello\nWorld\0123"));
	printf("   strlen: %ld\n",	  strlen("Hello\nWorld\0123"));

	printf("ft_strlen: %ld\n", ft_strlen("Hello\200World\0123"));
	printf("   strlen: %ld\n",	  strlen("Hello\200World\0123"));

	// printf("ft_strlen: %ld", ft_strlen(NULL));
	// printf("   srtlen: %ld",	strlen(NULL));

	/* ft_strcpy */
	printf("---------------------------\n");
	char dest1[100] = "Hello";
	char dest2[100] = "Hello";
	printf("ft_strcpy: %s\n", ft_strcpy(dest1, "World"));
	printf("   strcpy: %s\n",    strcpy(dest2, "World"));

	char dest3[100] = "";
	char dest4[100] = "";
	printf("ft_strcpy: %s\n", ft_strcpy(dest3, "Hello"));
	printf("   strcpy: %s\n",    strcpy(dest4, "Hello"));

	char dest5[100] = "Hello";
	char dest6[100] = "Hello";
	printf("ft_strcpy: %s\n", ft_strcpy(dest5, ""));
	printf("   strcpy: %s\n",    strcpy(dest6, ""));

	/* ft_strcmp */
	printf("---------------------------\n");

	printf("ft_strcmp: %d\n", ft_strcmp("Hello", "World"));
	printf("   strcmp: %d\n",    strcmp("Hello", "World"));

	printf("ft_strcmp: %d\n", ft_strcmp("Hello", "Hello"));
	printf("   strcmp: %d\n",    strcmp("Hello", "Hello"));

	printf("ft_strcmp: %d\n", ft_strcmp("Hello", "HellO"));
	printf("   strcmp: %d\n",    strcmp("Hello", "HellO"));

	printf("ft_strcmp: %d\n", ft_strcmp("", "Hello"));
	printf("   strcmp: %d\n",    strcmp("", "Hello"));

	printf("ft_strcmp: %d\n", ft_strcmp("Hello", ""));
	printf("   strcmp: %d\n",    strcmp("Hello", ""));

	printf("ft_strcmp: %d\n", ft_strcmp("", ""));
	printf("   strcmp: %d\n",    strcmp("", ""));

	printf("ft_strcmp: %d\n", ft_strcmp("Hello", "Hello\200"));
	printf("   strcmp: %d\n",    strcmp("Hello", "Hello\200"));

	/* ft_write */
	printf("---------------------------\n");

	printf("    %ld\n", ft_write(1, "Hello, World!", 13));
	printf("    %ld\n",    write(1, "Hello, World!", 13));

	printf("    %ld\n", ft_write(1, "Hello, World!", 5));
	printf("    %ld\n",    write(1, "Hello, World!", 5));

	printf("    %ld\n", ft_write(1, "", 0));
	printf("    %ld\n",    write(1, "", 0));

	int fd1 = open("test1", O_RDWR | O_CREAT);
	int fd2 = open("test2", O_RDWR | O_CREAT);
	printf("    %ld\n", ft_write(fd1, "Hello, World!", 13));
	printf("    %ld\n",    write(fd2, "Hello, World!", 13));

	/* ft_read */
	printf("---------------------------\n");

	char buff[10000];
	buff[9999] = 0;

	int fd = open("main.c", O_RDWR | O_CREAT);

	ssize_t ret = read(fd, buff, 10000);
	printf("%ld\n%s\n", ret, buff);

	/* ft_strdup */
	printf("---------------------------\n");
	char *str;

	str = ft_strdup("Hello");
	printf("|%s|\n", str);
	free(str);
	str = ft_strdup("World");
	printf("|%s|\n", str);
	free(str);

	str = ft_strdup("");
	printf("|%s|\n", str);
	free(str);

    return (0);
}
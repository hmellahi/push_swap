
#ifndef FUNCTIONS_H
# define FUNCTIONS_H


# include "minishell.h"
//This header file is only for functions' prototypes

/* 
## Allowed functions: 
####################
    malloc() free() write() open() read() close() fork() wait()
    waitpid() wait3() wait4() signal() kill() exit() getcwd()
    chdir() stat() lstat() fstat() execve() dup() dup2() pipe()
    opendir() readdir() closedir() strerror() errno()
*/

// main
//int         shell_prompt(ENV);

// strtools_0
size_t      str_len(const char *str);
void        put_char(char c);
void        put_str(const char *str);
void        fput_char(char c, int fd);
void        fput_str(const char *str, int fd);

// strtools_1
t_bool      find_eol(char *buff);
size_t      line_len(const char *str);
t_bool      str_cmp(char *s1, char *s2);
t_bool      str_ncmp(char *s1, char *s2, int max);

// strtools_2
char        *str_dup(const char *str);
char        *str_join(const char *s1, const char *s2);

//
int         get_line(int fd, char **line);

#endif
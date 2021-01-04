
#ifndef FUNCTIONS_H
# define FUNCTIONS_H


# include "minishell.h"
//This header file is only for functions' prototypes

/* 
## Allowed functions: 
####################
    malloc() free() write() open() read() 
    fork() wait() waitpid() wait3() wait4()
    stat() lstat() fstat() execve() pipe()
    chdir() opendir() readdir() closedir()
    getcwd() dup() dup2()
    signal() kill() close() exit()
    strerror() errno()
*/

// main
int         shell_prompt(ENV);
int         read_input(char **input);

// strtools_0
size_t      str_len(const char *str);
void        put_char(char c);
void        put_str(const char *str);
void        fput_char(char c, int fd);
void        fput_str(const char *str, int fd);

// strtools_1
t_bool      find_eol(char *buff);
size_t      line_len(const char *str);
t_bool      line_isempty(char *line);
t_bool      str_cmp(char *s1, char *s2);
t_bool      str_ncmp(char *s1, char *s2, int max);

// strtools_2
char        *str_dup(const char *str);
char        *str_join(const char *s1, const char *s2);
char        *sub_str(
    char const *s, size_t start, size_t len);
//
int         get_line(int fd, char **line);

//
t_env       *init_env();

#endif
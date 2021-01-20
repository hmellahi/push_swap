
#ifndef STRUCTS_H
# define STRUCTS_H

typedef	char			t_bool;

typedef struct			s_node
{
	void				*data;
	struct s_node		*next;
}						t_node;

typedef struct			s_btree
{
	void				*data;
	struct s_btree		*r;
	struct s_btree		*l;
}						t_btree;

typedef struct			s_file
{
	int					fd;
	char				*name;
}						t_file;

typedef struct			s_array
{
	int					*arr;
	int					size;
}						t_array;

typedef struct			s_token
{
	char				*tok; //"cd" ";"
	char				*type; //CMD, ARG, SEP,  "PIPE"
	size_t				*len;
	int					*order;
	t_bool				quoted;
}						t_token;

typedef struct			s_tokens_node
{
	t_token				*token;
	struct s_tokens_node*next;
}						t_tokens_node;

typedef struct			s_input
{
	char				*line;
	size_t				len;
	size_t				i;
}						t_input;

typedef struct			s_env
{
	int					argc;
	char				**argv;
	char				**env_var;
	t_input				*input;
	t_node              *tokens;
}						t_env;

#endif
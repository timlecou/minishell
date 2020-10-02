
#ifndef STRUCTURE_H
# define STRUCTURE_H

typedef struct		s_env
{
    char		*var;
    struct s_env	*next;
}			t_env;

typedef struct  s_cmd
{
    char        *name;
    int         is_op;
    char        *op;
    char        **av;
    int		ac;
}               t_cmd;

typedef struct  s_data
{
    int         nb_cmd;
    char        **cmd;
    char        **envp;
    t_env	*env;
    t_cmd       *tab;
}               t_data;
#endif

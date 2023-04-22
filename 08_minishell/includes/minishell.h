/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:59:07 by yongmipa          #+#    #+#             */
/*   Updated: 2023/03/28 11:44:04 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"

# include <unistd.h>
# include <stdio.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <fcntl.h>
# include <stdlib.h>
# include <termios.h>
# include <signal.h>
# include <errno.h>
# include <string.h>
# include <sys/wait.h>
# define TRUE 1
# define FALSE 0
# define PROMPT_COLOR "\033[38:5:111m"
# define COMMAND_COLOR "\033[0m"
# define WELCOME_COLOR "\033[38:5:225m"
# define ERROR_COLOR "\033[38:5:196m"
# define STDIN 0
# define STDOUT 1
# define STDERR 2

extern int	g_last_exit_code;

typedef enum e_signal
{
	GENERAL,
	CHILD,
	WAITING,
	HEREDOC
}	t_signal;

typedef enum e_type
{
	HEREDOC_IN,
	HEREDOC_OUT,
	REDIR_IN,
	REDIR_OUT,
	PIPE,
	WORD
}	t_type;

typedef struct s_info
{
	char			*cmd;
	int				type;
	struct s_info	*next;
}	t_info;

typedef struct s_envp
{
	char			*key;
	char			*value;
	struct s_envp	*next;
}	t_envp;

typedef struct s_pipe
{
	int		fd[2];
	int		total_pipe;
	int		heredoc_pos;
	int		heredoc_cnt;
	int		status;
	int		flag;
	pid_t	pid;
	char	**filename;
	int		stdout_back;
	int		stdin_back;
	int		*doc_cnt;
	int		here_doc_sig;
}	t_pipe;

void		execute(char *str, t_info *info, t_envp **envp_head);
char		*quote_bulk(char *line, char c);
char		*get_after_quote(char *line, char *bulk);
void		str_tokenize(t_info *info, char *line);
int			reminder_in_quote(char quote, int i, char *line);
void		find_dollar(t_info *token, t_envp *_env);
int			check_quote_couple(char *token);
void		next_dollar(char next, char **str, int *i);
char		*parse_dollar(char *str, t_envp *head);
void		clear_quote_in_token(t_info *token);
int			find_next_quote(char *line, char quote, int quote_idx);
int			here_quote(char *line);
char		*get_full_token(t_info *cmd);
int			is_quote(char *s);
int			is_not_whitespace(char line);
int			modu_spacebar_ya(char *line);
void		quote_process(t_info *info, char **line);
void		ft_remainder(t_info *info, char **line);
void		move_heredoc(t_info **token, int pipe);
void		move_list(t_info **token);
int			list_count_heredoc(t_info *token);
int			get_heredoc_pipe(t_info *token, int cnt);
void		execve_token(t_info *token, t_envp **env, pid_t pid);
t_info		*get_token(t_info **token, t_pipe *var, int i);
void		pipex(t_info *token, t_envp **env);
int			type_redir_in(t_info **token);
int			type_redir_out(t_info **token);
int			type_heredoc_in(t_info **token, t_pipe *var, int i);
int			type_heredoc_out(t_info **token);
void		access_builtin(t_info *head, t_envp **env, t_pipe *var);
t_pipe		*get_pipe_info(t_info *token);
void		here_doc(char *limiter, t_envp *envp, char *filename);
char		**set_path(char *cmd, t_envp *envp);
char		*get_cmd(char *cmd, t_envp *envp);
void		syntax_errno(char *cmd);
int			check_syntax(t_info *token);
int			get_pipe_count(t_info *token);
int			validate_quote_all(t_info *token);
int			vaildate_type(t_info *head);
int			ft_arrlen(char **arr);
int			ft_strchr_int(const char *s, char c);
char		*ft_strjoin_free(char *s1, char const *s2);
t_info		*init_list(void);
void		insert_list(t_info *info, char *cmd, int tpye);
void		list_delete(t_info **info);
int			list_size(t_info *info);
t_envp		*init_envp(void);
int			check_dupkey(t_envp *envp, char *key);
void		insert_envp(t_envp *envp, char *key, char *value);
void		append_envp(t_envp *envp, char *key, char *value);
t_envp		*set_envp(char **envp);
int			size_envp(t_envp *lst);
void		delete_envp_all(t_envp **envp);
char		**envp_to_arr(t_envp *head);
char		**dup_envp(t_envp *head);
char		*find_envp(t_envp *envp, char *key);
int			is_builtin(t_info *cmd);
int			builtin(t_info *cmd, t_envp **head, pid_t pid);
void		ft_pwd(t_envp *envp);
void		ft_env(t_info *cmd, t_envp *head);
void		ft_export(t_info *arg, t_envp *head);
void		ft_unset(t_info *arg, t_envp **envp);
int			validate_key(char *str);
void		delete_envp(t_info *arg_tmp, t_envp **envp);
void		ft_cd(t_info *arg, t_envp *envp);
void		ft_echo(t_info *arg);
void		ft_exit(t_info *arg);
void		ctrl_d(void);
void		handler(int signum);
void		set_signal(t_signal mode);
void		wait_handler(int signum);
void		common_errno(char *cmd, int res);
int			envp_errno(char *err_value);
void		cd_errno(char *err_value, int res);
void		exit_errno(int arg_status, char *cmd);
void		bulga(char *next_arg, int fd);
void		get_heredoc_file(t_info *token, t_envp *env, t_pipe *var);
char		**file_name(t_info *token);
int			*process_heredoc_cnt(t_info *token, int total_pipe);
int			check_heredoc(t_info *token);
void		wait_process(t_pipe *var);
#endif
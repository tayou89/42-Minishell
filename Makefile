# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junyu <junyu@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/07 12:45:09 by tayou             #+#    #+#              #
#    Updated: 2023/06/26 11:47:01 by tayou            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = cc
CCFLAGS = -Wall -Wextra -Werror
RM = rm
RMFLAGS = -rf
LDFLAGS = -lreadline -L ~/.brew/opt/readline/lib
CPPFLAGS = -I ~/.brew/opt/readline/include
LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft
COMMON_DIR = ./common
PARSING_DIR = ./parsing
EXCUTE_DIR = ./excute
BUILTIN_DIR = ./builtin
COMMON_FILE = minishell \
			  check_argc \
			  make_initial_setting \
			  handle_signal \
			  get_input_and_process_data
PARSING_FILE = parse_line \
			   get_pipe_count \
			   malloc_process \
			   get_process_line \
			   get_process_string_list \
			   execute_redirection_process execute_space_process execute_quote_process \
			   make_string_list \
			   interpret_string_in_list interpret_quote interpret_env \
			   get_command_array \
			   make_heredoc_file \
			   util_1 util_2 control_node control_d_process \
			  free_function free_process_data
BUILTIN_FILE = util/envname_vaild_check\
			   util/ft_atoll\
			   util/ft_lltoa\
			   util/env_util\
			   cd\
			   echo\
			   env\
			   excute_builtin\
			   exit\
			   pwd\
			   export\
			   unset
EXCUTE_FILE =  pipex\
			   dup\
			   create\
			   excute\
			   fork
COMMON_SRC = $(addprefix $(COMMON_DIR)/, $(addsuffix .c, $(COMMON_FILE)))
COMMON_OBJ = $(addprefix $(COMMON_DIR)/, $(addsuffix .o, $(COMMON_FILE)))
PARSING_SRC = $(addprefix $(PARSING_DIR)/, $(addsuffix .c, $(PARSING_FILE)))
PARSING_OBJ = $(addprefix $(PARSING_DIR)/, $(addsuffix .o, $(PARSING_FILE)))
BUILTIN_SRC = $(addprefix $(BUILTIN_DIR)/, $(addsuffix .c, $(BUILTIN_FILE)))
BUILTIN_OBJ = $(addprefix $(BUILTIN_DIR)/, $(addsuffix .o, $(BUILTIN_FILE)))
EXCUTE_SRC = $(addprefix $(EXCUTE_DIR)/, $(addsuffix .c, $(EXCUTE_FILE)))
EXCUTE_OBJ = $(addprefix $(EXCUTE_DIR)/, $(addsuffix .o, $(EXCUTE_FILE)))

all : $(NAME)

clean : 
	make -C $(LIBFT_DIR) fclean
	$(RM) $(RMFLAGS) $(COMMON_OBJ) $(PARSING_OBJ) $(EXCUTE_OBJ) $(BUILTIN_OBJ)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all

$(NAME) : $(LIBFT) $(COMMON_OBJ) $(PARSING_OBJ) $(EXCUTE_OBJ) $(BUILTIN_OBJ)
	$(CC) $(CCFLAGS) $(LDFLAGS) -o $(NAME) $^
	
$(LIBFT) : 
	make bonus -C $(LIBFT_DIR) all

%.o : %.c
	$(CC) $(CCFLAGS) $(CPPFLAGS) -o $@ -c $< 

.PHONY : all clean fclean re libft bonus

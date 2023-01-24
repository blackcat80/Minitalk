# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csitja-b <csitja-b@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 16:34:27 by csitja-b          #+#    #+#              #
#    Updated: 2023/01/24 19:02:06 by csitja-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# =============================== NAMES ====================================== #

NAME        	 		 = .minitalk
NAME_BONUS	 	 		 = .minitalk_bonus
CLIENT_NAME     		 = client
SERVER_NAME 			 = server
CLIENT_BONUS_NAME      	 = client_bonus
SERVER_BONUS_NAME 	 	 = server_bonus
HEADER 			 		 = minitalk.h

# ============================= COMPILATE ==================================== #

RM						= rm -rf
AR         				= ar - rcs
CFLAGS					= -Wall -Werror -Wextra

# =========================== DIRECTORIES ==================================== #

OBJ_DIR					= obj_dir
OBJS_SERVER 			= $(addprefix $(OBJ_DIR)/, $(SRC_SERVER:.c=.o))
OBJS_CLIENT				= $(addprefix $(OBJ_DIR)/, $(SRC_CLIENT:.c=.o))
OBJS_SERVER_BONUS	 	= $(addprefix $(OBJ_DIR)/, $(SRC_SERVER_BONUS:.c=.o))
OBJS_CLIENT_BONUS		= $(addprefix $(OBJ_DIR)/, $(SRC_CLIENT_BONUS:.c=.o))

# =========================== SOURCES ======================================== #

SRC_CLIENT				= utils.c  client.c
SRC_SERVER 				= utils.c  server.c
SRC_CLIENT_BONUS		= utils_bonus.c  client_bonus.c
SRC_SERVER_BONUS 		= utils_bonus.c  server_bonus.c
			  
# =========================== BOLD COLORS ==================================== #

DEF_COLOR 				= \033[1;39m
GRAY 	   				= \033[1;90m
RED		   				= \033[1;91m
GREEN	    			= \033[1;32m
YELLOW	    			= \033[1;93m
BLUE 					= \033[1;94m
MAGENTA     			= \033[1;95m
CYAN        			= \033[1;96m
WHITE		       		= \033[1;97m
	
# =========================== BACKGROUND COLORS ============================  #

BG_Black				=\033[40m

# =========================================================================== #

all: $(NAME)
		@echo "$(BG_Purple)$(GREEN)==== Project Minitalk compiled! ==== ✅ $(DEF_COLOR)$(BG_Black)\n"
		@touch $(NAME)
		
$(NAME):$(OBJS_SERVER) $(OBJS_CLIENT)
		@$(MAKE) $(CLIENT_NAME)
		@$(MAKE) $(SERVER_NAME)

$(NAME_BONUS):$(OBJS_SERVER_BONUS) $(OBJS_CLIENT_BONUS)
		@$(MAKE) $(CLIENT_BONUS_NAME)
		@$(MAKE) $(SERVER_BONUS_NAME)

$(CLIENT_NAME): $(OBJS_CLIENT)
		@$(CC) $(CFLAGS) $(OBJS_CLIENT) -o $(CLIENT_NAME)

$(SERVER_NAME): $(OBJS_SERVER)
		@${CC} ${CFLAGS} ${OBJS_SERVER} -o $(SERVER_NAME)

$(CLIENT_BONUS_NAME): $(OBJS_CLIENT_BONUS)
		@$(CC) $(CFLAGS) $(OBJS_CLIENT_BONUS) -o $(CLIENT_BONUS_NAME)

$(SERVER_BONUS_NAME): $(OBJS_SERVER_BONUS)
		@${CC} ${CFLAGS} ${OBJS_SERVER_BONUS} -o $(SERVER_BONUS_NAME)

$(OBJ_DIR)/%.o: %.c $(HEADER)
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)\n"
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

bonus: $(NAME_BONUS)
	@touch $(NAME_BONUS)
	@echo "$(BG_Purple)$(GREEN)==== Project Minitalk with bonus compiled! ==== ✅ $(DEF_COLOR)$(BG_Black)\n"

.PHONY: all clean fclean re client server client_bonus server_bonus

clean:
	@$(RM) $(OBJ_DIR) 
	@echo "$(CYAN)==== Minitalk object files cleaned! ====$(DEF_COLOR)\n"

fclean: clean
	@$(RM) $(CLIENT_NAME) $(SERVER_NAME) $(CLIENT_BONUS_NAME) $(SERVER_BONUS_NAME) $(NAME) $(NAME_BONUS)
	@echo "$(CYAN)==== Minitalk executable files and name cleaned! ====$(DEF_COLOR)\n"

re : fclean all
	@echo "$(GREEN)==== Cleaned and rebuilt everything for minitalk! ==== ✅ $(DEF_COLOR)\n"



NAME    = webserv
CC      = c++
FLAGS   = -Wall -Wextra -Werror -std=c++98 -g -Iinc
RM      = rm -rf

# Colors
REDD    = \e[0;38;2;255;0;0m
GREEN   = \e[92;5;118m
YELLOW  = \e[93;5;226m
GRAY    = \e[33;2;37m
RESET   = \e[0m
CURSIVE = \e[33;3m

HEADERS = inc/colors.hpp inc/librairies.hpp inc/Listen.hpp inc/Location.hpp inc/Server.hpp inc/Webserv.hpp
SRCS    = src/Listen.cpp src/Server.cpp src/Webserv.cpp main.cpp
OBJS    = $(SRCS:%.cpp=obj/%.o)

all: directories $(NAME)

$(NAME): $(OBJS)
	@printf "$(CURSIVE)$(GRAY)    - Compiling $(NAME)... $(RESET)\n"
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	@printf "$(GREEN)    - Executable $(NAME) ready.\n$(RESET)"

obj/%.o: %.cpp $(HEADERS)
	@mkdir -p $(@D)  # Crée le répertoire pour l'objet s'il n'existe pas encore
	@$(CC) $(FLAGS) -c $< -o $@

directories:
	@mkdir -p obj

clean:
	@if [ -d obj ]; then \
		$(RM) obj; \
		printf "$(YELLOW)    - Object files removed.$(RESET)\n"; \
	fi

fclean: clean
	@if [ -e $(NAME) ]; then \
		$(RM) $(NAME); \
		printf "$(YELLOW)    - Executable $(NAME) removed.$(RESET)\n"; \
	fi

re: fclean all

.PHONY: all clean fclean re directories

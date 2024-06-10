NAME	= ex03
	
CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -rf

#Colors:
REDD		=	\e[0;38;2;255;0;0m
GREEN		=	\e[92;5;118m
YELLOW		=	\e[93;5;226m
GRAY		=	\e[33;2;37m
RESET		=	\e[0m
CURSIVE		=	\e[33;3m

HEADERS = Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp Intern.hpp
SRCS    = Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp main.cpp
OBJS    = $(SRCS:%.cpp=obj/%.o)

all: directories $(NAME)

$(NAME): $(OBJS)
	@printf "$(CURSIVE)$(GRAY) 	- Compiling $(NAME)... $(RESET)\n"
	@ $(CC) $(FLAGS) $(OBJS) -o $(NAME)
	@printf "$(GREEN)    - Executable ready.\n$(RESET)"

obj/%.o: %.cpp $(HEADERS)
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
		$(RM) *_shrubbery; \
		printf "$(YELLOW)    - Executable removed.$(RESET)\n"; \
	fi

re: fclean all

.PHONY: all clean fclean re directories
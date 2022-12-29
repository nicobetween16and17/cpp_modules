NAME	=	account

all:	$(NAME)

$(NAME):
	c++ -Wall -Wextra -Werror -std=c++98 Account.cpp tests.cpp -o $(NAME)

clean:
	rm -rf Account.o

fclean:	clean
	rm -rf $(NAME)

re: fclean all
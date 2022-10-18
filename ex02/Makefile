SRCS			= Account.cpp tests.cpp

OBJS			= $(SRCS:.cpp=.o)

CC				= c++

FLAGS			= -Wall -Wextra -Werror -std=c++98

RM				= rm -f

NAME			= Banking


all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
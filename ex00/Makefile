SRCS			= megaphone.cpp

CC				= c++

FLAGS			= -Wall -Wextra -Werror -std=c++98

RM				= rm -f

NAME			= megaphone

OBJS			= $(SRCS:.cpp=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(FLAGS) $(OBJS) -o $(NAME)

.cpp.o		:
				${CC} ${FLAGS} -c $< -o ${<:.cpp=.o}

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
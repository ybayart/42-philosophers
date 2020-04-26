DIRSRC		= ./srcs/

DIRINC		= ./includes/

DIROBJ		= ./objs/

SRC			=	atoi \
				init \
				main \
				thread \
				time \

SRCS		= $(addprefix ${DIRSRC}, $(addsuffix .c, ${SRC}))

HEAD		= ./includes/ 

OBJS		= ${SRCS:.c=.o}

NAME		= philo_two

NAMELFT		= libft.a

CC			= gcc
RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c -I${DIRINC} $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			${CC} ${CFLAGS} -I ${DIRINC} -o ${NAME} ${OBJS}

all:		$(NAME)

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} $(NAME)

re:			fclean all

.PHONY:		all clean fclean re

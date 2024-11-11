# Variables
NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

# Source and Object Files
SRC =   ft_printf.c    ft_utils.c     ft_utils_hex.c



OBJS = ${SRC:.c=.o}


# Compile .c to .o files
.c.o:
	${CC} ${CFLAGS} -c $< -o $@

# Build library with standard objects
${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

# Main build target
all: ${NAME}


# Clean up object files
clean:
	${RM} ${OBJS} 

# Full clean including the library
fclean: clean
	${RM} ${NAME}

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re 

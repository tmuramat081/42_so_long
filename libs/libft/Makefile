# Make vars
NAME = libft.a
CC = gcc
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c \
ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
ft_split.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c \
ft_putendl_fd.c ft_putnbr_fd.c ft_striteri.c ft_isspace.c ft_lstnew.c ft_lstadd_front.c \
ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c 
ADD_SRCS = ft_isspace.c ft_strtol_d.c ft_strcspn.c ft_matrixlen.c ft_matrixdup.c ft_free_matrix.c
GNL_SRCS = ./get_next_line/get_next_line.c
PRF_SRCS = ./printf/ft_printf.c ./printf/doprintf.c ./printf/composer.c ./printf/parser.c \
./printf/converter.c ./printf/utils.c ./printf/printer.c
OBJS = ${SRCS:.c=.o}
ADD_OBJS = ${ADD_SRCS:.c=.o}
PRF_OBJS = ${PRF_SRCS:.c=.o}
GNL_OBJS = ${GNL_SRCS:.c=.o}
PRF_DIR = ./printf
GNL_DIR = ./get_next_line
INCS = -I. -I${PRF_DIR} -I${GNL_DIR}
CFLAG = -Wall -Wextra -Werror 
AR = ar rc

# Print vars
PRINTF = printf
DEFAULT = \033[0;39m
BLUE = \033[0;94m
GREEN = \033[0;92m
RED = \033[0;91m

# Progress vars
SRC_COUNT_TOT := $(shell expr $(shell echo -n $(SRCS) ${ADD_SRCS} ${GNL_SRCS} ${PRF_SRCS} | wc -w) - $(shell ls -Rl 2>&1 | grep ".o" | wc -l) + 1)
ifeq ($(shell test $(SRC_COUNT_TOT) -le 0; echo $$?), 0)
	SRC_COUNT_TOT := $(shell echo -n $(SRCS) ${ADD_SRCS} ${GNL_SRCS} ${PRF_SRCS} | wc -w)
endif
SRC_COUNT := 0
SRC_PCT = $(shell expr 100 \* $(SRC_COUNT) / $(SRC_COUNT_TOT))

${NAME}: ${OBJS} ${ADD_OBJS} ${PRF_OBJS} ${GNL_OBJS}
	@${AR} ${NAME} ${OBJS} ${ADD_OBJS} ${PRF_OBJS} ${GNL_OBJS}
	@$(PRINTF) "${GREEN}\r%100s\r${NAME} is up to date!\n${DEFAULT}"

.c.o:
	@$(eval SRC_COUNT = $(shell expr $(SRC_COUNT) + 1))
	@${PRINTF} "\r%100s\r[ %d/%d (%d%%) ] Compiling ${BLUE}$<${DEFAULT}..." "" $(SRC_COUNT) $(SRC_COUNT_TOT) $(SRC_PCT)
	@${CC} ${CFLAG} ${INCS} -c $< -o $@

all: ${NAME}

clean:
	@rm -f ${OBJS} ${ADD_OBJS} ${PRF_OBJS} ${GNL_OBJS}

fclean: clean
	@rm -f ${NAME}

re: fclean all

.PHONY: all bonus clean fclean re

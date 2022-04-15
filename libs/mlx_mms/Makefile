


MODULE_SRC= mlx_image.swift mlx_window.swift mlx_init.swift
MODULE_OBJ=$(MODULE_SRC:.swift=.swiftmodule)

SRC= interface.swift $(MODULE_SRC)
OBJ=$(SRC:.swift=.o)

C_SRC= mlx_xpm.c mlx_png.c mlx_string_put.c
C_OBJ=$(C_SRC:.c=.o)
CFLAGS=-O3

NAME=libmlx.dylib

INC=-I.
#OPTI=-Ounchecked

# Print variables
PRINTF = printf
DEFAULT = \033[0;39m
BLUE = \033[0;94m
GREEN = \033[0;92m
RED = \033[0;91m

# Progress variables
SRC_TOT := ${shell expr ${words ${SRC}} - ${shell ls -l ${OBJ_DIR}/ | grep .o$ | wc -l} + 1}
SRC_CNT := 0
SRC_PCT = $(shell expr 100 \* $(SRC_CNT) / $(SRC_TOT))
PROGRESS = $(eval SRC_COUNT = $(shell expr ${SRC_CNT} + 1)) \
	${PRINTF} "${GREEN}\r%100s\r[ %d/%d (%d%%) ] ${CC} ${CFLAGS} $< ...${DEFAULT}" "" $(SRC_CNT) $(SRC_TOT) $(SRC_PCT)

all: $(NAME)

$(NAME): $(MODULE_OBJ) $(OBJ) $(C_OBJ)
	swiftc $(OPTI) $(INC) -o $(NAME) -emit-library $(OBJ) $(C_OBJ) -lz
	@echo "%100\r${BLUE}--- ${NAME} is up to date! ---${DEFAULT}"



%.o: %.swift
	swiftc $(OPTI) $(INC) -parse-as-library -c $< -o $@
	${PROGRESS} 

%.swiftmodule: %.swift
	swiftc $(OPTI) $(INC) -parse-as-library -c $< -o $@ -emit-module -module-name $(patsubst %.swift,%,$<) -module-link-name $(patsubst %.swift,%,$<)

clean:
	rm -f $(NAME) $(OBJ) $(MODULE_OBJ) $(C_OBJ) *.swiftdoc *~


AS = nasm
ASFLAGS = -f elf64 -g
# LD = ld
# LDFLAGS =
RM = rm -rf
NAME = libasm

GENERAL = ft_write

SRCS = $(addsuffix .s $(GENERAL))

OBJ_DIR = obj
OBJS = $(SRCS:%.s=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	$(info Archiving libasm...)
	ar rc $(NAME) $(OBJS)
	$(info Done!)

$(OBJ_DIR):
	mkdir -p obj

$(OBJ_DIR)/%.o: %.s
	$(info Assembling...)
	$(AS) $(ASFLAGS) $(SRCS) $< -o $@
	$(info Done!)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus:

.PHONY: all libasm obj clean fclean re bonus

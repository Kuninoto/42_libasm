AS = nasm
ASFLAGS = -f elf64
RM = rm -rf
NAME = libasm.a

GENERAL = ft_read ft_strcmp ft_strcpy ft_strdup ft_strlen ft_write
SRCS = $(addsuffix .s, $(GENERAL))

OBJ_DIR = obj
OBJS = $(SRCS:%.s=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	$(info Assembling and archiving libasm...)
	ar rc $(NAME) $(OBJS)
	$(info Done!)

$(OBJ_DIR):
	mkdir -p obj

$(OBJ_DIR)/%.o: %.s
	$(AS) $(ASFLAGS) $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all libasm obj clean fclean re bonus

.SILENT:

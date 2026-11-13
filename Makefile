MAKEFLAGS	+=	--no-print-directory

MODULES	:=	$(sort $(patsubst %/,%,$(dir $(wildcard cppmodules*/Makefile))))

# Colors
RST		= 	\033[0m
MAGENTA	= 	\033[1;35m
BG_GREEN	= 	\033[42m
BG_RST		= 	\033[0m

all:
	@for mod in $(MODULES); do \
		printf "$(MAGENTA)Building $$mod...$(RST)\n"; \
		$(MAKE) -C "$$mod" all; \
	done

clean:
	@for mod in $(MODULES); do \
		printf "$(MAGENTA)Cleaning $$mod...$(RST)\n"; \
		$(MAKE) -C "$$mod" clean; \
	done

fclean: clean
	@for mod in $(MODULES); do \
		printf "$(MAGENTA)Fully cleaning $$mod...$(RST)\n"; \
		$(MAKE) -C "$$mod" fclean; \
	done

re: fclean all

.PHONY: all clean fclean re

clang -Wall -Wextra -Werror -I libft/includes -o validate.o -c validate.c -g
clang -Wall -Wextra -Werror -I libft/includes -o pre_read.o -c pre_read.c -g
clang -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
clang -o a.out validate.o pre_read.o -I libft/includes -L libft/ -lft -g

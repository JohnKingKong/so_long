# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvigneau <jvigneau@student.42quebec>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/24 11:00:19 by jvigneau          #+#    #+#              #
#    Updated: 2022/03/25 10:34:19 by jvigneau         ###   ########        #
#                                                                              #
# **************************************************************************** #
 #
define JR

BIG LEAK!!!! A PICTURE OF ME WORKING

                        .="=.
                      _/.-.-.\_     _
                     ( ( o o ) )    ))
                      |/  "  \|    //
      .-------.        \'---'/    //
     _|~~ ~~  |_       /`"""`\\   ((
   =(_|_______|_)=    / /_,_\ \\   \\\\
     |:::::::::|      \_\\_'__/ \   ))
     |:::::::[]|       /`  /`~\ | //
     |o=======.|      /   /    \ //
     `"""""""""`  ,--`,--'\/\    /
                  '-- "--'   '--'
endef
export JR

define TEA

		TEABAG THAT MOTHERF***ER

            .------.____
         .-'       \ ___)
      .-'         \\\\
   .-'        ___  \\)
.-'          /  (\  |)
         __  \  ( | |
        /  \  \__'| |
       /    \____).-'
     .'       /   |
    /     .  /    |
  .'     / \/     |
 /      /   \     |
       /    /    _|_
       \   /    /\ /\\
        \ /    /__v__\\
         '    |       |
              |     .#|
              |#.  .##|
              |#######|
              |#######|

endef
export TEA

define  NL


endef

SRCS	= 	main_bonus.c ./srcs/windows_bonus.c ./srcs/map_bonus.c \
			./srcs/render_bonus.c ./srcs/movements_bonus.c \
			./srcs/utils_bonus.c ./srcs/utils2_bonus.c \
			./srcs/collisions_bonus.c ./srcs/init_bonus.c \
			./srcs/player_render_bonus.c ./srcs/init_bonus2.c \
		
OBJS	=	${SRCS:.c=.o}

BONOBJS	=	${BONUS:.c=.o}

CC		=	@gcc

RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror -lmlx -lXext -lX11 -o so_long

LIBS	=	./libs/libft/libft.a

NAME	=	so_long

FTMAKE	=	cd ./libs/libft && make -s 

RUN		=	 ./so_long

CLS		= 	clear

$(NAME)	:		
			$(FTMAKE) 
			$(CC) $(SRCS) $(LIBS) $(CFLAGS)

all		:	$(NAME) 

clean	:	
			${RM} ${OBJS}
			$(FTMAKE) $@
			$(info ______________________________)
			$(info $(NL)Cleaning successful!$(NL))
			$(info ______________________________)

fclean	:	clean
			$(RM) $(NAME)
			$(FTMAKE) $@
			
re		:	fclean all
			
run     :   fclean all
			@echo "\033[0;37mPlease type in the path to the map :"; \
			read CHEMIN; \
			$(RUN) $$CHEMIN
			
bonus	:
			$(FTMAKE)

jr		: 
	clear
	@echo "$$JR"

tea	:
	clear
	@echo "$$TEA"

.PHONY	:	all clean fclean re bonus jr


.SILENT :   clean fclean


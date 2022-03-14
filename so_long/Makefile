# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/24 11:00:19 by jvigneau          #+#    #+#              #
#    Updated: 2022/03/14 12:44:55 by jvigneau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
define JR

	BIG LEAK!!!! A PICTURE OF ME WORKING

                        .="=.
                       /.-.-.\_     _
                     ( ( o o ) )    ))
                      |/  "  \|    //
      .-------.        \'---'/    //
     _|~~ ~~  |_       /`"""`\\   ((
   =(_|_______|_)=    / /_,_\ \\   \\\\
     |:::::::::|      \_\\_'__/ \   ))
     |:::::::[]|       /`  /`~\ | //
     |o=======.|      /   /    \ //
     `"""""""""`  ,--`,--'\/\    /
                  '-- "--'  '--'
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

SRCS    =   main.c ./srcs/utils_2.c ./srcs/map.c ./srcs/render.c \
			./srcs/movements.c ./srcs/utils.c ./srcs/map_utils.c \
			./srcs/collisions.c ./srcs/init.c ./srcs/player_render.c \
		
OBJS    =   ${SRCS:.c=.o}

BONOBJS =   ${BONUS:.c=.o}

CC      =   @gcc

RM      =   rm -f

CFLAGS  =   -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit -o so_long

LIBS    =   ./libs/libft/libft.a

NAME    =   so_long
FTMAKE  =   cd ./libs/libft && make -s 

RUN     =    ./so_long

CLS     =   clear

$(NAME) :       
			$(FTMAKE) 
			$(CC) $(SRCS) $(LIBS) $(CFLAGS)

all     :   $(NAME) 

clean   :   
			${RM} ${OBJS}
			$(FTMAKE) $@
			$(info ______________________________)
			$(info $(NL)Cleaning successful!$(NL))
			$(info ______________________________)

fclean  :   clean
			$(RM) $(NAME)
			$(FTMAKE) $@
			
re      :   fclean all
			
run :       fclean all
			@echo "\n\033[0;37mPlease type in the path to the map :"; \
			read CHEMIN; \
			$(RUN) $$CHEMIN

jr  :   
	${CLS}
	@echo "$$JR"

tea :   
	clear
	@echo "$$TEA"

.PHONY  :   all clean fclean re bonus jr


.SILENT :   clean fclean


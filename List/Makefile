##########################################################
#	MAKEFILE POUR SFML SOUS MINGW						 #
#	MODE DEBUG UNIQUEMENT								 #
#	CREE PAR KAILASDEV									 #
##########################################################

#Compilateur
CC=gcc
#compilation flags
CFLAGS=-ansi -std=c99
#dossiers inlude(bibliotheque)
IFLAGS=-ILib\FMOD\inc
#dossiers lib(bibliotheque)
LFLAGS=-LLib\FMOD\lib
#link
LINK=-lmingw32 -lSDL2main -lSDL2 -lfmodex
#nom de l'executable
EXEC=main
#recupere tous les .cpp
SRC=main.c \
	List.c
OBJ=$(SRC:.c=.o)

#executable a creer
all: $(EXEC)

$(EXEC): $(OBJ)
	@$(CC) -o $@ $^  $(CFLAGS) $(LFLAGS) $(IFLAGS) $(LINK)
	
%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS) $(LFLAGS) $(IFLAGS) $(LINK)
	
clean:
	rm -rf *.o

mrproper: clean
	rm -rf exec/$(EXEC)
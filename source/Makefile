CC=g++
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=
EXEC=main

all: $(EXEC)

main: Main.cpp LecteurFichier.cpp Capteur.cpp Controleur.cpp Mesure.cpp Point.cpp TypeMesure.cpp
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
			

all:
	gcc -c ./src/linked_list.c -I ./headerfiles/ -o ./obj/linked_list.o
	gcc ./apps/app.c ./obj/* -I ./headerfiles/ -o ./bin/app
	./bin/app
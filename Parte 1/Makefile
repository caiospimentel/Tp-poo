all: ExeC

ExeC: cliente.c tp_socket.o
	gcc cliente.c tp_socket.c -o cliente
	
tp_socket.o: tp_socket.c tp_socket.h
	gcc -c tp_socket.c


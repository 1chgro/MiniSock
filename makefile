

 all: server client
server: server.c
	cc -Wall -Wextra server.c -o server

client: client.c
	cc -Wall -Wextra client.c -o client


clean:
	rm -rf client server
ROOTPATH  = $(shell pwd)
SRC       = $(ROOTPATH)/src
HEAD      = $(ROOTPATH)/head
BIN       = $(ROOTPATH)/bin
LIB       = $(ROOTPATH)/lib



all:
	@cd $(SRC) && gcc tcp_complicating_server.c ds_socket.c  ds_tools.c -o tcp_complicating_server -I$(HEAD)
	@mv $(SRC)/tcp_complicating_server $(BIN)
	@echo "compile  complete..........."

.PHONY:clean
clean:
	@rm -fr $(BIN)/tcp_complicating_server

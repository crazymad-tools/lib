SRC_PATH=./
OBJECT=$(SRC_PATH)Socket.o
SRC_FILE=$(SRC_PATH)Socket.cc
LIB_OBJ=$(SRC_PATH)libcrazy_net.a
$(shell mkdir -p /usr/lib64/crazy)
$(shell mkdir -p /usr/include/crazy/net)

all : run $(LIB_OBJ)
.PHONY : all

$(LIB_OBJ) : $(OBJECT)
	ar rc $(LIB_OBJ) $(OBJECT)
$(OBJECT) : $(SRC_FILE)
	g++ -c $(SRC_FILE) -I./

run : main.o $(OBJECT)
	g++ -o run main.o $(OBJECT)
main.o:main.cc
	g++ -c main.cc -I./

.PHONY : install
install:
	cp ./*h /usr/include/crazy/net
	cp -f $(LIB_OBJ) /usr/lib64/crazy

.PHONY : clean
clean :
	-rm run main.o $(OBJECT) $(LIB_OBJ)


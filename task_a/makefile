# defines
CC = gcc
AR = ar -rcs
OBJECTS_MAIN = main.o
OBJECTS_LIB = hello_ariel.o
FLAGS = -Wall -fPIC

all:subtask_1 subtask_2 subtask_3
mains: $(OBJECTS_MAIN) hello_ariel.a
	$(CC) $(FLAGS) -o mains $(OBJECTS_MAIN) hello_ariel.a
maind: $(OBJECTS_MAIN) hello_ariel.so
	$(CC) $(FLAGS) -o maind main1_2 ./hello_ariel.so

hello_ariel_s: lib_hello_ariel.a
hello_ariel.a: $(OBJECTS_LIB) hello_ariel.h
	$(AR) lib_hello_ariel.a $(OBJECTS_LIB)

hello_ariel_d: lib_hello_ariel.so
hello_ariel.so: $(OBJECTS_LIB) hello_ariel.h
	$(CC) -shared -o hello_ariel.so $(OBJECTS_LIB)

# main 1.1
main1_1.o: 
	$(CC) $(FLAGS) -c main1_1.c

# main 1.2
main1_2.o:
	$(CC) $(FLAGS) -c main1_2.c

# main 1.3
main1_3.o:
	$(CC) $(FLAGS) -c main1_3.c

# complie hello_ariel.c
hello_ariel.o: hello_ariel.c hello_ariel.h
	$(CC) $(FLAGS) -c hello_ariel.c

# subtask 1
subtask_1:main1_1.o hello_ariel.o
	$(CC) $(FLAGS) -o subtask_1 main1_1.o hello_ariel.o

# subtask 2
subtask_2:main1_2.o hello_ariel.so
	$(CC) $(FLAGS) -o subtask_2 main1_2.o hello_ariel.so
	export LD_LIBRARY_PATH=/usr/local/lib:$LD_LIBRARY_PATH
	
# subtask 3
subtask_3:main1_3.o hello_ariel.so
	$(CC) $(FLAGS) -o subtask_3 main1_2.o ./hello_ariel.so
	
.PHONY: clean all hello_ariel_d hello_ariel_s

# clean
clean:
	rm -f *.o *.a *.so main mains maind subtask_1 subtask_2 subtask_3
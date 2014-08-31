CFLAGS=-Wall
MPICC=mpicc

HEADERS=vec_type.h \
		vector_functions.h

SOURCES=logistic.c \
		vector_abs.c \
		vector_compare.c \
		vector_reduce.c \
		vector_subtract.c 

OBJECTS=$(addsuffix .o, $(basename $(SOURCES)))

OTHER=Makefile

EXE_NAME=logistic

.PHONY: all clean

.DEFAULT: all

all: $(EXE_NAME)

# I should really put in rules to make headers only dependencies where they actually are, but lazy.
$(OBJECTS): %.o: %.c $(HEADERS)
	        $(MPICC) -c $(CFLAGS) $< -o $@

logistic: $(OBJECTS) $(HEADERS) $(OTHER)
	$(MPICC) $(CFLAGS) $(OBJECTS) -o $(EXE_NAME)

clean:
	-'rm' $(OBJECTS) $(EXE_NAME)


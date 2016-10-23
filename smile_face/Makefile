SOURCE=./smile_face.c
GXX=g++
#CPPFLAGS=-I/usr/local/include/cairo 
#LDFLAGS=-L/usr/local/lib \
		#-lcairo 
LIBCAIRO_INC=$(shell pkg-config --cflags cairo)
LIBCAIRO_LIBS=$(shell pkg-config --libs cairo)

CPPFLAGS += $(LIBCAIRO_INC)
LDFLAGS += $(LIBCAIRO_LIBS)

target:
	$(GXX) ${CPPFLAGS} ${LDFLAGS} $(SOURCE) -o smile_face
clean:
	rm -fr smile_face *.o


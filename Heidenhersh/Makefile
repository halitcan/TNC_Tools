CC		:=	g++
CFLAGS	:= -std=c++11 -Wall -I../include
LDFLAGS	:= -L../lib -lHeidenhersh -lHersh -lTNC150
TARGET	:= Heidenhersh
ALLOBJS	:= main.o gitversion.o

all: $(TARGET)

$(TARGET) : $(ALLOBJS) src/gitversion.cpp
	$(CC) $(ALLOBJS) -o $(TARGET) $(CFLAGS) $(LDFLAGS)

main.o : src/main.cpp
	$(CC) -c src/main.cpp $(CFLAGS)
	
src/gitversion.cpp: ../.git/HEAD ../.git/index
	echo "#include <string>" > $@
	echo "extern const std::string gitversion = \"$(shell git rev-parse HEAD)\";" >> $@
	
gitversion.o: src/gitversion.cpp
	$(CC) -c src/gitversion.cpp $(CFLAGS)
	
clean:
	-rm -f src/gitversion.cpp
	-rm -f $(TARGET)
	-rm -f *.o
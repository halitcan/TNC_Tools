CC			:= g++

LIBNAME		:= Hersh
SRCDIR 		:= src
BUILDDIR 	:= build
CFLAGS 		:= -g -Wall -fPIC -std=c++11
LIBS 		= -lpthread 
TARGET 		:= lib$(LIBNAME).so
LDFLAGS 	:= -shared -Wl,-soname=$(TARGET) -g

SRCEXT 		= cpp
SOURCES 	:= $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS 	:= $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
DEPS 		:= $(OBJECTS:.o=.deps)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	-@mkdir ../lib/
	@echo " Linking..."; $(CC) $(LDFLAGS) $^ -o ../lib/$(TARGET) $(LIBS)
	-@mkdir ../include/ 2> /dev/null
	-@mkdir ../include/$(LIBNAME) 2> /dev/null
	-@cp -f src/*.h ../include/$(LIBNAME)/ 
	
$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo " CC $<"; $(CC) $(CFLAGS) -MD -MF $(@:.o=.deps) -c -o $@ $<
	
clean:
	@echo " Cleaning..."; $(RM) -r $(BUILDDIR) ../lib/$(TARGET)
	
-include $(DEPS)

.PHONY: clean
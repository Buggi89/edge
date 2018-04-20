CC       := g++
SRCDIR   := src
BUILDDIR := lib
TESTDIR  := test
TARGET   := bin/edge
SRCEXT   := cpp
TESTEXT  := t

SOURCES  := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT) -and -not -name main.$(SRCEXT) )
OBJECTS  := $(patsubst $(SRCDIR)/%, $(BUILDDIR)/%, $(SOURCES:.$(SRCEXT)=.o))
DEPS     := $(OBJECTS:.o=.d)
TESTS    := $(shell find $(TESTDIR) -type f -name *.$(TESTEXT) -and -not -name main.$(TESTEXT))
TESTOBJS := $(patsubst $(TESTDIR)/%, $(BUILDDIR)/test/%, $(TESTS:.$(TESTEXT)=.o))
TESTDEPS := $(TESTOBJS:.o=.d)
CFLAGS   := -x c++ -g -Wall -std=c++0x
LIB      := 
INC      := -I include

$(TARGET): $(OBJECTS) $(BUILDDIR)/main.o
	@echo " Linking..."
	@echo " $(CC) $^ -o $(TARGET)";
	$(CC) $^ -o $(TARGET)

-include $(DEPS)
$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo " $(CC) $(CFLAGS) $(INC) -c -MMD -MF $(patsubst %.o,%.d,$@) -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -MMD -MF $(patsubst %.o,%.d,$@) -o $@ $<

new: clean $(TARGET)

clean:
	@echo " Cleaning..."
	rm -rf $(BUILDDIR) $(TARGET)

test: bin/tester
	@echo " Execute tests"
	bin/tester

bin/tester: $(TESTOBJS) $(BUILDDIR)/test/main.o $(OBJECTS)
	@echo " Linking tests..."
	$(CC) $^ -o bin/tester

-include $(TESTDEPS)
$(BUILDDIR)/test/%.o: $(TESTDIR)/%.$(TESTEXT)
	@mkdir -p $(BUILDDIR)/test
	@echo " $(CC) $(CFLAGS) $(INC) -c -MMD -MF $(patsubst %.o,%.d,$@) -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -MMD -MF $(patsubst %.o,%.d,$@) -o $@ $<

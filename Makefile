CXX := g++

SRCDIR := src
INCDIR := include
BUILDDIR := build
TARGETDIR := bin

TARGET := $(TARGETDIR)/program

SRCEXT := cpp
HEADEREXT := hpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
HEADERS := $(shell find $(INCDIR) -type f -name *.$(HEADEREXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CXXFLAGS := -std=c++17 -I$(INCDIR)

$(TARGET): $(OBJECTS)
	@mkdir -p $(TARGETDIR)
	$(CXX) $^ -o $(TARGET)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT) $(HEADERS)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	@echo "Cleaning...";
	$(RM) -r $(BUILDDIR) $(TARGETDIR)

run: $(TARGET)
	@echo "Running..."
	./$(TARGET)

.PHONY: clean run

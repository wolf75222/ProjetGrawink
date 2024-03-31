CXX := g++

SRCDIR := src
INCDIR := include
BUILDDIR := build
TARGETDIR := bin
TESTDIR := tests

TARGET := $(TARGETDIR)/program
TESTTARGET := $(TARGETDIR)/tests

SRCEXT := cpp
HEADEREXT := hpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
HEADERS := $(shell find $(INCDIR) -type f -name *.$(HEADEREXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
TESTSOURCES := $(shell find $(TESTDIR) -type f -name *.$(SRCEXT))
TESTOBJECTS := $(patsubst $(TESTDIR)/%,$(BUILDDIR)/%,$(TESTSOURCES:.$(SRCEXT)=.o))

CXXFLAGS := -std=c++17 -I$(INCDIR) -I$(INCDIR)/googletest/googletest/include

COMMON_LDFLAGS := -pthread
TEST_LDFLAGS := $(COMMON_LDFLAGS) -L$(INCDIR)/googletest/build/lib -lgtest -lgtest_main

$(TARGET): $(filter-out $(BUILDDIR)/test_%.o, $(OBJECTS))
	@mkdir -p $(TARGETDIR)
	$(CXX) $^ -o $(TARGET) $(COMMON_LDFLAGS)


$(TESTTARGET): $(TESTOBJECTS) $(filter-out $(BUILDDIR)/main.o, $(OBJECTS))
	@mkdir -p $(TARGETDIR)
	$(CXX) $^ -o $(TESTTARGET) $(TEST_LDFLAGS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT) $(HEADERS)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(BUILDDIR)/%.o: $(TESTDIR)/%.$(SRCEXT) $(HEADERS)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	@echo "Cleaning...";
	$(RM) -r $(BUILDDIR) $(TARGETDIR)

run: $(TARGET)
	@echo "Running..."
	./$(TARGET)

test: $(TESTTARGET)
	@echo "Running tests..."
	./$(TESTTARGET)

.PHONY: clean run test

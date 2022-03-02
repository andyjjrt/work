CXX := g++
CXXFLAGS :=-Wall -g -O2
TARGET := hw4
ODIR := O_
SDIR := .

LIB_SRC := $(shell ls *.cpp)
SRCS := $(LIB_SRC)

OBJS_ := $(patsubst %.cpp, %.o, $(SRCS))
OBJS := $(addprefix $(ODIR)/, $(OBJS_))

$(TARGET): $(ODIR) $(OBJS)
	$(CXX) -o $@ $(CXXFLAGS) $(OBJS)

$(ODIR):
	mkdir $@

$(ODIR)/%.o: $(SDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c$(INC) -o $@ $<

clean:
	rm -rf $(ODIR) $(TARGET)
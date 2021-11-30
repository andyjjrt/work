CXX := g++
CXXFLAGS :=-Wall -g -O2
TARGET := hw2
ODIR := O_
SDIR := .
DATA := $(shell ls *.csv)

LIB_SRC := $(shell ls *.cpp)
SRCS := $(LIB_SRC)

OBJS_ := $(patsubst %.cpp, %.o, $(SRCS))
OBJS := $(addprefix $(ODIR)/, $(OBJS_))

$(TARGET): $(ODIR) $(OBJS)
	$(CXX) -o $@ $(CXXFLAGS) $(OBJS)
	rm -rf $(DATA)

$(ODIR):
	mkdir $@

$(ODIR)/%.o: $(SDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c$(INC) -o $@ $<

clean:
	rm -rf $(ODIR) $(TARGET) $(DATA)
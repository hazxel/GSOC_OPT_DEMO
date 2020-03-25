CC = cc
CXX = g++

CXXFLAGS = -std=c++11

SRCS = $(wildcard *.cpp)

OBJS = $(SRCS:%.cpp=%.o)

TARGET = main

all:$(TARGET)
	@echo " Sources: " $(SRCS)
	@echo " Objects: " $(OBJS)
	@echo " Targets: " $(TARGET)
	@echo ""
	@echo " **************************************************************"
	@echo " * *"
	@echo " **************************************************************"
	@echo ""

$(TARGET): % : $(OBJS)
	$(CXX) -o $@ $(OBJS) $(CXXFLAGS)

$(OBJS): %:


.PHONY : clean cleanobj
clean:
	-rm $(TARGET) $(OBJS)
cleanobj:
	-rm $(OBJS)
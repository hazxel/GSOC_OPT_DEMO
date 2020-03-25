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
	@echo " * this is a demo of a simple Optimization Module             *"
	@echo " *                                                            *"
	@echo " * in this demo:                                              *"
	@echo " *     loss function:  f(x1,x2) = x1^2 + x2^2                 *"
	@echo " *     restraints:     x2 - x1 - 1 > 0                        *"
	@echo " *                     x2 + x1 - 1 > 0                        *"
	@echo " *     initial value:  x1 = 4, x2 = 5                         *"
	@echo " *     algorithm:      gradient descent                       *"
	@echo " *                                                            *"
	@echo " * run ./main to test the demo                                *"
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
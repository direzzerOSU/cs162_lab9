
CXX = g++
CXXFLAGS = -std=c++0x
#CXXFLAGS += -Wall
#CXXFLAGS += -pedantic-errors
#CXXFLAGS += -g
#CXXFLAGS += -O3
#LDFLAGS = -lboost_date_time

OBJS = main.o menu.o inputValidation.o containersSTL.o

SRCS = main.cpp menu.cpp inputValidation.cpp containersSTL.cpp

HEADERS = menu.hpp inputValidation.hpp containersSTL.hpp

#target: dependencies
#	rule to build
#

searchSort: ${SRCS} ${HEADERS}	
	${CXX} ${CXXFLAGS} ${SRCS} -o searchSort

#${OBJS}: ${SRCS}
#	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

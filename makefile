
CXX = g++
CXXFLAGS = -std=c++0x
#CXXFLAGS += -Wall
#CXXFLAGS += -pedantic-errors
#CXXFLAGS += -g
#CXXFLAGS += -O3
#LDFLAGS = -lboost_date_time

OBJS = main.o menu.o inputValidation.o CircularLinkedList.o

SRCS = main.cpp menu.cpp inputValidation.cpp CircularLinkedList.cpp

HEADERS = menu.hpp inputValidation.hpp CircularLinkedList.hpp

#target: dependencies
#	rule to build
#

palindrome: ${SRCS} ${HEADERS}	
	${CXX} ${CXXFLAGS} ${SRCS} -o palindrome

#${OBJS}: ${SRCS}
#	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

# specify the compiler
CXX = g++
CXXFLAGS = -std=c++11 -Wall
# specify the SFML include and lib directories
SFML_INCLUDE=-IC:/Users/sosob/OneDrive/Bureau/ENSISA/Informatique/Cpp/SFML-2.6.0/include
SFML_LIB=-LC:/Users/sosob/OneDrive/Bureau/ENSISA/Informatique/Cpp/SFML-2.6.0/lib -lsfml-graphics -lsfml-window -lsfml-system


SRCS = main.cpp Background.cpp Obstacle.cpp
OBJS = $(SRCS:.cpp=.o)

# specify the target file
TARGET=flappy_toast

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET) $(SFML_LIB)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(SFML_INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

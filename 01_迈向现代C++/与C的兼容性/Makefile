C = gcc
CXX = clang++

SOURCE_C = foo.c
OBJECTS_C = foo.o

SOURCE_CXX = 1.1.cpp

TARGET = main
LDFLAGS_COMMON = -std=c++2a

all:
# 先使用 gcc 编译 C 语言的代码：
	$(C) -c $(SOURCE_C)
# 编译出 foo.o 文件，再使用 clang++ 将 C++ 代码和 .o 文件链接起来（或者都编译为 .o 再统一链接）：
	$(CXX) $(SOURCE_CXX) $(OBJECTS_C) $(LDFLAGS_COMMON) -o $(TARGET)
clean:
	rm -rf *.o $(TARGET)
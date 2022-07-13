SourceFile := 13-2.cpp

Target := main

# main:
# 	g++ $(SourceFile) -o $(Target) -std=c++2a


main:
	rm -rf $(Target) && g++ $(SourceFile) -o $(Target) -std=c++2a && ./$(Target) && rm -rf $(Target)

# clean:
#  	rm -rf *.o $(Target)

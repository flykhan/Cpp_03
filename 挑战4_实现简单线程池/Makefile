SourceFile := *.cpp

Target := main

# main:
# 	g++ $(SourceFile) -o $(Target) -std=c++2a

# clean:
# 	rm -rf *.o $(Target)

main:
	rm -rf $(Target) && g++ $(SourceFile) -o $(Target) -std=c++2a -pthread && ./$(Target) && rm -rf $(Target)
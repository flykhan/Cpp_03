SourceFile := *.cpp

Target := main

main:
	g++ $(SourceFile) -o $(Target) -std=c++2a

clean:
	rm -rf *.o $(Target)

auto:
	rm -rf $(Target) && g++ $(SourceFile) -o $(Target) -std=c++2a && ./$(Target) && rm -rf $(Target)
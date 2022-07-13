SourceFile := 12-5.cpp

Target := main

# main:
# 	g++ $(SourceFile) -o $(Target) -std=c++2a

# clean:
# 	rm -rf *.o $(Target)

main:
	rm -rf $(Target) && g++ $(SourceFile) -o $(Target) -std=c++2a -pthread && ./$(Target) && rm -rf $(Target)

7:
	rm -rf $(Target) && g++ 12-7.cpp -o $(Target) -std=c++2a -pthread && ./$(Target) && rm -rf $(Target)

8:
	rm -rf $(Target) && g++ 12-8.cpp -o $(Target) -std=c++2a -pthread && ./$(Target) && rm -rf $(Target)

9:
	rm -rf $(Target) && g++ 12-9.cpp -o $(Target) -std=c++2a -pthread && ./$(Target) && rm -rf $(Target)

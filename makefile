CityProblem: driver.o
	g++ -o CityProblem driver.o
driver.o: driver.cpp graph.h
	g++ -c driver.cpp
clean:
	rm *.o CityProblem

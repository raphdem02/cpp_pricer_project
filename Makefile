CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
SOURCES = BlackScholesPricer.cpp Option.cpp main.cpp VanillaOption.cpp
EXECUTABLE = PricerLehmanBrothers

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(EXECUTABLE)

.PHONY: all clean

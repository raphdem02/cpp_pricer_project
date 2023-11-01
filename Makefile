CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
SOURCES = BlackScholesPricer.cpp Option.cpp main.cpp VanillaOption.cpp BinaryTree.cpp DigitalOption.cpp CRRPricer.cpp AsianOption.cpp MT.cpp BlackScholesMCPricer.cpp AmericanOption.cpp
EXECUTABLE = PricerLehmanBrothers

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(EXECUTABLE)

.PHONY: all clean

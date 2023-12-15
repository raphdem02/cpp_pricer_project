CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
SOURCES = CallOption.cpp PutOption.cpp BlackScholesPricer.cpp Option.cpp main.cpp VanillaOption.cpp DigitalOption.cpp DigitalCallOption.cpp DigitalPutOption.cpp BlackScholesPricer.cpp CRRPricer.cpp BinaryTree.cpp AsianOption.cpp AsianCallOption.cpp AsianPutOption.cpp BlackScholesMCPricer.cpp MT.cpp AmericanOption.cpp AmericanCallOption.cpp AmericanPutOption.cpp
EXECUTABLE = PricerLehmanBrothers

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(EXECUTABLE)

.PHONY: all clean

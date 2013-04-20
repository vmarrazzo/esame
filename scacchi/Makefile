# Compiler
#CXX = clang++

# Google Test Dir
#GTEST_DIR = ../../gtest_exp/gtest_trunk
GTEST_DIR = /cygdrive/c/Users/vmarrazzo/Documents/gtest-1.6.0

# Flags passed to the preprocessor.
GTEST_CPPFLAGS = -I$(GTEST_DIR)/include

GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

# Usually you shouldn't tweak such internal variables, indicated by a
# trailing _.
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

# Flags passed to the C++ compiler.
# per decodificare lo stackdump bisogna NON usare -ggdb
CXXFLAGS += -g3 -Wall -Wextra
#CXXFLAGS += -ggdb -Wall -Wextra
#CXXFLAGS += -g -Wall -Wextra -std=c++0x
CXXFLAGS_COVERATE = $(CXXFLAGS) -fprofile-arcs -ftest-coverage

# linker flags
LDFLAGS = -Wall -Wextra  
LDFLAGS_COVERAGE = $(LDFLAGS) -fprofile-arcs -ftest-coverage

SOURCES = pezzo.cpp scacchiera.cpp move2Nord.cpp

clean :
	rm -f $(TESTS) *.a *.o *.exe *.stackdump *.xml *.gc*
	
all : clean pezzo.o scacchiera.o

#./scacchieraTest.exe --gtest_shuffle --gtest_repeat=10
test : all scacchieraTest.exe
	./scacchieraTest.exe
	
coverage : coverage_prepare all scacchieraTest.exe
	./scacchieraTest.exe
	gcov $(SOURCES)
	
# modifico le variabili di compilazione per la coverage
coverage_prepare :
	$(eval LDFLAGS = $(LDFLAGS_COVERAGE))
	$(eval CXXFLAGS = $(CXXFLAGS_COVERATE))
	
# da notare  nel comando awk ci vorrebbe solo un $ 
# ma per la corretta interpreatazione in make diventano $$
decode_stackdump : scacchieraTest.exe
	awk '/^[0-9]/{print $$2}' $^.stackdump | addr2line.exe -f -e $^
	
scacchieraTest.exe : pezzo.o scacchiera.o scacchieraTest.o move2Nord.o gtest.a
	$(CXX) $(GTEST_CPPFLAGS) $(LDFLAGS) -lpthread $^ -o $@

scacchieraTest.o :
	$(CXX) $(GTEST_CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c scacchieraTest.cpp	
	
gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(GTEST_CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest-all.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^
	
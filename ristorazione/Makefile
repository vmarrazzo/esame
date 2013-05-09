# Compiler
CXX = clang++

# Google Test Dir
#GTEST_DIR = ../../gtest_exp/gtest_trunk
GTEST_DIR = /cygdrive/c/Users/vmarrazzo/Documents/gtest-1.6.0
GMOCK_DIR = /cygdrive/c/Users/vmarrazzo/Documents/gmock-1.6.0

# Flags passed to the preprocessor.
GTEST_CPPFLAGS = -I$(GTEST_DIR)/include
GMOCK_CPPFLAGS = -I$(GMOCK_DIR)/include

GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h $(GTEST_DIR)/include/gtest/internal/*.h

# Usually you shouldn't tweak such internal variables, indicated by a trailing _.
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

#linked std library
LD_LIBRARY = -pthread -lpthread

SOURCES = persona.cpp tavolo.cpp ristorante.cpp  

clean :
	rm -f *.a *.o *.exe *.stackdump *.xml *.gc*
	
all : clean persona.o tavolo.o ristorante.o 

#./ristoranteTest.exe --gtest_shuffle --gtest_repeat=10
test : all ristoranteTest.exe
	./ristoranteTest.exe
	
mock : all gruppoMockTest.exe
	./gruppoMockTest.exe
	
coverage : coverage_prepare all ristoranteTest.exe
	./ristoranteTest.exe
	gcov $(SOURCES)
	
# modifico le variabili di compilazione per la coverage
coverage_prepare :
	$(eval LDFLAGS = $(LDFLAGS_COVERAGE))
	$(eval CXXFLAGS = $(CXXFLAGS_COVERATE))
	
# da notare  nel comando awk ci vorrebbe solo un $ 
# ma per la corretta interpreatazione in make diventano $$
test_stackdump : ristoranteTest.exe
	awk '/^[0-9]/{print $$2}' $^.stackdump | addr2line.exe -f -e $^

mock_stackdump : gruppoMockTest.exe
	awk '/^[0-9]/{print $$2}' $^.stackdump | addr2line.exe -f -e $^
	
ristoranteTest.exe : persona.o tavolo.o ristorante.o placeGroup2Table.o ristoranteTest.o gmock.a gtest.a
	$(CXX) $(GTEST_CPPFLAGS) $(LDFLAGS) $(LD_LIBRARY) $^ -o $@
	
gruppoMockTest.exe : persona.o tavolo.o ristorante.o gruppoMockTest.o gmock.a gtest.a
	$(CXX) $(GTEST_CPPFLAGS) $(LDFLAGS) $(LD_LIBRARY) $^ -o $@	

ristoranteTest.o :
	$(CXX) $(GTEST_CPPFLAGS) $(GMOCK_CPPFLAGS) $(CXXFLAGS) -c ristoranteTest.cpp

gruppoMockTest.o :
	$(CXX) $(GTEST_CPPFLAGS) $(GMOCK_CPPFLAGS) $(CXXFLAGS) -c gruppoMockTest.cpp

mockgruppo.o :
	$(CXX) $(GTEST_CPPFLAGS) $(GMOCK_CPPFLAGS) -c mockgruppo.cpp	
	
gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(GTEST_CPPFLAGS) -I$(GTEST_DIR) $(GMOCK_CPPFLAGS) -I$(GMOCK_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest-all.cc
			
gmock-all.o : $(GTEST_SRCS_)
	$(CXX) $(GTEST_CPPFLAGS) -I$(GTEST_DIR) $(GMOCK_CPPFLAGS) -I$(GMOCK_DIR) $(CXXFLAGS) -c \
            $(GMOCK_DIR)/src/gmock-all.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^
	
gmock.a : gtest-all.o gmock-all.o
	$(AR) $(ARFLAGS) $@ $^

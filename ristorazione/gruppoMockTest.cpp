#include "ristorante.h"
#include "mockgruppo.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace testing;
using namespace ristorazione;

class GruppoMockSuite : public ::testing::Test {

	protected:
		// puntatore all'oggetto sotto test
		Ristorante* underTest_;

		GruppoMockSuite() {
			underTest_ = NULL;
		}
		
		~GruppoMockSuite() {
			if ( underTest_ != NULL )
				delete underTest_;
		}
};

TEST_F( GruppoMockSuite, SempliceInserimento) {

	Tavolo** input = new Tavolo*[1];
	
	input[0] = new Tavolo(3);
	
	underTest_ = new Ristorante( 1, input);
	
	MockGruppo gruppo;

	EXPECT_CALL( gruppo, QuantePersone())
				.Times(AtLeast(1))
				.WillRepeatedly(Return(100));

	EXPECT_EQ( 100, gruppo.QuantePersone()) << "Il Mock non funge!";
}

int main(int argc, char** argv) {
  // The following line must be executed to initialize Google Mock
  // (and Google Test) before running the tests.
  ::testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}

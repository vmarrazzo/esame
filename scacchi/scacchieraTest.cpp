#include "scacchiera.h"
#include "gtest/gtest.h"
#include <string>
#include <sstream>

using namespace std;
using namespace scacchi;

class ScacchieraSuite : public ::testing::Test {

	protected:
		// puntatore all'oggetto sotto test
		Scacchiera* underTest_;

		ScacchieraSuite() {
			underTest_ = NULL;
		}
		
		~ScacchieraSuite() {
			if ( underTest_ != NULL )
				delete underTest_;
		}
		
		void checkElementoTavola( int riga, int colonna, bool expVuota, TIPO expTipo = NULL__) {
		
			Pezzo* tmp = underTest_->getElemento( riga, colonna);
			bool esito = false;
			TIPO t = NULL__;
        
			ostringstream messaggioErrore;
			messaggioErrore << "Elemento (" << riga << "," << colonna << ")";  
	
			if ( expVuota ) {
				esito = (NULL == tmp);
				messaggioErrore << " NON vuoto!"; 
			}
			else {
				esito = (NULL != tmp);
				messaggioErrore << " vuoto!"; 
				
				t = tmp->getType();
			}
			
			EXPECT_TRUE(esito) << messaggioErrore.str();
			
			if ( !expVuota && expTipo != NULL__ )
				EXPECT_EQ( expTipo, t);
		}
};

TEST_F( ScacchieraSuite, PrimoTestCase) {

	int ut_righe = 8;
	int ut_colon = 12;
	
	underTest_ = new Scacchiera( ut_righe, ut_colon);
	
	EXPECT_EQ(  ut_righe, underTest_->getNumRighe()) << "Errore sulle righe memorizzate."; 
	EXPECT_EQ(  ut_colon, underTest_->getNumColonne()) << "Errore sulle colonne memorizzate.";
	
	EXPECT_EQ(  NULL, underTest_->getElemento(ut_righe, ut_colon)) << "Elemento (" << ut_righe << "," << ut_colon << ") non nullo!";
}

TEST_F( ScacchieraSuite, SecondoTestCase) {

	int ut_righe = 5;
	int ut_colon = 5;
	
	underTest_ = new Scacchiera( ut_righe, ut_colon);
	
	EXPECT_EQ(  ut_righe, underTest_->getNumRighe()) << "Errore sulle righe memorizzate."; 
	EXPECT_EQ(  ut_colon, underTest_->getNumColonne()) << "Errore sulle colonne memorizzate.";
	
	underTest_->piazzamento( 1, 4, new Pezzo(CAVALLO__));
	
	//ASSERT_TRUE( NULL != underTest_->getElemento( 1, 4)) << "Elemento (1,4) nullo!";
	
	checkElementoTavola( 1, 4, false, CAVALLO__);
}

/**
 * Anche i test case necessitano di un main
 */
int main(int argc, char **argv) {
  
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
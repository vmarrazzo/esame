#include "scacchiera.h"
#include "gtest/gtest.h"
#include <string>
#include <sstream>

#include "move2Nord.h"

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
				
				if ( tmp != NULL )	
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

TEST_F( ScacchieraSuite, TerzoTestCase) {

	int ut_righe = 5;
	int ut_colon = 5;
	
	underTest_ = new Scacchiera( ut_righe, ut_colon);
	
	underTest_->piazzamento( 1, 4, new Pezzo(CAVALLO__));
	
	checkElementoTavola( 1, 4, false, CAVALLO__);
	
	EXPECT_EQ( SUCCESSO_, underTest_->spostamento( 1, 4, SX__) );
	
	/**
	 * La casella (1,1) si trova in alto a sx
	 */
	
	checkElementoTavola( 1, 4, true, NULL__);
	checkElementoTavola( 1, 3, false, CAVALLO__);
	
	EXPECT_EQ( SUCCESSO_, underTest_->spostamento( 1, 3, GIU_) );
	
	checkElementoTavola( 1, 3, true, NULL__);
	checkElementoTavola( 2, 3, false, CAVALLO__);
}

TEST_F( ScacchieraSuite, QuartoTestCase) {

	int ut_righe = 5;
	int ut_colon = 5;
	
	underTest_ = new Scacchiera( ut_righe, ut_colon);
	
	underTest_->piazzamento( 1, 4, new Pezzo(CAVALLO__));
	underTest_->piazzamento( 2, 3, new Pezzo(TORRE__));
	
	checkElementoTavola( 1, 4, false, CAVALLO__);
	checkElementoTavola( 2, 3, false, TORRE__);
	
	EXPECT_EQ( SUCCESSO_, underTest_->spostamento( 1, 4, SX__) );
	
	/**
	 * La casella (1,1) si trova in alto a sx
	 */
	
	checkElementoTavola( 1, 4, true, NULL__);
	checkElementoTavola( 1, 3, false, CAVALLO__);
	
	EXPECT_EQ( ARRIVO_OCCUPATA_, underTest_->spostamento( 1, 3, GIU_) );
	
	checkElementoTavola( 1, 3, false, CAVALLO__);
	checkElementoTavola( 2, 3, false, TORRE__);
}

TEST_F( ScacchieraSuite, SimpleMove2NordTestCase) {

	int ut_righe = 5;
	int ut_colon = 5;
	
	underTest_ = new Scacchiera( ut_righe, ut_colon);

	underTest_->piazzamento( 3, 2, new Pezzo(PEDONE__));
	
	move2Nord(underTest_);
	
	checkElementoTavola( 1, 2, false, PEDONE__);
	
	/**
	 * Check that other cells in same column are NULL 
	 */
	checkElementoTavola( 2, 2, true, NULL__);
	checkElementoTavola( 3, 2, true, NULL__);
	checkElementoTavola( 4, 2, true, NULL__);
	checkElementoTavola( 5, 2, true, NULL__);
}
	
TEST_F( ScacchieraSuite, Move2NordTestCase) {

	int ut_righe = 5;
	int ut_colon = 5;
	
	underTest_ = new Scacchiera( ut_righe, ut_colon);
	
	underTest_->piazzamento( 1, 4, new Pezzo(CAVALLO__));
	underTest_->piazzamento( 2, 1, new Pezzo(PEDONE__));
	underTest_->piazzamento( 3, 1, new Pezzo(TORRE__));
	underTest_->piazzamento( 4, 2, new Pezzo(PEDONE__));
	underTest_->piazzamento( 5, 2, new Pezzo(PEDONE__));
	underTest_->piazzamento( 5, 3, new Pezzo(PEDONE__));
	underTest_->piazzamento( 5, 4, new Pezzo(PEDONE__));

	checkElementoTavola( 1, 4, false, CAVALLO__);
	checkElementoTavola( 2, 1, false, PEDONE__);
	checkElementoTavola( 3, 1, false, TORRE__);
	checkElementoTavola( 4, 2, false, PEDONE__);
	checkElementoTavola( 5, 2, false, PEDONE__);
	checkElementoTavola( 5, 3, false, PEDONE__);
	checkElementoTavola( 5, 4, false, PEDONE__);

	//EXPECT_TRUE(false) << "MANCA UN METODO DA IMPLEMENTARE!!!";
	move2Nord(underTest_);
	
	checkElementoTavola( 1, 4, false, CAVALLO__);
	checkElementoTavola( 1, 1, false, PEDONE__);
	checkElementoTavola( 2, 1, false, TORRE__);
	checkElementoTavola( 1, 2, false, PEDONE__);
	checkElementoTavola( 2, 2, false, PEDONE__);
	checkElementoTavola( 1, 3, false, PEDONE__);
	checkElementoTavola( 2, 4, false, PEDONE__);
}

/**
 * Anche i test case necessitano di un main
 */
int main(int argc, char **argv) {
  
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

#include "ristorante.h"
#include "gtest/gtest.h"
#include <string>
#include <sstream>


using namespace std;
using namespace ristorazione;

class RistoranteSuite : public ::testing::Test {

	protected:
		// puntatore all'oggetto sotto test
		Ristorante* underTest_;

		RistoranteSuite() {
			underTest_ = NULL;
		}
		
		~RistoranteSuite() {
			if ( underTest_ != NULL )
				delete underTest_;
		}
		/*
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
		*/
};

TEST_F( RistoranteSuite, PrimoTestCase) {

	Tavolo** input = new Tavolo*[2];
	
	input[0] = new Tavolo(3);
	input[1] = new Tavolo(2);
	
	underTest_ = new Ristorante( 2, input);
	
	Persona* tmp = new Persona();
	
	EXPECT_EQ( SUCCESSO_, underTest_->aggiungiPersona( tmp, (unsigned int)1)) << "Errore sull'inserimento persona."; 
	//EXPECT_EQ(  ut_colon, underTest_->getNumColonne()) << "Errore sulle colonne memorizzate.";

}

/**
 * Anche i test case necessitano di un main
 */
int main(int argc, char **argv) {
  
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
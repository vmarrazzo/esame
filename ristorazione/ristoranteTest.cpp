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

TEST_F( RistoranteSuite, SempliceInserimento) {

	Tavolo** input = new Tavolo*[2];
	
	input[0] = new Tavolo(3);
	input[1] = new Tavolo(2);
	
	underTest_ = new Ristorante( 2, input);
	
	Persona* tmp = new Persona();
	
	unsigned int tavolo = 1;
		
	EXPECT_EQ( SUCCESSO_, underTest_->aggiungiPersona( tmp, tavolo)) << "Errore primo inserimento persona."; 
}

TEST_F( RistoranteSuite, DoppioInserimento) {

	Tavolo** input = new Tavolo*[2];
	
	input[0] = new Tavolo(3);
	input[1] = new Tavolo(2);
	
	underTest_ = new Ristorante( 2, input);
	
	Persona* persona = new Persona();
	
	unsigned int tavolo = 1;
	
	EXPECT_EQ( SUCCESSO_, underTest_->aggiungiPersona( persona, tavolo) ) << "Errore primo inserimento persona.";
	EXPECT_EQ( PERSONA_GIA_PRESENTE_, underTest_->aggiungiPersona( persona, tavolo) ) << "Errore secondo inserimento stessa persona.";

}

TEST_F( RistoranteSuite, LiberaTavolo) {

	Tavolo** input = new Tavolo*[2];

	input[0] = new Tavolo(3); // Tavolo 1
	input[1] = new Tavolo(2); // Tavolo 2

	underTest_ = new Ristorante( 2, input);

	unsigned int tavolo = 2;

	Persona* prima 		= new Persona();
	Persona* seconda 	= new Persona();

	EXPECT_EQ( SUCCESSO_, underTest_->aggiungiPersona( prima, 	tavolo) ) << "Errore inserimento prima persona 1/2.";
	EXPECT_EQ( SUCCESSO_, underTest_->aggiungiPersona( seconda, tavolo) ) << "Errore inserimento seconda persona 1/2.";

	underTest_->liberaTavolo(tavolo);

	// si mangia bene e la gente torna subito
	EXPECT_EQ( SUCCESSO_, underTest_->aggiungiPersona( prima, 	tavolo) ) << "Errore inserimento prima persona 2/2.";
	EXPECT_EQ( SUCCESSO_, underTest_->aggiungiPersona( seconda, tavolo) ) << "Errore inserimento seconda persona 2/2.";

}

TEST_F( RistoranteSuite, ModificaTavolo) {

	Tavolo** input = new Tavolo*[1];

	input[0] = new Tavolo(2); // Tavolo 1

	underTest_ = new Ristorante( 1, input);

	unsigned int tavolo = 1;

	Persona* prima 		= new Persona();
	Persona* seconda 	= new Persona();
	Persona* terza	 	= new Persona();

	EXPECT_EQ( SUCCESSO_, underTest_->aggiungiPersona( prima, 	tavolo) ) << "Errore inserimento prima persona 1/2.";
	EXPECT_EQ( SUCCESSO_, underTest_->aggiungiPersona( seconda, tavolo) ) << "Errore inserimento seconda persona 1/2.";
	EXPECT_EQ( TAVOLO_PIENO_, underTest_->aggiungiPersona( terza, tavolo) )   << "Errore inserimento terza persona 1/2.";

	// ok bisogna modificare il tavolo 
	EXPECT_EQ( TAVOLO_OCCUPATO_, underTest_->modificaTavolo( tavolo, 3) )   << "Errore sulla modifica di un tavolo occupato 1/2.";
	
	// facciamo prima alzare le persone
	underTest_->liberaTavolo(tavolo);

	// riproviamo a modificare il tavolo 
	EXPECT_EQ( SUCCESSO_, underTest_->modificaTavolo( tavolo, 3) )   << "Errore sulla modifica di un tavolo occupato 2/2.";
		
	
	// si mangia bene e la gente torna subito
	EXPECT_EQ( SUCCESSO_, underTest_->aggiungiPersona( prima, 	tavolo) ) << "Errore inserimento prima persona 2/2.";
	EXPECT_EQ( SUCCESSO_, underTest_->aggiungiPersona( seconda, tavolo) ) << "Errore inserimento seconda persona 2/2.";
	EXPECT_EQ( SUCCESSO_, underTest_->aggiungiPersona( terza, tavolo) )   << "Errore inserimento terza persona 2/2.";

}

/**
 * Anche i test case necessitano di un main
 */
int main(int argc, char **argv) {
  
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

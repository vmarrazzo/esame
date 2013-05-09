#include <vector>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "ristorante.h"
#include "mockgruppo.h"
#include "placeGroup2Table.h"


using namespace ristorazione;
using namespace testing;

class RistoranteSuite : public Test {

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

TEST_F( RistoranteSuite, CreoRistoranteVuoto) {

	Tavolo** input = new Tavolo*[2];

	input[0] = new Tavolo(2); // Tavolo 1
	input[1] = new Tavolo(3); // Tavolo 2

	underTest_ = new Ristorante( 2, input);
}

TEST_F( RistoranteSuite, NumeroPostiTavolo) {

	unsigned int posti 					= 2;
	unsigned int posti_dopo_modifica 	= 8;

	Tavolo* ut = new Tavolo(posti);
	
	EXPECT_EQ( posti, ut->numeroPosti() ) << "Errore numero posti alla costruzione.";
	
	ut->cambiaNumeroPosti(posti_dopo_modifica);
	
	EXPECT_EQ( posti_dopo_modifica, ut->numeroPosti() ) << "Errore numero posti dopo modifica.";
}

TEST_F( RistoranteSuite, NumeroTavoliRistorante) {

	unsigned int numTavoli = 2;
	unsigned int postiTav1 = 3;
	unsigned int postiTav2 = 8;

	Tavolo** input = new Tavolo*[numTavoli];

	input[0] = new Tavolo(postiTav1); // Tavolo 1
	input[1] = new Tavolo(postiTav2); // Tavolo 2

	underTest_ = new Ristorante( numTavoli, input);

	map<unsigned int,unsigned int> listaTavoli = underTest_->elencoTavoliPosti();
	
	EXPECT_EQ( numTavoli, listaTavoli.size() ) << "Errore numero tavoli non coincide.";
	
	EXPECT_EQ( postiTav1, listaTavoli[1] ) << "Errore numero posti tavolo 1.";
	EXPECT_EQ( postiTav2, listaTavoli[2] ) << "Errore numero posti tavolo 2.";
}

/**
 * Questo test sparirà a regime
 */
/*
TEST_F( RistoranteSuite, SempliceTestMock) {

	Tavolo** input = new Tavolo*[1];
	
	input[0] = new Tavolo(3);
	
	underTest_ = new Ristorante( 1, input);
	
	MockGruppo gruppo;

	EXPECT_CALL( gruppo, QuantePersone())
				.Times(AtLeast(1))
				.WillRepeatedly(Return(100));

	EXPECT_EQ( 100, gruppo.QuantePersone()) << "Il Mock non funge!";

}
*/
TEST_F( RistoranteSuite, Test_placeGroup2Table) { 

	Tavolo** input = new Tavolo*[2];
	
	input[0] = new Tavolo(2);
	input[1] = new Tavolo(3);
	
	underTest_ = new Ristorante( 2, input);

	Persona* G1_P1 		= new Persona();
	Persona* G1_P2	 	= new Persona();

	Persona* G2_P1 		= new Persona();
	Persona* G2_P2	 	= new Persona();
	Persona* G2_P3	 	= new Persona();
	
	MockGruppo gruppo_1;

	EXPECT_CALL( gruppo_1, QuantePersone())
				.WillRepeatedly(Return(2));	

	EXPECT_CALL( gruppo_1, QualePersona(1))
				.WillRepeatedly(Return(G1_P1));	

	EXPECT_CALL( gruppo_1, QualePersona(2))
				.WillRepeatedly(Return(G1_P2));	
				
	MockGruppo gruppo_2;

	EXPECT_CALL( gruppo_2, QuantePersone())
				.WillRepeatedly(Return(3));
				
	EXPECT_CALL( gruppo_2, QualePersona(1))
				.WillRepeatedly(Return(G2_P1));	

	EXPECT_CALL( gruppo_2, QualePersona(2))
				.WillRepeatedly(Return(G2_P2));	
				
	EXPECT_CALL( gruppo_2, QualePersona(3))
				.WillRepeatedly(Return(G2_P3));	

	vector<Gruppo*> gruppi;
	
	gruppi.insert( gruppi.begin(), &gruppo_1);
	gruppi.insert( gruppi.begin(), &gruppo_2);
	
	placeGroup2Table( underTest_, gruppi);
	
	EXPECT_EQ( PERSONA_GIA_PRESENTE_, underTest_->aggiungiPersona( G1_P1, (unsigned int)1) ) << "Errore la persona G1_P1 NON si trova nel tavolo 1.";
	EXPECT_EQ( PERSONA_GIA_PRESENTE_, underTest_->aggiungiPersona( G1_P2, (unsigned int)1) ) << "Errore la persona G1_P2 NON si trova nel tavolo 1.";
	
	EXPECT_EQ( PERSONA_GIA_PRESENTE_, underTest_->aggiungiPersona( G2_P1, (unsigned int)2) ) << "Errore la persona G2_P1 NON si trova nel tavolo 2.";
	EXPECT_EQ( PERSONA_GIA_PRESENTE_, underTest_->aggiungiPersona( G2_P2, (unsigned int)2) ) << "Errore la persona G2_P2 NON si trova nel tavolo 2.";	
	EXPECT_EQ( PERSONA_GIA_PRESENTE_, underTest_->aggiungiPersona( G2_P3, (unsigned int)2) ) << "Errore la persona G2_P3 NON si trova nel tavolo 2.";	
}

/**
 * Anche i test case necessitano di un main
 */
int main(int argc, char **argv) {
  
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

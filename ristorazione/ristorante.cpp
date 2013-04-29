#include "ristorante.h"

using namespace std;

namespace ristorazione {

	Ristorante::Ristorante(unsigned int numTavoli, Tavolo** tavoli) {
	
		this->persone__ = list<Persona*>();
		this->tavoli__ = vector<Tavolo*>();
		
		for ( unsigned int index = 0 ; index < numTavoli ; index++ )
			this->tavoli__.insert( this->tavoli__.begin() + index, tavoli[index]);
	}
	
	Ristorante::~Ristorante() {

		for ( vector<Tavolo*>::iterator it = this->tavoli__.begin(); it != this->tavoli__.end(); ++it )	
		{
			Tavolo* tmp = *it;
			delete tmp;
			this->tavoli__.erase(it);
		}
		
		for ( list<Persona*>::iterator it = this->persone__.begin(); it != this->persone__.end(); ++it )
		{
			Persona* tmp = *it;
			delete tmp;
			this->persone__.erase(it);
		}
	}
	
	ESITO Ristorante::aggiungiPersona(Persona* p, unsigned int numTavolo) {
	
		ESITO resp = FALLIMENTO_;
		
		if ( personaGiaPresente(p) )
			resp = PERSONA_GIA_PRESENTE_;
		else if ( numTavolo <= this->tavoli__.size() ) {
		
			unsigned int indexTavolo = TAV2INDEX(numTavolo);
		
			Tavolo* tmp = this->tavoli__[indexTavolo];
		
			resp = tmp->aggiungiPersona(p);
			
			if ( resp == SUCCESSO_ )
				this->persone__.push_back(p);
		}

		return resp;
	}
	
	void Ristorante::liberaTavolo(unsigned int numTavolo) {
	
		if ( numTavolo <= this->tavoli__.size() ) {

			unsigned int indexTavolo = TAV2INDEX(numTavolo);

			Tavolo* tmp = this->tavoli__[indexTavolo];

			tmp->liberaTavolo();
		}
	
	}
	
	ESITO Ristorante::modificaTavolo(unsigned int numTavolo, unsigned int posti) {
	
		ESITO resp = FALLIMENTO_;

		return resp;
	}
	
	bool Ristorante::personaGiaPresente(Persona* p) {
		
		bool resp = false;
		
		for ( list<Persona*>::iterator it = this->persone__.begin(); it != this->persone__.end(); ++it )
		{
			Persona* tmp = *it;
			
			if ( p == tmp ) {
				resp = true;
				break;
			}
		}
		
		return resp;
	}
	
}

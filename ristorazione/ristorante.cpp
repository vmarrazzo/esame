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

		unsigned int numTavoli = this->tavoli__.size();
	
		for ( vector<Tavolo*>::iterator it = this->tavoli__.begin(); it != this->tavoli__.end(); ++it )	
		//for ( int index = 0 ; index < numTavoli ; index++ )
		{
			Tavolo* tmp = *it;
			delete tmp;
			this->tavoli__.erase(it);
		/*
			Tavolo* tmp = this->tavoli__[index];
			delete tmp;
			this->tavoli__.erase( this->tavoli__.begin() + index);
		*/
		}
		
		for ( list<Persona*>::iterator it = this->persone__.begin(); it != this->persone__.end(); ++it )
		{
			Persona* tmp = *it;
			delete tmp;
			this->persone__.erase(it);
		}
	}
	
	ESITO Ristorante::aggiungiPersona(Persona* p, unsigned int tavolo) {
	
	
	}
	
	void Ristorante::liberaTavolo(unsigned int tavolo) {
	
	
	}
	
	ESITO Ristorante::modificaTavolo(unsigned int tavolo, unsigned int posti) {
	
	
	}
	
}
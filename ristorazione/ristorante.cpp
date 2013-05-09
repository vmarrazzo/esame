#include "ristorante.h"

using namespace std;

namespace ristorazione {

	Ristorante::Ristorante(unsigned int numTavoli, Tavolo** tavoli) {
	
		for ( unsigned int index = 0 ; index < numTavoli ; index++ )
			this->tavoli__.insert( this->tavoli__.begin() + index, tavoli[index]);
	}
	
	Ristorante::~Ristorante() {

		while( !this->tavoli__.empty() )
		{
			vector<Tavolo*>::iterator it = this->tavoli__.begin();
			Tavolo* tmp = *it;
			delete tmp;
			this->tavoli__.erase(it);
		}
		
		while( !this->persone__.empty() )
		{
			list<Persona*>::iterator it = this->persone__.begin();
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

			list<Persona*>* daRimuovere = tmp->liberaTavolo();

			liberaListaRistorante(daRimuovere);
		}
	
	}
	
	ESITO Ristorante::modificaTavolo(unsigned int numTavolo, unsigned int posti) {
	
		ESITO resp = FALLIMENTO_;

		if ( numTavolo <= this->tavoli__.size() ) {

			unsigned int indexTavolo = TAV2INDEX(numTavolo);

			Tavolo* tmp = this->tavoli__[indexTavolo];

			resp = tmp->cambiaNumeroPosti(posti);
		}

		return resp;
	}
	
	bool Ristorante::personaGiaPresente(Persona* p) {
		
		bool resp = false;
		
		for ( list<Persona*>::iterator it = this->persone__.begin(); it != this->persone__.end(); ++it )
		{
			Persona* tmp = *it;
			
			if ( *p == *tmp ) {
				resp = true;
				break;
			}
		}
		
		return resp;
	}
	
	void Ristorante::liberaListaRistorante(list<Persona*>* ListaDaRimuovere) {

		list<Persona*> tmp = *ListaDaRimuovere;

		// se il tavolo non era vuoto
		if ( !tmp.empty() )
			do {
				list<Persona*>::iterator it = tmp.begin();

				rimuoviPersonaDaListaRistorante(*it);

				tmp.erase(it);
			}
			while( !tmp.empty() );
	}

	void Ristorante::rimuoviPersonaDaListaRistorante(Persona* PersonadaRimuovere) {

		for ( list<Persona*>::iterator it = this->persone__.begin(); it != this->persone__.end(); ++it )
		{
			Persona* tmp = *it;

			if ( *PersonadaRimuovere == *tmp ) {

				// le persone vengono rimosse dalla lista del ristorante
				// non vengono cancellate qui dentro
				//delete PersonadaRimuovere;

				this->persone__.erase(it);
				break;
			}
		}
	}



}

#include "tavolo.h"

using namespace std;

namespace ristorazione {

    Tavolo::Tavolo(unsigned int posti) {
      
        this->posti__ = posti;
    }

    Tavolo::~Tavolo() {

        // gestione de-allocazione TBD
		// il tavolo dealloca solo la lista alle persone ci pensa il ristorante
		this->persone__.clear();
    }

    ESITO Tavolo::aggiungiPersona(Persona* p)  {
        
        ESITO resp = TAVOLO_PIENO_;
  
        unsigned int current = this->persone__.size();

        if ( current < this->posti__ )
        {
          this->persone__.push_back (p);
          resp = SUCCESSO_;
        }

        return resp;
    }

    list<Persona*>* Tavolo::liberaTavolo()  {
    
    	// questo metodo ritorna un'array di persone da togliere dalla lista del ristorante
    	list<Persona*>* resp = new list<Persona*>(this->persone__);

        this->persone__.clear();

        return resp;
    }


    ESITO Tavolo::modificaTavolo(unsigned int posti)  {
  
        ESITO resp = TAVOLO_OCCUPATO_;
  
        if ( this->persone__.empty() )
        {
            this->posti__ = posti;
            resp = SUCCESSO_;
        }
  
        return resp;
    }

}

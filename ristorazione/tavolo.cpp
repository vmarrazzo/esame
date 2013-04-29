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

    void Tavolo::liberaTavolo()  {
    
        this->persone__.clear();
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

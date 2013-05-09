/*
===================================================
tavolo.h
===================================================
*/

#ifndef TAVOLO_
#define TAVOLO_

#define TAV2INDEX(tavolo) (tavolo-1)
#define INDEX2TAV(index)  (index+1)

#include <list>
#include "persona.h"

using namespace std;

namespace ristorazione {

  typedef int ESITO;
  
  static const ESITO SUCCESSO_              =  0;
  static const ESITO TAVOLO_PIENO_          = -1;
  static const ESITO TAVOLO_OCCUPATO_       = -2;
  static const ESITO PERSONA_GIA_PRESENTE_  = -3;
  static const ESITO FALLIMENTO_		 	= -4;

  class Tavolo {

      private:
        unsigned int posti__;
        list<Persona*> persone__;

      public:
        Tavolo(unsigned int posti);
        ~Tavolo();
        ESITO aggiungiPersona(Persona* p);
        list<Persona*>* liberaTavolo();
        ESITO cambiaNumeroPosti(unsigned int posti);
		unsigned int numeroPosti();
  };

}

#endif

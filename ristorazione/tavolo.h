/*
===================================================
tavolo.h
===================================================
*/

#ifndef TAVOLO_
#define TAVOLO_

#include <list>
#include "persona.h"

using namespace std;

namespace ristorazione {

  typedef int ESITO;
  
  static const ESITO SUCCESSO_        =  0;
  static const ESITO TAVOLO_PIENO_    = -1;
  static const ESITO TAVOLO_OCCUPATO_ = -2;

  class Tavolo {

      private:
        int posti__;
        list<Persona*> persone__;

      public:
        Tavolo(int posti);
        ~Tavolo();
        ESITO aggiungiPersona(Persona* p);
        void liberaTavolo();
        ESITO modificaTavolo(int posti);
  };

}

#endif

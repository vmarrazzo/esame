/*
===================================================
ristorante.h
===================================================
*/

#ifndef RISTORANTE_
#define RISTORANTE_

#include <vector>
#include <list>
#include "persona.h"
#include "tavolo.h"

using namespace std;

namespace ristorazione {

  class Ristorante {

      private:
        vector<Tavolo*> tavoli__;
        list<Persona*> persone__;

      public:
        Ristorante(unsigned int numTavoli, Tavolo** tavoli);
        ~Ristorante();
        ESITO aggiungiPersona(Persona* p, unsigned int tavolo);
        void liberaTavolo(unsigned int tavolo);
        ESITO modificaTavolo(unsigned int tavolo, unsigned int posti);
  };

}

#endif

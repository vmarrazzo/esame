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
        Ristorante(int numTavoli, Tavolo* tavoli);
        ~Ristorante();
        ESITO aggiungiPersona(Persona* p, int tavolo);
        void liberaTavolo(int tavolo);
        ESITO modificaTavolo(int tavolo, int posti);
  };

}

#endif

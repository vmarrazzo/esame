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
		bool personaGiaPresente(Persona* p);

      public:
        Ristorante(unsigned int numTavoli, Tavolo** tavoli);
        ~Ristorante();
        ESITO aggiungiPersona(Persona* p, unsigned int numTavolo);
        void liberaTavolo(unsigned int numTavolo);
        ESITO modificaTavolo(unsigned int numTavolo, unsigned int posti);
  };

}

#endif

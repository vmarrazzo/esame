/*
===================================================
gruppo.h
===================================================
*/

#ifndef GRUPPO_
#define GRUPPO_

#include "persona.h"

using namespace ristorazione;

class Gruppo {

	public:
		virtual ~Gruppo() {};
		virtual int QuantePersone() {}; // restituisce il numero di persone del gruppo
		virtual Persona* QualePersona(int i) { };
		// restituisce il puntatore alla i-esima
		// persona, con 1 <= i <= QuantePersone()
		// non interessa il resto
};

#endif

/* 
===================================================
scacchiera.h
=================================================== 
*/

#ifndef SCACCHIERA_
#define SCACCHIERA_

#include <cstdlib>
#include "pezzo.h"

using namespace std;

namespace scacchi {

	typedef int DIREZIONE;

	static const DIREZIONE SU__ = 1;
	static const DIREZIONE DX__ = 2;	
	static const DIREZIONE GIU_	= 3;
	static const DIREZIONE SX__ = 4;

	typedef int ESITO;

	static const ESITO PARTENZA_VUOTA_ 		= 0;
	static const ESITO ARRIVO_OCCUPATA_ 	= -1;
	static const ESITO ARRIVO_INESISTENTE_ 	= -2;
	static const ESITO SUCCESSO_			= 1;
	
	class Scacchiera {

		private:
			// dim scacchiera
			int righe_;	
			int colonne_;
			
			// disposizione pezzi su tavola
			Pezzo*** tavola__; // puntatore a puntatore a puntatore a Pezzo

		public:
			Scacchiera( int righe, int colonne);
			~Scacchiera();	
			int getNumRighe();
			int getNumColonne();
			Pezzo* getElemento( int riga, int colonna);
			void piazzamento( int riga, int colonna, Pezzo* p);
			ESITO spostamento( int riga, int colonna, DIREZIONE d);
	};

}

#endif
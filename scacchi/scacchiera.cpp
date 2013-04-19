#include "scacchiera.h"

namespace scacchi {

	Scacchiera::Scacchiera( int righe, int colonne) {
		
		this->righe_ = righe;
		this->colonne_ = colonne;
		
		// inizializzo ad un array di puntatori di puntatori a Pezzo
		this->tavola__ = new Pezzo**[this->righe_];
		
		for ( int index_r = 0 ; index_r < this->righe_ ; index_r++ )
			// ognuno di questi elementi è un puntatore a Pezzo
			// viene inizializzato con un array di puntatori
			this->tavola__[index_r] = new Pezzo*[this->colonne_];
		
		for ( int index_r = 0 ; index_r < this->righe_ ; index_r++ )
			for ( int index_c = 0 ; index_c < this->colonne_ ; index_c++ )
				this->tavola__[index_r][index_c] = NULL;
	}

	Scacchiera::~Scacchiera() {
		
		for ( int index_r = 0 ; index_r < this->righe_ ; index_r++ )
			for ( int index_c = 0 ; index_c < this->colonne_ ; index_c++ )
				if ( this->tavola__[index_r][index_c] != NULL ) {
					delete this->tavola__[index_r][index_c];
					this->tavola__[index_r][index_c] = NULL;
				}
		
		delete this->tavola__;
	}
	
	int Scacchiera::getNumRighe() {
	
		return this->righe_;
	}
	
	int Scacchiera::getNumColonne() {
	
		return this->colonne_;
	}
	
	Pezzo* Scacchiera::getElemento( int riga, int colonna) {
	
		Pezzo* resp = NULL;
			
		if ( riga <= this->righe_ && colonna <= this->colonne_ )
			resp = this->tavola__[COOR2INDEX(riga)][COOR2INDEX(colonna)];
			
		return resp; 
	}
	
	void Scacchiera::piazzamento( int riga, int colonna, Pezzo* p) {
		
		if ( riga <= this->righe_ && colonna <= this->colonne_ ) {
		
			Pezzo* tmp = this->tavola__[COOR2INDEX(riga)][COOR2INDEX(colonna)];
			
			this->tavola__[COOR2INDEX(riga)][COOR2INDEX(colonna)] = p;
			
			// per casella solo un pezzo ed un pezzo può state
			// solo su una casella per volta
			// Se c'era un pezzo lo dealloco.
			if ( tmp != NULL )
				delete tmp;
		}
	}
	
	ESITO Scacchiera::spostamento( int riga, int colonna, DIREZIONE d) {
	
		ESITO resp = PARTENZA_VUOTA_;

		int delta_riga 		= 0;
		int delta_colonna 	= 0;
		
		delta_colonna += ( d == SX__ ? -1 : 0 );
		delta_colonna += ( d == DX__ ?  1 : 0 );
		
		delta_riga += ( d == GIU_ ?  1 : 0 );
		delta_riga += ( d == SU__ ? -1 : 0 );

		int riga_arrivo = riga + delta_riga;
		int colonna_arrivo = colonna + delta_colonna;

		// se non esiste un pezzo nella partenza
		if ( 	( riga > this->righe_ || colonna > this->colonne_ ) ||
				this->tavola__[COOR2INDEX(riga)][COOR2INDEX(colonna)] == NULL	
			)
			resp = PARTENZA_VUOTA_;
		else // c'è il pezzo di partenza
		{
			// se la casella di arrivo esiste
			if ( 	riga_arrivo > this->righe_ || 
					colonna_arrivo > this->colonne_ 
				)
				resp = ARRIVO_INESISTENTE_;
			else // c'è la casella di arrivo
			{
				Pezzo* tmp = this->tavola__[COOR2INDEX(riga_arrivo)][COOR2INDEX(colonna_arrivo)];
				
				if ( tmp != NULL )
					resp = ARRIVO_OCCUPATA_;
				else // arrivo libera
				{
					this->tavola__[COOR2INDEX(riga_arrivo)][COOR2INDEX(colonna_arrivo)] = this->tavola__[COOR2INDEX(riga)][COOR2INDEX(colonna)];
					
					this->tavola__[COOR2INDEX(riga)][COOR2INDEX(colonna)] = NULL;
					
					resp = SUCCESSO_;
				}
			}
		}
		
		return resp;
	}
}
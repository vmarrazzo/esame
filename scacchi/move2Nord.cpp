#include "scacchiera.h"

using namespace std;
using namespace scacchi;

/**
 * Sposta tutti i pezzi presenti nella scacchiera sul lato Nord
 */
void move2Nord(Scacchiera* input) {

	int max_righe = input->getNumRighe();
	int max_colonne = input->getNumColonne();
	
	for ( int index_c = max_colonne ; index_c > 0 ; index_c-- )
		for ( int index_r = 1 ; index_r <= max_righe ; index_r++ )
		{
			Pezzo* current = NULL;
			current = input->getElemento( index_r, index_c);
			
			if ( current != NULL )
			{
					int count = 0;
					ESITO tmp;

					do {
						tmp = input->spostamento( index_r - (count++), index_c, SU__);
					}
					while ( tmp == SUCCESSO_ );
			}
		}
}
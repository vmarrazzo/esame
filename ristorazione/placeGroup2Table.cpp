#include "ristorante.h"
#include "gruppo.h"
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;
using namespace ristorazione;

bool comparatoreInversoGruppi ( Gruppo* i,Gruppo* j) { 

	return ( i->QuantePersone() > j->QuantePersone() ); 
}

void placeGroup2Table( Ristorante* r, vector<Gruppo*> gruppi) {

	map<unsigned int,unsigned int> listaTavoli = r->elencoTavoliPosti();
	unsigned int numTavoli = listaTavoli.size();
	
	// ordino il vettore tavoli per il numero di posti partendo dal più alto
	for ( unsigned int index = 1; index <= numTavoli ; index++ )
	{
		cout << index << " -> " << listaTavoli[index] << endl;
	
	}
	
	// ordino il vettore gruppi per il numero di persone partendo dal più alto
	sort ( gruppi.begin(), gruppi.end(), comparatoreInversoGruppi);
	
	// ordinatamente per ogni gruppo metto persone nei tavoli
}
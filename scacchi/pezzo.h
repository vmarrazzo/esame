/* 
===================================================
Pezzo.h
=================================================== 
*/

#ifndef PEZZO_
#define PEZZO_

namespace scacchi {

	typedef char TIPO;

	static const TIPO NULL__ 		= ' ';
	static const TIPO PEDONE__ 		= 'P';
	static const TIPO TORRE__ 		= 'T';
	static const TIPO CAVALLO__ 	= 'C';
	static const TIPO ALFIERE__ 	= 'A';
	static const TIPO REGINA__ 		= 'R';
	static const TIPO RE__ 			= 'E';

	class Pezzo {

		private:
			TIPO type_;	

		public:
			Pezzo( TIPO type);
			~Pezzo();	
			bool operator==(Pezzo& rhs)const;
			TIPO getType();
	};

}

#endif
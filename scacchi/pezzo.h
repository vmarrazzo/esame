/* 
===================================================
Pezzo.h
=================================================== 
*/

#ifndef PEZZO_
#define PEZZO_

namespace scacchi {

	typedef int TIPO;

	static const TIPO NULL__ 		= -1;
	static const TIPO PEDONE__ 		= 0;
	static const TIPO TORRE__ 		= 1;
	static const TIPO CAVALLO__ 	= 2;
	static const TIPO ALFIERE__ 	= 3;
	static const TIPO REGINA__ 		= 4;
	static const TIPO RE__ 			= 5;

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
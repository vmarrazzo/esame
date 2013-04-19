#include "pezzo.h"

namespace scacchi {

	Pezzo::Pezzo( TIPO type) {
		
		this->type_ = type;
	}
	
	Pezzo::~Pezzo() {

	}

	bool Pezzo::operator==(Pezzo& rhs)const {

		return this == &rhs;
	}

	TIPO Pezzo::getType() {

		return this->type_;
	}

}
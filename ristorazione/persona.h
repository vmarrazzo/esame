/*
===================================================
persona.h
===================================================
*/

#ifndef PERSONA_
#define PERSONA_

namespace ristorazione {

  class Persona {

      public:
        Persona();
        ~Persona();
        bool operator==(Persona& rhs)const;
  };

}

#endif

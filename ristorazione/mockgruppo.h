#include "gmock/gmock.h"  // Brings in Google Mock.
#include "gruppo.h"

class MockGruppo : public Gruppo {
	public:
		MOCK_METHOD0(QuantePersone, int());
		MOCK_METHOD1(QualePersona, Persona*(int i));
};
#ifndef SHOES_H
#define SHOES_H

#include "item.h"

class Shoes : public Item {
private:
	string purpose;
public:
	// Constructors and destructor
	Shoes();
	Shoes(string barcode, string color, string material, string size, string purpose, string description);
	~Shoes();

	// Mutators
	void setPurpose(string purpose);

	// Accessors
	string getPurpose() const;
};

#endif

// ****************************************************************************
// Shoes()
// Purpose: default constructor sets data members to the default.
// ****************************************************************************

// ****************************************************************************
// Shoes(string barcode, string color, string material, string size, string fit, string purpose, string description)
// Purpose: constructor sets all data members to the parameters provided.
// ****************************************************************************

// ****************************************************************************
// ~Shoes()
// Purpose: default destructor
// ****************************************************************************

// ****************************************************************************
// void setPurpose(string purpose)
// Purpose: set the purpose based on parameter
// Pre: purpose - mutator variable
// ****************************************************************************

// ****************************************************************************
// string getPurpose() const
// Purpose: return the purpose data member
// post: return the purpose data member
// ****************************************************************************
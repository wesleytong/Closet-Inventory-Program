#ifndef PANTS_H
#define PANTS_H

#include "item.h"

class Pants : public Item {
private:
	string purpose;
	string fit;

public:
	// Constructors and destructors
	Pants();
	Pants(string barcode, string color, string material, string size, string purpose, string fit, string description);
	~Pants();

	// Mutators
	void setPurpose(string purpose);
	void setFit(string fit);

	// Accessors
	string getPurpose() const;
	string getFit() const;
};

#endif

// ****************************************************************************
// Pants()
// Purpose: default constructor sets data members to the default.
// ****************************************************************************

// ****************************************************************************
// Pants(string barcode, string color, string material, string size, string purpose, string fit, string description)
// Purpose: constructor sets all data members to the parameters provided.
// ****************************************************************************

// ****************************************************************************
// ~Pants()
// Purpose: default destructor
// ****************************************************************************

// ****************************************************************************
// void setPurpose(string purpose)
// Purpose: set the purpose based on parameter
// Pre: purpose - mutator variable
// ****************************************************************************

// ****************************************************************************
// void setFit(string fit)
// Purpose: set the fit based on parameter
// Pre: fit - mutator variable
// ****************************************************************************

// ****************************************************************************
// string getPurpose() const
// Purpose: return the purpose data member
// post: return the purpose data member
// ****************************************************************************

// ****************************************************************************
// string getFit() const
// Purpose: return the fit data member
// Post: return the fit data member
// ****************************************************************************
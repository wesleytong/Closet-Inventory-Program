#ifndef SHIRT_H
#define SHIRT_H

#include "item.h"

class Shirt : public Item {
private:
	string fit;
	string purpose;
public:
	// Constructors and destructors
	Shirt();
	Shirt(string barcode, string color, string material, string size, string fit, string purpose, string description);
	~Shirt();

	// Mutators
	void setFit(string fit);
	void setPurpose(string purpose);

	// Accessors
	string getFit() const;
	string getPurpose() const;

};

#endif

// ****************************************************************************
// Shirt()
// Purpose: default constructor assigns default values to material, fit, purpose and size.
// ****************************************************************************

// ****************************************************************************
// Shirt(string barcode, string color, string material, string size, string fit, string purpose, string description)
// Purpose: Constructor that takes in all parameters while utilizing the parent constructor
// ****************************************************************************

// ****************************************************************************
// ~Shirt()
// Purpose: default destructor to delete shirt object.
// ****************************************************************************

// ****************************************************************************
// void setFit(string fit)
// Purpose: set the fit based on parameter
// Pre: fit - mutator variable
// ****************************************************************************

// ****************************************************************************
// void setPurpose(string purpose)
// Purpose: set the purpose based on parameter
// Pre: purpose - mutator variable
// ****************************************************************************

// ****************************************************************************
// string getFit() const
// Purpose: return the fit data member
// post: return the fit data member
// ****************************************************************************

// ****************************************************************************
// string getPurpose() const
// Purpose: return the purpose data member
// post: return the purpose data member
// ****************************************************************************
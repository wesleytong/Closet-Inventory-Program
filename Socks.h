#ifndef SOCKS_H
#define SOCKS_H

#include "item.h"

class Socks : public Item {
private:
	string fit, material, color, size, description;
public:
	// Constructors and destructors
	Socks();
	Socks(string barcode, string color, string material, string size, string fit, string description);
	~Socks();

	// Mutators
	void setFit(string fit);


	// Accessors
	string getFit() const;
	

};

#endif

// ****************************************************************************
// Socks()
// Purpose: Constructor that sets materials, fit and size to default.
// ****************************************************************************

// ****************************************************************************
// Socks(string barcode, string color, string material, string size, string fit, string description)
// Purpose: Constructor that takes in all parameters while utilizing the parent constructor.
// Create an object using the parameters provided.
// ****************************************************************************

// ****************************************************************************
// ~Socks()
// Purpose: default destructor to delete sock object.
// ****************************************************************************

// ****************************************************************************
// void setFit(string fit)
// Purpose: change the fit based on the parameter provided.
// Pre: f - parameter to change the fit data member.
// ****************************************************************************

// ****************************************************************************
// string getFit() const
// Purpose: return the fit data member
// Post: return the fit data member
// ****************************************************************************
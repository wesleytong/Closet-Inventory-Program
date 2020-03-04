#include "shirt.h"

// ****************************************************************************
// Purpose: default constructor assigns default values to material, fit, purpose and size.
// ****************************************************************************
Shirt::Shirt() : Item()
{
	fit = "";
	purpose = "";
}

// ****************************************************************************
// Purpose: Constructor that takes in all parameters while utilizing the parent constructor
// ****************************************************************************
Shirt::Shirt(string barcode, string color, string material, string size, string fit, string purpose, string description)
	: Item("Shirt", barcode, color, description, material, size)
{
	this->fit = fit;
	this->purpose = purpose;
}

// ****************************************************************************
// Purpose: default destructor to delete shirt object.
// ****************************************************************************
Shirt::~Shirt()
{
	// default destructor
}

// ****************************************************************************
// Purpose: set the fit based on parameter
// Pre: fit - mutator variable
// ****************************************************************************
void Shirt::setFit(string fit)
{
	this->fit = fit;
}

// ****************************************************************************
// Purpose: set the purpose based on parameter
// Pre: purpose - mutator variable
// ****************************************************************************
void Shirt::setPurpose(string purpose)
{
	this->purpose = purpose;
}



// ****************************************************************************
// Purpose: return the fit data member
// post: return the fit data member
// ****************************************************************************
string Shirt::getFit() const
{
	return fit;
}

// ****************************************************************************
// Purpose: return the purpose data member
// post: return the purpose data member
// ****************************************************************************
string Shirt::getPurpose() const
{
	return purpose;
}
#include "shirt.h"

// ****************************************************************************
// Purpose: default constructor assigns default values to material, fit, purpose and size.
// ****************************************************************************
Shirt::Shirt() : Item()
{
     material = "";
     fit = "";
     purpose = "";
     size = "";
}

// ****************************************************************************
// Purpose: Constructor that takes in all parameters while utilizing the parent constructor
// ****************************************************************************
Shirt::Shirt(string barcode, string color, string material, string fit, string purpose, string size)
     : Item("Shirt", barcode, color)
{
     this -> material = material;
     this -> fit = fit;
     this -> purpose = purpose;
     this -> size = size;
}

// ****************************************************************************
// Purpose: default destructor to delete shirt object.
// ****************************************************************************
Shirt::~Shirt()
{
     // default destructor
}

// ****************************************************************************
// Purpose: set the material based on parameter
// Pre: material - mutator variable
// ****************************************************************************
void Shirt::setMaterial(string material)
{
     this -> material = material;
}

// ****************************************************************************
// Purpose: set the fit based on parameter
// Pre: fit - mutator variable
// ****************************************************************************
void Shirt::setFit(string fit)
{
     this -> fit = fit;
}

// ****************************************************************************
// Purpose: set the purpose based on parameter
// Pre: purpose - mutator variable
// ****************************************************************************
void Shirt::setPurpose(string purpose)
{
     this -> purpose = purpose;
}

// ****************************************************************************
// Purpose: set the size based on parameter
// Pre: size - mutator variable
// ****************************************************************************
void Shirt::setSize(string size)
{
     this -> size = size;
}

// ****************************************************************************
// Purpose: return the material data member
// post: return the material data member
// ****************************************************************************
string Shirt::getMaterial() const
{
     return material;
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

// ****************************************************************************
// Purpose: return the size data member
// post: return the size data member
// ****************************************************************************
string Shirt::getSize() const
{
     return size;
}

#include "shoes.h"

// ****************************************************************************
// Purpose: default constructor sets data members to the default.
// ****************************************************************************
Shoes::Shoes()
{
     purpose = "";
     size = 0.0;
}


// ****************************************************************************
// Purpose: constructor sets all data members to the parameters provided.
// ****************************************************************************
Shoes::Shoes(string barcode, string color, string purpose, double size) : Item("Shoes", barcode, color)
{
     this -> purpose = purpose;
     this -> size = size;
}

// ****************************************************************************
// Purpose: default destructor
// ****************************************************************************
Shoes::~Shoes()
{
     // Default destructor
}

// ****************************************************************************
// Purpose: set the purpose based on parameter
// Pre: purpose - mutator variable
// ****************************************************************************
void Shoes::setPurpose(string purpose)
{
     this -> purpose = purpose;
}

// ****************************************************************************
// Purpose: set the size based on parameter
// Pre: size - mutator variable
// ****************************************************************************
void Shoes::setSize(double size)
{
     this -> size = size;
}

// ****************************************************************************
// Purpose: return the purpose data member
// post: return the purpose data member
// ****************************************************************************
string Shoes::getPurpose() const
{
     return purpose;
}

// ****************************************************************************
// Purpose: return the size data member
// post: return the size data member
// ****************************************************************************
double Shoes::getSize() const
{
     return size;
}

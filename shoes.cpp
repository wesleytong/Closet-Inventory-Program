#include "shoes.h"

// ****************************************************************************
// Purpose: default constructor sets data members to the default.
// ****************************************************************************
Shoes::Shoes()
{
     purpose = "";
}


// ****************************************************************************
// Purpose: constructor sets all data members to the parameters provided.
// ****************************************************************************
Shoes::Shoes(string barcode, string color, string material, string size, string purpose, string description)
     : Item("Shoes", barcode, color, description, material, size)
{
     this -> purpose = purpose;
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
// Purpose: return the purpose data member
// post: return the purpose data member
// ****************************************************************************
string Shoes::getPurpose() const
{
     return purpose;
}

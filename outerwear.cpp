#include "outerwear.h"

// ****************************************************************************
// Purpose: default constructor sets data members to the default.
// ****************************************************************************
Outerwear::Outerwear() : Item()
{
}

// ****************************************************************************
// Purpose: constructor sets all data members to the parameters provided.
// ****************************************************************************
Outerwear::Outerwear(string barcode, string color, string material, string size, string description)
     : Item("Outerwear", barcode, color, description, material, size)
{
}

// ****************************************************************************
// Purpose: default destructor
// ****************************************************************************
Outerwear::~Outerwear()
{
     // default destructor
}

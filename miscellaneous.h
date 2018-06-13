#ifndef MISCELLANEOUS_H
#define MISCELLANEOUS_H

#include "item.h"

class Miscellaneous : public Item {
private:
public:
     Miscellaneous();
     Miscellaneous(string style, string barcode, string color, string material, string description, string size);
     ~Miscellaneous();
};



#endif

// ****************************************************************************
// Miscellaneous()
// Purpose: Constructor that sets materials, fit and size to default.
// ****************************************************************************

// ****************************************************************************
// Miscellaneous(string style, string barcode, string color, string material, string description, string size)
// Purpose: Constructor that takes in all parameters while utilizing the parent constructor.
// Create an object using the parameters provided.
// ****************************************************************************

// ****************************************************************************
// ~Miscellaneous()
// Purpose: default destructor to delete Miscellaneous object.
// ****************************************************************************

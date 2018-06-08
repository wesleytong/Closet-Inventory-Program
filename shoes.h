#ifndef SHOES_H
#define SHOES_H

#include "item.h"

class Shoes : public Item {
public:
     string purpose;
     double size;
private:
     // Constructors and destructor
     Shoes();
     Shoes(string barcode, string color, string purpose, double size);
     ~Shoes();

     // Mutators
     void setPurpose(string purpose);
     void setSize(double size);

     // Accessors
     string getPurpose() const;
     double getSize() const;
};

#endif

// ****************************************************************************
// Shoes()
// Purpose: default constructor sets data members to the default.
// ****************************************************************************

// ****************************************************************************
// Shoes(string barcode, string color, string purpose, double size)
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
// void setSize(double size)
// Purpose: set the size based on parameter
// Pre: size - mutator variable
// ****************************************************************************

// ****************************************************************************
// string getPurpose() const
// Purpose: return the purpose data member
// post: return the purpose data member
// ****************************************************************************

// ****************************************************************************
// double getSize() const
// Purpose: return the size data member
// post: return the size data member
// ****************************************************************************

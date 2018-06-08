#ifndef SHIRT_H
#define SHIRT_H

#include "item.h"

class Shirt : public Item {
private:
     string material;
     string fit;
     string purpose;
     string size;
public:
     // Constructors and destructors
     Shirt();
     Shirt(string barcode, string color, string material, string fit, string purpose, string size);
     ~Shirt();

     // Mutators
     void setMaterial(string material);
     void setFit(string fit);
     void setPurpose(string purpose);
     void setSize(string size);

     // Accessors
     string getMaterial() const;
     string getFit() const;
     string getPurpose() const;
     string getSize() const;

};

#endif

// ****************************************************************************
// Shirt()
// Purpose: default constructor assigns default values to material, fit, purpose and size.
// ****************************************************************************

// ****************************************************************************
// Shirt(string barcode, string color, string material, string fit, string purpose. string size)
// Purpose: Constructor that takes in all parameters while utilizing the parent constructor
// ****************************************************************************

// ****************************************************************************
// ~Shirt()
// Purpose: default destructor to delete shirt object.
// ****************************************************************************

// ****************************************************************************
// void setMaterial(string material)
// Purpose: set the material based on parameter
// Pre: material - mutator variable
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
// void setSize(string size)
// Purpose: set the size based on parameter
// Pre: size - mutator variable
// ****************************************************************************

// ****************************************************************************
// string getMaterial() const
// Purpose: return the material data member
// post: return the material data member
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

// ****************************************************************************
// string getSize() const;
// Purpose: return the size data member
// post: return the size data member
// ****************************************************************************

#ifndef OUTERWEAR_H
#define OUTERWEAR_H

class Outerwear : public Item {
private:
     string purpose;
     string size;
public:
     // Constructors and destructors
     Outerwear();
     Outerwear(string barcode, string color, string purpose, string size);
     ~Outerwear();

     // Mutators
     void setPurpose(string purpose);
     void setSize(string size);

     // Accessors
     string getPurpose() const;
     string getSize() const;
};

#endif

// ****************************************************************************
// Outerwear()
// Purpose: default constructor sets data members to the default.
// ****************************************************************************

// ****************************************************************************
// Outerwear(string barcode, string color, string purpose, string size)
// Purpose: constructor sets all data members to the parameters provided.
// ****************************************************************************

// ****************************************************************************
// ~Outerwear()
// Purpose: default destructor
// ****************************************************************************

// ****************************************************************************
// void setPurpose(string purpose)
// Purpose: set the purpose based on parameter
// Pre: purpose - mutator variable
// ****************************************************************************

// ****************************************************************************
// void setSize(string size)
// Purpose: change the size based on the parameter provided.
// Pre: size - parameter to change the size data member.
// ****************************************************************************

// ****************************************************************************
// string getPurpose() const
// Purpose: return the purpose data member
// post: return the purpose data member
// ****************************************************************************

// ****************************************************************************
// string getSize() const
// Purpose: return the size data member
// Post: return the size data member
// ****************************************************************************

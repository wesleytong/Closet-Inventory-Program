#ifndef SOCKS_H
#define SOCKS_H

#include <string>
#include "item.h"


using namespace std;

class Socks : public Item {
private:
     string material;
     string fit;
     string size; //string instead of char because need to account for XS, XL, etc.
public:
     // Constructors and destructors
     Socks();
     Socks(string, string, string, string, string, string);
     ~Socks();

     // Mutators
     void setMaterial(string);
     void setFit(string);
     void setSize(string);

     // Accessors
     string getMaterial() const;
     string getFit() const;
     string getSize() const;

};

#endif

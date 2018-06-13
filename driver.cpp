#include <iostream>

#include "socks.h"
#include "shirt.h"
#include "shoes.h"
#include "pants.h"
#include "outerwear.h"
#include "miscellaneous.h"

using namespace std;

int main() {
     Miscellaneous s1("ring", "1111", "blue", "suede", "this is a test", "");

     cout << "This is the starting point for our project!!" << endl;
     cout << "Check to see if I need pull requests." << endl;

     cout << "Style: " << s1.getStyle() << endl;
     cout << "Barcode: " << s1.getBarcode() << endl;
     // cout << "Size: " << s1.getSize() << endl;
     cout << "Description: " << s1.getDescription() << endl;
     // cout <<  "Fit: " << s1.getFit() << endl;
     // cout << "Purpose: " << s1.getPurpose() << endl;


     return 0;
}

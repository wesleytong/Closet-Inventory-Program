#include "Item.h"

// ****************************************************************************
// Purpose: generate barcode based on specified rules (1st digit is style,
// 2nd digit is color, randomize the last two.
// Post: string that is the generated barcode.
// ****************************************************************************
string Item::generateBarcode() {
	// create a temp string to assign the first two numbers according to
	// specifications.
	// then randomize the next two numbers.
	string temp = "";

	// set the first digit according to style.
	if (style == "Socks")
	{
		temp += "1";
	}
	else if (style == "Shirt")
	{
		temp += "2";
	}
	else if (style == "Shoes")
	{
		temp += "3";
	}
	else if (style == "Pants")
	{
		temp += "4";
	}
	else if (style == "Outerwear")
	{
		temp += "5";
	}
	else if (style == "Miscellaneous")
	{
		temp += "6";
	}
	else
	{
		cout << "Not sure how you got here"
			<< "Proper precautions should have taken place to avoid this.."
			<< endl;
		return "0";
	}

	// set the second digit according to color.
	if (color == "Black")
	{
		temp += "0";
	}
	else if (color == "Brown")
	{
		temp += "1";
	}
	else if (color == "Red")
	{
		temp += "2";
	}
	else if (color == "Orange")
	{
		temp += "3";
	}
	else if (color == "Yellow")
	{
		temp += "4";
	}
	else if (color == "Green")
	{
		temp += "5";
	}
	else if (color == "Blue")
	{
		temp += "6";
	}
	else if (color == "Violet")
	{
		temp += "7";
	}
	else if (color == "Grey")
	{
		temp += "8";
	}
	else if (color == "White")
	{
		temp += "9";
	}
	else
	{
		cout << "Not sure how you got here"
			<< "Proper precautions should have taken place to avoid this.."
			<< endl;
		return "0";
	}

	// randomize the last two digits. (Convert to string to concat)
	srand(time(NULL));
	// first digit to randomize
	int randomInt = rand() % 10;
	temp += to_string(randomInt);

	srand(time(NULL));
	// second digit to randomize
	randomInt = rand() % 10;
	temp += to_string(randomInt);

	// Convert full barcode from string to int before returning.
	return temp;
}

// ****************************************************************************
// Purpose: Default constructor that defaults data members.

// ****************************************************************************
Item::Item()
{
	style = "";
	barcode = "";
	color = "";
	description = "";
	material = "";
	size = "";
}

// ****************************************************************************
// Purpose: Constructor that creates an item based on the parameters passed.
// Pre: style - set the style to the parameter passed.
//      barcode - set the barcode to the parameter passsed.
//      color - set the color to the parameter passed.
//      description - set the description to the parameter passed.
//      material - set the material to the parameter passed.
//      size - set the size to the parameter passed.
// Post: tree has been processed
// ****************************************************************************
Item::Item(string style, string barcode, string color, string description, string material, string size)
{
	this->style = style;
	if (barcode == "")
	{
		this->barcode = generateBarcode();
	}
	else
	{
		this->barcode = barcode;
	}
	this->color = color;
	this->description = description;
	this->material = material;
	this->size = size;
}

// ****************************************************************************
// Purpose: Default destructor.
// ****************************************************************************
Item::~Item()
{
	// This is the default destructor.
}

// ****************************************************************************
// Purpose: set the color data member to the parameter passed.
// Pre: color - set the color to the parameter passed.
// ****************************************************************************
void Item::setColor(string color)
{
	this->color = color;
}

// ****************************************************************************
// Purpose: set the material data member to the parameter passed.
// Pre: material - set the color to the parameter passed.
// ****************************************************************************
void Item::setMaterial(string material)
{
	this->material = material;
}

// ****************************************************************************
// Purpose: set the description data member to the parameter passed.
// Pre: description - set the description to the parameter passed.
// ****************************************************************************
void Item::setDescription(string description)
{
	this->description = description;
}

// ****************************************************************************
// Purpose: set the size data member to the parameter passed.
// Pre: size - set the size to the parameter passed.
// ****************************************************************************
void Item::setSize(string size)
{
	this->size = size;
}

// ****************************************************************************
// Purpose: return the material data member.
// Post: return the material data member.
// ****************************************************************************
string Item::getMaterial() const
{
	return material;
}

// ****************************************************************************
// Purpose: return the descrption data member.
// Post: return the description data member.
// ****************************************************************************
string Item::getDescription() const
{
	return description;
}

// ****************************************************************************
// Purpose: return the size data member.
// Post: return the size data member.
// ****************************************************************************
string Item::getSize() const
{
	return size;
}

// ****************************************************************************
// Purpose: return the style data member.
// Post: return the style data member.
// ****************************************************************************
string Item::getStyle() const
{
	return style;
}

// ****************************************************************************
// Purpose: return the barcode data member.
// Post: return the barcode data member.
// ****************************************************************************
string Item::getBarcode() const
{
	return barcode;
}

// ****************************************************************************
// Purpose: return the color data member.
// Post: return the color data member.
// ****************************************************************************
string Item::getColor() const
{
	return color;
}

void Item::setBarcode(string barcode) {
	this->barcode = barcode;
}

// ****************************************************************************
// Purpose: Overloaded == operator. Checks to see if two Item objects are the
// same by comparing object's data memebers for equality.
// Pre: obj - the object which will be used to compare data members.
// Post: returns true if two item are equal, returns false if not.
// ****************************************************************************
bool Item::operator==(const Item &obj) const
{
	if ((barcode == obj.barcode) && (description == obj.description))
	{
		return true;
	}
	else
	{
		return false;
	}
}

// ****************************************************************************
// Purpose: Overloaded = operator. Sets the item object equal to the parameter
// passed.
// Pre: obj - the object which will be used to set original objects data members.
// ****************************************************************************
void Item::operator=(const Item &right)
{
	barcode = right.barcode;
	color = right.color;
	description = right.description;
	material = right.material;
	size = right.size;
}

// ****************************************************************************
// Purpose: Overloaded > operator. Compares 2 Item objects.
// Pre: right - a item object that has its name used in comparison to left 
//              operand's same member.
// Post: Return true if left operand larger, and false otherwise.
// ****************************************************************************
bool Item::operator> (const Item &right)
{
	bool status;

	if (barcode.compare(right.barcode) > 0)
	{
		status = true;
	}
	else if (barcode.compare(right.barcode) == 0
		&& description.compare(right.description) > 0)
	{
		status = true;
	}
	else
	{
		status = false;
	}

	return status;
}

// ****************************************************************************
// Purpose: Overloaded > operator. Compares 2 Item objects.
// Pre: right - a item object that has its name used in comparison to left 
//              operand's same member.
// Post: Return true if left operand smaller, and false otherwise.
// ****************************************************************************
bool Item::operator< (const Item &right)
{
	bool status;

	if (barcode.compare(right.barcode) < 0)
	{
		status = true;
	}
	else if (barcode.compare(right.barcode) == 0
		&& description.compare(right.description) < 0)
	{
		status = true;
	}
	else
	{
		status = false;
	}

	return status;
}

// ****************************************************************************
// Overloaded << operator. Outputs member values of Item obj
// Pre: obj - a Item object that has its member values printed
// ****************************************************************************
ostream& operator<<(ostream &strm, const Item &obj)
{
	strm << "\nBarcode:" << obj.barcode << endl;
	strm << "Style: " << obj.style << endl;
	strm << "Description: " << obj.description << endl;
	return strm;
}

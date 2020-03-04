/*
TO DO:
- make the add functions read description without skipping over it (getline)
- print data to outfile from the menu options
- Integrate Hash Table
- make sure user can't input character
- Triple check the data input file
- Clean up, add comments
- Get rid of all of the data printing in the beginning 
*/

#include <string>
#include <iostream>
#include <fstream>
#include "Item.h"
#include "Miscellaneous.h"
#include "Outerwear.h"
#include "Pants.h"
#include "Shirt.h"
#include "Shoes.h"
#include "Socks.h"
#include "BST.h"
#include "BSTNode.h"
#include "hashTable.h"
#include <iomanip>

using namespace std;

int getNumOfEntries(string validation);
string validatePathname();


int main()
{
	int answer;
	int choice;
	string inVal;
	int choiceDouble;

	ifstream input;
	ofstream output;
	input.open("inFile.txt");

	BST<Item> *bst = new BST<Item>();
	BST<Item> *avlBST = new BST<Item>();

	string filePath = validatePathname();
	int size = getNumOfEntries(filePath);
	HashTable<List<Item*>, string> dataHash(size, filePath);

	string userInput;

	string barcode;

	if (!input) {
		cerr << "Unable to open inFile.txt";
		exit(1);
	}

	input.ignore();


	//BST<string> *barcodes = new BST<string>();

	do {

		//Socks
		getline(input, barcode, ',');
		if (barcode[0] == '1' && barcode.length() == 4) {
			string color, material, fit, size, style, description;
			//cout << "******************************" << endl;
			getline(input, style, ',');
			getline(input, color, ',');
			getline(input, material, ',');
			getline(input, size, ',');
			getline(input, fit, ',');
			getline(input, description, ',');
			//cout << color << material << fit << size << endl;
			//cout << "BARCODE:" << barcode << endl;
			//cout << "******************************" << endl;

			Socks sock(barcode, color, material, size, fit, description);

			bst->insert(sock);
			avlBST->avlinsert(sock);

			Socks* sock2 = new Socks(barcode, color, material, size, fit, description);
			dataHash.insert(sock2, sock2->getBarcode());
		}

		//Shirts
		else if (barcode[0] == '2' && barcode.length() == 4) {
			string color, material, style, fit, size, purpose, description;
			//cout << "******************************" << endl;
			getline(input, style, ',');
			getline(input, color, ',');
			getline(input, material, ',');
			getline(input, size, ',');
			getline(input, fit, ',');
			getline(input, purpose, ',');
			getline(input, description, ',');
			//cout << color << material << fit << size << purpose << endl;
			//cout << "BARCODE:" << barcode << endl;
			//cout << "******************************" << endl;

			Shirt shirt(barcode, color, material, size, fit, purpose, description);
			bst->insert(shirt);
			avlBST->avlinsert(shirt);

			Shirt* shirt2 = new Shirt(barcode, color, material, size, fit, purpose, description);
			dataHash.insert(shirt2, shirt2->getBarcode());
		}

		//Shoes
		else if (barcode[0] == '3' && barcode.length() == 4) {
			string style, color, material, size, purpose, description;
			//cout << "******************************" << endl;
			getline(input, style, ',');
			getline(input, color, ',');
			getline(input, material, ',');
			getline(input, size, ',');
			getline(input, purpose, ',');
			getline(input, description, ',');
			//cout << color << size << purpose << endl;
			//cout << "BARCODE:" << barcode << endl;
			//cout << "******************************" << endl;

			Shoes shoe(barcode, color, material, size, purpose, description);
			bst->insert(shoe);
			avlBST->avlinsert(shoe);
			Shoes* shoe2 = new Shoes(barcode, color, material, size, purpose, description);
			dataHash.insert(shoe2, shoe2->getBarcode());
		}

		//Pants
		else if (barcode[0] == '4' && barcode.length() == 4) {
			string color, purpose, size, fit, style, material, description;
			//cout << "******************************" << endl;
			getline(input, style, ',');
			getline(input, color, ',');
			getline(input, material, ',');
			getline(input, size, ',');
			getline(input, fit, ',');
			getline(input, purpose, ',');
			getline(input, description, ',');
			//cout << color << fit << size << purpose << endl;
			//cout << "BARCODE:" << barcode << endl;
			//cout << "******************************" << endl;
			Pants pants(barcode, color, material, size, purpose, fit, description);
			bst->insert(pants);
			avlBST->avlinsert(pants);
			Pants* pants2 = new Pants(barcode, color, material, size, purpose, fit, description);
			dataHash.insert(pants2, pants2->getBarcode());
		}

		//Outerwear
		else if (barcode[0] == '5' && barcode.length() == 4) {
			//cout << "******************************" << endl;
			string color, purpose, size, material, style, description;
			getline(input, style, ',');
			getline(input, color, ',');
			getline(input, material, ',');
			getline(input, size, ',');
			getline(input, description, ',');
			//cout << color << size << purpose << endl;
			//cout << "BARCODE:" << barcode << endl;
			//cout << "******************************" << endl;
			Outerwear outerwear(barcode, color, material, size, description);
			bst->insert(outerwear);
			avlBST->avlinsert(outerwear);
			Outerwear* outerwear2 = new Outerwear(barcode, color, material, size, description);
			dataHash.insert(outerwear2, outerwear2->getBarcode());
		}

		//Miscellaneous
		else if (barcode[0] == '6' && barcode.length() == 4) {
			//cout << "******************************" << endl;
			string style, color, material, description, size;
			getline(input, style, ',');
			getline(input, material, ',');
			getline(input, description, ',');
			getline(input, size, ',');
			//cout << color << style << endl;
			//cout << "BARCODE:" << barcode << endl;
			//cout << "******************************" << endl;
			Miscellaneous misc(style, barcode, color, material, description, size);
			bst->insert(misc);
			avlBST->avlinsert(misc);
			Miscellaneous* misc2 = new Miscellaneous(style, barcode, color, material, description, size);
			dataHash.insert(misc2, misc2->getBarcode());
		}
		bst->printBSTOperationInfo();
		avlBST->printAVLOperationInfo();
	} while (!input.eof());
	input.close();


	int answer1;
	int answer2;
	int answer3;
	int intAns;
	string firstName;
	string lastName;
	string changeName;
	string changeBirthday;

	do
	{
		cout << "\nWelcome to your closet" << endl;
		cout << "What would you like to do?" << endl;
		cout << "1: Add Data" << endl;
		cout << "2: Delete Data" << endl;
		cout << "3: Find data record with barcode" << endl;
		cout << "4: List data in hash table sequence" << endl;
		cout << "5: List data in key sequence(sorted)" << endl;
		cout << "6: Print indented tree" << endl;
		cout << "7: Efficiency" << endl;
		cout << "8: AVL" << endl;
		cout << "9: Exit" << endl;
		cout << "" << endl;
		cin >> answer;
		string tBar, tColor, tMaterial, tFit, tSize, tPurpose, tDescription;
		if (answer == 1) {
			cout << "Enter the number of the data type that you would like to add" << endl;
			cout << "1. Socks" << endl;
			cout << "2. Shirts" << endl;
			cout << "3. Shoes" << endl;
			cout << "4. Pants" << endl;
			cout << "5. Outerwear" << endl;
			cout << "6. Miscellanous" << endl;
			cin >> intAns;
			if (intAns == 1) {
				cout << "Enter barcode" << endl;
				cin >> tBar;
				cout << "Enter color" << endl;
				cin >> tColor;
				cout << "Enter material" << endl;
				cin >> tMaterial;
				cout << "Enter fit" << endl;
				cin >> tFit;
				cout << "Enter size" << endl;
				cin >> tSize;
				cout << "Enter description" << endl;
				//input.ignore();
				cin.ignore();
				getline(cin, tDescription);
				Socks tempSock(tBar, tColor, tMaterial, tSize, tFit, tDescription);
				bst->insert(tempSock);
				avlBST->insert(tempSock);
				Socks* sock = new Socks(tBar, tColor, tMaterial, tSize, tFit, tDescription);
				dataHash.insert(sock, sock->getBarcode());
			}
			if (intAns == 2) {
				//Random generator
				cout << "Enter barcode" << endl;
				cin >> tBar;
				cout << "Enter color" << endl;
				cin >> tColor;
				cout << "Enter material" << endl;
				cin >> tMaterial;
				cout << "Enter fit" << endl;
				cin >> tFit;
				cout << "Enter size" << endl;
				cin >> tSize;
				cout << "Enter purpose" << endl;
				cin >> tPurpose;
				cout << "Enter description" << endl;
				cin.ignore();
				getline(cin, tDescription);
				Shirt tempShirt(tBar, tColor, tMaterial, tSize, tFit, tPurpose, tDescription);
				bst->insert(tempShirt);
				avlBST->insert(tempShirt);
				Shirt* shirt = new Shirt(tBar, tColor, tMaterial, tSize, tFit, tPurpose, tDescription);
				dataHash.insert(shirt, shirt->getBarcode());
			}
			if (intAns == 3) {
				cout << "Enter barcode" << endl;
				cin >> tBar;
				cout << "Enter color" << endl;
				cin >> tColor;
				cout << "Enter material" << endl;
				cin >> tMaterial;
				cout << "Enter size" << endl;
				cin >> tSize;
				cout << "Enter purpose" << endl;
				cin >> tPurpose;
				cout << "Enter description" << endl;
				cin.ignore();
				getline(cin, tDescription);
				Shoes tempShoe(tBar, tColor, tMaterial, tSize, tPurpose, tDescription);
				bst->insert(tempShoe);
				avlBST->insert(tempShoe);
				Shoes* shoe = new Shoes(tBar, tColor, tMaterial, tSize, tPurpose, tDescription);
				dataHash.insert(shoe, shoe->getBarcode());
			}
			if (intAns == 4) {
				cout << "Enter barcode" << endl;
				cin >> tBar;
				cout << "Enter color" << endl;
				cin >> tColor;
				cout << "Enter material" << endl;
				cin >> tMaterial;
				cout << "Enter fit" << endl;
				cin >> tFit;
				cout << "Enter size" << endl;
				cin >> tSize;
				cout << "Enter purpose" << endl;
				cin >> tPurpose;
				cout << "Enter description" << endl;
				cin.ignore();
				getline(cin, tDescription);
				Pants tempPants(tBar, tColor, tMaterial, tSize, tPurpose, tFit, tDescription);
				bst->insert(tempPants);
				avlBST->insert(tempPants);
				Pants* pants = new Pants(tBar, tColor, tMaterial, tSize, tPurpose, tFit, tDescription);
				dataHash.insert(pants, pants->getBarcode());
			}
			if (intAns == 5) {
				cout << "Enter barcode" << endl;
				cin >> tBar;
				cout << "Enter color" << endl;
				cin >> tColor;
				cout << "Enter size" << endl;
				cin >> tSize;
				cout << "Enter material" << endl;
				cin >> tMaterial;
				cout << "Enter description" << endl;
				cin.ignore();
				getline(cin, tDescription);
				Outerwear tempOut(tBar, tColor, tMaterial, tSize, tDescription);
				bst->insert(tempOut);
				avlBST->insert(tempOut);
				Outerwear* outerwear = new Outerwear(tBar, tColor, tMaterial, tSize, tDescription);
				dataHash.insert(outerwear, outerwear->getBarcode());
			}
			if (intAns == 6) {
				string style;
				cout << "Enter style" << endl;
				cin >> style;
				cout << "Enter barcode" << endl;
				cin >> tBar;
				cout << "Enter color" << endl;
				cin >> tColor;
				cout << "Enter size" << endl;
				cin >> tSize;
				cout << "Enter material" << endl;
				cin >> tMaterial;
				cout << "Enter description" << endl;
				cin.ignore();
				getline(cin, tDescription);
				Miscellaneous misc(style, tBar, tColor, tMaterial, tDescription, tSize);
				bst->insert(misc);
				avlBST->insert(misc);
				Miscellaneous* misc2 = new Miscellaneous(style, tBar, tColor, tMaterial, tDescription, tSize);
				dataHash.insert(misc2, misc2->getBarcode());
			}
			bst->printBSTOperationInfo();
			avlBST->printAVLOperationInfo();
		}
		else if (answer == 2) {
			string barAns;
			cout << "Enter the barcode of the item you would like to delete" << endl;
			cin >> barAns;
			if (bst->search(barAns) == 1) {
				bst->remove(barAns);
				avlBST->remove(barAns);
				dataHash.remove(barAns);
			}
			else {
				cout << "Item with barcode: " << barAns << " does not exist" << endl;
			}
		}
		else if (answer == 3) {
			string barAns;
			//string barcodeAns;
			cout << "Enter the barcode of the item you would like to find" << endl;
			cin >> barAns;
			//barAns.setBarcode(barcodeAns);
			//cout << "I got here" << endl;
			if (bst->search(barAns) == 1) {
				cout << "Exists" << endl;
				BSTNode<Item>* item;
				item = bst->getNode(barAns);
				if (barAns[0] == '1') {
					//BSTNode<Socks>* item;
					//item = bst->getNode(barAns);
					cout << "\nBarcode:" << item->getData().getBarcode() << endl;
					cout << "Style: Socks" << endl;
					cout << "Color: " << item->getData().getColor() << endl;
					cout << "Material: " << item->getData().getMaterial() << endl;
					cout << "Size: " << item->getData().getSize() << endl;
					cout << "Description: " << item->getData().getDescription() << endl;
				}
				if (barAns[0] == '2') {
					cout << "\nBarcode:" << item->getData().getBarcode() << endl;
					cout << "Style: Shirt" << endl;
					cout << "Color: " << item->getData().getColor() << endl;
					cout << "Material: " << item->getData().getMaterial() << endl;
					cout << "Size: " << item->getData().getSize() << endl;
					//cout << "Fit: " << item->getData().getFit() << endl;
					//cout << "Purpose: " << item->getData().getPurpose() << endl;
					cout << "Description: " << item->getData().getDescription() << endl;
					//Shirt shirt(barcode, color, material, size, fit, purpose, description);
				}
				if (barAns[0] == '3') {
					cout << "\nBarcode:" << item->getData().getBarcode() << endl;
					cout << "Style: Shoes" << endl;
					cout << "Color: " << item->getData().getColor() << endl;
					cout << "Material: " << item->getData().getMaterial() << endl;
					cout << "Size: " << item->getData().getSize() << endl;
					cout << "Description: " << item->getData().getDescription() << endl;
				}
				if (barAns[0] == '4') {
					cout << "\nBarcode:" << item->getData().getBarcode() << endl;
					cout << "Style: Pants" << endl;
					cout << "Color: " << item->getData().getColor() << endl;
					cout << "Material: " << item->getData().getMaterial() << endl;
					cout << "Size: " << item->getData().getSize() << endl;
					cout << "Description: " << item->getData().getDescription() << endl;
				}
				if (barAns[0] == '5') {
					cout << "\nBarcode:" << item->getData().getBarcode() << endl;
					cout << "Style: Outerwear" << endl;
					cout << "Color: " << item->getData().getColor() << endl;
					cout << "Material: " << item->getData().getMaterial() << endl;
					cout << "Size: " << item->getData().getSize() << endl;
					cout << "Description: " << item->getData().getDescription() << endl;
				}
				if (barAns[0] == '6') {
					cout << "\nBarcode:" << item->getData().getBarcode() << endl;
					cout << "Style: Miscellaneous" << endl;
					cout << "Color: " << item->getData().getColor() << endl;
					cout << "Material: " << item->getData().getMaterial() << endl;
					cout << "Size: " << item->getData().getSize() << endl;
					cout << "Description: " << item->getData().getDescription() << endl;
				}
			}
			
			//barcodes->search(barAns);

		}
		else if (answer == 4) {
			dataHash.displayTable();
		}
		else if (answer == 5) {
			cout << "Printing inorder" << endl;
			bst->inorder();
		}
		else if (answer == 6) {
			int option;
			cout << "Printing indented tree" << endl;
			cout << "Which tree would you like to print indented?" << endl;
			cout << "For AVL tree, enter 1. For BST tree, enter 2." << endl;
			cin >> option;
			if (option == 1) {
				avlBST->printIndentedTree(0);
			}
			if (option == 2) {
				bst->printIndentedTree(0);
			}
		}
		else if (answer == 7) {
			dataHash.printTableStats();
			bst->printBSTOperationInfo();
			avlBST->printAVLOperationInfo();

		}
		else if (answer == 8) {
			cout << "Displaying AVL" << endl;
			avlBST->display();
		}
		else {
			cout << "Does not exist" << endl;
		}

	} while (answer != 9);


	system("pause");
	return 0;
}

// ****************************************************************************
// Purpose: return the number of entries that the file provided.
// Pre : validation - the pathName and filename to be read
// Post: the number of entries the file provided
// ****************************************************************************
int getNumOfEntries(string validation)
{

	ifstream inputFile;
	string pathName = validation;
	string line;

	int entryCtr = 0;

	inputFile.open(pathName.c_str());
	// If path exists, process file to find number of entries.
	while (getline(inputFile, line))
	{
		entryCtr++; // find number of lines.
	}

	// each entry consists of one line.
	inputFile.close();

	return entryCtr;
}

// ****************************************************************************
// Purpose: read in a path name. If the file is found, return the pathname,
// else return the default file
// Post: a string that contains a pathname to the file to read.
// ****************************************************************************
string validatePathname()
{
	ifstream inputFile;
	string pathName;
	string line;

	// Specify the directory where the file is to be found.
	cout << "Please specify the pathname of the file." << endl;
	cout << "> ";

	cin >> pathName;

	inputFile.open(pathName.c_str());

	// If path not found, use default text file.
	if (!inputFile)
	{
		cout << "\nERROR: File doesn't exist." << endl;
		cout << "Defaulting to sample input: ";
		pathName = "bst_testfile.txt";
		cout << pathName << endl << endl;
		inputFile.open(pathName);
	}

	return pathName;
}

#ifndef PRODUCT_H
#define PRODUCT_H

class Product {
	protected:
		struct List {
			List();
			std::string productName;
			int barcode;
			float price;
			int quantity;
			List* link;
		};
		List* head;
		List* tail;
		int itemCount;

	public:
		Product();
		void Addproduct(std::string, int, float, int);
		void Deleteproduct(int);
		void Updateproduct(int, std::string, float);
		void Updatequantity(int, int);
		void Displayproduct();
		int getItemCount() { return itemCount; }
		List* getHead() { return head; }
		void emptyList();
};

Product::Product() {
	head = NULL;
	tail = NULL;
	itemCount = 0;
}

Product::List::List() {
	productName = "";
	barcode = 0;
	price = 0;
	quantity = 0;
	link = NULL;
}

void Product::emptyList() {
	List* traverse = head;
	while (traverse != NULL) {
		traverse = traverse->link;
		delete head;
		head = traverse;
	}
	itemCount = 0;
}

void Product::Addproduct(std::string productName, int barcode, float price, int quantity) {
	List* product = new List;
	List* traverse = this->head;
	bool found = false;

	while (traverse != NULL && found == false) {
		if (traverse->barcode == barcode) {
			found = true;
		}
		else {
			traverse = traverse->link;
		}
	}
	
	if (found == true) {
		std::cout << "\n\t\t\t\tCANNOT ENTER EXISTING BARCODE\n\n";
	}
	else {
		product->productName = productName;
		product->barcode = barcode;
		product->price = price;
		product->quantity = quantity;
		product->link = NULL;
		itemCount++;
		std::cout << "\n\t\t\t\tITEM ADDED\n\n";

		if (head == NULL) {
			head = product;
			tail = product;
		}
		else {
			tail->link = product;
			tail = product;
		}
	}
}

void Product::Displayproduct() {
	if (head == NULL) {
		std::cout << "\t=====================================================================\n";
		std::cout << "\t\t\t\t  WELCOME TO" << std::endl;
		std::cout << "\t\t\t  HYPERMARKET MANAGEMENT SYSTEM" << std::endl;
		std::cout << "\t=====================================================================\n\n";
		std::cout << "\t\t--------------\t  PRODUCT LIST  \t--------------\n\n";
		std::cout << "\t\t\t\tEMPTY CART" << "\n\n";
		std::cout << "\t\t----------------------------------------------\n\n";
	}
	else {
		List* traverse = head;
		int index = 1;
		std::cout << "\t=====================================================================\n";
		std::cout << "\t\t\t\t  WELCOME TO" << std::endl;
		std::cout << "\t\t\t  HYPERMARKET MANAGEMENT SYSTEM" << std::endl;
		std::cout << "\t=====================================================================\n\n";
		std::cout << "\t\t--------------\t  PRODUCT LIST  \t--------------\n\n";
		std::cout << "\tProduct Name" << std::setw(25) << "Barcode" << std::right << std::setw(20) << std::setprecision(2) << "Price" << std::setw(20) << "Stock\n\n";
		while (traverse != NULL) {
			std::cout << "\t" << index << ". " << std::left << std::setw(30) << traverse->productName << std::setw(12) << traverse->barcode << std::right << std::setw(12) << std::fixed << std::setprecision(2) << traverse->price << std::setw(12) << "\t" << traverse->quantity << "\n";
			index++;
			traverse = traverse->link;
		}
		std::cout << "\n\t\t----------------------------------------------\n\n";
	}
}

void Product::Deleteproduct(int row_num) {
	List* traverse_previous = this->head;
	List* traverse = this->head;

	for (int i = 0; i < (row_num - 1); i++) {
		if (traverse != NULL) {
			traverse_previous = traverse;
			traverse = traverse->link;
		}
	}

	if (traverse == this->head) {
		traverse = traverse->link;
		head = traverse;
		delete traverse_previous;
	}
	else if (traverse == this->tail) {
		delete traverse;
		traverse_previous->link = NULL;
	}
	else {
		List* deleteItem = traverse;
		traverse = traverse->link;
		traverse_previous->link = traverse;
		delete deleteItem;
	}
	this->itemCount--;
}

void Product::Updateproduct(int row_num, std::string productName, float price) {
	List* traverse_update = this->head;
	bool found = false;

	for (int i = 0; i < (row_num - 1); i++) {
		if (traverse_update != NULL) {
			traverse_update = traverse_update->link;
		}
	}

	traverse_update->productName = productName;
	traverse_update->price = price;
}

void Product::Updatequantity(int quantity, int barcode) {
	List* traverse = this->head;
	bool found = false;

	while (traverse != NULL && found == false) {
		if (traverse->barcode == barcode) {
			found = true;
		}
		else {
			traverse = traverse->link;
		}
	}

	if (found == true) {
		traverse->quantity += quantity;
		std::cout << "\t\t\tPRODUCT SUPPLIED\n\n";
	}
	else {
		std::cout << "\t\t\tPRODUCT NOT FOUND\n\n";
	}
}
#endif
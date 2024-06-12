#ifndef SUPPLY_H
#define SUPPLY_H

class Supply : public Product {
	int request_num;

	public:
		Supply();
		void requestCheck();
		void supplyProduct(Product&, int);
		int getNumofRequest();
		void setHead(List*&);
		void setTail(List*&);
		void setTailLink(List*&);
};

void Supply::requestCheck() {
	if (head == NULL) {
		std::cout << "\t=====================================================================\n";
		std::cout << "\t\t\t\t  WELCOME TO" << std::endl;
		std::cout << "\t\t\t  HYPERMARKET MANAGEMENT SYSTEM" << std::endl;
		std::cout << "\t=====================================================================\n\n";
		std::cout << "\t\t--------------\t  SUPPLY REQUEST  \t--------------\n\n";
		std::cout << "\t\t\t\tEMPTY REQUEST" << "\n\n";
		std::cout << "\t\t----------------------------------------------\n\n";
	}
	else {
		List* traverse = head;
		int index = 1;
		std::cout << "\t=====================================================================\n";
		std::cout << "\t\t\t\t  WELCOME TO" << std::endl;
		std::cout << "\t\t\t  HYPERMARKET MANAGEMENT SYSTEM" << std::endl;
		std::cout << "\t=====================================================================\n\n";
		std::cout << "\t\t--------------\t  SUPPLY REQUEST  \t--------------\n\n";
		std::cout << "\tProduct Name" << std::setw(25) << "Barcode" << std::right << std::setw(20) << std::setprecision(2) << "Price" << std::setw(20) << "Request Stock\n\n";
		while (traverse != NULL) {
			std::cout << "\t" << index << ". " << std::left << std::setw(30) << traverse->productName << std::setw(12) << traverse->barcode << std::right << std::setw(12) << std::fixed << std::setprecision(2) << traverse->price << std::setw(12) << "\t" << traverse->quantity << "\n";
			index++;
			traverse = traverse->link;
		}
		std::cout << "\n\t\t----------------------------------------------\n\n";
	}
}

Supply::Supply() {
	request_num = 0;
}

void Supply::supplyProduct(Product& productlist, int row_num) {
	List* traverse = head;
	List* traverse_previous = head;
	int quantity = 0;
	int barcode = 0;

	for (int i = 0; i < (row_num - 1); i++) {
		if (traverse != NULL) {
			traverse_previous = traverse;
			traverse = traverse->link;
		}
	}

	quantity = traverse->quantity;
	barcode = traverse->barcode;
	productlist.Updatequantity(quantity, barcode);

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
	this->request_num--;
}

int Supply::getNumofRequest() {
	return request_num;
}

void Supply::setHead(List*& supply) {
	this->head = supply;
	request_num++;
}

void Supply::setTail(List*& supply) {
	this->tail = supply;
}

void Supply::setTailLink(List*& supply) {
	this->tail->link = supply;
	this->tail = supply;
	request_num++;
}

#endif
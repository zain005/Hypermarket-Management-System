#ifndef CART_H
#define CART_H

class Cart : public Product {
public:
	void Addproduct(Product&, int, int);
	void Deleteproduct(Cart&, Product&, int);
	float CalculateTotal();
	void Displayproduct();
};

void Cart::Addproduct(Product& productlist, int row_num, int quantity) {
	List* traverse = productlist.getHead();

	for (int i = 0; i < (row_num - 1); i++) {
		if (traverse != NULL) {
			traverse = traverse->link;
		}
	}

	if (quantity > traverse->quantity) {
		std::cout << "\n\t\t\t\tITEM NOT ENOUGH STOCK\n\n";
	}
	else {
		List* traverse_cart = this->head;
		bool found = false;
		while (traverse_cart != NULL && found == false) {
			if (traverse_cart->barcode == traverse->barcode) {
				found = true;
			}
			else {
				traverse_cart = traverse_cart->link;
			}
		}
		if (found == true) {
			std::cout << "\n\t\t\t\tITEM ALREADY EXIST IN CART\n\n";
		}
		else {
			List* product = new List;
			product->productName = traverse->productName;
			product->barcode = traverse->barcode;
			product->price = traverse->price;
			product->quantity = quantity;
			product->link = NULL;
			itemCount++;
			traverse->quantity -= quantity;
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
}

void Cart::Displayproduct() {
	if (head == NULL) {
		std::cout << "\t=====================================================================\n";
		std::cout << "\t\t\t\t  WELCOME TO HYPERMARKET" << std::endl;
		std::cout << "\t=====================================================================\n\n";
		std::cout << "\t\t--------------\t  CART  \t--------------\n\n";
		std::cout << "\t\t\t\tEMPTY CART" << "\n\n";
		std::cout << "\t\t----------------------------------------------\n\n";
	}
	else {
		List* traverse = head;
		int index = 1;
		std::cout << "\t=====================================================================\n";
		std::cout << "\t\t\t\t  WELCOME TO HYPERMARKET" << std::endl;
		std::cout << "\t=====================================================================\n\n";
		std::cout << "\t\t--------------\t  CART  \t--------------\n\n";
		std::cout << "\tProduct Name" << std::setw(25) << "Barcode" << std::right << std::setw(20) << std::setprecision(2) << "Price" << std::setw(20) << "Quantity\n\n";
		while (traverse != NULL) {
			std::cout << "\t" << index << ". " << std::left << std::setw(30) << traverse->productName << std::setw(12) << traverse->barcode << std::right << std::setw(12) << std::fixed << std::setprecision(2) << traverse->price << std::setw(12) << "\t" << traverse->quantity << "\n";
			index++;
			traverse = traverse->link;
		}
		std::cout << "\n\t\t----------------------------------------------\n\n";
	}
}

float Cart::CalculateTotal() {
	List* traverse = head;
	float total = 0;

	while (traverse != NULL) {
		total += (traverse->price * (float)traverse->quantity);
		traverse = traverse->link;
	}
	return total;
}

void Cart::Deleteproduct(Cart& cartlist, Product& productlist, int row_num) {
	List* traverse_previous = cartlist.getHead();
	List* traverse = cartlist.getHead();
	List* traverse_product = productlist.getHead();

	for (int i = 0; i < (row_num - 1); i++) {
		if (traverse != NULL) {
			traverse_previous = traverse;
			traverse = traverse->link;
		}
	}

	while (traverse_product->barcode != traverse->barcode) {
		traverse_product = traverse_product->link;
	}

	traverse_product->quantity += traverse->quantity;

	if (traverse->barcode == head->barcode) {
		traverse = traverse->link;
		head = traverse;
		delete traverse_previous;
	}
	else if (traverse->barcode == tail->barcode) {
		delete traverse;
		traverse_previous->link = NULL;
	}
	else {
		List* deleteItem = traverse;
		traverse = traverse->link;
		traverse_previous->link = traverse;
		delete deleteItem;
	}
	itemCount--;
}

#endif
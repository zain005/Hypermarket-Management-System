#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer : public Cart {
	private:
		struct Customerlist {
			Customerlist();
			std::string customer_name;
			std::string mobile_number;
			std::string email;
			List* cart;
			Customerlist* link;
		};
		Customerlist* head;
		Customerlist* tail;
		int num_of_customer;

	public:
		Customer();
		void checkOut();
		void Addcustomer(Cart&, std::string, std::string, std::string);
		void Displaycustomerlist();
		void Displaycart();

};

Customer::Customer() {
	head = NULL;
	tail = NULL;
	num_of_customer = 0;
}

void Customer::Displaycart() {
	if (head->cart == NULL) {
		std::cout << "\t=====================================================================\n";
		std::cout << "\t\t\t\t  WELCOME TO HYPERMARKET" << std::endl;
		std::cout << "\t=====================================================================\n\n";
		std::cout << "\t\t--------------\t  CART  \t--------------\n\n";
		std::cout << "\t\t\t\tEMPTY CART" << "\n\n";
		std::cout << "\t\t----------------------------------------------\n\n";
	}
	else {
		List* traverse = head->cart;
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

Customer::Customerlist::Customerlist() {
	customer_name = "";
	mobile_number = "";
	email = "";
	cart = NULL;
	link = NULL;
}

void Customer::Addcustomer(Cart& cartlist, std::string customer_name, std::string mobile_number, std::string email) {
	Customerlist* customer = new Customerlist;
	List* cart = NULL;
	List* temp_head = NULL;
	List* temp_tail = NULL;
	Product::List* temp_cart = cartlist.getHead();
	Product::List* temp_traverse = temp_cart;

	while (temp_traverse != NULL) {
		cart = new List;
		if (temp_head == NULL) {
			cart->productName = temp_traverse->productName;
			cart->barcode = temp_traverse->barcode;
			cart->price = temp_traverse->price;
			cart->quantity = temp_traverse->quantity;
			temp_head = cart;
			temp_tail = cart;
		}
		else {
			cart->productName = temp_traverse->productName;
			cart->barcode = temp_traverse->barcode;
			cart->price = temp_traverse->price;
			cart->quantity = temp_traverse->quantity;
			temp_tail->link = cart;
			temp_tail = cart;
		}
		temp_traverse = temp_traverse->link;
	}
	
	cartlist.emptyList();

	customer->customer_name = customer_name;
	customer->mobile_number = mobile_number;
	customer->email = email;
	customer->cart = temp_head;
	
	customer->link = NULL;
	num_of_customer++;

	if (head == NULL) {
		head = customer;
		tail = customer;
	}
	else {
		tail->link = customer;
		tail = customer;
	}
}

void  Customer::Displaycustomerlist() {
	Customerlist* traverse = head;

	if (head == NULL) {
		std::cout << "\t=====================================================================\n";
		std::cout << "\t\t\t\t  WELCOME TO" << std::endl;
		std::cout << "\t\t\t  HYPERMARKET MANAGEMENT SYSTEM" << std::endl;
		std::cout << "\t=====================================================================\n\n";
		std::cout << "\t\t--------------\t  CUSTOMER LIST  \t--------------\n\n";
		std::cout << "\t\t\t\tEMPTY ORDER" << "\n\n";
		std::cout << "\n\t\t----------------------------------------------\n\n";
	}
	else {
		int index = 1;
		std::cout << "\t=====================================================================\n";
		std::cout << "\t\t\t\t  WELCOME TO" << std::endl;
		std::cout << "\t\t\t  HYPERMARKET MANAGEMENT SYSTEM" << std::endl;
		std::cout << "\t=====================================================================\n\n";
		std::cout << "\t\t--------------\t  CUSTOMER LIST  \t--------------\n\n";
		std::cout << "\tCustomer Name" << std::setw(35) << "Mobile Number" << std::right << std::setw(25) << "Email" << std::setw(30) << "Total Price\n\n";
		while (traverse != NULL) {
			List* list_traverse = traverse->cart;
			float total = 0;
			while (list_traverse != NULL) {
				total += (list_traverse->price * list_traverse->quantity);
				list_traverse = list_traverse->link;
			}
			std::cout << "\t" << index << ". " << std::left << std::setw(25) << traverse->customer_name << std::right << std::setw(20) << traverse->mobile_number << std::right << std::setw(30) << traverse->email << std::right << std::setw(20) << std::fixed << std::setprecision(2) << total << "\n";
			index++;
			traverse = traverse->link;
		}
		std::cout << "\n\t\t----------------------------------------------\n\n";
	}
}

#endif
#ifndef ADMIN_H
#define ADMIN_H

class Admin : public Product {
	public:
		void login(std::string&, std::string&, int&, int&, bool&);
		void requestRestock(Product&, Supply&, int, int);
};

void Admin::login(std::string& UserName, std::string& UserPassword, int& system_main_menu_choice, int& exit_choice, bool& loginAttemptFail) {
	int loginAttempt = 0;
	while (loginAttempt < 5) {
		std::cout << "\t=====================================================================\n";
		std::cout << "\t\t\t\t  WELCOME TO" << std::endl;
		std::cout << "\t\t\t  HYPERMARKET MANAGEMENT SYSTEM" << std::endl;
		std::cout << "\t=====================================================================\n\n";
		std::cout << "\t--------------\t  ADMIN MAIN MENU  \t--------------\n\n";
		std::cout << "\tUsername: ";
		std::cin >> UserName;
		std::cout << "\tPassword: ";
		std::cin >> UserPassword;
		std::cout << "\n\n";

		if (UserName == "admin" && UserPassword == "admin") {
			break;
		}
		else {
			system("cls");
			std::cout << "\nInvalid login attempt. Please try again.\n" << '\n';
			loginAttempt++;
		}
	}
	if (loginAttempt == 5) {
		std::cout << "Exceed Login Attempt! The program will now terminate.";
		system_main_menu_choice = 3;
		exit_choice = 1;
		loginAttemptFail = true;
	}
}

void Admin::requestRestock(Product& productlist, Supply& supplylist, int quantity, int row_num) {
	List* traverse = productlist.getHead();

	for (int i = 0; i < (row_num - 1); i++) {
		if (traverse != NULL) {
			traverse= traverse->link;
		}
	}

	List* supply = new List;
	supply->productName = traverse->productName;
	supply->barcode = traverse->barcode;
	supply->price = traverse->price;
	supply->quantity = quantity;

	if (supplylist.getHead() == NULL) {
		supplylist.setHead(supply);
		supplylist.setTail(supply);
	}
	else {
		supplylist.setTailLink(supply);
	}
}

#endif
#include <iostream>
#include <string>
#include <iomanip>

#include "product.h"
#include "cart.h"
#include "supply.h"
#include "admin.h"
#include "customer.h"

int main() {
	int system_main_menu_choice = 0;
	int system_exit_choice = 0;
	int admin_main_menu_choice = 0;
	int admin_exit_choice = 0;
	int manage_inv_menu_choice = 0;
	int manage_inv_exit = 0;
	int customer_main_menu_choice = 0;
	int customer_exit_choice = 0;
	int supplier_main_menu_choice = 0;
	int supplier_exit_choice = 0;
	int manage_request_choice = 0;
	int manage_request_exit = 0;
	int row_num = -1;
	int quantity = 0;
	std::string adminUserName;
	std::string adminUserPassword;
	bool loginAttemptFail = false;
	Admin admin;
	Customer customer;
	Product productlist;
	Cart cartlist;
	Supply supplylist;
	productlist.Addproduct("Shirt", 1, 50.00, 100);
	productlist.Addproduct("Trousers", 2, 40.00, 100);
	productlist.Addproduct("Shoes", 3, 50.00, 100);
	productlist.Addproduct("Socks", 4, 20.50, 100);
	
	while (system_exit_choice != 1) { // main menu
		system("cls");
		std::cout << "\t=====================================================================\n";
		std::cout << "\t\t\t\t  WELCOME TO HYPERMARKET" << std::endl;
		std::cout << "\t=====================================================================\n\n";
		std::cout << "\t--------------\t  LOGIN MENU  \t--------------\n\n";
		std::cout << "\t1. CUSTOMER \n";
		std::cout << "\t2. ADMIN \n";
		std::cout << "\t3. SUPPLIER \n";
		std::cout << "\t4. EXIT \n";
		std::cout << "\n\n";

		while (system_main_menu_choice < 1 || system_main_menu_choice > 4) {
			std::cout << "\tSELECT ONE\n";
			std::cout << "\t>> ";
			std::cin >> system_main_menu_choice;

			if (system_main_menu_choice < 1 || system_main_menu_choice > 4) {
				std::cout << "\tPLEASE ENTER THE CORRECT CHOICES GIVEN.\n\n";
			}
		}

		if (system_main_menu_choice == 1) {
			customer_exit_choice = 0;
			while (customer_exit_choice != 1) { // customer main menu
				system("cls");
				std::cout << "\t=====================================================================\n";
				std::cout << "\t\t\t\t  WELCOME TO HYPERMARKET" << std::endl;
				std::cout << "\t=====================================================================\n\n";
				std::cout << "\t--------------\t  CUSTOMER MAIN MENU  \t--------------\n\n";
				std::cout << "\t1. ADD PRODUCT TO CART \n";
				std::cout << "\t2. DELETE PRODUCT FROM CART \n";
				std::cout << "\t3. DISPLAY CART \n";
				std::cout << "\t4. CHECK OUT \n";
				std::cout << "\t5. EXIT \n";
				std::cout << "\n\n";

				while (customer_main_menu_choice < 1 || customer_main_menu_choice > 5) {
					std::cout << "\tSELECT ONE\n";
					std::cout << "\t>> ";
					std::cin >> customer_main_menu_choice;

					if (customer_main_menu_choice < 1 || customer_main_menu_choice > 5) {
						std::cout << "\tPLEASE ENTER THE CORRECT CHOICES GIVEN.\n\n";
					}
				}

				if (customer_main_menu_choice == 1) { // add item to cart
					system("cls");
					productlist.Displayproduct();
					while (row_num < 0 || row_num > productlist.getItemCount()) {
						std::cout << "\n\tSELECT AN ITEM TO ADD OR TYPE \"0\" TO CANCEL\n";
						std::cout << "\t>> ";
						std::cin >> row_num;
						if (row_num < 0 || row_num > productlist.getItemCount()) {
							std::cout << "\t\t\tPLEASE INSERT THE CORRECT CHOICE GIVEN\n\n";
						}
					}
					if (row_num == 0) {
						std::cout << "\t\t\tCANCELLING...\n\n";
					}
					else {
						std::cout << "\n\tQUANTITY\n";
						std::cout << "\t>> ";
						std::cin >> quantity;
						cartlist.Addproduct(productlist, row_num, quantity);
					}
					system("pause");
					row_num = -1;
					customer_main_menu_choice = 0;
				}
				else if (customer_main_menu_choice == 2) { // delete item from cart
					system("cls");
					cartlist.Displayproduct();
					if (cartlist.getItemCount() == 0) {
						std::cout << "\n\t\t\tCANNOT DELETE FROM EMPTY CART\n\n";
					}
					else {
						while (row_num < 0 || row_num > cartlist.getItemCount()) {
							std::cout << "\n\tSELECT AN ITEM TO DELETE OR TYPE \"0\" TO CANCEL\n";
							std::cout << "\t>> ";
							std::cin >> row_num;
							if (row_num < 0 || row_num > cartlist.getItemCount()) {
								std::cout << "\t\t\tPLEASE INSERT THE CORRECT CHOICE GIVEN\n\n";
							}
						}
						if (row_num == 0) {
							std::cout << "\t\t\tCANCELLING...\n\n";
						}
						else {
							cartlist.Deleteproduct(cartlist, productlist, row_num);
							std::cout << "\t\t\tITEM DELETED\n\n";
						}
					}
					system("pause");
					row_num = -1;
					customer_main_menu_choice = 0;
				}
				else if (customer_main_menu_choice == 3) { // display cart
					system("cls");
					cartlist.Displayproduct();
					system("pause");
					customer_main_menu_choice = 0;
				}
				else if (customer_main_menu_choice == 4) { // check out
					system("cls");
					std::string customer_name = "";
					std::string mobile_num = "";
					std::string email = "";
					int pay = 0;
					std::cout << "\t=====================================================================\n";
					std::cout << "\t\t\t\t  WELCOME TO HYPERMARKET" << std::endl;
					std::cout << "\t=====================================================================\n\n";
					std::cout << "\t--------------\t  CUSTOMER MAIN MENU  \t--------------\n\n";

					if (cartlist.getItemCount() == 0) {
						std::cout << "\t\t\tEMPTY CART. CANNOT CHECKOUT" << "\n\n";
					}
					else {
						std::cout << "\n\tENTER CUSTOMER NAME OR TYPE \"0\" TO CANCEL\n";
						std::cout << "\t>> ";
						std::cin.ignore();
						std::getline(std::cin, customer_name, '\n');
						if (customer_name == "0") {
							std::cout << "\t\t\tCANCELLING...\n\n";
						}
						else {
							std::cout << "\n\tENTER MOBILE PHONE\n";
							std::cout << "\t>> ";
							std::cin >> mobile_num;
							std::cout << "\n\tENTER EMAIL\n";
							std::cout << "\t>> ";
							std::cin >> email;
							system("cls");
							cartlist.Displayproduct();
							std::cout << std::setw(55) << "Total" << std::setw(10) << std::fixed << std::setprecision(2) << cartlist.CalculateTotal() << "\n";
							std::cout << "\n\t\t----------------------------------------------\n\n";
							std::cout << "\n\tWELCOME " << customer_name << ".\n\n";
							while (pay < 1 || pay > 3) {
								std::cout << "\t1. PAY WITH CASH\n";
								std::cout << "\t2. PAY WITH CREDIT CARD\n";
								std::cout << "\t3. CANCEL\n";
								std::cout << "\t>> ";
								std::cin >> pay;
								if (pay < 1 || pay > 3) {
									std::cout << "\t\t\tPLEASE INSERT THE CORRECT CHOICE GIVEN\n\n";
								}
							}
							int confirm = 0;
							if (pay == 1 || pay == 2) {
								while (confirm < 1 || confirm > 2) {
									std::cout << "\n\t1. CONFIRM\n";
									std::cout << "\t2. CANCEL\n";
									std::cout << "\t>> ";
									std::cin >> confirm;
									if (confirm < 1 || confirm > 2) {
										std::cout << "\t\t\tPLEASE INSERT THE CORRECT CHOICE GIVEN\n\n";
									}
								}

								if (pay == 1 && confirm == 1) {
									customer.Addcustomer(cartlist, customer_name, mobile_num, email);
									std::cout << "\n\t\t\t\tPAYMENT SUCCESS\n\n";
								}
								else if (pay == 2 && confirm == 1) {
									customer.Addcustomer(cartlist, customer_name, mobile_num, email);
									std::cout << "\n\t\t\t\tTRANSACTION SUCCESS\n\n";
								}
								else {
									std::cout << "\t\t\tCANCELLING...\n\n";
								}
							}
							else {
								std::cout << "\t\t\tCANCELLING...\n\n";
							}
						}
					}
					
					system("pause");
					customer_main_menu_choice = 0;
				}
				else if (customer_main_menu_choice == 5) { // exit customer main menu
					customer_exit_choice = 1;
					customer_main_menu_choice = 0;
					system_main_menu_choice = 0;
					std::cout << "\n\tEXIT TO LOGIN MENU\n\n";
					system("pause");
				}
			}
		}
		else if (system_main_menu_choice == 2) { // admin main menu
			admin_exit_choice = 0;
			system("cls");
			admin.login(adminUserName, adminUserPassword, system_main_menu_choice, admin_exit_choice, loginAttemptFail); // login system
			while (admin_exit_choice != 1) {
				system("cls");
				std::cout << "\t=====================================================================\n";
				std::cout << "\t\t\t\t  WELCOME TO" << std::endl;
				std::cout << "\t\t\t  HYPERMARKET MANAGEMENT SYSTEM" << std::endl;
				std::cout << "\t=====================================================================\n\n";
				std::cout << "\t--------------\t  ADMIN MAIN MENU  \t--------------\n\n";
				std::cout << "\tWelcome "<< adminUserName << "!\n\n";
				std::cout << "\t1. MANAGE INVENTORY \n";
				std::cout << "\t2. STATISTIC \n";
				std::cout << "\t3. REQUEST INVENTORY\n";
				std::cout << "\t4. LOGOUT \n";
				std::cout << "\n\n";

				while (admin_main_menu_choice < 1 || admin_main_menu_choice > 4) {
					std::cout << "\tSELECT ONE\n";
					std::cout << "\t>> ";
					std::cin >> admin_main_menu_choice;

					if (admin_main_menu_choice < 1 || admin_main_menu_choice > 4) {
						std::cout << "\tPLEASE ENTER THE CORRECT CHOICES GIVEN.\n\n";
					}
				}

				if (admin_main_menu_choice == 1) { // managing inventory
					manage_inv_exit = 0;
					while (manage_inv_exit != 1) {
						system("cls");
						std::cout << "\t=====================================================================\n";
						std::cout << "\t\t\t\t  WELCOME TO" << std::endl;
						std::cout << "\t\t\t  HYPERMARKET MANAGEMENT SYSTEM" << std::endl;
						std::cout << "\t=====================================================================\n\n";
						std::cout << "\t--------------\t  ADMIN MAIN MENU  \t--------------\n\n";
						std::cout << "\t1. ADD PRODUCT \n";
						std::cout << "\t2. UPDATE PRODUCT \n";
						std::cout << "\t3. DELETE PRODUCT \n";
						std::cout << "\t4. VIEW PRODUCT \n";
						std::cout << "\t5. EXIT \n";
						std::cout << "\n\n";

						while (manage_inv_menu_choice < 1 || manage_inv_menu_choice > 5) {
							std::cout << "\tSELECT ONE\n";
							std::cout << "\t>> ";
							std::cin >> manage_inv_menu_choice;

							if (manage_inv_menu_choice < 1 || manage_inv_menu_choice > 5) {
								std::cout << "\tPLEASE ENTER THE CORRECT CHOICES GIVEN.\n\n";
							}
						}

						if (manage_inv_menu_choice == 1) {
							system("cls");
							std::string productName = "";
							int barcode = 0;
							float price = 0;
							productlist.Displayproduct();

							std::cout << "\n\tENTER PRODUCT NAME OR TYPE \"0\" TO CANCEL\n";
							std::cout << "\t>> ";
							std::cin.ignore();
							std::getline(std::cin, productName , '\n');
							if (productName == "0") {
								std::cout << "\t\t\tCANCELLING...\n\n";
							}
							else {
								std::cout << "\n\tENTER BARCODE\n";
								std::cout << "\t>> ";
								std::cin >> barcode;
								std::cout << "\n\tENTER PRICE\n";
								std::cout << "\t>> ";
								std::cin >> price;
								productlist.Addproduct(productName, barcode, price, 0);
							}
							
							system("pause");
							manage_inv_menu_choice = 0;
						}
						else if (manage_inv_menu_choice == 2) {
							system("cls");
							std::string productName = "";
							int barcode = 0;
							float price = 0;
							productlist.Displayproduct();
							if (productlist.getItemCount() == 0) {
								std::cout << "\n\t\t\tCANNOT UPDATE ITEM FROM EMPTY PRODUCT LIST\n\n";
							}
							else {
								while (row_num < 0 || row_num > productlist.getItemCount()) {
									std::cout << "\n\tSELECT AN ITEM TO UPDATE OR TYPE \"0\" TO CANCEL\n";
									std::cout << "\t>> ";
									std::cin >> row_num;
									if (row_num < 0 || row_num > productlist.getItemCount()) {
										std::cout << "\t\t\tPLEASE INSERT THE CORRECT CHOICE GIVEN\n\n";
									}
								}
								if (row_num == 0) {
									std::cout << "\t\t\tCANCELLING...\n\n";
								}
								else {
									std::cout << "\n\tENTER PRODUCT NAME\n";
									std::cout << "\t>> ";
									std::cin.ignore();
									std::getline(std::cin, productName, '\n');
									std::cout << "\n\tENTER PRICE\n";
									std::cout << "\t>> ";
									std::cin >> price;
									productlist.Updateproduct(row_num, productName, price);
									std::cout << "\t\t\tITEM UPDATED\n\n";
								}
							}
							system("pause");
							row_num = -1;
							manage_inv_menu_choice = 0;
						}
						else if (manage_inv_menu_choice == 3) {
							system("cls");
							productlist.Displayproduct();
							if (productlist.getItemCount() == 0) {
								std::cout << "\n\t\t\tCANNOT DELETE FROM EMPTY PRODUCT LIST\n\n";
							}
							else {
								while (row_num < 0 || row_num > productlist.getItemCount()) {
									std::cout << "\n\tSELECT AN ITEM TO DELETE OR TYPE \"0\" TO CANCEL\n";
									std::cout << "\t>> ";
									std::cin >> row_num;
									if (row_num < 0 || row_num > productlist.getItemCount()) {
										std::cout << "\t\t\tPLEASE INSERT THE CORRECT CHOICE GIVEN\n\n";
									}
								}
								if (row_num == 0) {
									std::cout << "\t\t\tCANCELLING...\n\n";
								}
								else {
									productlist.Deleteproduct(row_num);
									std::cout << "\t\t\tITEM DELETED\n\n";
								}
							}
							system("pause");
							row_num = -1;
							manage_inv_menu_choice = 0;
						}
						else if (manage_inv_menu_choice == 4) {
							system("cls");
							productlist.Displayproduct();
							system("pause");
							manage_inv_menu_choice = 0;
						}
						else if (manage_inv_menu_choice == 5) {
							manage_inv_menu_choice = 0;
							manage_inv_exit = 1;
							std::cout << "\n\tEXIT TO ADMIN MAIN MENU\n\n";
						}
					}

					system("pause");
					admin_main_menu_choice = 0;
				}
				else if (admin_main_menu_choice == 2) {
					system("cls");
					customer.Displaycustomerlist();
					system("pause");
					admin_main_menu_choice = 0;
				}
				else if (admin_main_menu_choice == 3) {
					system("cls");
					int request_quantity = 0;
					productlist.Displayproduct();
					while (row_num < 0 || row_num > productlist.getItemCount()) {
						std::cout << "\n\tSELECT AN ITEM TO REQUEST RESTOCK OR TYPE \"0\" TO CANCEL\n";
						std::cout << "\t>> ";
						std::cin >> row_num;
						if (row_num < 0 || row_num > productlist.getItemCount()) {
							std::cout << "\t\t\tPLEASE INSERT THE CORRECT CHOICE GIVEN\n\n";
						}
					}
					if (row_num == 0) {
						std::cout << "\t\t\tCANCELLING...\n\n";
					}
					else {
						std::cout << "\n\tHOW MANY STOCKS TO ADD?\n";
						std::cout << "\t>> ";
						std::cin >> request_quantity;
						admin.requestRestock(productlist, supplylist, request_quantity, row_num);
						std::cout << "\t\t\tREQUEST ADDED\n\n";
					}
					system("pause");
					row_num = -1;
					admin_main_menu_choice = 0;
				}
				else if (admin_main_menu_choice == 4) {
					admin_exit_choice = 1;
					admin_main_menu_choice = 0;
					system_main_menu_choice = 0;
					std::cout << "\n\tEXIT TO LOGIN MENU\n\n";
					system("pause");
				}
			}
		}
		else if (system_main_menu_choice == 3) {
			supplier_exit_choice = 0;
			while (supplier_exit_choice != 1) {
				system("cls");
				std::cout << "\t=====================================================================\n";
				std::cout << "\t\t\t\t  WELCOME TO" << std::endl;
				std::cout << "\t\t\t  HYPERMARKET MANAGEMENT SYSTEM" << std::endl;
				std::cout << "\t=====================================================================\n\n";
				std::cout << "\t--------------\t  SUPPLIER MAIN MENU  \t--------------\n\n";
				std::cout << "\t1. MANAGE REQUEST \n";
				std::cout << "\t2. EXIT \n";
				std::cout << "\n\n";

				while (supplier_main_menu_choice < 1 || supplier_main_menu_choice > 2) {
					std::cout << "\tSELECT ONE\n";
					std::cout << "\t>> ";
					std::cin >> supplier_main_menu_choice;

					if (supplier_main_menu_choice < 1 || supplier_main_menu_choice > 2) {
						std::cout << "\tPLEASE ENTER THE CORRECT CHOICES GIVEN.\n\n";
					}
				}

				if (supplier_main_menu_choice == 1) {
					manage_request_exit = 0;
					while (manage_request_exit != 1) {
						system("cls");
						std::cout << "\t=====================================================================\n";
						std::cout << "\t\t\t\t  WELCOME TO" << std::endl;
						std::cout << "\t\t\t  HYPERMARKET MANAGEMENT SYSTEM" << std::endl;
						std::cout << "\t=====================================================================\n\n";
						std::cout << "\t--------------\t  ADMIN MAIN MENU  \t--------------\n\n";
						std::cout << "\t1. SUPPLY PRODUCT \n";
						std::cout << "\t2. VIEW REQUEST \n";
						std::cout << "\t3. EXIT \n";
						std::cout << "\n\n";

						while (manage_request_choice < 1 || manage_request_choice > 3) {
							std::cout << "\tSELECT ONE\n";
							std::cout << "\t>> ";
							std::cin >> manage_request_choice;

							if (manage_request_choice < 1 || manage_request_choice > 3) {
								std::cout << "\tPLEASE ENTER THE CORRECT CHOICES GIVEN.\n\n";
							}
						}

						if (manage_request_choice == 1) {
							system("cls");
							supplylist.requestCheck();

							if (supplylist.getNumofRequest() == 0) {
								std::cout << "\n\t\t\tCANNOT SUPPLY PRODUCT\n\n";
							}
							else {
								while (row_num < 0 || row_num > supplylist.getNumofRequest()) {
									std::cout << "\n\tSELECT AN ITEM TO SUPPLY OR TYPE \"0\" TO CANCEL\n";
									std::cout << "\t>> ";
									std::cin >> row_num;
									if (row_num < 0 || row_num > supplylist.getNumofRequest()) {
										std::cout << "\t\t\tPLEASE INSERT THE CORRECT CHOICE GIVEN\n\n";
									}
								}

								if (row_num == 0) {
									std::cout << "\t\t\tCANCELLING...\n\n";
								}
								else {
									supplylist.supplyProduct(productlist, row_num);
								}
							}
							system("pause");
							row_num = -1;
							manage_request_choice = 0;
						}
						else if (manage_request_choice == 2) {
							system("cls");
							supplylist.requestCheck();
							system("pause");
							manage_request_choice = 0;
						}
						else {
							std::cout << "\n\tEXIT TO SUPPLIER MAIN MENU\n\n";
							manage_request_choice = 0;
							manage_request_exit = 1;
						}
					}

					system("pause");
					supplier_main_menu_choice = 0;
				}
				else if (supplier_main_menu_choice == 2) {
					supplier_exit_choice = 1;
					supplier_main_menu_choice = 0;
					system_main_menu_choice = 0;
					std::cout << "\n\tEXIT TO LOGIN MENU\n\n";
					system("pause");
				}
			}
		}
		else if (system_main_menu_choice == 4) {
			system_exit_choice = 1;
			if (loginAttemptFail == true) {
				std::cout << "\n\tEXCEEDING LOGIN ATTEMPT! THE SYSTEM IS NOW EXITING...\n\n";
			}
			else {
				std::cout << "\n\tEXITING SYSTEM...\n\n";
				std::cout << "\tTHANK YOU FOR USING HYPERMARKET SYSTEM \n\n";
			}
		}
	}
}
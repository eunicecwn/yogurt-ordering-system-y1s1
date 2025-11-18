#include <iostream> // Library of standard input-output stream (cout/ cin/ int/ double/ float )
#include <iomanip> // Library of manage input and output formatting (setw/ getline/ setprecision/ left or right) 
#include <sstream> // Library of String Stream it's allows performing insertion, extraction, and other operation (clear/ str)
#include <stdio.h> // Library of Standard Output and related to input/output function (getch)
#include <stdlib.h> // Library of Standard Library it's related to input/output functions and related to allocation memory of input/ output
#include <conio.h> // Library of C++ header file used mostly by compilers to provide console input/output (getch)
#include <string.h> // Library of string.h header file in C++ used to manipulate a string or array of characters. (strcpy/ strlen)

using namespace std;

/* Constant Variable */
const string nl = "\n";
const string breakline = nl + "----------------------------------------------------------------------------";
const string Msg_invalidSelection = nl + "Invalid Selection. Please Try Again.";
const string Msg_invalidAmount = nl + "Insuffient Amount. Please Try Again.";
const string Msg_invalidCardNo = nl + "Invalid Credit Card No.. Please Try Again.";
const string Msg_selection = nl + "Your Selection is : ";
const string Msg_cardNo = "Please Enter Card Number : ";
const string Msg_pytAmt = "Please Enter Payment Amount : RM ";

/* Function - Menu */
static void logo() {
	const string line1 = "MM";
	const string line2 = "M";
	const string line3 = " M";
	const string line4 = "  M";
	const string line5 = "   M";
	const string line6 = "    M";
	const string line7 = "     M";
	// call logo display
	cout << setw(27) << line1 << setw(11) << line1 << setw(5) << line1 << setw(11) << line1 << endl;
	cout << setw(26) << line2 << line3 << setw(8) << line6 << setw(2) << line2 << setw(4) << line2 << setw(2) << line3 << setw(8) << line6 << setw(2) << line2 << endl;
	cout << setw(26) << line2 << line4 << setw(6) << line5 << setw(3) << line2 << setw(4) << line2 << setw(2) << line4 << setw(6) << line5 << setw(3) << line2 << endl;
	cout << setw(26) << line2 << line5 << setw(4) << line4 << setw(4) << line2 << setw(4) << line2 << setw(2) << line5 << setw(4) << line4 << setw(4) << line2 << endl;
	cout << setw(26) << line2 << line6 << setw(2) << line3 << setw(5) << line2 << setw(4) << line2 << setw(2) << line6 << setw(2) << line3 << setw(5) << line2 << endl;
	cout << setw(26) << line2 << line7 << setw(6) << line2 << setw(4) << line2 << setw(4) << line7 << setw(6) << line2 << endl;
	
}

static void header() {
	cout << breakline << endl;
	cout << nl << "                  Welcome To Miao Miao Yogurt Order System                  " << endl;
}

static void login() {
	cout << breakline << endl;
	cout << nl << "Please Select The User :" << endl;
	cout << "[1.] Login ( Member )" << endl;
	cout << "[2.] Login ( Guest )" << endl;
	cout << "[3.] Register New ( Member )" << nl << endl;
	cout << "=======================================================" << endl;
	cout << "** Join our Member for more promotion & discount !!! **" << endl;
	cout << "=======================================================" << endl;
	cout << Msg_selection;
}

static void main_Menu() {
	cout << breakline << endl;
	cout << nl << "Please Select Your Option :" << endl;
	cout << "[1.] Order Menu" << endl;
	cout << "[2.] Customer Support" << endl;
	cout << "[3.] Login/Register" << endl;
	cout << "[4.] Exit" << endl;
	cout << breakline << endl;
	cout << Msg_selection;
}

static void flavor_Menu() {
	cout << breakline << endl;
	cout << nl << "Please Choose Your Flavor :" << endl;
	cout << "[1.] Base Yogurt" << endl;
	cout << "[2.] Pistachio Yogurt" << endl;
	cout << "[3.] Strawberry Yogurt" << endl;
	cout << "[4.] Chocolate Yogurt" << endl;
	cout << "[5.] Vanilla Yogurt" << endl;
	cout << breakline << endl;
	cout << Msg_selection;
}

static void topping_Menu() {
	cout << breakline << endl;
	cout << nl << "Would You Want to Add-On Toppings ?" << endl;
	cout << "[A] - Biscoff ( +RM 5 )" << endl;
	cout << "[B] - Honey Syrup ( + RM 5 )" << endl;
	cout << "[C] - Rainbow Chocolate Rice ( + RM 2 )" << endl;
	cout << breakline << endl;
	cout << Msg_selection;
}

static void payment_Menu() {
	cout << nl << "Please Choose Payment Method :" << nl << endl;
	cout << "[A] - Cash" << endl;
	cout << "[B] - Credit Card / Debit Card" << endl;
	cout << Msg_selection;
}

static void thankYou() {
	cout << nl << "----------------------------------------------------------------" << endl;
	cout << "----------------------------------------------------------------" << endl;
	cout << "-------------------------- T H A N K ---------------------------" << endl;
	cout << "--------------------------   Y O U   ---------------------------" << endl;
	cout << "-------------------- F O R  O R D E R I N G --------------------" << endl;
	cout << "--------------- P L E A S E  C O M E  A G A I N ----------------" << endl;
	cout << "----------------------------------------------------------------" << endl;
	cout << "----------------------------------------------------------------" << endl;
}

static void sysClr() {
	system("cls");
}

/* Function - Validation */
static string selectValidation(int minValue, int maxValue, string message) {
	string option;
	while (cin >> option) {
		stringstream strm(option);
		int i;
		strm >> i;
		if (option.length() <= 1) if (i >= minValue && i <= maxValue) break;
		cout << Msg_invalidSelection << endl;
		cout << message;
	}
	return option;
}

static char alphaValidation(char f_val, char s_val, char t_val = 'DEF') {
	char option;
	while (cin >> option) {
		if (toupper(option) == f_val) break;
		if (toupper(option) == s_val) break;
		if (t_val != 'DEF' && toupper(option) == t_val) break;
		cout << Msg_invalidSelection << endl;
		cout << Msg_selection;
	}
	return toupper(option);
}

static int quantityValidation() {
	bool alpha = false;
	char quantity[] = "";
	while (cin >> quantity) {
		for (int i = 0; i < strlen(quantity); i++) {
			if (isalpha(quantity[i])) {
				cout << Msg_invalidAmount << endl;
				cout << nl << "Quantity : ";
				alpha = true;
				break;
			}
		}
		if (!alpha) break;
	}
	return int(quantity);

}

static double paymentValidation(double subTotal) {
	double payAmt;
	while (cin >> payAmt) {
		if (payAmt >= subTotal) break;
		cout << Msg_invalidAmount << endl;
		cout << nl << Msg_pytAmt;
	}
	return payAmt;
}

static string creditCardValidation() {
	string cardNum;
	while (cin >> cardNum) {
		bool chkIsDigit = false;
		for (int i = 0; i < cardNum.length(); i++) {
			if (isdigit(cardNum[i]) == false) {
				chkIsDigit = false;
			}
			chkIsDigit = true;
		}
		if (chkIsDigit && cardNum.length() == 16) break;
		cout << Msg_invalidCardNo << endl;
		cout << nl << Msg_cardNo;
	}
	return cardNum;
}

/* Function - Report */
static void fineDisplay(double chg) {
	cout << breakline << endl;
	cout << nl << "Your Change Is : RM " << chg << nl << endl;
	cout << "----------------------------------------------------------------------------" << endl;
	cout << "--------------------------------- T H A N K --------------------------------" << endl;
	cout << "---------------------------------   Y O U   --------------------------------" << endl;
	cout << "----------------------------------- F O R ----------------------------------" << endl;
	cout << "------------------------------ O R D E R I N G -----------------------------" << endl;
	cout << "----------------------------------------------------------------------------" << endl;
}

static void customerServDisplay(int orderCount) {
	int custService;

	cout << nl << "You Selected Customer Service" << endl;
	cout << nl << "Please Choose Your Service Option :" << endl;
	cout << "[1.] Check Order Status" << endl;
	cout << "[2.] Report an Issue" << endl;
	cout << "[3.] Contact us" << endl;
	cout << Msg_selection;
	cin >> custService;
	switch (custService) {
	case 1:
		if (orderCount > 0) {
			cout << "\nOrder Status: Your current order is being processed." << endl;
		}
		else {
			cout << "\nOrder Status: You haven't place any orders." << endl;
		}
		break;

	case 2: {
		string issue; //the braces {} around case 2 make sure that 'issue' variable is accessible inside here only, prevent initialization issues
		cout << "\nPlease describe the issue with your order: \n";
		cin.ignore();   //to ignore the newline from previous input
		getline(cin, issue);
		cout << "\nThank you! We have received your issue report: " << issue << endl;
		break;
	}
	case 3:
		// Display restaurant contact information
		cout << nl << "CONTACT US : " << endl;
		cout << nl << "----------------------------------------------" << endl;
		cout << "----------------------------------------------" << endl;
		cout << "----------------- K I N D L Y ----------------" << endl;
		cout << "------------------- M A K E ------------------" << endl;
		cout << "---------------------- A ---------------------" << endl;
		cout << "------------------- C A L L ------------------" << endl;
		cout << "--------------------- T O --------------------" << endl;
		cout << "--------------------- U S --------------------" << endl;
		cout << "---------- + 0 1 6 - 3 8 5  3 6 6 8 ----------" << endl;
		cout << "--------- B R A N C H  M A N A G E R ---------" << endl;
		cout << "----------------- M R .  M C -----------------" << endl;
		cout << "----------------------------------------------" << endl;
		cout << "----------------------------------------------" << endl;
		cout << "-- Follow us on our social media :          --" << endl;
		cout << "-- Instagram : @MiaoMiaoYogurt              --" << endl;
		cout << "-- Facebook  : facebook.com/MiaoMiaoYogurt  --" << endl;
		cout << "-- Twitter   : @MiaoMiaoYogurt              --" << endl;
		cout << "----------------------------------------------" << endl;
		break;
	}
}

static void summaryDisplay(int orderCount, string itemsOrdered[], string toppingsOrdered[], int itemsQuantities[], double tempTotal) {

	cout << nl << "----------------------------------------------------------------" << endl;
	cout << nl << "-------------------- S U M M A R Y   L I S T -------------------" << endl;
	cout << nl << "----------------------------------------------------------------" << endl;
	cout << left << setw(23) << "Item Order" << left << setw(20) << "Toppings" << right << setw(16) << "Quantity" << endl;

	for (int i = 0; i < orderCount; ++i) {
		cout << left << setw(23) << to_string(i + 1) + ". " + itemsOrdered[i]
			<< left << setw(20) << toppingsOrdered[i]
			<< right << setw(13) << itemsQuantities[i] << endl;
	}

	cout << nl << "----------------------------------------------------------------" << endl;
	cout << nl << "-------------- P R O F I T   O F   T H E   D A Y ---------------" << endl;
	cout << nl << "----------------------------------------------------------------" << endl;
	cout << nl << "Subtotal : RM " << tempTotal << endl;
	cout << nl << "----------------------------------------------------------------" << endl;
	cout << nl << "----------------------------------------------------------------" << endl;
}

static void invDisplay(int orderCount, string itemsOrdered[], string toppingsOrdered[], int itemsQuantities[], int itemsPrices[],
	double taxTotal, double sstTotal, double tempTotal, char payMethod, double change, string cardNum, double discount, bool isMember) {

	cout << nl << "=========================================================================" << endl;
	cout << nl << "                              I N V O I C E                              " << endl;
	cout << nl << "=========================================================================" << endl;
	cout << left << setw(23) << "Item Order" << left << setw(20) << "Toppings" << right << setw(14) << "Quantity" << right<< setw(12) << "Price (RM)" << endl;
	cout << "-------------------------------------------------------------------------" << endl << nl;
	for (int i = 0; i < orderCount; ++i) {
		cout << left << setw(23) << to_string(i + 1) + ". " + itemsOrdered[i]
			<< left << setw(20) << toppingsOrdered[i]
			<< right << setw(13) << itemsQuantities[i]
			<< right << setw(12) << itemsPrices[i] << endl;
	}
	cout << nl << "-------------------------------------------------------------------------" << endl;
	cout << nl << "Tax             : RM " << taxTotal << endl;
	cout << nl << "SST             : RM " << sstTotal << endl;
	cout << nl << "Subtotal        : RM " << tempTotal << endl;
	cout << nl << "-------------------------------------------------------------------------" << endl;
	if (payMethod == 'A') cout << nl << "Change          : RM " << change << endl;
	if (payMethod == 'B') cout << nl << "Card Number     : " << cardNum << endl;
	if (isMember) cout << nl << "Discount (20%)  : RM " << discount << endl;
	cout << nl << "=========================================================================" << endl;
	cout << "Returning To Menu......" << endl;
	cout << nl << "Press Any Button To Return Menu " << endl;
	char conti = _getch();
}

/* Function - Login & Register */
static bool loginProcess(int userCount, int userID[], string userName[], string userPwd[]) {

	/* LOGIN */
	bool userFound = false;
	bool passMatch = false;
	int uid;
	int tempUserCount = 0;
	string username;
	string password;

	cout << breakline << endl << nl;
	if (userCount > 0) tempUserCount = userCount - 1;
	
	if (userName[tempUserCount] == "") {		// Check No Existing User
		cout << "No Membership Record Found. Please Register New Member" << endl;
		cout << nl << "Press Any Button To Return Menu " << endl;
		char conti = _getch();

	}
	else {
		do {
			cout << "USERNAME : ";
			cin >> username;
			for (int i = 0; i < userCount; ++i) {		// Check Existing User
				if (username == userName[i]) {
					uid = userID[i];
					userFound = true;
					break;
				}
			}
			if (!userFound) cout << "Invalid Username. Please Try Again!!" << nl << endl;

		} while (!userFound);

		do {
			cout << "PASSWORD : ";
			cin >> password;
			if (password == userPwd[uid]) passMatch = true;
			if (!passMatch) cout << "Invalid Password. Please Try Again!!" << nl << endl;

		} while (!passMatch);

		if (userFound && passMatch) {
			cout << breakline << endl;
			cout << "Welcome Back !!! " << userName[uid] << endl;
			cout << "----------------------------------------------------------------------------" << endl;
		}
	}
	return userFound;
}

static int registerProcess(int userCount, int MAX_USER, int userID[], string userName[], string userPwd[]) {

	/* REGISTER */
	if (userCount == MAX_USER - 1) {
		cout << "========================================" << endl;
		cout << "** Membership availability is FULL !! **" << endl;
		cout << "**     Try your luck next time ;)     **" << endl;
		cout << "========================================" << endl;
		cout << nl << "Press Any Button To Continue" << endl;
		char conti = _getch();
	}

	while (userCount < MAX_USER) {

		string username;
		string password;
		cout << breakline << endl << nl;
		cout << "Enter The Mandatory(**) Field :" << endl;
		cout << "** USERNAME : ";
		cin >> username;
		cout << "** PASSWORD : ";
		cin >> password;

		userID[userCount] = userCount;
		userName[userCount] = username;
		userPwd[userCount] = password;

		cout << "==========================================" << endl;
		cout << "** Membership registered successful !!! **" << endl;
		cout << "==========================================" << endl;
		cout << nl << "Press Any Button To Continue" << endl;
		char conti = _getch();
		userCount++;
		break;
	};

	return userCount;
}


int main() {

	/* Function */
	string itemSelected;
	string toppingSelected;
	string paymentSelected;
	string cardNum;
	double tempTotal = 0;
	double payAmt = 0;
	double taxTotal = 0;
	double sstTotal = 0;
	double subTotal = 0;
	double discount = 0;
	double change = 0; 
	char payMethod = ' ';
	char anotherOrder = ' ';
	char invalidToppings1 = ' ';
	char invalidToppings = ' ';
	char invalidFlavor1 = ' ';
	char invalidFlavor = ' ';
	char invalid = ' ';
	char invoice = ' ';
	int quantity = 0;
	int priceBase = 10;
	int pricePist = 15;
	int priceStraw = 20;
	int priceChoco = 25;
	int priceVanilla = 15;
	int priceSelected = 0;
	int priceBis = 5;
	int priceHoney = 5;
	int priceRainbow = 2;
	int priceSelectedToppings = 0;
	bool isMember = false;

	// Array Order Items Details
	int orderCount = 0;					// Count Total Order
	const int MAX_ORDERS = 5;			// Maximum of orders
	string items[MAX_ORDERS];			// Store Items Into Total
	string toppings[MAX_ORDERS];		// Store Toppings Into Total
	int quantities[MAX_ORDERS]{};		// Store Quantities Into Total
	double prices[MAX_ORDERS]{};		// Store Prices Into Total
	double discountPrice[MAX_ORDERS]{};
	string itemsOrdered[MAX_ORDERS];	// Store Ordered Items
	string toppingsOrdered[MAX_ORDERS]; // Store Selected Toppings
	int itemsPrices[MAX_ORDERS]{};		// Store Prices of Ordered Items
	int itemsQuantities[MAX_ORDERS]{};	// Store Quantities of Ordered Items

	// Array Login Details
	int userCount = 0;
	const int MAX_USER = 5;
	int userID[MAX_USER]{};
	string userName[MAX_USER];
	string userPwd[MAX_USER];

	/* PROGRAM START */

	logo();			// call out logo
	header();		// call out header
startOver:
	main_Menu();	// call out menu
	string opt_MainMenu = selectValidation(1, 4, Msg_selection);		// validation

	switch (stoi(opt_MainMenu)) {
	case 1:
		/* Order Menu */
		cout << nl << "You Selected Order Menu" << endl;

		do {
			flavor_Menu();
			string opt_flavor = selectValidation(1, 5, Msg_selection);		// validation

			if (stoi(opt_flavor) == 1) {
				priceSelected = priceBase;
				itemSelected = "Base Yogurt";
			}
			else if (stoi(opt_flavor) == 2) {
				priceSelected = pricePist;
				itemSelected = "Pistachio Yogurt";
			}
			else if (stoi(opt_flavor) == 3) {
				priceSelected = priceStraw;
				itemSelected = "Strawberry Yogurt";
			}
			else if (stoi(opt_flavor) == 4) {
				priceSelected = priceChoco;
				itemSelected = "Chocolate Yogurt";
			}
			else if (stoi(opt_flavor) == 5) {
				priceSelected = priceVanilla;
				itemSelected = "Vanilla Yogurt";
			}

			cout << nl << "You Have Selected " << itemSelected << " In Your Order" << endl;

			topping_Menu();
			char opt_Topping = alphaValidation('A', 'B', 'C');		// validation

			if (opt_Topping == 'A') {
				priceSelectedToppings = priceBis;
				toppingSelected = "Biscoff";
			}
			else if (opt_Topping == 'B') {
				priceSelectedToppings = priceHoney;
				toppingSelected = "Honey Syrup";
			}
			else if (opt_Topping == 'C') {
				priceSelectedToppings = priceRainbow;
				toppingSelected = "Rainbow Chocolate Rice";
			}

			cout << nl << "You Have Selected " << toppingSelected << " To Add-On Toppings" << endl;
			cout << nl << "The Price of Yogurt is : RM " << priceSelected << endl;
			cout << nl << "The Price of Add-On is : RM " << priceSelectedToppings << endl;
			cout << breakline << endl;
			cout << nl << "How Many Would You Like To Order?" << endl;
			cout << nl << "Quantity : ";
			cin >> quantity;
			//quantity = quantityValidation();

			// store array item info
			itemsOrdered[orderCount] = itemSelected;
			itemsPrices[orderCount] = priceSelected;
			discountPrice[orderCount] = discount;
			itemsQuantities[orderCount] = quantity;
			toppingsOrdered[orderCount] = toppingSelected;

			tempTotal += quantity * (priceSelected + priceSelectedToppings);

			// check maximum & next order
			if (orderCount == (MAX_ORDERS - 1)) {
				cout << nl << "Maximum Order Exceed!! [Max " << MAX_ORDERS << " Order / Person]" << endl;
				anotherOrder = 'N';
				cout << nl << "Press Any Button To Continue" << endl;
				char conti = _getch();
			}
			else {
				cout << breakline << endl;
				cout << nl << "Do You Want To Make Another Order? [Y/N]" << endl;
				cout << Msg_selection;
				anotherOrder = alphaValidation('Y', 'N');
			}

			orderCount++;

		} while (anotherOrder == 'Y');

		/* Calculation */
		taxTotal = (tempTotal * 0.06);
		sstTotal = (tempTotal * 0.08);
		if (isMember) subTotal = (tempTotal + taxTotal + sstTotal) * 0.8;
		else subTotal = (tempTotal + taxTotal + sstTotal);
		cout << nl << "Total Payable Amount : RM " << fixed << setprecision(2) << tempTotal << endl;
		cout << breakline << endl;
		cout << "inc Tax 6%      : RM " << fixed << setprecision(2) << taxTotal << endl;
		cout << "inc SST 8%      : RM " << fixed << setprecision(2) << sstTotal << endl;
		cout << "Sub Total (RM)  : RM " << fixed << setprecision(2) << subTotal << endl;
		cout << breakline << endl;
		if (isMember) {
			cout << "You Award 20% Discount" << endl;
			discount = (tempTotal + taxTotal + sstTotal) * 0.20 ;
		}

		/* Payment Method */
		payment_Menu();
		payMethod = alphaValidation('A', 'B');

		if (payMethod == 'A') {

			paymentSelected = "Cash";
			cout << nl << Msg_pytAmt;
			double payAmt = paymentValidation(subTotal);		// validation
			change = payAmt - subTotal;
			fineDisplay(change);
		}
		else {
			paymentSelected = "Credit Card";
			cout << nl << Msg_cardNo;
			cardNum = creditCardValidation();		// validation
		}

		cout << nl << "Do You Need a Invoice? [Y/N]" << endl << Msg_selection;
		invoice = alphaValidation('Y', 'N');

		/* Display Invoice */
		if (invoice == 'Y') invDisplay(orderCount, itemsOrdered, toppingsOrdered, itemsQuantities, itemsPrices, taxTotal, sstTotal, tempTotal, payMethod, change, cardNum,discount, isMember);
	
		return main();

	case 2:
		/* Customer Service */
		customerServDisplay(orderCount);
		goto startOver;

	
	case 3: {
		/* Logout */
		userlogin:
		login();		// call out login
		string opt_LoginMenu = selectValidation(1, 3, Msg_selection);		//validation

		switch (stoi(opt_LoginMenu)) {
		case 1: {
			bool userFound = loginProcess(userCount, userID, userName, userPwd);
			if (!userFound) goto userlogin;
			else isMember = true;
			goto startOver;
		}
		case 2:
			isMember = false;
			goto startOver;
			
		case 3:
			userCount = registerProcess(userCount, MAX_USER, userID, userName, userPwd);
			goto userlogin;
		}
	}
	case 4:
		/* Exit */
		logo();
		if (orderCount > 0) summaryDisplay(orderCount, itemsOrdered, toppingsOrdered, itemsQuantities, tempTotal);
		thankYou();
		break;
	}
	
	return 0;
}
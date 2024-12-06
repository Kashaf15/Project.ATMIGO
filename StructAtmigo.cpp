#include <iostream>
#include <string>
#include <iomanip>
#include<fstream>
using namespace std;

const int asize = 80;

// Struct to hold account holder's arrays
struct AccountArrays {
    string accountee;
    string pins;
    string complaints;
    string allianceResponse;
    float deposits;
    float totalAmount;
    float withdraws;
    float transferFunds;
    int securityThreats;
};

// Struct to hold account holder's variables
struct AccountVariables {
    int input;
    int i;
    int count;
    bool accounteeAuthenticity;
    string username;
    string pin;
    float temp;
    int loggedInUserType;
};

//Validations
bool validInput(bool isValid, string inputStr,int &input);
bool validPin(bool isValid,string &pin);
bool validFloat(string &input);

//Conversion
float stringToFloat(string &input);

//Interface Functions
void displayAtmigo();//Function to display the Interface
int showMenu(AccountVariables &v);//Main Menu Function
int adminLogIn(AccountVariables &v);//Admin Login Function
int accounteeLogIn(AccountVariables &v, const int asize,AccountArrays a[]);//Account Holder Login Function
int showAdminMenu(AccountVariables &v);//Admin Menu Function
int showAccounteeMenu(AccountVariables &v);//Account Holder Menu Function

//Input Data
void inputData(AccountArrays a[],const int asize);

//Load Data function
void loadData(AccountArrays a[], const int asize);


//Admin Functions
void addUser(AccountVariables &v, const int asize, AccountArrays a[]) ;//Add User Function
void removeUser(const int asize,AccountArrays a[]);//Remove User Function
void updateUser(const int asize,AccountArrays a[]);//Update User Function
void totalUser(const int asize, AccountArrays a[]);//Total Users List Function
void securityThreat(const int asize, AccountArrays a[]);//Security Threats Function
void transactionHistory(const int asize, AccountArrays a[]);//Transaction history Function
void customerAlliance(const int asize,AccountArrays a[]);//Customer Support Function


//Account Holder Functions
void cashDeposit(int index, AccountArrays a[]);//Cash Deposit Function
void cashWithdraw(int index,AccountArrays a[]);//Cash Withdrawl Function
void cashWithdrawalMultiCurrency(int index, AccountArrays a[]);//Cash withdrawl through multiCurrency Function
void cashDepositMultiCurrency(int index, AccountArrays a[]);//Cash Deposit through multiCurrency Function
void fundsTransfer(int index, const int asize, AccountArrays a[]);//Transfer Funds to another account Holder Function
void accountBalanceCheck(int index, AccountArrays a[]);//Account Balance Check Function
void accounteeTransactionHistory(int index, AccountArrays a[]);//Account holder transaction history function
void threatAlert(int index, AccountArrays a[]);//Threat Notification to account Holder
void feedback(int index, AccountArrays a[]);//Feedback Function

//The User Name and Paasword for Admin iS "Admin" and "1234" respectively
int main()
{

    // Initialize account variables with default values
    AccountVariables v;
    v.input = 0;
    v.i = 0;
    v.count = 0;
    v.accounteeAuthenticity = false;
    v.username = "";
    v.pin = "";
    v.temp = 0.0;
    v.loggedInUserType = -10; // 1 for administrator, 2 for user

    AccountArrays a[asize];
    //File Handling Function Call
    inputData(a,asize);
    
    // Initialize account arrays with default values
    
    for (int i = 0; i < asize; i++) {
        a[i].accountee = "";
        a[i].pins = "";
        a[i].complaints = "";
        a[i].allianceResponse= "";
        a[i].deposits = 0.0;
        a[i].totalAmount = 0.0;
        a[i].withdraws = 0.0;
        a[i].transferFunds = 0.0;
        a[i].securityThreats = 0;
    }

    // program header
    displayAtmigo();
    cout << endl;

    do
    {
        cout << endl;
        v.input=showMenu(v);
        switch (v.input)
        {
        case 1: 
        {
            // Admin login
            v.loggedInUserType = adminLogIn(v);
            break;
        }

        case 2:
        {
            v.loggedInUserType=accounteeLogIn(v,asize,a);
            break;
        }
        case 0:
        {
            v.loggedInUserType = -10;
            cout << "------------->>>>>>The System has been Exited<<<<<<-------------" << endl;
            break;
        }
        default:
            cout << "Invalid choice!!!"<<endl;
            break;
        }

        if (v.loggedInUserType == 1) // administrator
        {
            do
            {
                switch (showAdminMenu(v))
                {
                case 1:
                {
                    addUser(v,asize,a);
                    break;
                }
                case 2:
                {
                    removeUser(asize,a);
                    break;
                }
                case 3:
                {
                    updateUser(asize,a);
                    break;
                }
                case 4:
                {
                    totalUser(asize,a);
                    break;
                }
                case 5:
                {
                    securityThreat(asize,a);
                    break;
                }
                case 6:
                {
                    transactionHistory(asize,a);
                    break;
                }
                case 7:
                {
                    customerAlliance(asize,a);
                    break;
                }
                case 0:
                    cout <<endl<< "         Administrator is logged out!!" << endl;
                    break;

                default:
                    cout << "Invalid choice!!!"<<endl;
                    break;
                }
            } while (v.input != 0);
            v.input = -1; // this statment is to make sure that do not exit from outer loop
        }
        else if (v.loggedInUserType == 2)
        {
           for (int index = 0; index < asize; index++)
            {
                if (v.username == a[index].accountee && v.pin == a[index].pins) 
                {
                    do
                    {   
                    switch (showAccounteeMenu(v))
                    {

                        case 1:
                        {
                            cashDeposit(index,a);
                            break;
                        }
                        case 2:
                        {
                            cashWithdraw(index,a);
                            break;
                        }
                        case 3:
                        {
                            cashWithdrawalMultiCurrency(index, a);
                            break;
                        }
                        case 4:
                        {
                            cashDepositMultiCurrency(index,a);
                            break;
                        }
                        case 5:
                        {
                            fundsTransfer(index,asize,a);
                            break;
                        }
                        case 6:
                        {
                            accountBalanceCheck(index, a);
                            break;
                        }
                        case 7:
                        {
                            accounteeTransactionHistory(index, a);
                            break;
                        }
                        case 8:
                        {
                            threatAlert(index,a);
                            break;
                        }
                        case 9:
                        {
                            feedback(index,a);
                            break;
                        }
                        case 0:
                            cout <<endl<< "          You are logged out!!         " << endl;
                            break;
                        default:
                        cout << "Invalid choice!!!"<<endl;
                        break;
                    }
                    } while (v.input != 0);

                }
            }
            v.input = -1; // this statment is to make sure that do not exit from outer loop
        }
        else if (v.loggedInUserType == -1)
        {
            cout << "You have entered invalid Credentials!!!" << endl;
        }
    } while (v.input != 0);
    loadData(a,asize);
    return 0;
}
// Function Implementations
bool validInput(bool isValid, string inputStr,AccountVariables &v) {
    // Validate that the input is numeric
    isValid = true;

    for (int i = 0; i < inputStr.length(); i++) {
        if (inputStr[i] < '0' || inputStr[i] > '9') {
            isValid = false; // Non-digit character found
            break;
        }
    }

    if (!isValid) {
        cout << "Invalid input! Please enter a valid number." << endl;
    } else {
        // Convert the valid string to an integer
        v.input = 0;
        for (int i = 0; i < inputStr.length(); i++) {
            v.input = v.input * 10 + (inputStr[i] - '0');
        }

        // Check if the input is within the valid range
        if (v.input < 0 || v.input > 9) {
            isValid = false;
            cout << "Invalid input!" << endl;
        }
    }
    return isValid;
}
bool validPin(bool isValid,string &pin)
{
    while (!isValid) {
        cout << "Enter a 4-digit PIN: ";
        cin >> pin;

        // Validate length
        if (pin.length() != 4) {
            cout << "PIN must be exactly 4 digits long. Try again." << endl;
            continue;
        }

        // Validate all characters are digits
        isValid = true; // Assume valid initially
        for (int i = 0; i < 4; i++) {
            if (pin[i] < '0' || pin[i] > '9') { // Check if character is not a digit
                cout << "PIN must contain only numeric digits. Try again." << endl;
                isValid = false;
                break;
            }
        }
    }
    return isValid;
}
void displayAtmigo() {
    system("cls");
    system("Color 06");
    cout << " __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __  " << endl;
    cout << "|                                                                 |" << endl;
    cout << "|     ___      ____    __  __      _____      ____     ______     |" << endl;
    cout << "|    /___\\    (_  _)  (  \\/  )    (_   _)    / ___)   (   _  )    |" << endl;
    cout << "|   /(___)\\     )(     )    (      _) (_    ( (_ -.    ) (_)(     |" << endl;
    cout << "|  (__) (__)   (__)   (_/\\/\\_)    (_____)    \\____/   (______)    |" << endl;
    cout << "|                                                                 |" << endl;
    cout << "|__ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __|" << endl;
    return;
}

int showMenu(AccountVariables &v) {
    cout << "------------------->>>>> Sign In Options <<<<<<---------------------" << endl;
    cout << "1. Administrator\n2. Account Holder\n0. Exit" << endl;
    
    bool isValid = false;
    string inputStr;
    do{
        cout << "Enter a number: ";
        cin >> inputStr;
        isValid=validInput(isValid,inputStr,v);
    }
    while(!isValid);
    return v.input;
}

int adminLogIn(AccountVariables &v) {
    system("cls");
    cout << "----------------->>>>>>Administrator Log-IN<<<<<<----------------" << endl;
    cout << " ________________" << endl;
    cout << "| Enter Username:|";
    cin.ignore(1000, '\n');
    getline(cin, v.username);
    cout << endl;
    cout << " ___________" << endl;
    cout << "| Enter Pin:|";
    cin >> v.pin;
    cout << endl;

    if (v.username == "Admin" && v.pin == "1234") {
        v.loggedInUserType = 1; // Admin logged in
    } else {
        v.loggedInUserType = -1; // Invalid credentials
    }
    return v.loggedInUserType;
}

int accounteeLogIn(AccountVariables &v, const int asize,AccountArrays a[]) {
    system("cls");
    cout << "----------------->>>>>>Accountee Log-IN<<<<<<----------------" << endl;
    cout << " ________________" << endl;
    cout << "| Enter Username:|";
    cin.ignore(1000, '\n');
    getline(cin, v.username);
    cout << endl;
    cout << " ___________" << endl;
    cout << "| Enter Pin:|";
    cin >> v.pin;
    cout << endl;

    for (int i = 0; i < asize; i++) {
        if (v.username == a[i].accountee && v.pin == a[i].pins) {
            v.accounteeAuthenticity = true;
            break;
        }
        if (v.username == a[i].accountee && v.pin != a[i].pins) {
            a[i].securityThreats++;
        }
    }

    v.loggedInUserType = v.accounteeAuthenticity ? 2 : -1;
    return v.loggedInUserType;
}

int showAdminMenu(AccountVariables &v) {
    cout << "-------------->>>>>> Administrator Menu <<<<<<-------------------" << endl<<endl;
    cout <<"1. Add User\n2. Remove User\n3. Update User\n4. Total Users \n5. Threat Warnings \n6. Transaction History\n7. Assistance Alliance\n0. Log out" << endl;
    
    bool isValid = false;
    string inputStr;
    do{
        cout << "Enter a number: ";
        cin >> inputStr;
        isValid=validInput(isValid,inputStr,v);
    }
    while(!isValid);
    system("cls");
    return v.input;
}
int showAccounteeMenu(AccountVariables &v)
{
    cout << "-------------->>>>>>accounteeountee Menu<<<<<<<-------------------" << endl;
    cout << endl;
    cout << "1. Cash Deposit\n2. Cash Withdrawl\n3. Multi-Currency Withdrawl\n4. MultiCurrency Deposit\n5. Funds Transfer\n6. Accountee Statement\n7. Transaction History\n8. Accountee Threat Alerts\n9. Feedback\n0. Sign out" << endl;
    
    bool isValid = false;
    string inputStr;
    do{
        cout << "Enter a number: ";
        cin >> inputStr;
        isValid=validInput(isValid,inputStr,v);
    }
    while(!isValid);

    system("cls");
    return v.input;
}
void addUser(AccountVariables &v, const int asize, AccountArrays a[]) 
{
    system("cls");
    cout << "----------------->>>>>>Add User<<<<<<----------------" << endl<<endl;
    if (v.count >= asize) {
        cout << "No more space for additional users." << endl;
        return;
    }

    cin.ignore(1000, '\n'); // Clear input buffer
    cout << "Enter Account Holder's Name: ";
    getline(cin, a[v.count].accountee);

    // Custom PIN validation

    string pin="";
    bool isValid = false;
    do{
        isValid=validPin(isValid,pin);
    }
    while(!isValid);
    a[v.count].pins = pin; // Store the validated PIN

    //ammount validation
    string input;
    bool isValidFloat=false;
    do 
    {
        cout << "Enter total Amount in the Account in Pkr: ";
        cin >> input;

        isValidFloat = validFloat(input);

        if (!isValidFloat) {
            cout << "Invalid input. Please enter a valid amount" << endl;
        }
        cin.clear();

    } while (!isValidFloat);
    a[v.count].totalAmount = stringToFloat(input);
    v.count++;
    cout << "User added successfully!" << endl;
    return;
}
float stringToFloat(string &input) {
    float result = 0.0;
    float fractionPart = 0.0;
    bool isFraction = false;
    float divisor = 10.0;

    // Loop through each character in the string
    for (int i = 0; i < input.length(); i++) {
        char c = input[i];

        if (c == '.') {
            isFraction = true; // Switch to processing the fractional part
            continue;
        }

        // Calculate the integer or fractional part
        if (!isFraction) {
            result = result * 10 + (c - '0'); // Build the integer part
        } else {
            fractionPart += (c - '0') / divisor; // Build the fractional part
            divisor *= 10;
        }
    }

    return result + fractionPart; // Combine integer and fractional parts
}
bool validFloat(string &input) {
    bool hasDecimalPoint = false; // To track if there's a decimal point

    // Check if the input is empty
    if (input.empty()) {
        return false;
    }

    // Handle the first character (it could be + or - or a digit)
    int startIndex = 0;
    if (input[0] == '+' || input[0] == '-') {
        startIndex = 1; // If it starts with + or -, we start checking from the next character
    }

    // Loop through each character in the string, starting from the second character if there's a sign
    for (int i = startIndex; i < input.length(); i++) {
        char c = input[i];


        // Check for a decimal point
        if (c == '.') {
            if (hasDecimalPoint) { // More than one decimal point is invalid
                return false;
            }
            hasDecimalPoint = true;
            continue; // Skip the decimal point check for the next character
        }

        // Check if the character is a digit (valid digits 0-9)
        if (c < '0' || c > '9') {
            return false; // Invalid character found (not a digit)
        }
    }

    // Ensure the input is not just a sign or decimal point
    if (input == "+" || input == "-" || input == "." || input == "+." || input == "-.") {
        return false;
    }

    return true; // Input passes all checks
}
void removeUser(const int asize,AccountArrays a[])
{
    system("cls");
//Remove User Functionalities
    cout << "----------------------->>>>>>Remove User<<<<<<--------------------------" << endl;
    string choice;//to ask from administrator user's name
    bool accounteeFound = false;
    cout << "Enter The Account Holder's Name to remove: ";
    getline(cin, choice);
    cin.ignore();
    for (int i = 0; i < asize; i++)
    {
        if (choice == a[i].accountee)
        {
            a[i].accountee = "";
            a[i].pins = "";
            a[i].totalAmount=0;
            accounteeFound = true;
            cout << "Account removed successfully!!\n";
            break;
            }
    }
    //to check if the user exists
    if (!accounteeFound)
    {
    cout << "User Doesn't Exist Yet!!" << endl
    << endl;
    }
    return;
}
void updateUser(const int asize,AccountArrays a[])
{
    system("cls");
//Updating user portal
    cout << "----------------------->>>>>>Update User<<<<<<--------------------------" << endl;
    string choice;
    bool accounteeFound = false;
    cin.ignore(1000, '\n');
    cout << "Enter the Account Holder's name to update:";
    getline(cin, choice);
    for (int i = 0; i < asize; i++)
    {
        if (choice == a[i].accountee)
        {
            cin.ignore(1000, '\n');
            cout << "Enter new name for accountee: ";
            getline(cin, a[i].accountee);
            cout << "Enter new pin: ";
            cin >> a[i].pins;
            accounteeFound = true;
            cout << "Account Updated successfully!!\n";
            break;
        }
    }
    //searching user to update
    if (!accounteeFound)
    {
    cout << "User Doesn't Exist Yet!!" << endl
     << endl;
    }
    return;
}
void totalUser(const int asize, AccountArrays a[]) {
    // Total Users List
    cout << "----------------------->>>>>> Total Users <<<<<<--------------------------" << endl;

    bool accounteeExists = false;
    cout << setw(30) << left << "Account Holder Names" 
         << setw(10) << right << "PIN Code" << endl
         << "---------------------------------------------" << endl;

    for (int i = 0; i < asize; i++) {
        if (!a[i].accountee.empty()) { // Skip empty entries
            cout << setw(30) << left << a[i].accountee
                 << setw(10) << right << a[i].pins << endl;
            accounteeExists = true;
        }
    }

    // Checking if any user exists
    if (!accounteeExists) {
        cout << "\nNo Account Holders Yet!\n" << endl;
    }

    cout << "---------------------------------------------------------------------" << endl;
    return;
}
void securityThreat(const int asize, AccountArrays a[])
{
    // Security Threat Notifications
    bool threatMade = false;

    cout << "----------------------->>>>>> Security Complaints <<<<<<--------------------------" << endl
         << endl;
    cout << "....................................................................." << endl;

    for (int i = 0; i < asize; i++)
    {
        if (a[i].securityThreats != 0)
        {
            cout << "An Unauthorized Person tried to break into account number 1212-UBL-234" 
                 << i + 1 
                 << " under the Account Holder's Name: " << a[i].accountee 
                 << " " << a[i].securityThreats 
                 << " times but Failed!!\nKindly Look into that!!" << endl;
            cout << endl;
            cout << "....................................................................." << endl;
            threatMade = true;
        }
    }

    if (!threatMade)
    {
        cout << "No Threat Made to Any Account Yet!!" << endl << endl;
    }
    return;
}
void transactionHistory(const int asize, AccountArrays a[])
{
    // Transaction History Portal
    bool transactionMade = false;

    cout << "----------------------->>>>>> Transaction History <<<<<<--------------------------" << endl
         << endl;
    cout << "********************************************************************************" << endl;
    cout << "The transaction history of all accounts listed below:" << endl;

    for (int i = 0; i < asize; i++)
    {
        if (a[i].withdraws != 0)
        {
            cout << "Transaction made by ACC No. 111-UBL-231" << (i + 1) 
                 << " under the Account Holder name: " << a[i].accountee << endl
                 << " Dated on September, " << i + 11 
                 << " 2024 was Pkr. " << a[i].withdraws << endl;
            cout << "********************************************************************************" << endl;
            transactionMade = true;
        }
    }

    // To check if any transaction has been made
    if (!transactionMade)
    {
        cout << "No Transaction Made by Any User Yet!!" << endl;
    }
    return;
}
void customerAlliance(const int asize,AccountArrays a[])
{
    bool feedback=false;
    // Feedback Portal
    cout << "----------------------->>>>>> Feedback <<<<<<--------------------------" << endl
         << endl;

    for (int i = 0; i < asize; i++)
    {
        if (a[i].complaints != "")
        {
            cout << "Feedback: " << a[i].complaints << endl;
            cout << "Response: ";
            cin.ignore(1000, '\n');
            getline(cin, a[i].allianceResponse);
            feedback=true;
        }
    }
    if(!feedback)
    {
        cout<<"No Complaints Registered Yet!!"<<endl<<endl;
    }
    cout << "........................................................................" << endl;
    return;
}
void cashDeposit(int index, AccountArrays a[])
{
    system("cls");
    cout << "---------------------------->>>>>>>>Cash Deposit<<<<<<<<--------------------------" << endl
         << endl;

    string input;
    bool isValidFloat=false;
    do 
    {
        cout << "Enter the amount you want to deposit (Maximum: Rs. 50000 && Minimum: Rs. 1000): Pkr. ";
        cin >> input;

        isValidFloat = validFloat(input);

        if (!isValidFloat) {
            cout << "Invalid input. Please enter a valid amount" << endl;
        }
        cin.clear();

    } while (!isValidFloat);
    a[index].deposits = stringToFloat(input);

    if (a[index].deposits < 1000)
    {
        cout << "The Amount is too low to deposit!!" << endl;
    }
    else if (a[index].deposits > 50000)
    {
        cout << "The Amount is exceeding the limit!" << endl;
    }
    else if (a[index].deposits >= 1000 && a[index].deposits <= 50000)
    {
        a[index].totalAmount += a[index].deposits;
        cout << "Amount entered in your account successfully!!" << endl;
    }
    else
    {
        cout << "Invalid Input!!" << endl;
    }

    cout << "............................................................................" << endl
         << endl;
    return;
}
void cashWithdraw(int index,AccountArrays a[])
{
    system("cls");
    cout << "--------------------------->>>>>>>>Cash Withdraw<<<<<<<<-------------------------" << endl
         << endl;

    string input;
    bool isValidFloat=false;
    do 
    {
        cout << "Enter the amount you want to withdraw (Maximum: Rs. 50000 && Minimum: Rs. 1000): Pkr. ";
        cin >> input;

        isValidFloat = validFloat(input);

        if (!isValidFloat) {
            cout << "Invalid input. Please enter a valid amount" << endl;
        }
        cin.clear();

    } while (!isValidFloat);
    a[index].withdraws = stringToFloat(input);
    
    if(a[index].withdraws>a[index].totalAmount)
    {
        cout<<"No Sufficient balance to make this Withdrawl!!"<<endl;
    }
    else if (a[index].withdraws < 1000)
    {
        cout << "The Amount is too low to withdraw!!" << endl;
    }
    else if (a[index].withdraws > 50000)
    {
        cout << "The Amount is exceeding the limit!" << endl;
    }
    else if (a[index].withdraws >= 1000 && a[index].withdraws <= 50000 && a[index].withdraws <= a[index].totalAmount)
    {
        a[index].totalAmount -= a[index].withdraws;
        cout << "Amount withdrawn from your account successfully!!" << endl;
    }
    else
    {
        cout << "Insufficient balance for this withdrawal!!" << endl;
    }

    cout << ".................................................................................." << endl
         << endl;
    return;
}
void cashWithdrawalMultiCurrency(int index, AccountArrays a[]) {
    system("cls");
    // Multi Currency Withdrawal
    cout << "-------------------------->>>>>>>>Multi Currency Withdraw<<<<<<<<--------------------------" << endl << endl;

    int choice;
    cout << "Choose your Currency for Cash Withdrawal (1 for USD, 2 for SAR): ";
    cin >> choice;
    cout << endl;

    if (choice == 1) {
        // USD Withdrawal

        string input;
        bool isValidFloat=false;
        do 
        {
            cout << "Enter the amount you want to Withdraw (Max: $5000, Min: $500):";
            cin >> input;

            isValidFloat = validFloat(input);

            if (!isValidFloat) {
            cout << "Invalid input. Please enter a valid amount" << endl;
            }
            cin.clear();

        } while (!isValidFloat);
        a[index].withdraws = stringToFloat(input);

        if((a[index].withdraws*300)>a[index].totalAmount)
        {
            cout<<"No Sufficient balance to make this Withdrawl!!"<<endl;
        }
        else if (a[index].withdraws < 500) {
            cout << "The Amount is too low to Withdraw!!" << endl;
        } else if (a[index].withdraws > 5000) {
            cout << "The Amount is exceeding the Limit!!" << endl;
        } else if (a[index].withdraws >= 500 && a[index].withdraws <= 5000) {
            a[index].withdraws = a[index].withdraws * 300;
            a[index].totalAmount -= a[index].withdraws;
            cout << "The Amount has been Withdrawn from your Account Successfully!!" << endl;
        } else {
            cout << "Invalid Input!!" << endl;
        }
    } else if (choice == 2) {
        // SAR Withdrawal

        string input;
        bool isValidFloat=false;
        do 
        {
            cout << "Enter the amount you want to Withdraw (Max: SAR 10000, Min: SAR 1000): SAR ";
            cin >> input;

            isValidFloat = validFloat(input);

            if (!isValidFloat) {
            cout << "Invalid input. Please enter a valid amount" << endl;
            }
            cin.clear();

        } while (!isValidFloat);
        a[index].withdraws = stringToFloat(input);

        if((a[index].withdraws*80)>a[index].totalAmount)
        {
            cout<<"No Sufficient balance to make this Withdrawl!!"<<endl;
        }
        else if (a[index].withdraws < 1000) {
            cout << "The Amount is too low to Withdraw!!" << endl;
        } else if (a[index].withdraws > 10000) {
            cout << "The Amount is exceeding the Limit!!" << endl;
        } else if ((a[index].withdraws >= 1000) && (a[index].withdraws <= 10000) && (a[index].withdraws < (a[index].totalAmount / 80))) {
            a[index].withdraws = a[index].withdraws * 80;
            a[index].totalAmount -= a[index].withdraws;
            cout << "The Amount has been Withdrawn from your Account Successfully!!" << endl;
        } else {
            cout << "Invalid Input!!" << endl;
        }
    } else {
        cout << "Invalid Input!!" << endl;
    }

    cout << ".................................................................................." << endl;
    return;
}
void cashDepositMultiCurrency(int index, AccountArrays a[])
{
    system("cls");
    // Deposit for MultiCurrency
    cout << "------------------------->>>>>>>> Multi Currency Deposit <<<<<<<<-----------------------" << endl
         << endl;

    int choice;
    cout << "Choose your Currency for Cash Deposit (choose 1 for USD / 2 for SAR): ";
    cin >> choice;
    cout << endl;

    if (choice == 1)
    {
        cout << "Enter the amount you want to Deposit (Maximum: $5000 && Minimum: $500): $ ";
        cin >> a[index].deposits;

        string input;
        bool isValidFloat=false;
        do 
        {
            cout << "Enter the amount you want to deposit (Max: $5000, Min: $500):";
            cin >> input;

            isValidFloat = validFloat(input);

            if (!isValidFloat) {
            cout << "Invalid input. Please enter a valid amount" << endl;
            }
            cin.clear();

        } while (!isValidFloat);
        a[index].deposits = stringToFloat(input);

        if (a[index].deposits < 500)
        {
            cout << "The Amount is too low to deposit!!" << endl;
        }
        else if (a[index].deposits > 5000)
        {
            cout << "The Amount is exceeding the Limit!!" << endl;
        }
        else
        {
            a[index].deposits = a[index].deposits / 300; // Assuming 300 is the exchange rate
            a[index].totalAmount += a[index].deposits;
            cout << "The Amount has been deposited in your Account Successfully!!" << endl;
        }
    }
    else if (choice == 2)
    {
        cout << "Enter the amount you want to Deposit (Maximum: SAR 10000 && Minimum: SAR 1000): SAR ";
        cin >> a[index].deposits;

        string input;
        bool isValidFloat=false;
        do 
        {
            cout << "Enter the amount you want to Deposit (Maximum: SAR 10000 && Minimum: SAR 1000): SAR ";
            cin >> input;

            isValidFloat = validFloat(input);

            if (!isValidFloat) {
            cout << "Invalid input. Please enter a valid amount" << endl;
            }
            cin.clear();

        } while (!isValidFloat);
        a[index].deposits = stringToFloat(input);

        if (a[index].deposits < 1000)
        {
            cout << "The Amount is too low to deposit!!" << endl;
        }
        else if (a[index].deposits > 10000)
        {
            cout << "The Amount is exceeding the Limit!!" << endl;
        }
        else
        {
            a[index].deposits = a[index].deposits / 80; // Assuming 80 is the exchange rate
            a[index].totalAmount += a[index].deposits;
            cout << "The Amount has been deposited in your Account Successfully!!" << endl;
        }
    }
    else
    {
        cout << "Invalid Input!!" << endl;
    }

    cout << ".................................................................................." << endl;
    return;
}
void fundsTransfer(int index, const int asize, AccountArrays a[]) 
{
    system("cls");
    // Funds Transfer
    cout << "------------------------>>>>>>>> Funds Transfer <<<<<<<<-----------------------" << endl
         << endl;

    string accounteeName, currency;
    int choice;
    bool accounteeFound = false;

    cout << "Enter the Name of Account Holder you want to transfer funds to: ";
    cin >> accounteeName;
    cout << endl;

    // Loop through accounts to find matching accountee
    for (int i = 0; i < asize; i++) 
    {
        if (accounteeName == a[i].accountee) 
        {
            accounteeFound = true;
            cout << "The Account Number 1212-UBL-234" << i + 1 << " has been found under Account Holder's Name: " << accounteeName << "." << endl;

            cout << "Choose the currency (Pkr, USD, SAR): ";
            cin >> currency;

            // Input validation for currency type
            if (currency != "Pkr" && currency != "USD" && currency != "SAR") 
            {
                cout << "Invalid currency choice!! Please select a valid currency (Pkr, USD, SAR)." << endl;
                return; // exit if invalid currency
            }

            // Enter amount to transfer

            string input;
            bool isValidFloat=false;
            do 
            {
                cout << "Enter the amount you want to transfer:  ";
                cin >> input;

                isValidFloat = validFloat(input);

                if (!isValidFloat) {
                cout << "Invalid input. Please enter a valid amount" << endl;
                }
                cin.clear();

            } while (!isValidFloat);
            a[index].transferFunds = stringToFloat(input);

            cout << endl;

            // Validate amount is not negative or zero
            if (a[index].transferFunds <= 0) 
            {
                cout << "Invalid amount! Please enter a positive value." << endl;
                return; // exit if invalid amount
            }

            // Check if the user has enough balance to transfer
            if (a[index].transferFunds > a[index].totalAmount) 
            {
                cout << "Insufficient balance! You only have Pkr " << a[index].totalAmount << " in your account." << endl;
                return; // exit if insufficient balance
            }

            // Currency-wise transfer logic
            if (currency == "Pkr") 
            {
                cout << "Are you sure you want to transfer Pkr. " << a[index].transferFunds
                     << " to the Account Holder ID 1212-UBL-234" << i + 1 << " (1/0)? ";
                cin >> choice;
                cout << endl;

                if (choice == 1) 
                {
                    a[index].totalAmount -= a[index].transferFunds;
                    a[i].totalAmount += a[index].transferFunds;
                    cout << "The Amount Pkr. " << a[index].transferFunds 
                         << " has been transferred to the Account Holder ID 1212-UBL-234" << i + 1 
                         << " Successfully!!" << endl;
                } 
                else if (choice == 0) 
                {
                    cout << "Thank you for your Cooperation!!" << endl;
                } 
                else 
                {
                    cout << "Invalid Input!!" << endl;
                }
            } 
            else if (currency == "USD") 
            {
                cout << "Are you sure you want to transfer $ " << a[index].transferFunds 
                     << " to the Account Holder ID 1212-UBL-234" << i + 1 << " (1/0)? ";
                cin >> choice;
                cout << endl;

                if (choice == 1) 
                {
                    a[index].totalAmount -= (a[index].transferFunds * 300); // Assuming exchange rate is 300
                    a[i].totalAmount += (a[index].transferFunds * 300);
                    cout << "The Amount $ " << a[index].transferFunds 
                         << " has been transferred to the Account Holder ID 1212-UBL-234" << i + 1 
                         << " Successfully!!" << endl;
                } 
                else if (choice == 0) 
                {
                    cout << "Thank you for your Cooperation!!" << endl;
                } 
                else 
                {
                    cout << "Invalid Input!!" << endl;
                }
            } 
            else if (currency == "SAR") 
            {
                cout << "Are you sure you want to transfer SAR " << a[index].transferFunds 
                     << " to the Account Holder ID 1212-UBL-234" << i + 1 << " (1/0)? ";
                cin >> choice;

                if (choice == 1) 
                {
                    a[index].totalAmount -= (a[index].transferFunds * 80); // Assuming exchange rate is 80
                    a[i].totalAmount += (a[index].transferFunds * 80);
                    cout << "The Amount SAR " << a[index].transferFunds 
                         << " has been transferred to the Account Holder ID 1212-UBL-234" << i + 1 
                         << " Successfully!!" << endl;
                } 
                else if (choice == 0) 
                {
                    cout << "Thank you for your Cooperation!!" << endl;
                } 
                else 
                {
                    cout << "Invalid Input!!" << endl;
                }
            }

            break; // Exit the loop once the accountee is found and processed
        }
    }

    // If accountee is not found
    if (!accounteeFound) 
    {
        cout << "Error: The Customer ID cannot be Found!!" << endl;
    }

    cout << ".................................................................................." << endl
         << endl;
    return;
}
void accountBalanceCheck(int index, AccountArrays a[])
{
    system("cls");
    cout << "------------------------->>>>>>>> Account Balance <<<<<<<<<<--------------------" << endl
         << endl;

    cout << "||||||||||||||||||||||||||||||||||||" << endl;
    cout << "                LAHORE              " << endl
         << endl;
    cout << "11/10/2024       11:57:03      0076" << endl;
    cout << "        ACCOUNT BALANCE DETAILS    " << endl
         << endl;

    cout << "Card No: 52967*********6328\n"
         << "Account No.: 54533******4343\n"
         << "STAN: 78786" << endl
         << endl;

    cout << "Available Balance: PKR " << a[index].totalAmount << endl
         << endl;

    cout << "               THANK YOU            " << endl
         << endl;

    cout << "||||||||||||||||||||||||||||||||||||" << endl
         << endl;

    cout << ".................................................................................." << endl
         << endl;
    return;
}
void accounteeTransactionHistory(int index, AccountArrays a[])
{
    system("cls");
    // To check transaction history
    cout << "---------------------->>>>>>>> Transaction History <<<<<<<<-------------------" << endl
         << endl;

    cout << "Below is a detailed record of your last transaction, including date and amount." << endl;
    cout << ".................................................................................." << endl
         << endl;

    if (a[index].withdraws != 0 || a[index].deposits != 0 || a[index].transferFunds != 0)
    {
        // Check withdrawals
        if (a[index].withdraws != 0)
        {
            if (a[index].withdraws > 50000)
            {
                cout << "The Amount " << a[index].withdraws << " has been withdrawn from your Account\n"
                     << "through International Currency on September " << index + 1 << ", 2024." << endl;
            }
            else
            {
                cout << "The Amount PKR " << a[index].withdraws << " has been withdrawn from your\n"
                     << "Account on September " << index + 1 << ", 2024." << endl;
            }
            cout << ".................................................................................." << endl;
        }

        // Check deposits
        if (a[index].deposits != 0)
        {
            if (a[index].deposits > 50000)
            {
                cout << "The Amount " << a[index].deposits << " has been deposited to your Account\n"
                     << "through International Currency on September " << index + 2 << ", 2024." << endl;
            }
            else
            {
                cout << "The Amount PKR " << a[index].deposits << " has been deposited to your\n"
                     << "Account on September " << index + 2 << ", 2024." << endl;
            }
            cout << ".................................................................................." << endl;
        }

        // Check transfers
        if (a[index].transferFunds != 0)
        {
            if (a[index].transferFunds < 50000)
            {
                cout << "The Amount " << a[index].transferFunds << " has been transferred from your Account\n"
                     << "through International Currency on September " << index + 4 << ", 2023." << endl;
            }
            else
            {
                cout << "The Amount PKR " << a[index].transferFunds << " has been transferred from your\n"
                     << "Account on September " << index + 4 << ", 2023." << endl;
            }
            cout << ".................................................................................." << endl;
        }
    }
    else
    {
        cout << "No Transactions Made Yet!!" << endl;
        cout << ".................................................................................." << endl
             << endl;
    }
    return;
}
void threatAlert(int index, AccountArrays a[])
{
    system("cls");
    // Security Threats to your Account
    cout << "------------------------>>>>>>>> Security Threats <<<<<<<<-------------------" << endl
         << endl;

    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "An Unauthorized Person tried to break into your account " 
         << a[index].securityThreats << " times but Failed!!" << endl;
    cout << "Be Careful to whom you share your PIN with!!" << endl;
    cout << endl;

    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl
         << endl;
    return;
}
void feedback(int index, AccountArrays a[])
{
    system("cls");
    // Feedback
    cout << "----------------->>>>>> Feedback Portal <<<<<<----------------" << endl;
    cout << "Enter your Feedback: ";
    cin.ignore(1000, '\n'); // To handle newline characters in the input buffer
    getline(cin, a[index].complaints);
    cout << endl
         << endl;

    cout << "...................Thank you for using our ATM.................." << endl
         << endl;

    // Display response to previous feedback if available
    if (a[index].allianceResponse != "")
    {
        
        cout << "Response to your previous feedback:" << endl;
        cout << "............................................................................." << endl
             << endl;
        cout << a[index].allianceResponse << endl;
        cout << "............................................................................." << endl
             << endl;
    }
    return;
}
void loadData(AccountArrays a[], const int asize) {

    ofstream fout("OutputData.txt");
    if (!fout.is_open()) {
        cout << "Unable to open file" << endl; // Fixed missing operator
        return;
    }

    // Write the header to the file
    fout << "Accountee\tPIN\tComplaint\tAlliance Response\tSecurity Threats\tDeposits\tTotal Amount\tWithdrawals\tTransfer Funds\n";
    
    // Write each account's data to the file
    for (int i = 0; i < asize; i++) {
        if (!a[i].accountee.empty()) { // Skip empty records
            fout << a[i].accountee << "\t\t"
                 << a[i].pins << "\t\t"
                 << a[i].complaints << "\t\t"
                 << a[i].allianceResponse << "\t\t"
                 << a[i].securityThreats<< "\t\t"
                 << a[i].deposits << "\t\t"
                 << a[i].totalAmount << "\t\t"
                 << a[i].withdraws << "\t\t"
                 << a[i].transferFunds << endl;
        }
    }
    
    fout.close(); // Close the file
    cout << "Data successfully written to OutputData.txt" << endl; // Confirmation message
    return;
}
void inputData(AccountArrays a[],const int asize)
{
    ifstream fin("inputData.txt");
    if (!fin.is_open()) {
        cout << "Unable to open file" << endl; // Fixed missing operator
        return;
    }	
    for(int i=0;i<asize;i++)
    {
        getline(fin,a[i].accountee,',');
        getline(fin,a[i].pins,',');
        getline(fin,a[i].complaints,',');
        getline(fin,a[i].allianceResponse,',');
        fin>>a[i].securityThreats;
        fin>>a[i].deposits;
        fin>>a[i].totalAmount;
        fin>>a[i].withdraws;
        fin>>a[i].transferFunds;
        fin.ignore();
    }
    fin.close();
    return;
}












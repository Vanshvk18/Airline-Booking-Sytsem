#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void mainMenu();

class Management
{
public:
    Management()
    {
        mainMenu();
    }
};

class Details
{
public:
    static string name, gender;
    int phoneNo;
    int age;
    string address;
    static int cId;
    char arr[100];

    void information()
    {
        cout << "\nEnter the customer ID: ";
        cin >> cId;
        cout << "Enter the name: ";
        cin >> name;
        cout << "Enter the age: ";
        cin >> age;
        cout << "Enter the gender: ";
        cin >> gender;
        cout << "\nYour details are saved with us\n" << endl;
    }
};

int Details::cId;
string Details::name;
string Details::gender;

class Registration
{
public:
    static int choice;
    int choice1;
    int back;
    static float charges;

    void flights()
    {
        string flightN[] = {"Dubai", "Canada", "UK", "USA", "Australia", "Europe"};

        for (int a = 0; a < 6; a++)
        {
            cout << (a + 1) << ". Flight to " << flightN[a] << endl;
        }

        cout << "\nWelcome to the airlines" << endl;
        cout << "\nPress the number of the country to which you want to book the flight: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "____________________Welcome to Dubai Emirates_______________\n" << endl;
            cout << "Your comfort is our priority. Enjoy the flight" << endl;

            cout << "Following are the flights:\n" << endl;

            cout << "1. DUB-498" << endl;
            cout << "\t08-01-2022 8:00am 10hrs Rs. 14000" << endl;

            cout << "2. DUB-658" << endl;
            cout << "\t09-01-2022 4:00am 12hrs Rs. 10000" << endl;

            cout << "3. DUB-400" << endl;
            cout << "\t11-01-2022 11:00am 11hrs Rs. 9000" << endl;

            cout << "\nSelect the flight you want to book: ";
            cin >> choice1;
            if (choice1 == 1)
            {
                charges = 14000;
                cout << "\nYou have successfully booked the flight DUB-498" << endl;
                cout << "\nYou can go to the main menu and take the ticket" << endl;
            }
            else if (choice1 == 2)
            {
                charges = 10000;
                cout << "\nYou have successfully booked the flight DUB-658" << endl;
                cout << "\nYou can go to the main menu and take the ticket" << endl;
            }
            else if (choice1 == 3)
            {
                charges = 9000;
                cout << "\nYou have successfully booked the flight DUB-400" << endl;
                cout << "\nYou can go to the main menu and take the ticket" << endl;
            }
            else
            {
                cout << "\nInvalid input, returning to the previous menu" << endl;
                flights();
            }
            cout << "\nPress any key to go back to the main menu: ";
            cin >> back;
            if (back == 1)
            {
                mainMenu();
            }
            else
            {
                mainMenu();
            }
            break;
        }
        case 2:
        {
            cout << "____________________Welcome to Canadian Airlines _______________\n" << endl;
            cout << "Your comfort is our priority. Enjoy the flight" << endl;

            cout << "Following are the flights:\n" << endl;

            cout << "1. CA-498" << endl;
            cout << "\t09-01-2022 2:00pm 10hrs Rs. 34000" << endl;

            cout << "2. CA-658" << endl;
            cout << "\t09-01-2022 4:00am 12hrs Rs. 41000" << endl;

            cout << "3. CA-400" << endl;
            cout << "\t11-01-2022 11:00am 11hrs Rs. 40000" << endl;

            cout << "\nSelect the flight you want to book: ";
            cin >> choice1;
            if (choice1 == 1)
            {
                charges = 34000;
                cout << "\nYou have successfully booked the flight CA-498" << endl;
                cout << "\nYou can go to the main menu and take the ticket" << endl;
            }
            else if (choice1 == 2)
            {
                charges = 41000;
                cout << "\nYou have successfully booked the flight CA-658" << endl;
                cout << "\nYou can go to the main menu and take the ticket" << endl;
            }
            else if (choice1 == 3)
            {
                charges = 40000;
                cout << "\nYou have successfully booked the flight CA-400" << endl;
                cout << "\nYou can go to the main menu and take the ticket" << endl;
            }
            else
            {
                cout << "\nInvalid input, returning to the previous menu" << endl;
                flights();
            }
            cout << "\nPress any key to go back to the main menu: ";
            cin >> back;
            if (back == 1)
            {
                mainMenu();
            }
            else
            {
                mainMenu();
            }
            break;
        }
        case 3:
        {
            cout << "____________________Welcome to UK Airways _______________\n" << endl;
            cout << "Your comfort is our priority. Enjoy the flight" << endl;

            cout << "Following are the flights:\n" << endl;

            cout << "1. UK-798" << endl;
            cout << "\t12-01-2022 10:00pm 15hrs Rs. 64000" << endl;

            cout << "\nSelect the flight you want to book: ";
            cin >> choice1;
            if (choice1 == 1)
            {
                charges = 64000;
                cout << "\nYou have successfully booked the flight UK-798" << endl;
                cout << "You can go to the main menu and take the ticket" << endl;
            }
            else
            {
                cout << "Invalid input, returning to the previous menu" << endl;
                flights();
            }
            cout << "Press any key to go back to the main menu: ";
            cin >> back;
            if (back == 1)
            {
                mainMenu();
            }
            else
            {
                mainMenu();
            }
            break;
        }
        case 4:
        {
            cout << "____________________Welcome to US Airlines _______________\n" << endl;
            cout << "Your comfort is our priority. Enjoy the flight" << endl;

            cout << "Following are the flights:\n" << endl;

            cout << "1. US-567" << endl;
            cout << "\t10-01-2022 7:00pm 5hrs Rs. 37000" << endl;

            cout << "2. US-658" << endl;
            cout << "\t09-01-2022 4:00am 12hrs Rs. 39000" << endl;

            cout << "3. US-508" << endl;
            cout << "\t11-01-2022 11:00am 11hrs Rs. 42000" << endl;

            cout << "\nSelect the flight you want to book: ";
            cin >> choice1;
            if (choice1 == 1)
            {
                charges = 37000;
                cout << "\nYou have successfully booked the flight US-567" << endl;
                cout << "You can go to the main menu and take the ticket" << endl;
            }
            else if (choice1 == 2)
            {
                charges = 39000;
                cout << "\nYou have successfully booked the flight US-658" << endl;
                cout << "You can go to the main menu and take the ticket" << endl;
            }
            else if (choice1 == 3)
            {
                charges = 42000;
                cout << "\nYou have successfully booked the flight US-508" << endl;
                cout << "You can go to the main menu and take the ticket" << endl;
            }
            else
            {
                cout << "Invalid input, returning to the previous menu" << endl;
                flights();
            }
            cout << "Press any key to go back to the main menu: ";
            cin >> back;
            if (back == 1)
            {
                mainMenu();
            }
            else
            {
                mainMenu();
            }
            break;
        }
        case 5:
        {
            cout << "____________________Welcome to Australian Airlines _______________\n" << endl;
            cout << "Your comfort is our priority. Enjoy the flight" << endl;

            cout << "Following are the flights:\n" << endl;

            cout << "1. AUS-698" << endl;
            cout << "\t18-09-2022 10:00pm 4hrs Rs. 60000" << endl;

            cout << "2. AUS-968" << endl;
            cout << "\t09-01-2022 12:00am 16hrs Rs. 10000" << endl;

            cout << "3. AUS-401" << endl;
            cout << "\t11-01-2022 11:00am 11hrs Rs. 40000" << endl;

            cout << "\nSelect the flight you want to book: ";
            cin >> choice1;
            if (choice1 == 1)
            {
                charges = 60000;
                cout << "\nYou have successfully booked the flight AUS-698" << endl;
                cout << "You can go to the main menu and take the ticket" << endl;
            }
            else if (choice1 == 2)
            {
                charges = 10000;
                cout << "\nYou have successfully booked the flight AUS-968" << endl;
                cout << "You can go to the main menu and take the ticket" << endl;
            }
            else if (choice1 == 3)
            {
                charges = 40000;
                cout << "\nYou have successfully booked the flight AUS-401" << endl;
                cout << "You can go to the main menu and take the ticket" << endl;
            }
            else
            {
                cout << "Invalid input, returning to the previous menu" << endl;
                flights();
            }
            cout << "Press any key to go back to the main menu: ";
            cin >> back;
            if (back == 1)
            {
                mainMenu();
            }
            else
            {
                mainMenu();
            }
            break;
        }
        case 6:
        {
            cout << "____________________Welcome to European Airlines _______________\n" << endl;
            cout << "Your comfort is our priority. Enjoy the flight" << endl;

            cout << "Following are the flights:\n" << endl;

            cout << "1. EU-100" << endl;
            cout << "\t12-03-2022 2:00am 18hrs Rs. 50000" << endl;

            cout << "2. EU-658" << endl;
            cout << "\t09-01-2022 4:00am 12hrs Rs. 70000" << endl;

            cout << "3. EU-200" << endl;
            cout << "\t17-01-2022 1:00am 14hrs Rs. 55000" << endl;

            cout << "\nSelect the flight you want to book: ";
            cin >> choice1;
            if (choice1 == 1)
            {
                charges = 50000;
                cout << "\nYou have successfully booked the flight EU-100" << endl;
                cout << "You can go to the main menu and take the ticket" << endl;
            }
            else if (choice1 == 2)
            {
                charges = 70000;
                cout << "\nYou have successfully booked the flight EU-658" << endl;
                cout << "You can go to the main menu and take the ticket" << endl;
            }
            else if (choice1 == 3)
            {
                charges = 55000;
                cout << "\nYou have successfully booked the flight EU-200" << endl;
                cout << "You can go to the main menu and take the ticket" << endl;
            }
            else
            {
                cout << "Invalid input, returning to the previous menu" << endl;
                flights();
            }
            cout << "Press any key to go back to the main menu: ";
            cin >> back;
            if (back == 1)
            {
                mainMenu();
            }
            else
            {
                mainMenu();
            }
            break;
        }
        default:
        {
            cout << "Invalid input, returning to the main menu" << endl;
            mainMenu();
            break;
        }
        }
    }
};

float Registration::charges;
int Registration::choice;

class Ticket : public Registration, Details
{
public:
    void Bill()
    {
        string destination = "";
        ofstream outf("records.txt");
        {
            outf << "_______________XYZ Airlines_____________" << endl;
            outf << "_________________Ticket_________________" << endl;
            outf << "________________________________________" << endl;

            outf << "Customer ID: " << Details::cId << endl;
            outf << "Customer Name: " << Details::name << endl;
            outf << "Customer Gender: " << Details::gender << endl;
            outf << "\tDescription" << endl << endl;

            if (Registration::choice == 1)
            {
                destination = "Dubai";
            }
            else if (Registration::choice == 2)
            {
                destination = "Canada";
            }
            else if (Registration::choice == 3)
            {
                destination = "UK";
            }
            else if (Registration::choice == 4)
            {
                destination = "USA";
            }
            else if (Registration::choice == 5)
            {
                destination = "Australia";
            }
            else if (Registration::choice == 6)
            {
                destination = "Europe";
            }

            outf << "Destination: " << destination << endl;
            outf << "Flight cost: " << Registration::charges << endl;
        }
        outf.close();
    }

    void dispBill()
    {
        ifstream ifs("records.txt");
        if (!ifs)
        {
            cout << "File error" << endl;
        }
        while (!ifs.eof())
        {
            ifs.getline(arr, 100);
            cout << arr << endl;
        }
        ifs.close();
    }
};

void mainMenu()
{
     int lchoice;
    int back;

    cout << "\t              XYZ Airlines " << endl;
    cout << "\t ____________________________ " << endl;
    cout << "\t|                            |" << endl;
    cout << "\t|     Main Menu              |" << endl;
    cout << "\t|____________________________|" << endl;
    cout << "\t|                            |" << endl;
    cout << "\t|  1. Add customer details   |" << endl;
    cout << "\t|  2. Flight registration    |" << endl;
    cout << "\t|  3. Ticket and charges     |" << endl;
    cout << "\t|  4. Exit                   |" << endl;
    cout << "\t|                            |" << endl;
    cout << "\t|____________________________|" << endl;
    cout << endl;
    
    cout << "Enter your choice: ";
    cin >> lchoice;

    Details d;
    Registration r;
    Ticket t;

    switch (lchoice)
    {
    case 1:
    {
        cout << "_________________Customer Details_______________\n" << endl;
        d.information();
        cout << "Press any key to go back to the main menu: \n";
        cin >> back;
        mainMenu();
        break;
    }
    case 2:
    {
        cout << "______________Book a flight using this system_________\n" << endl;
        r.flights();
        break;
    }
    case 3:
    {
        cout << "________Get your ticket_____\n" << endl;
        t.Bill();
        cout << "Your ticket is printed. You can collect it\n" << endl;
        cout << "Press 1 to display your ticket: ";
        cin >> back;

        if (back == 1)
        {
            t.dispBill();
            cout << "Press any key to go back to the main menu: \ns ";
            cin >> back;
            mainMenu();
        }
        else
        {
            mainMenu();
        }
        break;
    }
    case 4:
    {
        cout << "\n\n\t_______Thank You__________" << endl;
        break;
    }
    default:
    {
        cout << "Invalid input, please try again\n" << endl;
        mainMenu();
        break;
    }
    }
}

int main()
{
    Management Mobj;
    return 0;
}

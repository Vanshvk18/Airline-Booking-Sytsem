#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

// Forward declaration
class AirlineManagement;

// =====================================================================
// 1. Abstraction: Abstract Base Class for any bookable service
// =====================================================================
class BookableService
{
private:
    string serviceCode;
    float charges;

public:
    BookableService(string code, float serviceCharges) : serviceCode(code), charges(serviceCharges) {}
    virtual ~BookableService() {}

    string getCode() const { return serviceCode; }
    float getCharges() const { return charges; }

    virtual void displayDetails() const = 0;
};

// =====================================================================
// 2. Inheritance: Concrete Flight class inheriting from BookableService
// =====================================================================
class Flight : public BookableService
{
private:
    string destination;
    string departureTime;

public:
    Flight(string code, float charges, string dest, string time)
        : BookableService(code, charges), destination(dest), departureTime(time) {}

    string getDestination() const { return destination; }
    string getDepartureTime() const { return departureTime; }

    void displayDetails() const override
    {
        cout << "  Flight to: " << destination << endl;
        cout << "  Departure: " << departureTime << endl;
    }
};

// =====================================================================
// 3. Customer Class: Encapsulates customer data and their bookings
// =====================================================================
class Customer
{
private:
    int customerId;
    string name;
    string gender;
    int age;
    vector<BookableService *> bookedServices;

public:
    Customer(int id, string cName, int cAge, string cGender)
        : customerId(id), name(cName), age(cAge), gender(cGender) {}

    ~Customer()
    {
        for (BookableService *service : bookedServices)
        {
            delete service;
        }
    }

    int getId() const { return customerId; }
    string getName() const { return name; }
    string getGender() const { return gender; }
    const vector<BookableService *> &getBookedServices() const { return bookedServices; }

    void bookService(BookableService *service)
    {
        bookedServices.push_back(service);
        cout << "\nService " << service->getCode() << " booked successfully for " << name << "!" << endl;
    }
};

// =====================================================================
// 4. Ticket Class: Uses composition, is only for ticket generation
// =====================================================================
class Ticket
{
public:
    void generateAndDisplayBill(const Customer &customer)
    {
        cout << "\n--- Generating Ticket for Customer ID: " << customer.getId() << " ---" << endl;

        string fileName = "ticket_" + to_string(customer.getId()) + ".txt";
        ofstream outFile(fileName);

        if (!outFile)
        {
            cerr << "Error: Could not open file for writing." << endl;
            return;
        }

        auto write = [&](const string &line)
        {
            cout << line << endl;
            outFile << line << endl;
        };

        write("_______________XYZ Airlines_____________");
        write("_________________Ticket_________________");
        write("________________________________________\n");
        write("Customer ID:   " + to_string(customer.getId()));
        write("Customer Name: " + customer.getName());
        write("Customer Gender: " + customer.getGender());
        write("\n\t--- Booked Services ---\n");

        float totalCharges = 0.0f;
        const auto &services = customer.getBookedServices();
        if (services.empty())
        {
            write("No services booked.");
        }
        else
        {
            for (const auto *service : services)
            {
                const Flight *flight = dynamic_cast<const Flight *>(service);
                if (flight)
                {
                    write("Service Type: Flight");
                    write("Destination:  " + flight->getDestination());
                    write("Flight Code:  " + flight->getCode());
                    write("Departure:    " + flight->getDepartureTime());
                    write("Flight Cost:  Rs. " + to_string(service->getCharges()));
                    write("------------------------------------");
                    totalCharges += service->getCharges();
                }
            }
        }

        write("\nTotal Charges: Rs. " + to_string(totalCharges));
        write("________________________________________");

        outFile.close();
        cout << "\nTicket saved to file: " << fileName << endl;
    }
};

// =====================================================================
// 5. AirlineManagement Class: Manages all operations and data
// =====================================================================
class AirlineManagement
{
private:
    vector<Customer> customers;
    vector<Flight> availableFlights; // Vector to store the airline's flights
    int nextCustomerId = 1;

    // This method populates our airline with a list of flights
    void initializeFlights()
    {
        availableFlights.emplace_back("DUB-498", 14000.0f, "Dubai", "08:00 AM");
        availableFlights.emplace_back("DUB-658", 10000.0f, "Dubai", "04:00 AM");
        availableFlights.emplace_back("CAN-101", 45000.0f, "Canada", "10:00 PM");
        availableFlights.emplace_back("CAN-230", 48000.0f, "Canada", "12:00 PM");
        availableFlights.emplace_back("UK-798", 64000.0f, "UK", "10:00 PM");
        availableFlights.emplace_back("USA-567", 37000.0f, "USA", "07:00 PM");
        availableFlights.emplace_back("USA-508", 42000.0f, "USA", "11:00 AM");
        availableFlights.emplace_back("AUS-698", 60000.0f, "Australia", "10:00 PM");
        availableFlights.emplace_back("AUS-401", 40000.0f, "Australia", "11:00 AM");
        availableFlights.emplace_back("EUR-100", 50000.0f, "Europe", "02:00 AM");
        availableFlights.emplace_back("EUR-200", 55000.0f, "Europe", "01:00 AM");
        availableFlights.emplace_back("UK-812", 67000.0f, "UK", "06:00 AM");
        availableFlights.emplace_back("DUB-410", 19000.0f, "Dubai", "09:00 PM");
        availableFlights.emplace_back("USA-990", 49000.0f, "USA", "03:00 PM");
    }

    Customer *findCustomer(int id)
    {
        for (auto &customer : customers)
        {
            if (customer.getId() == id)
            {
                return &customer;
            }
        }
        return nullptr;
    }

public:
    // Constructor for AirlineManagement
    AirlineManagement()
    {
        initializeFlights(); // Load flights as soon as the system starts
    }

    void addCustomerDetails()
    {
        string name, gender;
        int age;
        cout << "\n--- Add New Customer Details ---\n";
        cout << "Enter the name: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, name);
        cout << "Enter the age: ";
        cin >> age;
        cout << "Enter the gender: ";
        cin >> gender;
        customers.emplace_back(nextCustomerId, name, age, gender);
        cout << "\nCustomer added! Their ID is " << nextCustomerId++ << "." << endl;
    }

    void bookFlight()
    {
        int customerId;
        cout << "\nEnter Customer ID to book a flight: ";
        cin >> customerId;
        Customer *customer = findCustomer(customerId);
        if (!customer)
        {
            cout << "Error: Customer not found." << endl;
            return;
        }

        cout << "\n--- Available Flights for " << customer->getName() << " ---" << endl;
        // Display all available flights dynamically
        for (size_t i = 0; i < availableFlights.size(); ++i)
        {
            const auto &flight = availableFlights[i];
            cout << i + 1 << ". Flight " << flight.getCode()
                 << " to " << flight.getDestination()
                 << " at " << flight.getDepartureTime()
                 << " (Rs. " << flight.getCharges() << ")" << endl;
        }

        cout << "\nSelect the flight number you want to book: ";
        int flightChoice;
        cin >> flightChoice;

        if (flightChoice > 0 && flightChoice <= availableFlights.size())
        {
            // Adjust index (user enters 1-based, vector is 0-based)
            const Flight &selectedFlight = availableFlights[flightChoice - 1];

            // Create a new booking for the customer
            // This is a new object on the heap that the customer will own
            BookableService *service = new Flight(
                selectedFlight.getCode(),
                selectedFlight.getCharges(),
                selected.getDestination(),
                selected.getDepartureTime());

            customer->bookService(service);
        }
        else
        {
            cout << "Invalid flight choice." << endl;
        }
    }

    void showTicket()
    {
        int customerId;
        cout << "\nEnter Customer ID to view ticket: ";
        cin >> customerId;
        const Customer *customer = findCustomer(customerId);
        if (!customer)
        {
            cout << "Error: Customer not found." << endl;
            return;
        }
        if (customer->getBookedServices().empty())
        {
            cout << "Error: This customer has no bookings." << endl;
            return;
        }
        Ticket ticket;
        ticket.generateAndDisplayBill(*customer);
    }

    void run()
    {
        int choice;
        do
        {
            cout << "\n\n\t        XYZ Airlines        " << endl;
            cout << "\t ____________________________ " << endl;
            cout << "\t|         Main Menu          |" << endl;
            cout << "\t|____________________________|" << endl;
            cout << "\t|  1. Add Customer Details   |" << endl;
            cout << "\t|  2. Book a Flight          |" << endl;
            cout << "\t|  3. View Ticket            |" << endl;
            cout << "\t|  4. Exit                   |" << endl;
            cout << "\t|____________________________|" << endl;
            cout << "\nEnter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                addCustomerDetails();
                break;
            case 2:
                bookFlight();
                break;
            case 3:
                showTicket();
                break;
            case 4:
                cout << "\n\n\t_______Thank You__________" << endl;
                break;
            default:
                cout << "Invalid input, please try again." << endl;
            }
        } while (choice != 4);
    }
};

// =====================================================================
// 6. Main Function
// =====================================================================
int main()
{
    AirlineManagement system;
    system.run();
    return 0;
}

#include <iostream>
#include <iomanip>
#include <thread>
#include <chrono>
using namespace std;

const int console_width = 50;
string line(console_width,'=');
const int NUMTrip = 50;


//centering a text
void center_text(string text = "FUEL TRACKER", int width = 50) {
    
    int padding = (width - text.length()) / 2;
    cout << string(width, '=') << endl;
    cout << string(padding, ' ') << text << endl;
    cout << string(width, '=') << endl << endl;
    cout << "[1] Add Trip (Calculate Fuel Efficiency)" << endl;
    cout << "[2] Edit Saved Records" << endl;
    cout << "[3] Display records" << endl;
    cout << "[4] Delete a record" << endl;
    cout << "[5] Exit Program" << endl << endl;
    cout << "Enter your Choice: ";
};

//choice 1 adding a trip
void addtrip (string routes[], double distances[], double fuel[], double efficiency[], double cost[], double price[], int choice, int &recordCount) {
    double idist, ifuel, ieff, icost, iprice;
    string iroute;
    char saveChoice;

    cout << "Enter Route/Destination (e.g. Oriental Mindoro - Batangas): ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    getline(cin,iroute);
    
    while(true) {
        cout << "Enter distance (km): ";
        cin >> idist;
        if(cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Distance cannot have letters." << endl;
            this_thread::sleep_for(chrono::seconds(1));
            continue;
        }
        else if(idist <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Distance cannot be a negative number or equal to zero..." << endl;
        }
        else {
            break;
        }
    }
    while(true) {
        cout << "Enter fuel used (L): ";
        cin >> ifuel;
        if(cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Fuel used cannot have letters." << endl;
            this_thread::sleep_for(chrono::seconds(1));
            continue;
        }
        else if(ifuel <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Fuel used cannot be a negative number or equal to zero..." << endl;
        }
        else {
            break;
        }
    }
    while(true) {
        cout << "Enter fuel price in Php: ";
        cin >> iprice;
        if(cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Fuel price cannot have letters." << endl;
            this_thread::sleep_for(chrono::seconds(1));
            continue;
        }
        else if(iprice <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Fuel price cannot be a negative number or equal to zero..." << endl;
        }
        else {
            break;
    }
}

    ieff = idist / ifuel;
    icost = ifuel * iprice;
    cout << "Fuel efficiency: " << ieff << "km/L" << endl;
    cout << fixed << setprecision(2) << "Trip cost: Php " << icost << endl;

    this_thread::sleep_for(chrono::seconds(2));

        cout << "Save this record?: (Y/N): ";
        do{
            cin >> saveChoice;
            switch (saveChoice) {
                case 'y':
                case 'Y': {
                    routes[recordCount] = iroute;
                    distances[recordCount] = idist;
                    fuel[recordCount] = ifuel;
                    efficiency[recordCount] = ieff;
                    cost[recordCount] = icost;
                    price[recordCount] = iprice;
                    recordCount = recordCount + 1;

                    cout << "Data saved successfully!\nPress Enter to Continue...";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin.get();
                    break;
                };

                case 'N':
                case 'n':  {
                    cout << "Data Discarded..";
                    break;
                };
                
                default: {
                    cout << "Please enter Y/N only.";
                    break;
                }
            }
        }
        while(saveChoice != 'Y' && saveChoice != 'y' && saveChoice != 'n' && saveChoice != 'N');
        
};

//choice 2 to do Edit a record
void editRecord (string routes[], int recordCount, double distances[], double fuel[], double efficiency[], double price[], double cost[]) {
    if(recordCount > 0) {
        while(true) {
            cout << "Which Trip to be edited?" << endl;
            this_thread::sleep_for(chrono::seconds(2)); //to delay the display of record
            cout << "Trip No. | Route | Distance | Fuel Used | Fuel Price | Efficiency | Cost" << endl;
        for(int i = 0; i < recordCount; i++) {
        cout << i + 1 << " | "  << routes[i] << " | " << distances[i] << " | " << fuel[i] <<  " | " << price[i] << " | " << efficiency[i] << " | " << cost[i] << endl;
        }
        int editTrip;
        cin >> editTrip;
            if(editTrip <= 0 || editTrip > recordCount) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please input a valid trip number...\n";
                this_thread::sleep_for(chrono::seconds(1));
                continue;
            }
        
            else {
                string eroute;
                double edist, efuel, eEff, eCost, eprice;
                int choiceEdit;
                do {
                cout << "Which one to edit?\n[1] Route\n[2] Distance\n[3] Fuel\n[4] Fuel Price\n[5] Exit\n\nEnter your choice: " << endl;
                    cin >> choiceEdit;
                    switch(choiceEdit) {
                        case 1: {
                            cout << "Enter a New route: ";
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            getline(cin,eroute);
                            routes[editTrip - 1] = eroute;
                            cout << "Route has been edited Successfully!" << endl;
                            this_thread::sleep_for(chrono::seconds(2));
                            break;
                        }
                        case 2: {
                            cout << "Enter a New Distance: ";
                            cin >> edist;
                            distances[editTrip - 1] = edist;
                            efficiency[editTrip - 1] = distances[editTrip - 1] / fuel[editTrip - 1];
                            cout << "Distance has been edited successfully!" << endl;
                            this_thread::sleep_for(chrono::seconds(2));
                            break;
                        }
                        
                        case 3: {
                            cout << "Enter a new Fuel used: ";
                            cin >> efuel;
                            fuel[editTrip - 1] = efuel;
                            efficiency[editTrip - 1] = distances[editTrip - 1] / fuel[editTrip - 1];
                            cost[editTrip - 1] = fuel[editTrip - 1] * price[editTrip - 1];
                            cout << "Fuel used has been edited successfully!" << endl;
                            this_thread::sleep_for(chrono::seconds(2));
                            break;
                        }
                        
                        case 4: {
                            cout << "Enter a new fuel price: ";
                            cin >> eprice;
                            price[editTrip - 1] = eprice;
                            cost[editTrip - 1] = price[editTrip - 1] * fuel[editTrip - 1];

                            cout << "Fuel price has been edited successfully!" << endl;
                            this_thread::sleep_for(chrono::seconds(2));
                            break;
                        }
                        
                        case 5: {
                            cout << "Back to Main menu\n\n";
                            this_thread::sleep_for(chrono::seconds(2));
                            break;
                        }
                        default: {
                            cout << "Input a valid number..\n\n";
                            break;
                        }
                    };
                }
                while (choiceEdit != 5);
            }
            
            break;
        }
    }
    
    else {      
        cout << "No previous trips to edit..." << endl;
        this_thread::sleep_for(chrono::seconds(2));
        cout << endl;
    }
};


//choice 3 to display a record
void displayRecord(string routes[], int recordCount, double distances[], double fuel[], double efficiency[], double cost[], double price[]) {
    if(recordCount > 0) {
        cout << "Trip No. | Route | Distance | Fuel Used | Fuel Price | Efficiency | Cost" << endl;
        for(int i = 0; i < recordCount; i++) {
        cout << i + 1 << " | "  << routes[i] << " | " << distances[i] << " | " << fuel[i] <<  " | " << price[i] << " | " << efficiency[i] << " | " << cost[i] << endl;
        
       }
       cout << "Press Enter to back to Main Menu.";
       cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
       
    }
    else {      
        cout << "No previous trips to display..." << endl;
        this_thread::sleep_for(chrono::seconds(2));
        cout << endl;
        }

};

//Delete a Record
void recordDelete(string routes[], int &recordCount, double distances[], double fuel[], double efficiency[], double price[], double cost[]) {
    if(recordCount > 0) {
    while(true) {
        cout << "Which Trip you wish to delete?" << endl;
            this_thread::sleep_for(chrono::seconds(2)); //to delay the display of record
            cout << "Trip No. | Route | Distance | Fuel Used | Fuel Price | Efficiency | Cost" << endl;
        for(int i = 0; i < recordCount; i++) {
        cout << i + 1 << " | "  << routes[i] << " | " << distances[i] << " | " << fuel[i] <<  " | " << price[i] << " | " << efficiency[i] << " | " << cost[i] << endl;
        }
        int TripDel;
        cin >> TripDel;
            if(TripDel <= 0 || TripDel > recordCount) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please input a valid trip number...\n";
                this_thread::sleep_for(chrono::seconds(1));
                continue;
            }
            else {
                for(int i = TripDel - 1; i < recordCount - 1; i++) {
                    routes[i] = routes[i + 1];
                    distances[i] = distances[i + 1];
                    fuel[i] = fuel[i + 1];
                    efficiency[i] = efficiency[i + 1];
                    price[i] = price[i + 1];
                    cost[i] = cost[i + 1];
                }
                recordCount = recordCount - 1;

                cout << "Trip has been Deleted. Press Enter to continue...\n\n";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get();
            }
            
           
        break;
        }
        
    }
    else {
        cout << "No previous trips to delete..." << endl;
        this_thread::sleep_for(chrono::seconds(2));
        cout << endl;
        }
            
};

//psst, gising, tapos na granny

int main() {
    string routes[NUMTrip];
    double distances[NUMTrip], fuel[NUMTrip], efficiency[NUMTrip], cost[NUMTrip], price[NUMTrip];
    int del_item, recordCount = 0, choice, editTrip;
    char saveChoice;
    
    while(true) {
        center_text();
        cin >> choice;
        cout << endl;
        switch (choice) {
            case 1: {
                addtrip(routes, distances, fuel, efficiency, cost, price, choice, recordCount);
                break;
            }

            case 2: {
                editRecord(routes, recordCount, distances, fuel, efficiency, price, cost);
                break;
            }
            case 3: {
                displayRecord(routes, recordCount, distances, fuel, efficiency, cost, price);
                break;
            }
            case 4: {
                recordDelete(routes, recordCount, distances, fuel, efficiency, cost, price);
                break;
            }
            case 5: {
                cout << "Thank you for Using the Fuel Efficiency Tracker.\nPress Enter to Exit.";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get();
                return 0;
            }
            default: {
                cout << "Invalid Input.." << endl;
                break;
            }
        }
    }
return 0;
}
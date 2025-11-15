#include <iostream>
#include <vector>
using namespace std;

class Route {
public:
    int routeID;
    string startPoint;
    string endPoint;
    vector<string> stops;

    Route(int id, string start, string end) {
        routeID = id;
        startPoint = start;
        endPoint = end;
    }

    void addStop(string stopName) {
        stops.push_back(stopName);
    }

    void displayRoute() {
        cout << "\nRoute ID: " << routeID;
        cout << "\nStart: " << startPoint;
        cout << "\nEnd: " << endPoint;
        cout << "\nStops:";

       
        for (int i = 0; i < stops.size(); i++) {
            cout << "\n  - " << stops[i];
        }
        cout << "\n";
    }
};


class BusSystem {
public:
    vector<Route> routes;

    void addRoute(Route r) {
        routes.push_back(r);
    }

    void displayAllRoutes() {
        for (int i = 0; i < routes.size(); i++) {
            routes[i].displayRoute();
        }
    }

    void searchRoute(int id) {
        for (int i = 0; i < routes.size(); i++) {
            if (routes[i].routeID == id) {
                cout << "\nRoute Found!";
                routes[i].displayRoute();
                return;
            }
        }
        cout << "\nRoute ID not found!\n";
    }
};


int main() {
    BusSystem system;

  
    Route r1(101, "Main Gate", "IT Department");
    r1.addStop("Hostel 1");
    r1.addStop("Library");
    r1.addStop("Science Block");

    system.addRoute(r1);

   
    system.displayAllRoutes();

    
    system.searchRoute(101);

    return 0;
}

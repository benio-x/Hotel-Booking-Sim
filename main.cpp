#include <iostream>
#include <vector>

using namespace std;

class Hotel {
private:
    struct Room {
        int number;
        bool isBooked;
    };

    vector<Room> rooms;

public:
    Hotel(int totalRooms);
    bool bookRoom(int roomNumber);
    void showAvailableRooms();
};

Hotel::Hotel(int totalRooms) {
    for (int i = 1; i <= totalRooms; i++) {
        Room room = { i, false }; // create a Room object
        rooms.push_back(room);    // add the Room object to the vector
    }
}

bool Hotel::bookRoom(int roomNumber) {
    if (roomNumber <= 0 || roomNumber > rooms.size()) return false; // check if roomNumber is valid
    if (!rooms[roomNumber - 1].isBooked) {
        rooms[roomNumber - 1].isBooked = true;
        return true;
    }
    return false;
}

void Hotel::showAvailableRooms() {
    for (vector<Room>::const_iterator it = rooms.begin(); it != rooms.end(); ++it) {
        if (!it->isBooked)
        cout << "room " << it->number << ",  ";
    }
}

int main() {
    Hotel myHotel(10);
    int roomNumber;
    char choice = ' ';
    int count = 0;
        cout << "*********************************************************" << endl;
        cout << "\nHello and welcome to hotel Shibuya, for online booking, \n";
    while (true) {
        cout << "the available rooms we have left are:\n";
        myHotel.showAvailableRooms();

        cout << "\n\nplease enter a room number to book or -1 if you wish to exit: ";
        cin >> roomNumber;

        if (roomNumber == -1) break;

        if (myHotel.bookRoom(roomNumber)) {
            count++;
            cout << "room " << roomNumber << "  was successfully booked!\n";
            cout << "would you like to book another room, y/n?" << endl;
            cin >> choice;
            
            
            if(choice == 'n' || choice == 'N')
            {
                cout << "you have made " << count << " bookings with Shibuya hotel, have a great rest of you day!" << endl;
                return 0;
            }
            else if (choice == 'y' || choice == 'Y')
            {  
                continue;
                
            }else if (choice != 'y' || choice != 'Y' || choice != 'n' || choice != 'N')
            {
                cout << "you have made an unprocessible decison, so your advancement was not possible" << endl;
                cout << "your " << count << " booking have been complete, for further action please contact front desk 1-800FRS" << endl;
                return 0;
            }
        } else {
            cout << "\n...room " << roomNumber << " is already booked or invalid, please choose a different room,\n";
        }
    }

    cout << "thank you for using our hotel booking system.\n";
    return 0;
}

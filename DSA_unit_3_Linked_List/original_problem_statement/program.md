## Program for Supply Chain Management

#include <iostream>
#include <string>

using namespace std;

struct Block {
    string location;
    string custodian;
    string timestamp;
    bool isVerified;
    Block* next;
};

class SupplyChainTracker {
private:
    Block* head;

public:
    SupplyChainTracker() {
        head = NULL;
    }

    void insertBlock(string loc, string cust, string time, bool verified) {
        Block* newBlock = new Block();
        newBlock->location = loc;
        newBlock->custodian = cust;
        newBlock->timestamp = time;
        newBlock->isVerified = verified;
        newBlock->next = NULL;

        if (head == NULL) {
            head = newBlock;
        } else {
            Block* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newBlock;
        }
        cout << "\n[SUCCESS] New journey block successfully added to the tracker.\n";
    }

    void trackJourney() {
        if (head == NULL) {
            cout << "\n[NOTICE] No journey history available for this item.\n";
            return;
        }

        Block* temp = head;
        cout << "\n========== PRODUCT SUPPLY CHAIN JOURNEY HISTORY ==========\n";
        int step = 1;
        while (temp != NULL) {
            cout << " Step " << step++ << ":\n";
            cout << "   Location   : " << temp->location << "\n";
            cout << "   Custodian  : " << temp->custodian << "\n";
            cout << "   Timestamp  : " << temp->timestamp << "\n";
            cout << "   VerificationStatus: " << (temp->isVerified ? "SECURE / VERIFIED" : "UNVERIFIED PENDING") << "\n";
            cout << "          │\n          ▼\n";
            temp = temp->next;
        }
        cout << "   [ Current Status Location ]\n";
        cout << "========================================================\n";
    }

    void verifyCustodian(string targetCustodian) {
        if (head == NULL) {
            cout << "\n[ERROR] No logs exist to verify.\n";
            return;
        }

        Block* temp = head;
        bool found = false;

        while (temp != NULL) {
            if (temp->custodian == targetCustodian) {
                cout << "\n[MATCH FOUND] Authenticated record details:\n";
                cout << " -> Handled at: " << temp->location << " during " << temp->timestamp << "\n";
                found = true;
            }
            temp = temp->next;
        }

        if (!found) {
            cout << "\n[ALERT/WARNING] No custodian record match found! Chain might be untrusted.\n";
        }
    }
};

int main() {
    SupplyChainTracker tracker;
    int choice;
    string loc, cust, time;
    int statusInput;
    bool verified;

    tracker.insertBlock("Factory-Munich", "PharmaCorp Labs", "04-Oct-2026 09:00", true);
    tracker.insertBlock("Customs-Hub-Frankfurt", "DHL Logistics", "04-Oct-2026 14:30", true);

    while (true) {
        cout << "\n*** MINI-BLOCKCHAIN SUPPLY CHAIN JOURNEY TRACKER ***\n";
        cout << "1. Add New Journey Checkpoint (Insert Block)\n";
        cout << "2. Track Complete Journey (Traverse List)\n";
        cout << "3. Verify Custodian History (Search Record)\n";
        cout << "4. Exit System\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear newline buffer

        switch (choice) {
            case 1:
                cout << "Enter current processing location: ";
                getline(cin, loc);
                cout << "Enter custodian officer/facility name: ";
                getline(cin, cust);
                cout << "Enter event time (DD-MM-YYYY HH:MM): ";
                getline(cin, time);
                cout << "Enter integrity state status (1 for Verified, 0 for Unverified): ";
                cin >> statusInput;
                verified = (statusInput == 1);

                tracker.insertBlock(loc, cust, time, verified);
                break;

            case 2:
                tracker.trackJourney();
                break;

            case 3:
                cout << "Enter custodian name to verify identity lookup: ";
                getline(cin, cust);
                tracker.verifyCustodian(cust);
                break;

            case 4:
                cout << "\nExiting Ledger Tracker Application.\n";
                return 0;

            default:
                cout << "\n[INVALID] Invalid option selection! Please try again.\n";
        }
    }
}

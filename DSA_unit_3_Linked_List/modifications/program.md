## Program for Modifications
#include <iostream>
#include <string>

using namespace std;

struct CheckpointNode {
    string location;
    string custodian;
    string timestamp;
    CheckpointNode* next;
};

class SupplyChainManager {
private:
    CheckpointNode* front; 
    CheckpointNode* rear;  
    CheckpointNode* top;  

public:
    SupplyChainManager() {
        front = NULL;
        rear = NULL;
        top = NULL;
    }


    void addForwardCheckpoint(string loc, string cust, string time) {
        CheckpointNode* newNode = new CheckpointNode();
        newNode->location = loc;
        newNode->custodian = cust;
        newNode->timestamp = time;
        newNode->next = NULL;

        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "[SUCCESS] Checkpoint added to Forward Tracker: " << loc << "\n";
    }

    void printForwardJourney() {
        if (front == NULL) {
            cout << "\n[NOTICE] Forward journey queue is empty. No active tracking route available.\n";
            return;
        }

        CheckpointNode* temp = front;
        cout << "\n================= FORWARD SUPPLY CHAIN TRACKER (QUEUE) =================\n";
        int order = 1;
        while (temp != NULL) {
            cout << " [" << order++ << "] Location: " << temp->location 
                 << " | Custodian: " << temp->custodian 
                 << " | Time: " << temp->timestamp << "\n";
            temp = temp->next;
        }
        cout << "========================================================================\n";
    }

    void triggerRecallAnalysis() {
        if (front == NULL) {
            cout << "\n[ERROR] Underflow. No active batch checkpoints left to recall.\n";
            return;
        }

        CheckpointNode* temp = front;
        string loc = temp->location;
        string cust = temp->custodian;
        string time = temp->timestamp;

        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }
        delete temp;

        CheckpointNode* recallNode = new CheckpointNode();
        recallNode->location = loc;
        recallNode->custodian = cust;
        recallNode->timestamp = time;
        recallNode->next = top;
        top = recallNode;

        cout << "[RECALL ACTIVATED] Shifted location '" << loc << "' to Reverse Recall Tracking Stack.\n";
    }

    void processRecallRollback() {
        if (top == NULL) {
            cout << "\n[NOTICE] Recall stack is empty. Reverse logistics audit complete or uninitialized.\n";
            return;
        }

        cout << "\n================ REVERSE RECALL LOGISTICS AUDIT (STACK) ================\n";
        cout << "Backtracking safety custody path from most recent downward to point of origin:\n\n";

        while (top != NULL) {
            CheckpointNode* temp = top;
            cout << " <- [ROLLBACK CHECKPOINT] ->\n";
            cout << "    Location  : " << temp->location << "\n";
            cout << "    Custodian : " << temp->custodian << "\n";
            cout << "    Timestamp : " << temp->timestamp << "\n";
            cout << "    Status    : SECURED AND RETURNED DETOXIFIED\n\n";

            top = top->next;
            delete temp;
        }
        cout << "========================================================================\n";
        cout << "[SUCCESS] Entire tracking rollback complete. Product batch isolated at source origin.\n";
    }
};

int main() {
    SupplyChainManager tracker;
    int choice;
    string loc, cust, time;
    tracker.addForwardCheckpoint("Factory-Mumbai", "BioLabs India", "16-Oct-2026 09:00");
    tracker.addForwardCheckpoint("Distribution-Hub-Pune", "SafeTrans Logistics", "16-Oct-2026 14:00");
    tracker.addForwardCheckpoint("Pharmacy-Retail-Nashik", "MedLife Pharmacy", "16-Oct-2026 18:30");

    while (true) {
        cout << "\n*** MODIFIED LEDGER TRACKING PLATFORM (STACKS & QUEUES) ***\n";
        cout << "1. Record New Distribution Stage Checkpoint (Enqueue)\n";
        cout << "2. Audit Complete Forward Chain Journey (Traverse Queue)\n";
        cout << "3. Trigger Batch Recall Phase (Dequeue & Push to Stack)\n";
        cout << "4. Execute Reverse Logistics Traceback Plan (Pop Stack Summary)\n";
        cout << "5. Exit Platform\n";
        cout << "Enter selection option: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1:
                cout << "Enter shipping transit facility location: ";
                getline(cin, loc);
                cout << "Enter current cargo custodian holding agent: ";
                getline(cin, cust);
                cout << "Enter tracking dispatch time (DD-MM-YYYY HH:MM): ";
                getline(cin, time);
                tracker.addForwardCheckpoint(loc, cust, time);
                break;

            case 2:
                tracker.printForwardJourney();
                break;

            case 3:
                tracker.triggerRecallAnalysis();
                break;

            case 4:
                tracker.processRecallRollback();
                break;

            case 5:
                cout << "\nTerminating application execution safely.\n";
                return 0;

            default:
                cout << "\n[INVALID] Selection out of boundaries. Re-enter valid choice parameters.\n";
        }
    }
}

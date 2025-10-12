#include <bits/stdc++.h>
#include <thread>
#include <chrono>
using namespace std;

class Call {
public:
    int ID;
    int ArrivalTime;
    string CustomerName;
    Call(int id, int at, string cn) {
        ID = id;
        ArrivalTime = at;
        CustomerName = cn;
    }
};

class CallCenter {
    queue<Call> incomingcalls;
    int CSR;
    vector<bool> CSRStatus;

public:
    CallCenter(int n) {
        CSR = n;
        CSRStatus.resize(n, false);
    }

    void addCall(Call c) {
        incomingcalls.push(c);
        cout << "Call from " << c.CustomerName << " added to the queue." << endl;
    }

    void processCall() {
        for (int i = 0; i < CSR; i++) {
            if (!CSRStatus[i] && !incomingcalls.empty()) {
                Call c = incomingcalls.front();
                incomingcalls.pop();
                CSRStatus[i] = true;
                cout << "CSR " << i + 1 << " is attending call from " << c.CustomerName << "." << endl;

                // Run the call simulation in a new thread
                thread t(&CallCenter::simulateCallEnd, this, i, c);
                t.detach();
            }
        }
    }

    void simulateCallEnd(int csrIndex, Call c) {
        this_thread::sleep_for(chrono::seconds(5)); // simulate call time
        CSRStatus[csrIndex] = false;
        cout << "CSR " << csrIndex + 1 << " has finished call from " << c.CustomerName << " and is now free." << endl;
    }
};

int main() {
    CallCenter cc(3); // 3 Customer Service Representatives

    // Simulate call arrivals
    cc.addCall(Call(1, 0, "Alice"));
    cc.addCall(Call(2, 1, "Bob"));
    cc.addCall(Call(3, 2, "Charlie"));
    cc.addCall(Call(4, 3, "David"));
    cc.addCall(Call(5, 4, "Emma"));

    // Continuous simulation loop
    for (int i = 0; i < 5; i++) { // run 5 cycles of checking
        cc.processCall();
        this_thread::sleep_for(chrono::seconds(2)); // check every 2 seconds
    }

    // Wait for all calls to finish before program exits
    this_thread::sleep_for(chrono::seconds(10));

    return 0;
}

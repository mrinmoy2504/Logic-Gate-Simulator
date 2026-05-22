#include <iostream>
#include <string>

using namespace std;

// Base Class
class LogicGate {
protected:
    bool x, y, z;
    string gateName;
public:
    LogicGate(string name) : gateName(name) {
        cout << "\nSimulation for --> " << gateName << endl;
    }
    virtual ~LogicGate() {}
};

// 1. AND Gate
class AndGate : public LogicGate {
public:
    AndGate() : LogicGate("AND Gate Operation") {}

    // Operator overloading for binary inputs
    bool operator()(bool x, bool y) {
        z = x && y;
        return z;
    }

    ~AndGate() { cout << "Opt for next operation\n"; }
};

// 2. OR Gate
class OrGate : public LogicGate {
public:
    OrGate() : LogicGate("Or Gate Operation") {}

    bool operator()(bool x, bool y) {
        z = x || y;
        return z;
    }

    ~OrGate() { cout << "Opt for next operation\n"; }
};

// 3. NOT Gate
class NotGate : public LogicGate {
public:
    NotGate() : LogicGate("NOT (Inverter) Gate Operation") {}

    // Operator overloading for a single input
    bool operator()(bool x) {
        z = !x;
        return z;
    }

    ~NotGate() { cout << "Opt for next operation\n"; }
};

// 4. Buffer
class Buffer : public LogicGate {
public:
    Buffer() : LogicGate("Buffer Operation") {}

    bool operator()(bool x) {
        z = x;
        return z;
    }

    ~Buffer() { cout << "Opt for next operation\n"; }
};

// 5. NAND Gate
class NandGate : public LogicGate {
public:
    NandGate() : LogicGate("NAND (Universal Gate) Operation") {}

    bool operator()(bool x, bool y) {
        z = !(x && y);
        return z;
    }

    ~NandGate() { cout << "Opt for next operation\n"; }
};

// 6. NOR Gate
class NorGate : public LogicGate {
public:
    NorGate() : LogicGate("NOR (Universal Gate) Operation") {}

    bool operator()(bool x, bool y) {
        z = !(x || y);
        return z;
    }

    ~NorGate() { cout << "Opt for next operation\n"; }
};

// 7. XOR Gate
class XorGate : public LogicGate {
public:
    XorGate() : LogicGate("XOR (Exclusive Gate) Operation") {}

    bool operator()(bool x, bool y) {
        z = (x != y);
        return z;
    }

    ~XorGate() { cout << "Opt for next operation\n"; }
};

// 8. XnorGate
class XnorGate : public LogicGate {
public:
    XnorGate() : LogicGate("XNOR (Exclusive Gate) Operation") {}

    bool operator()(bool x, bool y) {
        z = !(x != y);
        return z;
    }

    ~XnorGate() { cout << "Opt for next operation\n"; }
};

int main() {
    int option;
    bool a, b;

    while (true) {
        cout << "\n======= LOGIC GATE SIMULATOR =======" << endl;
        cout << "\n1. AND Gate\n2. OR Gate\n3. NOT Gate(single input)\n4. Buffer (single input)\n5. NAND Gate \n6. NOR Gate\n7. XOR Gate\n8. XNOR Gate\n0. Exit" << endl;
        cout << "Select: ";
        cin >> option;

        if (option == 0) break;
        if (option < 0 || option > 8) {
            cout << "Invalid choice!" << endl;
            continue;
        }

        cout << "Enter Input A (0 or 1): ";
        cin >> a;

        switch (option) {
            case 1: {
                cout << "Enter Input B (0 or 1): "; cin >> b;
                AndGate myAnd;
                // Using overloaded operator()
                cout << "\n-->>> Result: " << myAnd(a, b) << endl;
                break;
            }
            case 2: {
                cout << "Enter Input B (0 or 1): "; cin >> b;
                OrGate myOr;
                cout << "\n-->>> Result: " << myOr(a, b) << endl;
                break;
            }
            case 3: {
                NotGate myNot;
                cout << "\n-->>> Result: " << myNot(a) << endl;
                break;
            }
            case 4: {
                Buffer myBuf;
                cout << "\n-->>> Result: " << myBuf(a) << endl;
                break;
            }
            case 5: {
                cout << "Enter Input B (0 or 1): "; cin >> b;
                NandGate myNand;
                cout << "\n-->>> Result: " << myNand(a, b) << endl;
                break;
            }
            case 6: {
                cout << "Enter Input B (0 or 1): "; cin >> b;
                NorGate myNor;
                cout << "\n-->>> Result: " << myNor(a, b) << endl;
                break;
            }
            case 7: {
                cout << "Enter Input B (0 or 1): "; cin >> b;
                XorGate myXor;
                cout << "\n-->>> Result: " << myXor(a, b) << endl;
                break;
            }
            case 8: {
                cout << "Enter Input B (0 or 1): "; cin >> b;
                XnorGate myXnor;
                cout << "\n-->>> Result: " << myXnor(a, b) << endl;
                break;
            }
        }
    }

    cout << "\nExiting the simulation ..." << endl;
    return 0;
}

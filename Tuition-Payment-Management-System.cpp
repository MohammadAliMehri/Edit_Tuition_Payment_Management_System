#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct daneshjo
{
    int ID;
    string esm;
    float shahriye;
    float mablagh;
};

void menu()
{
    cout << "System Modiriyate Shahriye Daneshjo " << endl;
    cout << "1. ezafe kardan daneshjo" << endl;
    cout << "2. pardakht" << endl;
    cout << "3. namayesh etelaat daneshjo ba esm ya ID" << endl;
    cout << "4. namayesh hameye daneshjo ha" << endl;
    cout << "5. khoroj" << endl;
    cout << "----------------------------------------" << endl;
}

void afzoodan_daneshjoo()
{
    ifstream infile("tuition.txt");
    daneshjo list[100];
    int tedad = 0;
    while (infile >> list[tedad].ID >> list[tedad].esm >> list[tedad].shahriye >> list[tedad].mablagh) { // Khandan etelaat daneshjo
        tedad++; // Shomarande tedad daneshjo ha
        if (tedad >= 100) { // Baraye inke zarfiat ejad konim
            cout << "Zarfiat takmil" << endl; // error bede agar zarfiat nadare file
            return;
        }
    }
    infile.close();

    daneshjo d;
    ofstream file("tuition.txt", ios::app); // Neveshtan etelaat daneshjo || ios = input/output stream | app = append
    cout << "Vared kardan etelaat daneshjo" << endl;
    cout << "ID: ";
    cin >> d.ID; // ID daneshjo
    for (int i = 0; i < tedad; i++) {
        if (list[i].ID == d.ID) { // Baraye inke agar ID tekrari bashad bege 
            cout << "ID tekrari ast. Lotfan ID mokhtalef vared konid." << endl;
            return;
        }
    }
    cout << "Esm: ";
    cin >> d.esm; // Esm daneshjo
    cout << "Mablagh kol shahriye: ";
    cin >> d.shahriye; // Mablagh kol shahriye
    cout << "Mablaghi ke pardakht mikonid: ";
    cin >> d.mablagh; // Mablagh avalie pardakht shode
    file << d.ID << " " << d.esm << " " << d.shahriye << " " << d.mablagh << endl;
    file.close();
}

void pardakht_shahriye()
{
    string value;
    float poul;
    cout << "Vared kardan ID/esm daneshjo baraye pardakht: ";
    cin >> value; // agar esm vared shod ya id ba hamoon joostojo kone
    cout << "Mablaghi ke mikayd pardakht konid: ";
    cin >> poul;

    ifstream infile("tuition.txt"); // Baz kardan file baraye khandan etelaat
    daneshjo list[100]; // Araye baraye 100 daneshjo
    int tedad = 0;      // Shomarande tedad daneshjo ha

    // 1. Khandan hameye daneshjooha va rikhtan dar araye
    while (infile >> list[tedad].ID >> list[tedad].esm >> list[tedad].shahriye >> list[tedad].mablagh)
    {
        if (list[tedad].ID == atoi(value.c_str()) || list[tedad].esm == value) // baraye inke value ro ba ID ya Esm daneshjoo moghayese kone va poul ezafe kone | atoi(value.c_str()) tabdil string be int tabdil koone
        {   
            list[tedad].mablagh += poul; // Ezafe kardan pool
            break;
        }
        tedad++;
    }
    infile.close();

    if(tedad == 100){
        cout << "Daneshjo ba in ID/esm peyda nashod." << endl;
        return;
    }

    // Neveshtan dobare araye dar file
    ofstream outfile("tuition.txt");
    for (int i = 0; i < 100; i++)
    {
        outfile << list[i].ID << " " << list[i].esm << " " << list[i].shahriye << " " << list[i].mablagh << endl; // Neveshtan etelaat daneshjo ha
    }
    outfile.close();
    cout << "Pardakht ba movafaghiat anjam shod." << endl;
}

void namayesh_etelaat_daneshjo()
{
    cout << "ID/Esm ? ";
    string value;
    cin >> value;
    ifstream file("tuition.txt"); // Baz kardan file baraye khandan etelaat
    daneshjo d;                // Sakhtan yek moteghayer baraye zakhire etelaat daneshjo

    while (file >> d.ID >> d.esm >> d.shahriye >> d.mablagh) // Khandan etelaat daneshjo
    {
        if (d.esm == value || d.ID == atoi(value.c_str())){ // baraye inke value ro ba ID ya Esm daneshjoo moghayese kone | atoi(value.c_str()) tabdil string be int tabdil koone (be soorat automatic tabdil mikone)
            cout << "----------------------------------------" << endl;
            cout << "Etelaat daneshjo:" << endl;
            cout << "ID: " << d.ID << endl;
            cout << "Esm: " << d.esm << endl;
            cout << "Mablagh kol shahriye: " << d.shahriye << endl;  // Namayesh mablagh kol shahriye
            cout << "Mablagh pardakht shode: " << d.mablagh << endl; // Namayesh mablagh pardakht shode

            if (d.mablagh < d.shahriye)
                cout << "Vaziyat: Bedehkar" << endl;
            else
                cout << "Vaziyat: Tasviye shode" << endl;

            file.close();
            return;
        }
    }

    cout << "Daneshjo peyda nashod." << endl;
    file.close();
}

void namayesh_hame()
{
    ifstream file("tuition.txt"); // Baz kardan file baraye khandan etelaat
    daneshjo d;                // Sakhtan yek moteghayer baraye zakhire etelaat daneshjo
    cout << "=== List Hameye Daneshjo ha ===" << endl;
    while (file >> d.ID >> d.esm >> d.shahriye >> d.mablagh) // Khandan etelaat daneshjo
    {
        cout << "ID: " << d.ID << endl;                          // Namayesh ID
        cout << "Esm: " << d.esm << endl;                        // Namayesh esm
        cout << "Mablagh kol shahriye: " << d.shahriye << endl;  // Namayesh mablagh kol shahriye
        cout << "Mablagh pardakht shode: " << d.mablagh << endl; // Namayesh mablagh pardakht shode
        if (d.mablagh < d.shahriye)
            cout << "Vaziyat: Bedehkar" << endl;
        else
            cout << "Vaziyat: Tasviye shode" << endl;
        cout << "----------------------------------------" << endl;
    }
    file.close();
}

int main()
{
    int choice;

    do
    {
        menu();
        cout << ">> ";
        cin >> choice;

        if (cin.fail()) // agar voroodi eshtebahi bashad
        {
            cin.clear();             // baraye inke agar chiz eshtebahi vared shood voroodi pak beshe
            cin.ignore(10000, '\n'); // baraye inke agar chiz eshtebahi vared shood ignore koone
            choice = 0;              // yani ta dorost entekhab nashode sefr ast
            cout << "Lotfan yek adad sahih vared konid." << endl;
            continue;
        }

        switch (choice)
        {
        case 1:
            afzoodan_daneshjoo();
            break;
        case 2:
            pardakht_shahriye();
            break;
        case 3:
            namayesh_etelaat_daneshjo();
            break;
        case 4:
            namayesh_hame();
            break;
        case 5:
            break;
        }
    } while (choice != 5);
    cout << "Bye.";
}
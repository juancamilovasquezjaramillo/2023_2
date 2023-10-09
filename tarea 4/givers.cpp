
///Juan Camilo vasquez Jaramillo
///codigo: 8976396
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
//La función addPerson es O(1).
//La función setGiftMoney es O(n), ya que recorre el vector de personas.
//La función addRecipient es O(n), ya que recorre el vector de personas dos veces en el peor caso.
//La función calculateNet es O(n^2), ya que tiene un bucle anidado para distribuir los regalos entre los destinatarios.
//La función printBalances es O(n).
//Por lo tanto, la complejidad combinada es O(n) + O(n^2) = O(n^2).

using namespace std;

// Define una clase 'Person' para representar a las personas.
class Person {
public:
    string name;           // Nombre de la persona.
    int giftMoney;         // Cantidad de dinero recibida como regalo.
    vector<string> recipients; // Lista de personas que recibieron regalos de esta persona.
    int net;               // Saldo neto.

    Person(string name) {
        this->name = name;
        giftMoney = 0;
        net = 0;
    }
};

// Define una clase 'Calculator' para gestionar los cálculos del intercambio de regalos.
class Calculator {
public:
    // Función para agregar una persona a la lista.
    void addPerson(string name) {
        people.push_back(Person(name));
    }

    // Función para establecer la cantidad de dinero recibida como regalo para una persona.
    void setGiftMoney(string name, int money) {
        for (auto& person : people) {
            if (person.name == name) {
                person.giftMoney = money;
                return;
            }
        }
    }

    // Función para agregar un destinatario a la lista de una persona que dio un regalo.
    void addRecipient(string giverName, string recipientName) {
        for (auto& person : people) {
            if (person.name == giverName) {
                if (find_if(people.begin(), people.end(), [&](const Person& p) { return p.name == recipientName; }) != people.end()) {
                    person.recipients.push_back(recipientName);
                }
                return;
            }
        }
    }

    // Función para calcular los saldos netos.
    void calculateNet() {
        for (auto& person : people) {
            int numRecipients = person.recipients.size();

            if (numRecipients > 0) {
                int gift = person.giftMoney / numRecipients;
                int remaining = person.giftMoney % numRecipients;

                for (auto& recipientName : person.recipients) {
                    for (auto& recipient : people) {
                        if (recipient.name == recipientName) {
                            recipient.net += gift;
                        }
                    }
                }

                person.net -= person.giftMoney;
                person.net += remaining;
            }
        }
    }

    // Función para imprimir los saldos netos de cada persona.
    void printBalances() {
        for (auto& person : people) {
            cout << person.name << " " << person.net << endl;
        }
    }

private:
    vector<Person> people; // Un vector para almacenar la lista de personas.
};

int main() {
    Calculator calc;

    int numPeople;
    cin >> numPeople;

    // Ingresa los nombres de las personas y agrégalos al calculador.
    for (int i = 0; i < numPeople; i++) {
        string name;
        cin >> name;
        calc.addPerson(name);
    }

    // Ingresa el dinero de regalo, los destinatarios y el dinero adicional de regalo.
    for (int i = 0; i < numPeople; i++) {
        string name;
        int money;
        int numRecipients;
        cin >> name >> money >> numRecipients;

        calc.setGiftMoney(name, money);

        for (int j = 0; j < numRecipients; j++) {
            string recipient;
            cin >> recipient;
            calc.addRecipient(name, recipient);
        }
    }

    int additionalPeople;
    cin >> additionalPeople;

    // Ingresa dinero adicional de regalo.
    for (int i = 0; i < additionalPeople; i++) {
        string name;
        cin >> name;
        int money;
        cin >> money;
        calc.setGiftMoney(name, money);
    }

    // Calcula e imprime los saldos netos.
    calc.calculateNet();
    calc.printBalances();

    return 0;
}

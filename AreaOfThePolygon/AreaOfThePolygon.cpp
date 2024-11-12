#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Punkt {
private:
    double x, y;

public:
    // Konstruktory
    Punkt() : x(0), y(0) {}
    Punkt(double x, double y) : x(x), y(y) {}
    Punkt(const Punkt& p) : x(p.x), y(p.y) {}

    // Gettery i settery
    double getX() const { return x; }
    double getY() const { return y; }
    void setX(double x) { this->x = x; }
    void setY(double y) { this->y = y; }

    // Prze³adowane operatory
    Punkt operator+(const Punkt& p) const {
        return Punkt(x + p.x, y + p.y);
    }

    Punkt operator-(const Punkt& p) const {
        return Punkt(x - p.x, y - p.y);
    }

    Punkt& operator=(const Punkt& p) {
        if (this != &p) { // zapobiega przypisaniu do samego siebie
            x = p.x;
            y = p.y;
        }
        return *this;
    }

    friend ostream& operator<<(ostream& out, const Punkt& p) {
        out << "(" << p.x << ", " << p.y << ")";
        return out;
    }

    friend istream& operator>>(istream& in, Punkt& p) {
        in >> p.x >> p.y;
        return in;
    }

    // Iloczyn skalarny (dot product)
    static double iloczynSkalarny(const Punkt& v1, const Punkt& v2) {
        return v1.x * v2.x + v1.y * v2.y;
    }

    // D³ugoœæ wektora
    double dlugosc() const {
        return sqrt(x * x + y * y);
    }

    // Cosinus k¹ta miêdzy dwoma wektorami
    static double cosinusKata(const Punkt& v1, const Punkt& v2) {
        double iloczyn = iloczynSkalarny(v1, v2);
        return iloczyn / (v1.dlugosc() * v2.dlugosc());
    }
};

class Wielokat {
private:
    vector<Punkt> wierzcholki;

public:
    // Konstruktory
    Wielokat() {}
    Wielokat(const vector<Punkt>& punkty) : wierzcholki(punkty) {}
    Wielokat(const Wielokat& wielokat) : wierzcholki(wielokat.wierzcholki) {}

    // Dodawanie wierzcho³ka
    void dodajWierzcholek(const Punkt& p) {
        wierzcholki.push_back(p);
    }

    // Gettery
    Punkt getWierzcholek(int index) const {
        if (index >= 0 && index < wierzcholki.size()) {
            return wierzcholki[index];
        }
        throw out_of_range("Indeks poza zakresem");
    }

    int liczbaWierzcholkow() const {
        return wierzcholki.size();
    }

    // Obliczanie pola wielok¹ta (wzór Gaussa)
    double pole() const {
        double pole = 0;
        int n = wierzcholki.size();
        for (int i = 0; i < n; i++) {
            Punkt p1 = wierzcholki[i];
            Punkt p2 = wierzcholki[(i + 1) % n];
            pole += p1.getX() * p2.getY() - p2.getX() * p1.getY();
        }
        return fabs(pole) / 2.0;
    }

    // Prze³adowane operatory
    friend ostream& operator<<(ostream& out, const Wielokat& wielokat) {
        out << "Wielok¹t o wierzcho³kach: ";
        for (const auto& wierzcholek : wielokat.wierzcholki) {
            out << wierzcholek << " ";
        }
        return out;
    }

    friend istream& operator>>(istream& in, Wielokat& wielokat) {
        int n;
        cout << "Podaj liczbê wierzcho³ków: ";
        in >> n;
        wielokat.wierzcholki.clear();
        for (int i = 0; i < n; ++i) {
            Punkt p;
            cout << "Podaj wierzcho³ek " << i + 1 << ": ";
            in >> p;
            wielokat.dodajWierzcholek(p);
        }
        return in;
    }

    // Operator przypisania
    Wielokat& operator=(const Wielokat& wielokat) {
        if (this != &wielokat) { // zapobiega przypisaniu do samego siebie
            wierzcholki = wielokat.wierzcholki;
        }
        return *this;
    }
};

int main() {
    // Test klasy Punkt
    Punkt p1(3, 4);
    Punkt p2(1, 2);
    cout << "Punkt 1: " << p1 << endl;
    cout << "Punkt 2: " << p2 << endl;

    Punkt p3 = p1 + p2;
    cout << "Punkt 1 + Punkt 2: " << p3 << endl;

    Punkt p4 = p1 - p2;
    cout << "Punkt 1 - Punkt 2: " << p4 << endl;

    cout << "Iloczyn skalarny p1 i p2: " << Punkt::iloczynSkalarny(p1, p2) << endl;
    cout << "Cosinus k¹ta miêdzy p1 i p2: " << Punkt::cosinusKata(p1, p2) << endl;

    // Test klasy Wielok¹t
    Wielokat wielokat;
    wielokat.dodajWierzcholek(Punkt(0, 0));
    wielokat.dodajWierzcholek(Punkt(4, 0));
    wielokat.dodajWierzcholek(Punkt(4, 3));

    cout << "Wielok¹t: " << wielokat << endl;
    cout << "Pole wielok¹ta: " << wielokat.pole() << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class ElectronicDevice{
protected: 
    string Brand;
    string Model; 
public:
    ElectronicDevice(const string& Brand, const string& Model): Brand(Brand), Model(Model){};
    
    virtual void display() const{
        cout << Brand << " " << Model << endl;
    }
    
    void EditBrand(const string& newBrand){
        Brand = newBrand;
    }
    
    void EditModel(const string& newModel){
        Model = newModel;
    }
    
    virtual ~ElectronicDevice(){};
};

class Smartphone: public ElectronicDevice{
protected:
    string os;
public:
    Smartphone(const string& Brand, const string& Model, const string& os): ElectronicDevice(Brand, Model), os(os){};
    void display() const override{
        cout << Brand << " " << Model << " " << os << endl;
    }
    
    ~Smartphone(){};
};

class Laptop: public ElectronicDevice{
protected:
    double screenSize;
public:
    Laptop(const string& Brand, const string& Model, const double& screenSize): ElectronicDevice(Brand, Model), screenSize(screenSize){};
    void display() const override{
        cout << Brand << " " << Model << " " << screenSize << endl;
    }
    
    ~Laptop(){};
};

void editDevice(ElectronicDevice* ptr){
    ptr->EditBrand("New Brand");
    ptr->EditModel("New Model");
}

int main()
{
    vector<ElectronicDevice*> data;
    data.resize(5);
    data[0] = new ElectronicDevice("View Sonic", "VG2755-2K 27");
    data[1] = new Smartphone("Samsung", "Galaxy S23", "Android 14");
    data[2] = new Smartphone("Apple", "iPhone 14", "iOS 16");
    data[3] = new Laptop("Samsung", "Galaxy Book", 15.5);
    data[4] = new Laptop("Apple", "MacBook Air", 16.1);

    for (const auto i: data){
        i->display();
    }
    
    cout << " " << endl;
    
    for (const auto i: data){
        editDevice(i);
        i->display();
        delete i;
    }
    
    return 0;
}

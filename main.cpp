#include <iostream>
#include "firstclass.h"
#include <clocale>
#include <cmath>
#include <string>
#include <typeinfo>

using namespace std;

class food{
public:
    int calorie;
    int gram;
    float price;
    int cooking_time;
    int heating(int time){
        if(time<(cooking_time+3))
            calorie += time;
        else
            calorie=0;
        return 0;

    }
};

class human{
public:
    float lenght;
    float weight;
    int age;
    int to_eat(food y){
        weight += y.calorie/(float)7000;
        return 0;

    }
    void chr_print(string x){
        cout<< endl << x << "'s chromosome number: " << num_of_chr << endl;
    }
    float body_indx();

    // privet olan verilere eriþmek için set ve get
    void setBiogender(string x){
        biogender=x;
    }
    string getBiogender(){
        return biogender;
    }

    void setSkincolor(string x){
        skincolor=x;
    }
    string getSkincolor(){
        return skincolor;
    }
    // overloading örnek ayni isimde farklý içerik alan fonksiyonlar
    void sethome(string x){
        home=x;
    }
    void sethome(string x,string y){
        home=x+"/"+y;
    }
    void setphone(long long x){
        phone= to_string(x);
    }
    void setphone(string x){
        phone=x;
    }



private: // buradaki deðiþkenlere class dýþýndan eriþilemez ve deðiþtirilemez.
    int num_of_chr = 46;
    string biogender;
    string skincolor;
protected: // privat gibi çalýþýr ama developer gibi çocuk classlardan eriþililebilir
    float iq=115;
    string home;
    string phone;

};



float human::body_indx() { // dýþarda fonksiyon ekleme
    return weight/ pow(lenght,2);
}




class developer:public human{
public:
    string knw_lang;
    string knw_os;
    string knw_db;
    string faw_ide;
    string knw_sw;
    string knw_sklls;
    string add_knw(string x){
        string y;
        cout << "What is the information to add?" << x;
        cin >> y;
        x += y;
        return 0;
    }
    void studying(float time){
        iq += time/1000;
    }
    float iqprint (){
        return iq;
    }
};




int main() {
    setlocale(LC_ALL,"Turkish");

    food sausage;
    sausage.calorie=380;
    sausage.gram=270;
    sausage.cooking_time=5;

    food sandwich;
    sandwich.calorie=366;
    sandwich.gram=150;
    sandwich.price=3.90;

    developer hugo;
    hugo.weight=137;
    hugo.lenght=1.81;
    hugo.age=23;
    hugo.knw_lang="C++, Python,";
    hugo.knw_db="MysQl, ";
    hugo.knw_os="Linux, BSD, MacOsX, Windows, ";
    hugo.faw_ide="Clion, PyCharm, Spider, SublimeText, Codelite, ";
    hugo.knw_sklls="Linux Packaging, Linux System Admin, LAMP Server, ";
    hugo.knw_sw="Blender, Gimp, ";
    // hugo.biogender = "Fluid Gender"; privet olan verilere eriþmek için set() ve get() fonksiyonlarý oluþturulmalý.
    hugo.setBiogender("Fluid Gender");
    hugo.setSkincolor("White");

    cout<< "Hugo's weight: " << hugo.weight << " KG" << endl;
    cout << "Hugo is eating a sandwich....."<< endl;
    hugo.to_eat(sandwich);
    cout<< "Hugo's new weight: " << hugo.weight << " KG" << endl;
    cout << endl << "Hugo is cooking sausage." << endl;
    cout << "How many minutes do you cook? : ";
    int time;
    cin >> time;
    sausage.heating(time);
    if (sausage.calorie==0)
        cout << "Hugo burned sausage. :( " << endl;
    else
        cout << "Hugo cooked sausage. :) " << endl;
    hugo.chr_print("Hugo");

    cout << "Hugo's body mass index : " << hugo.body_indx() << endl;
    cout << "Hugo's gender: " << hugo.getBiogender() << " and skin color: " << hugo.getSkincolor() << endl;
    cout << "Hugo's IQ: " << hugo.iqprint() << endl << "Hugo is studying.... ( 60 min )" << endl;
    hugo.studying(60);
    cout << "Hugo's new IQ: " << hugo.iqprint() << endl;







    exit(0);
    return 0;
}

#include <iostream>
#include "json.hpp"

#include <fstream>

int main(){
    Json json;
    std::ofstream file("../bin/test.json");

    json.Insert("name","nekomanma634");
    json.Insert("Job","None");
    json.Insert("userIP",7052);
    json.Insert("gakuseki",240124);
    json.Insert("Denwa", "080-4444-444");
    json.InsertArray("array",{"hoge",100,"mican",200,"kotatu",300});

    json.Update();
    std::cout << json.GetJsonData();
    file      << json.GetJsonData();

    std::cout << "\n\nEnd\n" << std::endl;

    return 0;
}
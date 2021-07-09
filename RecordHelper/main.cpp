#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string set_base_address();

int main() {
    std::cout << "Welcome to the Artifact Impact data record helper!" << std::endl;

    //record_file << "h\n";
    //record_file.close();
    return 0;
}

void ask_attrib_and_write(string address);

void before_enhancement(){
    string base_address = set_base_address();
    string before_address = base_address;
    before_address.append("0.csv");

    cout << "Please enter the number as the type of the artifact "
            "(0: Flower, 1: Plume, 2: Sands, 3: Goblet, 4: Circlet):" << endl;
    int type;
    cin >> type;
    ofstream record_file (before_address, ios::app);
    record_file << type;
    record_file << ",";

    cout << "Please enter the number as the type of the base attribute of the artifact "
            "(0: Flower, 1: Plume, 2: Sands, 3: Goblet, 4: Circlet):" << endl;

    ask_attrib_and_write(before_address);
}

void ask_attrib_and_write(string address){
    ofstream record_file (address, ios::app);
    float value;
    string attrib_keywords[18]
    value
}

float ask_and_return(string prompt){
    cout << prompt << endl;
    float value;
    cin >> value;
    return value;
}


void write_to_file(string address, float value){

}

string set_base_address(){
    std::string record_address_base = "../../Data/";
    std::cout << "Please enter the number as the set of the artifact "
                 "(0: JueDouShi, 1: YueTuan, 2: MoNv, 3: QianYan, 4: ShaoNv, "
                 "5: CuiLv, 6: DuHuo, 7: ChenLun, 8: CangBai, 9: BingFeng):" << std::endl;
    int set_num;
    std::cin >> set_num;
    switch(set_num){
        case 9:
            record_address_base.append("bing_feng/");
            break;
    }
    return record_address_base;
}

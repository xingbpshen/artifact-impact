#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string set_base_address();
void before_enhancement();

int main() {
    std::cout << "Welcome to the Artifact Impact data record helper!" << std::endl;

    before_enhancement();
    return 0;
}

void ask_attrib_and_write(string address);

void before_enhancement(){
    string base_address = set_base_address();
    string before_address = base_address;
    before_address.append("0.csv");

    cout << "Please enter the number as the type of the artifact "
            "\n0: Flower, 1: Plume, 2: Sands, 3: Goblet, 4: Circlet\n>>";
    int type;
    cin >> type;
    ofstream record_file (before_address, ios::app);
    record_file << type;
    record_file << ",";

    cout << "Please enter the number as the type of the base attribute of the artifact "
            "\n0: ATK, 1: ATK%, \n2: DEF, 3: DEF%, \n4: HP, 5: HP%, \n6: CRITRATE%, 7: CRITDMG%, \n8: ELEMASTER, 9: ENERREC%, "
            "\n10: HEALBOU%, \n11: PHYDMG%, 12: PYRODMG%, 13: ELECTRODMG%, 14: CRYODMG%, \n15: HYDRODMG%, 16: ANEMODMG%, 17: GEODMG%\n>>";
    cin >> type;
    record_file << type;
    record_file << ",";
    record_file.close();

    ask_attrib_and_write(before_address);
}

void ask_attrib_and_write(string address){
    ofstream record_file (address, ios::app);
    float value;
    string attrib_keywords[18] = {"ATK", "ATK%", "DEF", "DEF%", "HP", "HP%", "CRITRATE%", "ELEMASTER", "ENERREC%",
                                  "HEALBOU%", "PHYDMG%", "PYRODMG%", "ELECTRODMG%", "CRYODMG%", "HYDRODMG%", "ANEMODMG%", "GEODMG%"};
    cout << attrib_keywords->length();
    for(int i = 0; i < attrib_keywords->size(); i++){

    }
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
                 "\n0: JueDouShi, \n1: YueTuan, \n2: MoNv, \n3: QianYan, \n4: ShaoNv, "
                 "\n5: CuiLv, \n6: DuHuo, \n7: ChenLun, \n8: CangBai, \n9: BingFeng\n>>";
    int set_num;
    std::cin >> set_num;
    switch(set_num){
        case 9:
            record_address_base.append("bing_feng/");
            break;
    }
    return record_address_base;
}

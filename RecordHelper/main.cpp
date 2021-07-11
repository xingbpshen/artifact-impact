#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

#define QUANTITY_OF_SEC_ATTRIB_TYPES 18

string set_base_address();
void before_enhancement();
void fill_in_sec_attributes();
void write_to_data_file();
void after_enhancement(string base_address);
void check_rerun();

//ofstream record_file (artifact.address, ios::app);
//record_file << type;
//record_file << ",";

struct Artifact{
    string address = "-1";
    int type = -1;
    int base_attrib_type = -1;
    float attrib_0[2] = {-1, -1};
    float attrib_1[2] = {-1, -1};
    float attrib_2[2] = {-1, -1};
    float attrib_3[2] = {-1, -1};
};

static Artifact artifact;

int main() {
    std::cout << "Welcome to the Artifact Impact data record helper!" << std::endl;

    before_enhancement();

    check_rerun();
    cout << "Program exit... Thank you for using Artifact Impact - Record Helper!" << endl;
    return 0;
}

void check_rerun(){
    cout << "Record another artifact? (Y/N)\n>>";
    string input;
    cin >> input;
    if(input == "Y" || input == "y"){
        before_enhancement();
        check_rerun();
    } else if(input == "N" || input == "n"){

    } else {
        cout << "Invalid response, please enter Y or N to continue." << endl;
        check_rerun();
    }
}


void before_enhancement(){
    string base_address = set_base_address();
    artifact.address = base_address;
    artifact.address.append("0.csv");

    cout << "Now, the artifact should be at level 0." << endl;
    cout << "Please enter the number as the type of the artifact."
            "\n0: Flower, 1: Plume, 2: Sands, 3: Goblet, 4: Circlet\n>>";
    cin >> artifact.type;

    cout << "Please enter the number as the type of the base attribute of the artifact."
            "\n0: ATK, 1: ATK%, \n2: DEF, 3: DEF%, \n4: HP, 5: HP%, \n6: CRITRATE%, 7: CRITDMG%, \n8: ELEMASTER, 9: ENERREC%, "
            "\n10: HEALBOU%, \n11: PHYDMG%, 12: PYRODMG%, 13: ELECTRODMG%, 14: CRYODMG%, \n15: HYDRODMG%, 16: ANEMODMG%, 17: GEODMG%\n>>";
    cin >> artifact.base_attrib_type;

    fill_in_sec_attributes();

    write_to_data_file();

    after_enhancement(base_address);
}

void after_enhancement(string base_address){
    artifact.address = base_address;
    artifact.address.append("20.csv");
    cout << "Next, please enhance the artifact to level 20." << endl;
    fill_in_sec_attributes();
    write_to_data_file();
    cout << "You are all set, thanks for recording the artifact data." << endl;
}

void write_to_data_file(){
    ofstream recordfile (artifact.address, ios::app);
    recordfile << artifact.type;
    recordfile << ',';
    recordfile << artifact.base_attrib_type;
    recordfile << ',';
    float sec_attrib_comple[QUANTITY_OF_SEC_ATTRIB_TYPES];
    for(float & i : sec_attrib_comple){
        i = 0;
    }
    sec_attrib_comple[(int)artifact.attrib_0[0]] = artifact.attrib_0[1];
    sec_attrib_comple[(int)artifact.attrib_1[0]] = artifact.attrib_1[1];
    sec_attrib_comple[(int)artifact.attrib_2[0]] = artifact.attrib_2[1];
    if(artifact.attrib_3[0] != -1) sec_attrib_comple[(int)artifact.attrib_3[0]] = artifact.attrib_3[1];
    for(float i : sec_attrib_comple){
        recordfile << i;
        recordfile << ',';
    }
    recordfile << '\n';
    recordfile.close();
}

void parse_sec_attrib_input(string input, int pos){
    stringstream ss(input);
    vector<float> v;
    while(ss.good()){
        string substring;
        getline(ss, substring, ',');
        v.push_back(stof(substring));
    }
    artifact.attrib_0[pos] = v[0];
    artifact.attrib_1[pos] = v[1];
    artifact.attrib_2[pos] = v[2];
    if(v.size() == 4)
    artifact.attrib_3[pos] = v[3];
}

void fill_in_sec_attributes(){
    cout << "Please enter numbers as the types of secondary attributes, separate them with commas (e.g. 1,6,7,0)."
            "\n0: ATK, 1: ATK%, \n2: DEF, 3: DEF%, \n4: HP, 5: HP%, \n6: CRITRATE%, 7: CRITDMG%, \n8: ELEMASTER, 9: ENERREC%, "
            "\n10: HEALBOU%, \n11: PHYDMG%, 12: PYRODMG%, 13: ELECTRODMG%, 14: CRYODMG%, \n15: HYDRODMG%, 16: ANEMODMG%, 17: GEODMG%\n>>";
    string input;
    cin >> input;
    parse_sec_attrib_input(input, 0);
    cout << "Please enter corresponding values for previous attributes you have entered, separate them with commas (e.g. 3.6,3.9,7.8,16).\n>>";
    cin >> input;
    parse_sec_attrib_input(input, 1);
}

string set_base_address(){
    std::string record_address_base = "../../Data/";
    std::cout << "Please enter the number as the set of the artifact."
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

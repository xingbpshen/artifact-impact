#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <filesystem>

using namespace std;
namespace fs = std::__fs::filesystem;
using std::__fs::filesystem::current_path;

#define QUANTITY_OF_SEC_ATTRIB_TYPES 18
#define ENABLE_COMBINED_REC 1

string set_base_address();
void before_enhancement();
void fill_in_sec_attributes();
void write_to_data_file();
void after_enhancement(string base_address);
void check_rerun();
int init();

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
static string path;

#if ENABLE_COMBINED_REC
static string com_file_path_base;
static string com_file_path;
#endif

int main() {
    init();
    std::cout << "Welcome to the Artifact Impact data record helper!" << std::endl;

    before_enhancement();

    check_rerun();
    cout << "Program exit... Thank you for using Artifact Impact - Record Helper!" << endl;
    return 0;
}

int init(){
    path = current_path();
    path.append("/Artimpact/RH_data/");
    fs::create_directories(path);
#if ENABLE_COMBINED_REC
    com_file_path_base = path;
    com_file_path_base.append("combined/");
    fs::create_directories(com_file_path_base);
#endif
    return 0;
}

void check_rerun(){
    cout << "Record another artifact? (Y/N)\n>>";
    string input;
    cin >> input;
    if(input == "Y" || input == "y"){
        Artifact new_artifact;
        artifact = new_artifact;
        before_enhancement();
        check_rerun();
    } else if(input == "N" || input == "n"){

    } else {
        cout << "Invalid response, please enter Y or N to continue." << endl;
        check_rerun();
    }
}


void before_enhancement(){
#if ENABLE_COMBINED_REC
    com_file_path = com_file_path_base;
    com_file_path.append("0.csv");
#endif
    string base_address = set_base_address();
    artifact.address = base_address;
    artifact.address.append("0.csv");

    cout << "\nNow, the artifact should be at level 0." << endl;
    cout << "Please enter the number as the type of the artifact."
            "\n0: Flower, 1: Plume, 2: Sands, 3: Goblet, 4: Circlet\n>>";
    cin >> artifact.type;

    cout << "\nPlease enter the number as the type of the base attribute of the artifact."
            "\n0: ATK, 1: ATK%, \n2: DEF, 3: DEF%, \n4: HP, 5: HP%, \n6: CRITRATE%, 7: CRITDMG%, \n8: ELEMASTER, 9: ENERREC%, "
            "\n10: HEALBOU%, \n11: PHYDMG%, 12: PYRODMG%, 13: ELECTRODMG%, 14: CRYODMG%, \n15: HYDRODMG%, 16: ANEMODMG%, 17: GEODMG%\n>>";
    cin >> artifact.base_attrib_type;

    fill_in_sec_attributes();

    write_to_data_file();

    after_enhancement(base_address);
}

void after_enhancement(string base_address){
#if ENABLE_COMBINED_REC
    com_file_path = com_file_path_base;
    com_file_path.append("20.csv");
#endif
    artifact.address = base_address;
    artifact.address.append("20.csv");
    cout << "\nNext, please enhance the artifact to level 20." << endl;
    fill_in_sec_attributes();
    write_to_data_file();
    cout << "\nYou are all set, thanks for recording the artifact data." << endl;
    cout << "Data saved under ";
    cout << path << endl;
}

void write(string input_path){
    ofstream recordfile (input_path, ios::app);
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

void write_to_data_file(){
    write(artifact.address);
#if ENABLE_COMBINED_REC
    write(com_file_path);
#endif
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
    cout << "\nPlease enter numbers as the types of secondary attributes, separate them with commas (e.g. 1,6,7,0)."
            "\n0: ATK, 1: ATK%, \n2: DEF, 3: DEF%, \n4: HP, 5: HP%, \n6: CRITRATE%, 7: CRITDMG%, \n8: ELEMASTER, 9: ENERREC%, "
            "\n10: HEALBOU%, \n11: PHYDMG%, 12: PYRODMG%, 13: ELECTRODMG%, 14: CRYODMG%, \n15: HYDRODMG%, 16: ANEMODMG%, 17: GEODMG%\n>>";
    string input;
    cin >> input;
    parse_sec_attrib_input(input, 0);
    cout << "\nPlease enter corresponding values for previous attributes you have entered, separate them with commas (e.g. 3.6,3.9,7.8,16).\n>>";
    cin >> input;
    parse_sec_attrib_input(input, 1);
}

string set_base_address(){
    std::string record_address_base = path;
    std::cout << "Please enter the number as the set of the artifact."
                 "\n0: JueDouShi, \n1: YueTuan, \n2: MoNv, \n3: QianYan, \n4: ShaoNv, "
                 "\n5: CuiLv, \n6: DuHuo, \n7: ChenLun, \n8: CangBai, \n9: BingFeng, "
                 "\n10: ZongShi, \n11: RanXue, \n12: RuLei, \n13: NiFei, \n14: PanYan, \n15: PingLei\n>>";
    int set_num;
    std::cin >> set_num;
    switch(set_num){
        case 0:
            record_address_base.append("jue_dou_shi/");
            break;
        case 1:
            record_address_base.append("yue_tuan/");
            break;
        case 2:
            record_address_base.append("mo_nv/");
            break;
        case 3:
            record_address_base.append("qian_yan/");
            break;
        case 4:
            record_address_base.append("shao_nv/");
            break;
        case 5:
            record_address_base.append("cui_lv/");
            break;
        case 6:
            record_address_base.append("du_huo/");
            break;
        case 7:
            record_address_base.append("chen_lun/");
            break;
        case 8:
            record_address_base.append("cang_bai/");
            break;
        case 9:
            record_address_base.append("bing_feng/");
            break;
        case 10:
            record_address_base.append("zong_shi/");
            break;
        case 11:
            record_address_base.append("ran_xue/");
            break;
        case 12:
            record_address_base.append("ru_lei/");
            break;
        case 13:
            record_address_base.append("ni_fei/");
            break;
        case 14:
            record_address_base.append("pan_yan/");
            break;
        case 15:
            record_address_base.append("ping_lei/");
            break;
        default:
            cout << "Invalid input, please try again." << endl;
            set_base_address();
    }
    fs::create_directories(record_address_base);
    return record_address_base;
}

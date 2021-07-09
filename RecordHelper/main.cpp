#include <iostream>
#include <fstream>

using namespace std;

string set_base_address();

int main() {
    std::cout << "Welcome to the Artifact Impact data record helper!" << std::endl;

    //ofstream record_file ("../../Data/bing_feng/0.csv", ios::app);
    string base_address = set_base_address();
    
    //record_file << "h\n";
    //record_file.close();
    return 0;
}

string set_base_address(){
    std::string record_address_base = "../../Data/";
    std::cout << "Please enter the number as the set of the artifact (0: JueDouShi, 1: YueTuan, 2: MoNv, 3: QianYan, 4: ShaoNv, "
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

import sys
import warnings
warnings.filterwarnings("ignore")
import numpy as np
import joblib
from tensorflow import *

min_x_set = 0
max_x_set = 717
min_y_set = 0
max_y_set = 717

model = joblib.load('model.pkl')


def read_from_input(prompt):
    element = str(input(prompt))
    element = np.array(element.split(','))
    element = np.ndarray.astype(element, float)
    return element


def check_continue():
    string = str(input("\nEstimate another artifact? (Y/N)\n>>"))
    if string == "Y" or string == "y":
        start()
    elif string == "N" or string == "n":
        return
    else:
        sys.stdout.write("\nInvalid input, please enter Y or N.")
        check_continue()


def start():
    data = np.array([0, 0])
    data_2 = np.array([0, 0, 0, 0, 0, 0, 0, 0, 0, 0])
    # read_from_input("Please enter the number as the set of the artifact."
    #                          "\n0: JueDouShi, \n1: YueTuan, \n2: MoNv, \n3: QianYan, \n4: ShaoNv, "
    #                          "\n5: CuiLv, \n6: DuHuo, \n7: ChenLun, \n8: CangBai, \n9: BingFeng, "
    #                          "\n10: ZongShi, \n11: RanXue, \n12: RuLei, \n13: NiFei, \n14: PanYan, \n15: PingLei\n")
    data[0] = read_from_input("\nNow, the artifact should be at level 0.\nPlease enter the number as the type of the "
                              "artifact. "
                              "\n0: Flower, 1: Plume, 2: Sands, 3: Goblet, 4: Circlet\n>>")
    data[1] = read_from_input("\nPlease enter the number as the type of the base attribute of the artifact."
                              "\n0: ATK,        1: ATK%, "
                              "\n2: DEF,        3: DEF%, "
                              "\n4: HP,         5: HP%, "
                              "\n6: CRITRATE%,  7: CRITDMG%, "
                              "\n8: ELEMASTER, "
                              "\n9: ENERREC%, "
                              "\n10: HEALBOU%, "
                              "\n11: PHYDMG%, "
                              "\n12: PYRODMG%,  13: ELECTRODMG%, "
                              "\n14: CRYODMG%,  15: HYDRODMG%, "
                              "\n16: ANEMODMG%, 17: GEODMG%\n>>")

    temp = np.ndarray.astype(
        read_from_input("\nPlease enter numbers as the types of secondary attributes, separate them with commas (e.g. "
                        "1,6,7,0). "
                        "\n0: ATK,       1: ATK%, "
                        "\n2: DEF,       3: DEF%, "
                        "\n4: HP,        5: HP%, "
                        "\n6: CRITRATE%, 7: CRITDMG%, "
                        "\n8: ELEMASTER, "
                        "\n9: ENERREC%\n>>"), int)
    temp_2 = read_from_input("\nPlease enter corresponding values for previous attributes you have entered, separate "
                             "them with commas (e.g. 3.6,3.9,7.8,16).\n>>")
    data_2[temp[0]] = temp_2[0]
    data_2[temp[1]] = temp_2[1]
    data_2[temp[2]] = temp_2[2]
    if len(temp) == 4:
        data_2[temp[3]] = temp_2[3]
        if (temp[0] != 6) and (temp[0] != 7) and (temp[1] != 6) and (temp[1] != 7) and (temp[2] != 6) and (temp[2] != 7) and (temp[3] != 6) and (temp[3] != 7):
            sys.stdout.write("\nThe estimated final total CRIT (CRITRATE * 2 + CRITDMG) is: \n")
            sys.stdout.write("0.00")
            sys.stdout.write("\n")
            check_continue()
            return
    data = np.ndarray.astype(data, float)
    data_2 = np.ndarray.astype(data_2, float)
    data = np.append(data, data_2)

    data = (data - min_x_set) / (max_x_set - min_x_set)
    data = np.reshape(data, (1, 12))
    pred = model.predict(data) * (max_y_set - min_y_set) + min_y_set
    pred = np.reshape(pred, (12,))
    sys.stdout.write("\nThe estimated final total CRIT (CRITRATE * 2 + CRITDMG) is: \n")
    sys.stdout.write(str(pred[8] * 2 + pred[9]))
    sys.stdout.write("\n")
    check_continue()


sys.stdout.write("\n\n\nWelcome to Artifact Impact - Estimator v1.0!\n")
start()

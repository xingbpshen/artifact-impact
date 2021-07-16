import numpy as np
import joblib
from tensorflow import *


def read_from_input(prompt):
    element = str(input(prompt))
    element = np.array(element.split(','))
    element = np.ndarray.astype(element, float)
    return element


model = joblib.load('model.pkl')
data = np.array([0, 0])
data_2 = np.array([0, 0, 0, 0, 0, 0, 0, 0, 0, 0])
# read_from_input("Please enter the number as the set of the artifact."
#                          "\n0: JueDouShi, \n1: YueTuan, \n2: MoNv, \n3: QianYan, \n4: ShaoNv, "
#                          "\n5: CuiLv, \n6: DuHuo, \n7: ChenLun, \n8: CangBai, \n9: BingFeng, "
#                          "\n10: ZongShi, \n11: RanXue, \n12: RuLei, \n13: NiFei, \n14: PanYan, \n15: PingLei\n")
print("Welcome to Artifact Impact - Estimator v.1.0b!")
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
if len(temp) is 4:
    data_2[temp[3]] = temp_2[3]

data = np.ndarray.astype(data, float)
data_2 = np.ndarray.astype(data_2, float)
data = np.append(data, data_2)

# data = np.array([4, 5, 0, 0, 21, 0, 299, 0, 3.4, 0, 0, 4.5])
data = data / 508
data = np.reshape(data, (1, 12))
pred = model.predict(data) * 508
pred = np.reshape(pred, (12, ))
print("\nThe estimated final total CRIT (CRITRATE * 2 + CRITDMG) is: ")
print(pred[8] * 2 + pred[9])

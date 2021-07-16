import joblib
import numpy as np


def read_file(file_path):
    train_x = np.genfromtxt(file_path + '/0.csv', delimiter=',')
    train_y = np.genfromtxt(file_path + '/20.csv', delimiter=',')
    train_x = train_x[~np.isnan(train_x)]
    train_y = train_y[~np.isnan(train_y)]
    return train_x, train_y


def preprocessing(train_x, train_y):
    train_x = (train_x - 0) / (508 - 0)
    train_y = (train_y - 0) / (508 - 0)
    train_x = np.reshape(train_x, ((int)(len(train_x) / 12), 12))
    train_y = np.reshape(train_y, ((int)(len(train_y) / 12), 12))
    return train_x, train_y


model = joblib.load('/Users/AntonioShen/MLProjects/artifact-impact/ArtifactImpact/model.pkl');
test_x, test_y = read_file('/Users/AntonioShen/MLProjects/artifact-impact/Data/testing/')
test_x, test_y = preprocessing(test_x, test_y)

score = model.evaluate(test_x, test_y)

print(score[1] * 100)

exit()

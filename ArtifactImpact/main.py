import numpy as np
from keras.models import Sequential
from keras.layers import Dense
from keras.layers import Dropout
import joblib


def read_file(file_path):
    train_x = np.genfromtxt(file_path + '/0.csv', delimiter=',')
    train_y = np.genfromtxt(file_path + '/20.csv', delimiter=',')
    train_x = train_x[~np.isnan(train_x)]
    train_y = train_y[~np.isnan(train_y)]
    return train_x, train_y


def preprocessing(train_x, train_y):
    min = train_y[np.argmin(train_y)]
    max = train_y[np.argmax(train_y)]
    train_x = (train_x - min) / (max - min)
    train_y = (train_y - min) / (max - min)
    train_x = np.reshape(train_x, ((int)(len(train_x) / 12), 12))
    train_y = np.reshape(train_y, ((int)(len(train_y) / 12), 12))
    return train_x, train_y


train_x, train_y = read_file('/Users/AntonioShen/MLProjects/artifact-impact/Data/training')
train_x, train_y = preprocessing(train_x, train_y)

model = Sequential()
model.add(Dense(12, activation='tanh'))
model.add(Dense(32, activation='tanh'))
model.add(Dense(32, activation='relu'))
model.add(Dense(12, activation='relu'))

model.compile(optimizer='rmsprop', loss='mean_squared_logarithmic_error', metrics=['accuracy'])
model.fit(train_x, train_y, epochs=400, verbose=2, batch_size=4)

joblib.dump(model, '/Users/AntonioShen/MLProjects/artifact-impact/ArtifactImpact/model.pkl')
exit()

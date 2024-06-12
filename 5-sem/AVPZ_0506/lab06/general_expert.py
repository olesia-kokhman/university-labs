import csv

import numpy as np


class GeneralExpert:
    def __init__(self, index, name, weight):
        self.index = index
        self.name = name
        self.marks = []
        self.indicator_weights = []
        self.load_marks()
        self.load_indicator_weights()
        self.weight = weight

    def load_marks(self):
        path = f"data//experts_marks//{self.index}.csv"

        print(f"Load marks from {self.name} experts from {path}")

        data = []

        with open(path, 'r') as file:
            csv_reader = csv.reader(file)
            for row in csv_reader:
                data = [int(val) for val in row]

        matrix = np.array(data)
        self.marks = matrix

    def load_indicator_weights(self):
        path = f"data//indicator_weights//{self.index}.csv"

        print(f"Load indicator weights for experts from {path}")

        data = []

        with open(path, 'r') as file:
            csv_reader = csv.reader(file)
            for row in csv_reader:
                data = [int(val) for val in row]

        matrix = np.array(data)
        self.indicator_weights = matrix

    def average_mark_value(self): # 8.32
        return np.sum(self.mark_values()/np.sum(self.indicator_weights))

    def mark_values(self):
        return [self.marks[i] * self.indicator_weights[i] for i in range(len(self.marks))]

    def mark_values_with_weight(self):
        return [el * self.weight for el in self.mark_values()]

    def average_mark_value_with_weight(self): # 5.82
        return self.average_mark_value() * self.weight

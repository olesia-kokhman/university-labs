import csv

import numpy as np


class DynamicExperts:
    def __init__(self, index, name, weight):
        self.index = index
        self.name = name
        self.marks = []
        self.indicator_weights = []
        self.expert_weights = []
        self.load_marks()
        self.load_indicator_weights()
        self.load_expert_weights()
        self.weight = weight

    def load_marks(self):
        path = f"data//experts_marks//{self.index}.csv"

        print(f"Load marks from {self.name} experts from {path}")

        data = []

        with open(path, 'r') as file:
            csv_reader = csv.reader(file)
            for row in csv_reader:
                data.append([int(val) for val in row])

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

    def load_expert_weights(self):
        path = f"data//expert_weights.csv"

        print(f"Expert weights for {self.name} dynamic experts from {path}")

        data = []

        with open(path, 'r') as file:
            csv_reader = csv.reader(file)
            for row in csv_reader:
                data.append([int(val) for val in row])

        matrix = np.array(data)
        self.expert_weights = matrix[self.index - 1]


    def average_mark_value(self):
        return np.sum(self.mark_values()/np.sum(self.indicator_weights))

    def mark_values(self):
        return [np.average([self.marks[i]]) * self.indicator_weights[i] for i in range(len(self.marks))]

    def mark_values_with_weight(self):
        return [el * self.weight for el in self.mark_values()]

    def average_mark_value_with_weight(self):
        return self.average_mark_value() * self.weight

import numpy as np


class AverageExpert:
    def __init__(self, experts, name):
        self.name = name
        self.experts = experts
        self.indicator_weights = [self.average_indicator_weight(i) for i in range(len(self.experts[0].indicator_weights))]


    def mark_values_with_weight(self):
        return [self.mark_value_with_weight(i) for i in range(len(self.experts[0].mark_values_with_weight()))]

    def average_mark_value_with_weight(self):
        return np.average([self.average_indicator_weight(i) for i in range(len(self.experts[0].indicator_weights))])

    def average_indicator_weight(self, i):
        return np.average([expert.indicator_weights[i] for expert in self.experts])

    def mark_value_with_weight(self, i):
        return np.average([expert.mark_values_with_weight()[i] for expert in self.experts])
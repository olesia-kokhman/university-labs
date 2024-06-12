import numpy as np


class IndicatorData:
    def __init__(self, experts):
        self.experts = experts

    def complex_expert_indicators(self):
        return [self.complex_expert_indicator(i) for i in range(len(self.experts[0].mark_values()))]

    def complex_expert_indicator(self, i):
        return sum([expert.mark_values()[i] * expert.weight for expert in self.experts])/ self.weight_sum()

    def complex_total_indicators(self):
        return [self.complex_total_indicator(i) for i in range(len(self.experts[0].mark_values()))]

    def complex_total_indicator(self, i):
        return self.complex_expert_indicator(i) / self.average_indicator_weight(i)

    def average_complex_expert_indicator(self):
        return np.average(self.complex_expert_indicators()) / self.average_total_indicator_weight()

    def average_complex_total_indicator(self):
        return np.average(self.complex_total_indicators())

    def average_mark_value_total_indicator_with_weight(self):
        return np.sum([expert.average_mark_value_with_weight() for expert in self.experts]) / self.weight_sum()

    def weight_sum(self):
        return sum([expert.weight for expert in self.experts])

    def average_indicator_weight(self, i):
        return np.average([expert.indicator_weights[i] for expert in self.experts])

    def average_total_indicator_weight(self):
        return np.average([self.average_indicator_weight(i) for i in range(len(self.experts[0].indicator_weights))])

    def average_total_mark_value(self):
        return np.average([expert.average_mark_value() for expert in self.experts])
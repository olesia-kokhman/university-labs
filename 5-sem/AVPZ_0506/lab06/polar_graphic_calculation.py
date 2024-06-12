import math


class PolarGraphicCalculation:
    def __init__(self, expert, indicator_data):
        self.expert = expert
        self.indicator_data = indicator_data

    def betas(self):
        return [360 * weight / sum(self.expert.indicator_weights) for weight in self.expert.indicator_weights]

    def alphas(self):
        alpha = -self.betas()[0] / 2

        result = [alpha]

        for beta in self.betas()[0:]:
            alpha = alpha + beta
            result.append(alpha)

        return result

    def degrees(self):
        return [(self.alphas()[i + 1] + self.alphas()[i])/2 for i in range(len(self.alphas()[1:]))]

    def a_points(self):
        return [self.expert.mark_values_with_weight()[i] * math.sin(math.radians(self.degrees()[i])) for i in range(len(self.expert.mark_values_with_weight()))]

    def b_points(self):
        return [self.expert.mark_values_with_weight()[i] * math.cos(math.radians(self.degrees()[i])) for i in range(len(self.expert.mark_values_with_weight()))]

    def area(self):
        a = self.a_points() + [self.a_points()[0]]
        b = self.b_points() + [self.b_points()[0]]

        return sum([math.fabs(a[i] * b[i + 1] - b[i] * a[i + 1]) for i in range(len(self.betas()))]) / 2.0

    def z(self):
        return self.area() / (math.pi * 100 * 100)
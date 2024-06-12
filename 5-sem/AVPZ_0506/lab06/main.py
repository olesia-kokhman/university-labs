import numpy as np
from matplotlib import pyplot as plt

from average_expert import AverageExpert
from dynamic_experts import DynamicExperts
from polar_graphic_calculation import PolarGraphicCalculation
from general_expert import GeneralExpert
from indicator_data import IndicatorData
from indicators_formatter import IndicatorsFormatter
from polar_graphics_visualization import PolarGraphicsVisualization


def start():
    branch_expert = GeneralExpert(1, "branch expert", 0.7)
    usability_expert = GeneralExpert(2, "usability expert", 0.8)
    programming_expert = GeneralExpert(3, "programming expert", 0.9)
    user_dynamic_experts = DynamicExperts(4, "users", 0.5)

    indicator_data = IndicatorData([branch_expert, usability_expert, programming_expert, user_dynamic_experts])

    experts = [branch_expert, usability_expert, programming_expert, user_dynamic_experts]

    formatter = IndicatorsFormatter(experts, indicator_data)
    print(formatter.expert_weights_table())
    print(formatter.general_table())

    experts_for_graphics = experts.copy()
    average_expert = AverageExpert(experts, "average expert")
    experts_for_graphics.append(average_expert)

    polar_graphic_calculations = []
    for expert in experts_for_graphics:
        polar_graphic_calculations.append(PolarGraphicCalculation(expert, indicator_data))

    polar_graphics_visualization = PolarGraphicsVisualization(polar_graphic_calculations)
    polar_graphics_visualization.plot()


if __name__ == '__main__':
    start()

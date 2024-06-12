import pandas as pd
from tabulate import tabulate


class IndicatorsFormatter:
    def __init__(self, experts, indicator_data):
        self.experts = experts
        self.indicator_data = indicator_data

    def general_table(self):
        index = list(range(1, len(self.experts[0].marks) + 1))

        columns = []
        averages = {}
        averages_with_weight = {}

        for expert in self.experts:
            series = pd.Series(expert.mark_values(), name=f"{expert.name} marks", index=index)
            columns.append(series)
            averages[series.name] = expert.average_mark_value()
            averages_with_weight[series.name] = expert.average_mark_value_with_weight()

        columns.append(pd.Series(self.indicator_data.complex_expert_indicators(), name="Σw_(ij)*x_(ij)*q_k/Σq_k", index=index))
        averages[columns[-1].name] = self.indicator_data.average_complex_expert_indicator()
        averages_with_weight[columns[-1].name] = self.indicator_data.average_total_mark_value()

        columns.append(pd.Series(self.indicator_data.complex_total_indicators(), name="X_i", index=index))
        averages[columns[-1].name] = self.indicator_data.average_complex_total_indicator()
        averages_with_weight[columns[-1].name] = self.indicator_data.average_mark_value_total_indicator_with_weight()

        result = pd.concat(columns, axis=1)

        result.loc[len(result) + 1] = averages
        result.loc[len(result) + 1] = averages_with_weight

        index.append("Average marks")
        index.append("Marks with expert weight")

        result = result.set_axis(index, axis="index")

        return tabulate(result.round(2), headers='keys', tablefmt='heavy_grid')

    def expert_weights_table(self):
        values = [expert.weight for expert in self.experts]

        index = [expert.name for expert in self.experts]

        return tabulate(pd.DataFrame(values, index=index, columns=["Weight Value"]), headers='keys', tablefmt='heavy_grid')

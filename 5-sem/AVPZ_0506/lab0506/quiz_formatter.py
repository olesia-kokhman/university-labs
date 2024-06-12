import pandas as pd
from tabulate import tabulate


class QuizFormatter:
    ROUND_NUMBER = 4

    def __init__(self, quiz):
        pd.options.display.float_format = '{:,.4f}'.format
        self.quiz = quiz

    def quiz_table(self):
        index = range(1, len(self.quiz.risks) + 1)
        table = pd.DataFrame(self.quiz.risks, columns=range(1, len(self.quiz.risks[0]) + 1), index=index)
        risk_column = pd.Series(self.quiz.risk_possibilities(), name='Risk (ER)', index=index)
        loss_column = pd.Series(self.quiz.losses, name='Loss (LRER)', index=index)
        risk_amount_column = pd.Series(self.quiz.risk_possibility_amounts(), name='Risk Amount (VRER)', index=index)
        ranking_column = pd.Series(self.ranking_mapping(), name=self.ranking_name(), index=index)

        result = pd.concat([table, risk_column, loss_column, risk_amount_column, ranking_column], axis=1)

        return tabulate(result.round(self.ROUND_NUMBER), headers='keys', tablefmt='heavy_grid')

    def ranking_mapping(self):
        mapping = [None] * len(self.quiz.risks)
        for key, array in self.quiz.interval_ranking().items():
            for index in array:
                mapping[index] = self.humanized_ranking_keys()[key]

        return mapping

    def ranking_name(self):
        intervals = self.quiz.ranking_intervals()

        intervals = [round(i, self.ROUND_NUMBER) for i in intervals]

        return f"Ranking [{intervals[0]}, {intervals[1]}), [{intervals[1]}, {intervals[2]}), ({intervals[2]}, {intervals[3]}]"

    def aggregated_risks_table(self):
        mapping_names = [f"{self.humanized_aggregated_risk_possibility_keys()[i]} Risks" for i in self.quiz.risk_type_ranges()]

        table = pd.DataFrame(self.quiz.aggregated_risk_possibility().values(), columns=["Value"], index=mapping_names)

        return tabulate(table, headers='keys', tablefmt='heavy_grid')

    def humanized_ranking_keys(self):
        return {
            1: "Low ranking",
            2: "Medium ranking",
            3: "High ranking",
            4: "High ranking"
        }

    def humanized_aggregated_risk_possibility_keys(self):
        return {
            self.quiz.risk_type_ranges()[0]: "Technical",
            self.quiz.risk_type_ranges()[1]: "Cost",
            self.quiz.risk_type_ranges()[2]: "Planning",
            self.quiz.risk_type_ranges()[3]: "Managing",
        }
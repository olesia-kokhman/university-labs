import csv
import numpy as np


class RiskQuiz:
    def __init__(self, risks_data_path='data//quiz//risks.csv', losses_data_path='data//quiz//losses.csv'):
        self.risks = []
        self.losses = {}
        self.risks_data_path = risks_data_path
        self.losses_data_path = losses_data_path
        self.load_risks()
        self.load_losses()

    def load_risks(self):
        csv_file_path = self.risks_data_path

        print(f"Load risk quiz from specialists from {csv_file_path}")

        data = []

        with open(csv_file_path, 'r') as file:
            csv_reader = csv.reader(file)
            for row in csv_reader:
                data.append([float(val) for val in row])

        matrix = np.array(data)
        self.risks = matrix

    def load_losses(self):
        csv_file_path = self.losses_data_path

        print(f"Load losses quiz from specialists from {csv_file_path}")

        data = []

        with open(csv_file_path, 'r') as file:
            csv_reader = csv.reader(file)
            for row in csv_reader:
                data = [float(val) for val in row]

        matrix = np.array(data)
        self.losses = matrix

    def risk_possibilities(self):
        possibilities = []

        for row in self.risks:
            possibilities.append(np.average(row))

        return possibilities

    def aggregated_risk_possibility(self):
        possibilities = {}

        for i_range in self.risk_type_ranges():
            possibilities[i_range] = (np.sum(self.risk_possibilities()[i_range.start:i_range.stop]) / self.agregated_risks_sum())

        return possibilities

    def agregated_risks_sum(self):
        return np.sum(self.risk_possibilities())

    def risk_possibility_amounts(self):
        losses = self.losses

        risks = self.risk_possibilities()

        return risks * losses

    def ranking_intervals(self):
        possibilitites = self.risk_possibility_amounts()

        min_value = np.min(possibilitites)
        max_value = np.max(possibilitites)
        mpr = (max_value - min_value) / 3

        return [min_value, min_value + mpr, min_value + 2 * mpr, max_value]

    def interval_ranking(self):
        possibilitites = self.risk_possibility_amounts()

        ranks = np.digitize(possibilitites, self.ranking_intervals())

        grouped_by_intervals = {}

        for i in np.unique(ranks):
            grouped_by_intervals[i] = []

        for i in range(len(possibilitites)):
            grouped_by_intervals[ranks[i]].append(i)

        return grouped_by_intervals

    def risk_type_ranges(self):
        return [range(11), range(11, 19), range(19, 30), range(30, 46)]

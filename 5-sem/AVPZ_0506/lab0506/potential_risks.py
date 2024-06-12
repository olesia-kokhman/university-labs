import csv
import numpy as np


class PotentialRisks:
    RISK_NAMES = ["technical_risks", "valuable_risks", "planning_risks", "realization_risks"]

    def __init__(self, kind=None, risks={}):
        self.risks = risks
        self.kind = kind
        if kind:
            self.load_risks()

    def load_risks(self):
        print(f"Load potential risks from csv with kind: {self.kind}")

        for risk_name in self.RISK_NAMES:
            csv_file_path = f'data//{self.kind}_{risk_name}.csv'
            print(csv_file_path)

            data = []

            with open(csv_file_path, 'r') as file:
                csv_reader = csv.reader(file)
                for row in csv_reader:
                    data = [int(i) for i in row]

            matrix = np.array(data)
            self.risks[risk_name] = matrix

    def risk_count(self):
        count = 0
        for array in list(self.risks.values()):
            count += array.size
        return count

    def risk_possibilities(self):
        possibilities = {}

        for key, value in self.risks.items():
            possibilities[key] = np.sum(value) * 1.0 / self.risk_count()

        return possibilities

    def risks_sum(self):
        total_sum = 0

        for array in self.risk_possibilities().values():
            total_sum += np.sum(array)
        return total_sum


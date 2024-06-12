import csv

import numpy as np


class Activities:
    def __init__(self):
        self.solutions = []
        self.load_activities()

    def load_activities(self):
        csv_file_path = f'data//quiz//activities.csv'

        print(f"Load activities from {csv_file_path}")

        data = []

        with open(csv_file_path, 'r') as file:
            csv_reader = csv.reader(file)
            for row in csv_reader:
                data.append([float(val) for val in row])

        matrix = np.array(data)
        self.solutions = matrix

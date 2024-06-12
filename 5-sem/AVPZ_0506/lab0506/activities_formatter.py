import pandas as pd
from tabulate import tabulate


class ActivitiesFormatter:
    def __init__(self, activities):
        self.activities = activities

    def activity_table(self):
        index = range(1, len(self.activities.solutions) + 1)
        table = pd.DataFrame(self.activities.solutions, columns=['Activity index', 'Risk index'], index=index)

        return tabulate(table, headers='keys', tablefmt='heavy_grid')

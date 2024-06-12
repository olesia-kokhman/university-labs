import pandas as pd
from tabulate import tabulate


class PotentialRisksFormatter:
    def __init__(self, potential_risks):
        self.potential_risks = potential_risks

    def risks(self):
        risks = []

        index = []

        for key, array in self.potential_risks.risks.items():
            i = 1
            for el in array:
                index.append(f"{key} {i}")
                risks.append(el)
                i += 1

        table = pd.DataFrame(risks, columns=['Risk'], index=index)

        return tabulate(table, headers='keys', tablefmt='heavy_grid')

    def risks_possibilities_table(self):
        table = pd.DataFrame(self.potential_risks.risk_possibilities().values(), columns=['Value'], index=self.potential_risks.risk_possibilities().keys())

        return tabulate(table, headers='keys', tablefmt='heavy_grid')

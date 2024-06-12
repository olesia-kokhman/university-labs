import math

import numpy as np
from matplotlib import pyplot as plt

class PolarGraphicsVisualization:
    def __init__(self, polar_graphic_calculations):
        self.polar_graphic_calculations = polar_graphic_calculations

    def plot(self):
        num_rows = 2  # Number of rows for subplots
        num_cols = (len(self.polar_graphic_calculations) + 1) // num_rows  # Number of columns

        fig, axs = plt.subplots(num_rows, num_cols, subplot_kw={'projection': 'polar'})

        fig.set_size_inches(8, 8)

        for i in range(len(self.polar_graphic_calculations)):
            row = i // num_cols
            col = i % num_cols
            self.subplot(self.polar_graphic_calculations[i], fig, axs[row, col])

        # If the number of subplots is odd, remove the empty subplot
        if len(self.polar_graphic_calculations) % 2 == 1:
            fig.delaxes(axs.flatten()[-1])  # Remove the last empty subplot

        plt.tight_layout()  # Adjusts subplot parameters for better layout
        plt.show()

    def subplot(self, polar_graphic_calculation, fig, ax):
        theta = np.deg2rad(polar_graphic_calculation.degrees() + [360])

        expert = polar_graphic_calculation.expert

        array = expert.mark_values_with_weight()
        array.append(expert.mark_values_with_weight()[0])
        ax.set_facecolor((0, 197/256, 0, 0.37))
        ax.fill(theta, array, color="yellow")

        ax.plot(theta, array, marker='o')

        ax.set_title(f'Diagram for {expert.name}')
        ax.text(theta[4], 80, f'$z_Σ$ = {round(polar_graphic_calculation.z(),4)}', weight='bold', bbox={'facecolor': 'white', })
        ax.text(theta[7], 80, f'$S_бк$ = {round(polar_graphic_calculation.area(),4)}', weight='bold', bbox={'facecolor': 'white', })

        ax.set_ylim(0,  100)  # Встановлення меж для радіуса
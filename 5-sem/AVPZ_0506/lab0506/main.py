from contextlib import redirect_stdout

from activities import Activities
from activities_formatter import ActivitiesFormatter
from potential_risks import PotentialRisks
from potential_risks_formatter import PotentialRisksFormatter
from risk_quiz import RiskQuiz
from quiz_formatter import QuizFormatter

def start():
    potential_risks = PotentialRisks("source")
    potential_risks_formatter = PotentialRisksFormatter(potential_risks)
    print("Source of potential risks:")
    print(potential_risks_formatter.risks())
    print("Risk possibility for each type of risk:")
    print(potential_risks_formatter.risks_possibilities_table())
    print("Sum of risk possibilities:")
    print(potential_risks.risks_sum())

    potential_risks = PotentialRisks("identification")
    potential_risks_formatter = PotentialRisksFormatter(potential_risks)
    print("Identification of potential risks:")
    print(potential_risks_formatter.risks())
    print("Risk possibility for each type of risk:")
    print(potential_risks_formatter.risks_possibilities_table())
    print("Sum of risk possibilities:")
    print(potential_risks.risks_sum())

    risk_quiz = RiskQuiz()
    quiz_formatter = QuizFormatter(risk_quiz)
    print("Quiz table:")
    print(quiz_formatter.quiz_table())
    print("Aggregated risk possibility for each type of risk:")
    print(quiz_formatter.aggregated_risks_table())

    activities = Activities()
    activities_formatter = ActivitiesFormatter(activities)
    print("Activities that we need to make to decrease risks:")
    print(activities_formatter.activity_table())

    new_risk_quiz = RiskQuiz("data//quiz//risks_after_activities.csv", "data//quiz//losses_after_activities.csv")
    new_quiz_formatter = QuizFormatter(new_risk_quiz)
    print("Quiz table:")
    print(new_quiz_formatter.quiz_table())
    print("Aggregated risk possibility for each type of risk:")
    print(new_quiz_formatter.aggregated_risks_table())

if __name__ == '__main__':
    start()
    with open('out.txt', 'w+', encoding="utf-8") as f:
        with redirect_stdout(f):
            start()


"""
COMP.CS.100 Tehtävä 3.8.3 Parasetamolin annostelusta
Tekijä: Anna Kleemola, anna.kleemola@tuni.fi
Opiskelijanumero: K431687
"""


def calculate_dose(weight, time, previous_dose):
    """Claculates the dose of parasetamol.


    :param weight: patient's weight.
    :param time: time passed since prev dose.
    :param previous_dose: dose for last 24 hours.
    :return: return next dose.
    """
    if time < 6:
        return 0

    if previous_dose == 4000:
        return 0

    elif previous_dose + weight * 15 > 4000:
        return 4000 - previous_dose

    else:
        return weight * 15



def main():
    weight = int(input("Patient's weight (kg): "))
    time = int(input("How much time has passed from the previous dose (full "
                     "hours): "))
    dose = int(input("The total dose for the last 24 hours (mg): "))
    amount = calculate_dose(weight, time, dose)
    print(f"The amount of Parasetamol to give to the patient: {amount}")

    # calculate_dose assumes parameters to be of type int
    # and they should be passed in the order: weight, time, total_doze_24
    # (or more like the automated tests assume this)


if __name__ == "__main__":
  main()
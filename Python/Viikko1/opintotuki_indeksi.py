"""
COMP.CS.100 Kolmas ohjelma
Tekijä: Anna Kleemola
Opiskelijanumero: K431687
"""

opintotuki = input("Enter the amount of the study benefits: ")
#Muunnetaan merkkijono liukuluvuksi.
opintotuki_liukuluku = float(opintotuki)
indeksikorotus = 1.0117
korotettu_opintotuki = opintotuki_liukuluku * indeksikorotus
uusi_korotettu_tuki = korotettu_opintotuki * indeksikorotus
print("If the index raise is 1.17 percent, the study benefit,")
print("after a raise, would be", korotettu_opintotuki, "euros")
print("and if there was another index raise, the study")
print("benefits would be as much as", uusi_korotettu_tuki, "euros")
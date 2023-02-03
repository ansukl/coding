-- Database basics 2021
-- H4 T1
-- anna.kleemola@tuni.fi

SELECT ingredient_id, ingredient_name, kcal, protein
FROM ingredient
WHERE kcal > 300 OR protein = 0
ORDER BY ingredient_id ASC;

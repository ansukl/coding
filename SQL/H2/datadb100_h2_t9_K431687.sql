-- Database basics 2021
-- H2 T9
-- anna.kleemola@tuni.fi

SELECT ing.ingredient_id, ing.ingredient_name
FROM ingredient ing

LEFT OUTER JOIN contains con
     ON con.ingredient_id = ing.ingredient_id

WHERE ice_cream_id IS NULL


ORDER BY ing.ingredient_id ASC;
-- Database basics 2021
-- H2 T6
-- anna.kleemola@tuni.fi

SELECT DISTINCT con.ingredient_id, ingredient_name
FROM contains con

LEFT OUTER JOIN ingredient ing
    ON con.ingredient_id = ing.ingredient_id


ORDER BY con.ingredient_id ASC;
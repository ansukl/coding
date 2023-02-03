-- Database basics 2021
-- H5.2 T6
-- anna.kleemola@tuni.fi

SELECT ing.ingredient_id, ingredient_name, COUNT(ice_cream_id) AS ice_cream_count
FROM ingredient ing LEFT OUTER JOIN contains con
    ON ing.ingredient_id = con.ingredient_id
GROUP BY ing.ingredient_id, ingredient_name
ORDER BY ing.ingredient_id ASC;

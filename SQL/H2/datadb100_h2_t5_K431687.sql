-- Database basics 2021
-- H2 T5
-- anna.kleemola@tuni.fi

SELECT ice_cream_name
FROM contains con
LEFT OUTER JOIN ice_cream ice
    ON con.ice_cream_id = ice.ice_cream_id

LEFT OUTER JOIN ingredient ing
    ON con.ingredient_id = ing.ingredient_id

WHERE ingredient_name = 'Vanilla extract'

ORDER BY ice_cream_name ASC;
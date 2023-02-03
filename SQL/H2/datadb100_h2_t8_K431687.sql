-- Database basics 2021
-- H2 T8
-- anna.kleemola@tuni.fi

SELECT ingredient_name, ice_cream_name
FROM ingredient ing

LEFT OUTER JOIN contains con
     ON con.ingredient_id = ing.ingredient_id

LEFT OUTER JOIN ice_cream ice
    ON con.ice_cream_id = ice.ice_cream_id


ORDER BY ingredient_name ASC, ice_cream_name ASC;
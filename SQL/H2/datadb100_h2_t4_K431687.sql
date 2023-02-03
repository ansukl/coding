-- Database basics 2021
-- H2 T4
-- anna.kleemola@tuni.fi

SELECT manufacturer_name, ice_cream_name, ingredient_name
FROM contains con
LEFT OUTER JOIN ice_cream ice
    ON con.ice_cream_id = ice.ice_cream_id

    LEFT OUTER JOIN manufacturer man
        ON ice.manufacturer_id = man.manufacturer_id

LEFT OUTER JOIN ingredient ing
    ON con.ingredient_id = ing.ingredient_id

ORDER BY manufacturer_name ASC, ice_cream_name ASC, ingredient_name ASC;
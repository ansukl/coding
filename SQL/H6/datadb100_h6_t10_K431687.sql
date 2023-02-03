-- Database basics 2021
-- H6 T10
-- anna.kleemola@tuni.fi

SELECT man.manufacturer_id, manufacturer_name, COUNT(DISTINCT ice.ice_cream_id) AS ice_creams, COUNT(DISTINCT ingredient_id) AS ingredients
FROM manufacturer man LEFT OUTER JOIN ice_cream ice
    ON man.manufacturer_id = ice.manufacturer_id
    LEFT OUTER JOIN contains con
        ON ice.ice_cream_id = con.ice_cream_id
GROUP BY man.manufacturer_id
ORDER BY man.manufacturer_id ASC;

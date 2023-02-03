-- Database basics 2021
-- H6 T4
-- anna.kleemola@tuni.fi

SELECT manufacturer_id, manufacturer_name
FROM manufacturer
WHERE NOT EXISTS
    (SELECT * FROM ice_cream
    WHERE manufacturer.manufacturer_id = ice_cream.manufacturer_id)
ORDER BY manufacturer_id ASC;

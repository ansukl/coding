-- Database basics 2021
-- H4 T4
-- anna.kleemola@tuni.fi

SELECT ice_cream_name, manufacturer_name, country
FROM ice_cream, manufacturer
WHERE ice_cream.manufacturer_id = manufacturer.manufacturer_id AND
    ice_cream.manufacturer_id = 2 OR ice_cream.manufacturer_id = 3
ORDER BY manufacturer_name ASC, ice_cream_name ASC;

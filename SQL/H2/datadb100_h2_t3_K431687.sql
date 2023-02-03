-- Database basics 2021
-- H2 T3
-- anna.kleemola@tuni.fi
SELECT ice_cream_id, ice_cream_name, manufacturing_cost, manufacturer_name
FROM ice_cream, manufacturer
WHERE ice_cream.manufacturer_id = manufacturer.manufacturer_id AND manufacturing_cost > '1'
ORDER BY ice_cream_id ASC;
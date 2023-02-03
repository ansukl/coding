-- Database basics 2021
-- H6 T2
-- anna.kleemola@tuni.fi

SELECT manufacturer_id, manufacturer_name
FROM manufacturer
WHERE manufacturer_id NOT IN
    (SELECT manufacturer_id FROM ice_cream)
ORDER BY manufacturer_id ASC;


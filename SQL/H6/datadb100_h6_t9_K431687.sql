-- Database basics 2021
-- H6 T9
-- anna.kleemola@tuni.fi

SELECT manufacturer_name
FROM ice_cream ice, manufacturer man
WHERE ice.manufacturer_id = man.manufacturer_id
GROUP BY ice.manufacturer_id
HAVING AVG(manufacturing_cost) > 1.1325;

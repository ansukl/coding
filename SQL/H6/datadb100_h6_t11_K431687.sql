-- Database basics 2021
-- H6 T11
-- anna.kleemola@tuni.fi

SELECT ice_cream_id, ice_cream_name, manufacturing_cost, manufacturer_id, COUNT(DISTINCT manufacturer_id) AS ice_cream_count, AVG(manufacturing_cost) AS avg_cost
FROM ice_cream
ORDER BY ice_cream_count DESC, manufacturer_id ASC, ice_cream_id ASC;

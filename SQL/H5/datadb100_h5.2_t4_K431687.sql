-- Database basics 2021
-- H5.2 T4
-- anna.kleemola@tuni.fi

SELECT man.manufacturer_id, manufacturer_name, COUNT(ice_cream_id) AS ice_cream_count,
    MIN(manufacturing_cost) AS min_cost,
    MAX(manufacturing_cost) AS max_cost
FROM manufacturer man, ice_cream ice
WHERE man.manufacturer_id = ice.manufacturer_id
GROUP BY man.manufacturer_id, manufacturer_name
HAVING COUNT(*) > 0
ORDER BY man.manufacturer_id ASC;

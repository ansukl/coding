-- Database basics 2021
-- H5.2 T5
-- anna.kleemola@tuni.fi

SELECT man.manufacturer_id, manufacturer_name, COUNT(ice_cream_id) AS ice_cream_count,
    MIN(manufacturing_cost) AS min_cost,
    MAX(manufacturing_cost) AS max_cost
FROM manufacturer man LEFT OUTER JOIN ice_cream ice
    ON man.manufacturer_id = ice.manufacturer_id
GROUP BY man.manufacturer_id, manufacturer_name
ORDER BY man.manufacturer_id ASC;

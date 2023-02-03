-- Database basics 2021
-- H6 T8
-- anna.kleemola@tuni.fi

SELECT ice_cream_name, manufacturing_cost, manufacturer_name
FROM ice_cream ice INNER JOIN manufacturer man
    ON ice.manufacturer_id = man.manufacturer_id
GROUP BY ice_cream_name
HAVING MAX(manufacturing_cost) = (SELECT MAX(manufacturing_cost) FROM ice_cream);

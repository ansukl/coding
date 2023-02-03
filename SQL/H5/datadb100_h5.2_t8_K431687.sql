-- Database basics 2021
-- H5.2 T8
-- anna.kleemola@tuni.fi

SELECT ice.ice_cream_id, ice_cream_name, manufacturer_name
FROM ice_cream ice, contains con
    LEFT OUTER JOIN manufacturer man ON man.manufacturer_id = ice.manufacturer_id
WHERE ice.ice_cream_id = con.ice_cream_id
GROUP BY ice.ice_cream_id, ice_cream_name
HAVING COUNT(*) = 2
ORDER BY ice.ice_cream_id ASC;

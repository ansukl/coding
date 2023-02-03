-- Database basics 2021
-- H5.1 T5
-- anna.kleemola@tuni.fi

SELECT con.ice_cream_id, ice_cream_name
FROM ice_cream ice, contains con
WHERE con.ice_cream_id = ice.ice_cream_id
EXCEPT
SELECT con.ice_cream_id, ice_cream_name
FROM ice_cream ice, contains con
WHERE con.ice_cream_id = ice.ice_cream_id AND ingredient_id = 1
ORDER BY con.ice_cream_id ASC;

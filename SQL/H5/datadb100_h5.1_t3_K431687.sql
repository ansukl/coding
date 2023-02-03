-- Database basics 2021
-- H5.1 T3
-- anna.kleemola@tuni.fi

SELECT con.ice_cream_id, ice_cream_name
FROM ice_cream ice, contains con
WHERE con.ice_cream_id = ice.ice_cream_id AND ingredient_id = 3
INTERSECT
SELECT con.ice_cream_id, ice_cream_name
FROM ice_cream ice, contains con
WHERE con.ice_cream_id = ice.ice_cream_id AND ingredient_id = 4
ORDER BY con.ice_cream_id ASC;
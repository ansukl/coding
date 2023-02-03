-- Database basics 2021
-- H2 T7
-- anna.kleemola@tuni.fi

SELECT man.manufacturer_id, man.manufacturer_name, ice.ice_cream_id, ice.ice_cream_name
FROM manufacturer man

LEFT OUTER JOIN ice_cream ice
    ON ice.manufacturer_id = man.manufacturer_id


ORDER BY man.manufacturer_id ASC, ice.ice_cream_id ASC;
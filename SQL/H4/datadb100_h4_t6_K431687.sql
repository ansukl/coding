-- Database basics 2021
-- H4 T6
-- anna.kleemola@tuni.fi

SELECT con.ice_cream_id, ice_cream_name
FROM contains con
    LEFT OUTER JOIN ice_cream ice
        ON ice.ice_cream_id = con.ice_cream_id

    LEFT OUTER JOIN contains cont
        ON cont.ice_cream_id = con.ice_cream_id

WHERE con.ingredient_id = 3 AND cont.ingredient_id = 4
ORDER BY con.ice_cream_id ASC;

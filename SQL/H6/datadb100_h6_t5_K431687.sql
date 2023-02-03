-- Database basics 2021
-- H6 T5
-- anna.kleemola@tuni.fi

SELECT ice_cream_id, ice_cream_name
FROM ice_cream
WHERE ice_cream_id IN
    (SELECT ice_cream_id FROM contains WHERE ingredient_id = 3)
    AND
    ice_cream_id IN
    (SELECT ice_cream_id FROM contains WHERE ingredient_id = 4)
ORDER BY ice_cream_id ASC;

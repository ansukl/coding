-- Database basics 2021
-- H5.2 T3
-- anna.kleemola@tuni.fi

SELECT ingredient_id, COUNT(ice_cream_id) AS count
FROM contains
GROUP BY ingredient_id
ORDER BY ingredient_id ASC;

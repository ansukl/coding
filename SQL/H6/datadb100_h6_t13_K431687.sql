-- Database basics 2021
-- H6 T13
-- anna.kleemola@tuni.fi

SELECT ice_cream_name
FROM ice_cream
WHERE manufacturing_cost BETWEEN 1 and 1.4
ORDER BY ice_cream_name ASC;

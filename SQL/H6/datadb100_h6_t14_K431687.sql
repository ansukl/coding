-- Database basics 2021
-- H6 T14
-- anna.kleemola@tuni.fi

SELECT ice_cream_name, manufacturing_cost * 1.1 AS increased_cost
FROM ice_cream
ORDER BY ice_cream_name ASC;
